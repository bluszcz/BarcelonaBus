# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = BarcelonaBus

CONFIG += sailfishapp

SOURCES += src/BarcelonaBus.cpp \
    src/BusReader.cpp

OTHER_FILES += qml/BarcelonaBus.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/BarcelonaBus.changes.in \
    rpm/BarcelonaBus.spec \
    rpm/BarcelonaBus.yaml \
    translations/*.ts \
    BarcelonaBus.desktop

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/BarcelonaBus-de.ts

HEADERS += \
    src/BusReader.h

