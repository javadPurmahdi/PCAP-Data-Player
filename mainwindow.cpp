#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <IPv4Layer.h>
#include <UdpLayer.h>
#include <TcpLayer.h>
#include <Packet.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

/*@/****************************************************************************
**
** Copyright (C) 2020 javad purmahdi <javad.purmahdi@gmail.com>.
** Contact: https://www.qt.io/licensing/
**
** This file is part of PacketDataPlayer
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    reader = NULL;

    server     = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(server_connected()));
    tcpSocket  = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(socket_Connected()));
    udpSocket  = new QUdpSocket(this);

    playTimer = new QTimer();
    connect(playTimer,SIGNAL(timeout()),this,SLOT(playTimer_tick()));

    msgLabel = new QLabel(ui->statusBar);
    statusBar()->addWidget(msgLabel);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnFilePath_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Open Pcap File","","PCAP File (*.pcap)");


    if(filePath == "")
    {
        return;
    }
    ui->txtFilePath->setText(filePath);

    pcpp::PcapFileReaderDevice checkFile(filePath.toStdString().c_str());
    if(checkFile.open())
    {
        int cnt = 0;
        pcpp::RawPacket packet;
        while(checkFile.getNextPacket(packet))
        {
            cnt++;
        }
        ui->txtEndPacket->setMaximum(cnt);
        ui->txtEndPacket->setValue(cnt);
        checkFile.close();
    }

}

void MainWindow::on_pushButton_clicked()
{
    if(ui->cmbConnectiontype->currentIndex() == 0)//tcp server
    {
        socketConnected = false;
        server->close();
        server->listen(QHostAddress::Any,ui->txtPort->text().toInt());
    }

    if(ui->cmbConnectiontype->currentIndex() == 1)//tcp client
    {
        socketConnected = false;
        server->close();
        if(tcpSocket->isOpen())
        {
            tcpSocket->close();
        }

        tcpSocket->connectToHost(QHostAddress(ui->txtIp->text()),ui->txtPort->text().toInt());

    }
}

void MainWindow::server_connected()
{
    tcpSocket = server->nextPendingConnection();
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(socketDisconnect()));

    ui->cmbConnectiontype->setEnabled(false);
    ui->txtIp->setEnabled(false);
    ui->txtPort->setEnabled(false);
    ui->pushButton->setText("Disconnect");
    socketConnected = true;
}

void MainWindow::socket_Connected()
{
    ui->pushButton->setText("Disconnect");
    socketConnected = true;
}

void MainWindow::socketDisconnect()
{
    socketConnected = false;
    ui->cmbConnectiontype->setEnabled(true);
    ui->txtIp->setEnabled(true);
    ui->txtPort->setEnabled(true);
    ui->pushButton->setText("Connect");
}

void MainWindow::on_btnPlay_clicked(bool checked)
{
    m_packetNumber = 0;
    if(checked)
    {
        if(reader != NULL)
        {
            if(reader->isOpened())
            {
                reader->close();
            }
            delete reader;
            reader = NULL;
        }
        reader = new pcpp::PcapFileReaderDevice(ui->txtFilePath->text().toStdString().c_str());
        qDebug()<<"open file status"<<reader->open();


        int maxNum = ui->txtStartPacket->value();
        while(m_packetNumber < maxNum)
        {
            pcpp::RawPacket packet;
            bool read = reader->getNextPacket(packet);

            m_packetNumber++;
            if(!read)
                break;
        }

        playTimer->stop();
        playTimer->start(ui->txtTimerSpeed->value());
    }
    else
    {
        if(reader != NULL)
        {
            if(reader->isOpened())
            {
                reader->close();
            }
            delete reader;
            reader = NULL;
        }
    }
}

void MainWindow::on_btnReset_clicked()
{
    m_packetNumber = 0;
    if(reader != NULL)
    {
        if(reader->isOpened())
        {
            reader->close();
            reader->open();
        }
    }
}

void MainWindow::playTimer_tick()
{

    if(ui->txtEndPacket->value() != 0)
    {
        if(m_packetNumber > ui->txtEndPacket->value())
        {
            if(ui->repeat->isChecked())
            {
                on_btnPlay_clicked(true);
            }
            return;
        }
    }

    if(reader == NULL)
    {
        return;
    }
    if(!reader->isOpened())
        return;


    pcpp::RawPacket rawData;
    bool readed = reader->getNextPacket(rawData);
    if(readed)
    {
        pcpp::Packet parsPacket(&rawData);

        if(parsPacket.isPacketOfType(pcpp::TCP))
        {
            pcpp::TcpLayer *tcpLayer = parsPacket.getLayerOfType<pcpp::TcpLayer>();

            static QVector<uint8_t> memory;
            if(memory.isEmpty())
                memory.resize(3e6);
            size_t dataLength = tcpLayer->getDataLen();
            size_t startIndex = tcpLayer->getHeaderLen();
            tcpLayer->copyData(&memory.front());

            m_packetNumber++;

            msgLabel->setText("PCK NUM:" + QString::number(m_packetNumber));

            if(ui->cmbConnectiontype->currentIndex() < 2)//tcp server or client
            {
                if(tcpSocket->isOpen())
                {
                    tcpSocket->write((char*)(&memory.front() + startIndex) , dataLength - startIndex);
                }
            }

            if(ui->cmbConnectiontype->currentIndex() == 2)
            {
                udpSocket->writeDatagram((char*)(&memory.front() + startIndex) , dataLength - startIndex
                                         ,QHostAddress(ui->txtIp->text()),ui->txtPort->text().toInt());
            }
        }


        if(parsPacket.isPacketOfType(pcpp::UDP))
        {
            pcpp::UdpLayer *udpLayer = parsPacket.getLayerOfType<pcpp::UdpLayer>();

            static QVector<uint8_t> memory;
            if(memory.isEmpty())
                memory.resize(3e6);
            size_t dataLength = udpLayer->getDataLen();
            size_t startIndex = udpLayer->getHeaderLen();

            if(startIndex >= dataLength)
                return;
            udpLayer->copyData(&memory.front());

            m_packetNumber++;

            msgLabel->setText("PCK NUM:" + QString::number(m_packetNumber));

            if(ui->cmbConnectiontype->currentIndex() < 2)//tcp server or client
            {
                if(tcpSocket->isOpen())
                {
                    tcpSocket->write((char*)(&memory.front() + startIndex) , dataLength - startIndex);
                }
            }

            if(ui->cmbConnectiontype->currentIndex() == 2)
            {
                udpSocket->writeDatagram((char*)(&memory.front() + startIndex) , dataLength - startIndex
                                         ,QHostAddress(ui->txtIp->text()),ui->txtPort->text().toInt());
            }
        }

    }
}

void MainWindow::on_actionAbout_triggered()
{
    QString msg = "This Application writen by javad \njavad.purmahdi@gmail.com";
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}
