TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -L"/usr/lib/"
LIBS += -L"/usr/local/lib/"
include(qmake_modules/findOpenGL.pro)
include(qmake_modules/findLuaJIT.pro)
include(qmake_modules/findBullet.pro)
include(qmake_modules/findSFML.pro)
include(qmake_modules/findGLEW.pro)
include(qmake_modules/findAssimp.pro)
INCLUDEPATH += inc
SOURCES += "src/main.cpp" \
    src/baseapp.cpp \
    src/testapp.cpp \
    src/vector.cpp \
    src/fileio.c
HEADERS += "inc/baseapp.h" \
    inc/testapp.h \
    inc/vector.h \
    inc/static.h \
    inc/fileio.h
