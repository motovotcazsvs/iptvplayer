#include <QGuiApplication>
#include <QQmlApplicationEngine>

//#include <QCoreApplication>
//#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;



	QString playlistFile = "/home/dell/PROGRAMMING/iptvplayer/vipdrive_playlist.m3u8";
    QFile file(playlistFile);
    
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString playlistContent = in.readAll();
        file.close();

        // Шукаємо першу HTTP-адресу
        QRegExp regex("http://[^\n]+");
        int pos = regex.indexIn(playlistContent);
        QString httpUrl;
        if (pos > -1) {
            httpUrl = regex.cap(0); // Перша HTTP-адреса
        }

        // Передаємо URL в QML
        engine.rootContext()->setContextProperty("playlistUrl", httpUrl);
    }


    // Завантаження QML файлу
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

