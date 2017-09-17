# Config.pri file version 2.0. Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR = $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        profile {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        } else {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }

    }

    CONFIG(release, debug|release) {
        !profile {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

simulator {
    CONFIG(debug, debug|release) {
        !profile {
            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

config_pri_assets {
    OTHER_FILES += \
        $$quote($$BASEDIR/assets/components/AlbumTrackListItem.qml) \
        $$quote($$BASEDIR/assets/components/BioContainer.qml) \
        $$quote($$BASEDIR/assets/components/CustomTitleBar.qml) \
        $$quote($$BASEDIR/assets/components/Friend.qml) \
        $$quote($$BASEDIR/assets/components/HorizontalList.qml) \
        $$quote($$BASEDIR/assets/components/ImageBackground.qml) \
        $$quote($$BASEDIR/assets/components/InputTitleBar.qml) \
        $$quote($$BASEDIR/assets/components/PeriodsList.qml) \
        $$quote($$BASEDIR/assets/components/RecentTrack.qml) \
        $$quote($$BASEDIR/assets/components/StatCount.qml) \
        $$quote($$BASEDIR/assets/components/Stats.qml) \
        $$quote($$BASEDIR/assets/components/Tag.qml) \
        $$quote($$BASEDIR/assets/components/TagsContainer.qml) \
        $$quote($$BASEDIR/assets/components/TopAlbum.qml) \
        $$quote($$BASEDIR/assets/components/TopArtist.qml) \
        $$quote($$BASEDIR/assets/components/TopTrack.qml) \
        $$quote($$BASEDIR/assets/components/TopTrackListItem.qml) \
        $$quote($$BASEDIR/assets/components/UserTopArtist.qml) \
        $$quote($$BASEDIR/assets/components/UserTopTrack.qml) \
        $$quote($$BASEDIR/assets/components/WebImageView.qml) \
        $$quote($$BASEDIR/assets/images/Lastfm_logo.png) \
        $$quote($$BASEDIR/assets/images/concert_bg.jpg) \
        $$quote($$BASEDIR/assets/images/heart_filled.png) \
        $$quote($$BASEDIR/assets/images/ic_all.png) \
        $$quote($$BASEDIR/assets/images/ic_cd.png) \
        $$quote($$BASEDIR/assets/images/ic_chart.png) \
        $$quote($$BASEDIR/assets/images/ic_concerts.png) \
        $$quote($$BASEDIR/assets/images/ic_contact.png) \
        $$quote($$BASEDIR/assets/images/ic_favorite.png) \
        $$quote($$BASEDIR/assets/images/ic_groups_white.png) \
        $$quote($$BASEDIR/assets/images/ic_reload.png) \
        $$quote($$BASEDIR/assets/images/me.png) \
        $$quote($$BASEDIR/assets/images/opac_bg.png) \
        $$quote($$BASEDIR/assets/main.qml) \
        $$quote($$BASEDIR/assets/pages/AlbumPage.qml) \
        $$quote($$BASEDIR/assets/pages/ArtistPage.qml) \
        $$quote($$BASEDIR/assets/pages/ArtistTopTracks.qml) \
        $$quote($$BASEDIR/assets/pages/ChartsPage.qml) \
        $$quote($$BASEDIR/assets/pages/FriendsPage.qml) \
        $$quote($$BASEDIR/assets/pages/HelpPage.qml) \
        $$quote($$BASEDIR/assets/pages/Login.qml) \
        $$quote($$BASEDIR/assets/pages/LovedTracksPage.qml) \
        $$quote($$BASEDIR/assets/pages/MyProfilePage.qml) \
        $$quote($$BASEDIR/assets/pages/ScrobblesPage.qml) \
        $$quote($$BASEDIR/assets/pages/SettingsPage.qml) \
        $$quote($$BASEDIR/assets/pages/TagPage.qml) \
        $$quote($$BASEDIR/assets/pages/TopAlbumsPage.qml) \
        $$quote($$BASEDIR/assets/pages/TopArtistsPage.qml) \
        $$quote($$BASEDIR/assets/pages/TopTracksPage.qml) \
        $$quote($$BASEDIR/assets/pages/UserPage.qml)
}

config_pri_source_group1 {
    SOURCES += \
        $$quote($$BASEDIR/src/Logger.cpp) \
        $$quote($$BASEDIR/src/applicationui.cpp) \
        $$quote($$BASEDIR/src/config/AppConfig.cpp) \
        $$quote($$BASEDIR/src/lastfm/AlbumController.cpp) \
        $$quote($$BASEDIR/src/lastfm/ArtistController.cpp) \
        $$quote($$BASEDIR/src/lastfm/ChartController.cpp) \
        $$quote($$BASEDIR/src/lastfm/LastFM.cpp) \
        $$quote($$BASEDIR/src/lastfm/TagController.cpp) \
        $$quote($$BASEDIR/src/lastfm/TrackController.cpp) \
        $$quote($$BASEDIR/src/lastfm/UserController.cpp) \
        $$quote($$BASEDIR/src/main.cpp) \
        $$quote($$BASEDIR/src/services/ImageService.cpp)

    HEADERS += \
        $$quote($$BASEDIR/src/Common.hpp) \
        $$quote($$BASEDIR/src/Logger.hpp) \
        $$quote($$BASEDIR/src/applicationui.hpp) \
        $$quote($$BASEDIR/src/config/AppConfig.hpp) \
        $$quote($$BASEDIR/src/lastfm/AlbumController.hpp) \
        $$quote($$BASEDIR/src/lastfm/ArtistController.hpp) \
        $$quote($$BASEDIR/src/lastfm/ChartController.hpp) \
        $$quote($$BASEDIR/src/lastfm/LastFM.hpp) \
        $$quote($$BASEDIR/src/lastfm/LastFMCommon.hpp) \
        $$quote($$BASEDIR/src/lastfm/TagController.hpp) \
        $$quote($$BASEDIR/src/lastfm/TrackController.hpp) \
        $$quote($$BASEDIR/src/lastfm/UserController.hpp) \
        $$quote($$BASEDIR/src/services/ImageService.hpp)
}

CONFIG += precompile_header

PRECOMPILED_HEADER = $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES += \
        $$quote($$BASEDIR/../src/*.c) \
        $$quote($$BASEDIR/../src/*.c++) \
        $$quote($$BASEDIR/../src/*.cc) \
        $$quote($$BASEDIR/../src/*.cpp) \
        $$quote($$BASEDIR/../src/*.cxx) \
        $$quote($$BASEDIR/../src/config/*.c) \
        $$quote($$BASEDIR/../src/config/*.c++) \
        $$quote($$BASEDIR/../src/config/*.cc) \
        $$quote($$BASEDIR/../src/config/*.cpp) \
        $$quote($$BASEDIR/../src/config/*.cxx) \
        $$quote($$BASEDIR/../src/lastfm/*.c) \
        $$quote($$BASEDIR/../src/lastfm/*.c++) \
        $$quote($$BASEDIR/../src/lastfm/*.cc) \
        $$quote($$BASEDIR/../src/lastfm/*.cpp) \
        $$quote($$BASEDIR/../src/lastfm/*.cxx) \
        $$quote($$BASEDIR/../src/services/*.c) \
        $$quote($$BASEDIR/../src/services/*.c++) \
        $$quote($$BASEDIR/../src/services/*.cc) \
        $$quote($$BASEDIR/../src/services/*.cpp) \
        $$quote($$BASEDIR/../src/services/*.cxx) \
        $$quote($$BASEDIR/../assets/*.qml) \
        $$quote($$BASEDIR/../assets/*.js) \
        $$quote($$BASEDIR/../assets/*.qs) \
        $$quote($$BASEDIR/../assets/components/*.qml) \
        $$quote($$BASEDIR/../assets/components/*.js) \
        $$quote($$BASEDIR/../assets/components/*.qs) \
        $$quote($$BASEDIR/../assets/images/*.qml) \
        $$quote($$BASEDIR/../assets/images/*.js) \
        $$quote($$BASEDIR/../assets/images/*.qs) \
        $$quote($$BASEDIR/../assets/pages/*.qml) \
        $$quote($$BASEDIR/../assets/pages/*.js) \
        $$quote($$BASEDIR/../assets/pages/*.qs)

    HEADERS += \
        $$quote($$BASEDIR/../src/*.h) \
        $$quote($$BASEDIR/../src/*.h++) \
        $$quote($$BASEDIR/../src/*.hh) \
        $$quote($$BASEDIR/../src/*.hpp) \
        $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS = $$quote($${TARGET}_ru.ts) \
    $$quote($${TARGET}.ts)
