include(../../modules/qtx_jsonrpc.pri)
include(../../mkspecs/features/qtx_config.prf)
include(../../mkspecs/features/qtx_module.prf)

INCLUDEPATH += \
    ../../../qtxjson/include

include(jsonrpc.pri)

LIBS += \
    -L../../../qtxjson/lib

LIBS += -lQtxJson
