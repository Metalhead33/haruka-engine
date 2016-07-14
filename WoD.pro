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
    src/model.cpp \
    src/bufferObject.cpp \
    src/Mesh.cpp \
    src/BaseAapp.cpp \
    src/FileIO.c \
    src/TestApp.cpp \
    src/Shader.cpp
HEADERS += \
    inc/bufferObject.hpp \
    inc/Mesh.hpp \
    inc/Model.hpp \
    inc/BaseAapp.hpp \
    inc/FileIO.h \
    inc/Static.hpp \
    inc/TestApp.hpp \
    inc/Shader.hpp
