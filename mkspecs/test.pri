include(features/qtx_testcase.prf)


QT += network

INCLUDEPATH += \
    ../../../src/jsonrpc \
    ../../../../qtxjson/include \
    ../../../../qtxmockcore/include

LIBS += \
    -L../../../lib \
    -L../../../../qtxjson/lib \
    -L../../../../qtxmockcore/lib

LIBS += -lQtxJsonRpc -lQtxJson -lQtxMockCore
