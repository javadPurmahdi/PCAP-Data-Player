#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <PcapFileDevice.h>
#include <QTcpSocket>
#include <QTcpServer>
#include <QUdpSocket>
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnFilePath_clicked();

    void on_pushButton_clicked();

    void server_connected();

    void socket_Connected();

    void socketDisconnect();

    void on_btnPlay_clicked(bool checked);

    void on_btnReset_clicked();

    void playTimer_tick();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;

    QLabel *msgLabel;

    pcpp::PcapFileReaderDevice *reader;
    QTimer *playTimer;

    QTcpServer *server;
    QTcpSocket *tcpSocket;
    QUdpSocket *udpSocket;

    int m_packetNumber;

    bool socketConnected;


};

#endif // MAINWINDOW_H
