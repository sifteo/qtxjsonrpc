include(features/qtx_testcase.prf)


QT += network

INCLUDEPATH += \
    ../../../src/jsonrpc \
    ../../../../qtxjson/include

LIBS += \
    -L../../../lib \
    -L../../../../qtxjson/lib \

LIBS += -lQtxJsonRpc -lQtxJson
