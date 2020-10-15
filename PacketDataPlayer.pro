#-------------------------------------------------
#
# Project created by QtCreator 2020-10-08T10:37:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = PacketDataPlayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui


#============ For Linux ===============================
#INCLUDEPATH += 'usr/include/netinet'
#DEPENDPATH  += 'usr/include/netinet'

#LIBS += -lPcap++ -lPacket++ -lCommon++ -lpcap -lpthread
#DEFINES += PCAPPP_POST_BUILD
#DEFINES += PCAPPP_BUILD_FLAG
#========================================================



#============ For Windows ===============================
LIBS += -L'D:/dev/PcapPlusPlus-master/Dist' -lPcap++ -lPacket++ -lCommon++
INCLUDEPATH += 'D:/dev/PcapPlusPlus-master/Dist/header'
DEPENDPATH  += 'D:/dev/PcapPlusPlus-master/Dist/header'


LIBS += -L'D:/dev/pthreads-w32-2-9-1-release/Pre-built.2/lib/x64' -lpthreadVC2
INCLUDEPATH += 'D:/dev/pthreads-w32-2-9-1-release/Pre-built.2/include'
DEPENDPATH  += 'D:/dev/pthreads-w32-2-9-1-release/Pre-built.2/include'

LIBS += -L'D:/dev/WpdPack_4_1_2/WpdPack/Lib/x64' -lwpcap -lPacket
INCLUDEPATH += 'D:/dev/WpdPack_4_1_2/WpdPack/Include'
DEPENDPATH  += 'D:/dev/WpdPack_4_1_2/WpdPack/Include'

LIBS += -lWs2_32 -lIPHLPAPI
#=======================================================
