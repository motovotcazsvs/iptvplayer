#include "CPlaylistManager.h"
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QDebug>

CPlaylistManager::CPlaylistManager(QObject* parent) : 
	QObject(parent), 
	_current_stream(0) 
{

}

void CPlaylistManager::loadPlaylist(const QString& file_path) 
{
    QFile file(file_path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "Не вдалося відкрити файл:" << file_path;
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Парсимо всі HTTP-адреси
    QRegExp regex("http://[^\n]+");
    int pos = 0;
    while((pos = regex.indexIn(content, pos)) != -1){
        _list_stream.append(regex.cap(0));
        pos += regex.matchedLength();
    }

    if(!_list_stream.isEmpty()){
        _current_stream = 0;
        emit streamChanged(_list_stream[_current_stream]);
    }
}

QString CPlaylistManager::currentStream() const 
{
    if(_current_stream >= 0 && _current_stream < _list_stream.size())
        return _list_stream[_current_stream];
    return QString();
}

void CPlaylistManager::nextStream() {
    if(_list_stream.isEmpty()) return;

    _current_stream = (_current_stream + 1) % _list_stream.size();
    emit streamChanged(_list_stream[_current_stream]);
}

void CPlaylistManager::previousStream() {
    if (_list_stream.isEmpty()) return;

    _current_stream = (_current_stream - 1 + _list_stream.size()) % _list_stream.size();
    emit streamChanged(_list_stream[_current_stream]);
}

