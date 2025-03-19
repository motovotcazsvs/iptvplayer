#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CPlaylistManager.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CPlaylistManager playlist_manager;
    playlist_manager.loadPlaylist("/home/dell/PROGRAMMING/iptvplayer/vipdrive_playlist.m3u8");

    engine.rootContext()->setContextProperty("playlist_manager", &playlist_manager);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

