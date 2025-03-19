#ifndef CPLAYLISTMANAGER_H
#define CPLAYLISTMANAGER_H

#include <QObject>
#include <QString>
#include <QStringList>

class CPlaylistManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentStream READ currentStream NOTIFY streamChanged)

public:
    explicit CPlaylistManager(QObject *parent = nullptr);
    
    void loadPlaylist(const QString& file_path);
    QString currentStream() const;

public slots:
    void nextStream();
    void previousStream();

signals:
    void streamChanged(const QString& new_stream);

private:
    QStringList _list_stream;
    int _current_stream;
};

#endif // CPLAYLISTMANAGER_H

