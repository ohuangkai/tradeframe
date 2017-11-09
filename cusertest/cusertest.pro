QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../cuser/release/ -lcuser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../cuser/debug/ -lcuser
else:unix: LIBS += -L$$OUT_PWD/../cuser/ -lcuser

INCLUDEPATH += $$PWD/../cuser
DEPENDPATH += $$PWD/../cuser

INCLUDEPATH += $$PWD/../common
include($$PWD/../common/common.pro)


#SUBDIRS += \
#    ../common/common.pro

#HEADERS += \
#    ../common/capiinterface.h \
#    ../common/cmarketdata.h \
#    ../common/cmonitor.h \
#    ../common/cspinmutex.h \
#    ../common/cstrategy.h \
#    ../common/cuserinfo.h
