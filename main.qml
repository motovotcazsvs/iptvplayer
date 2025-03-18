import QtQuick 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "IPTV Player"

    // Медійний плеєр для відтворення плейлиста
    MediaPlayer {
        id: mediaPlayer
        autoPlay: true
        loops: MediaPlayer.Infinite
	//source: "http://jxbkvhho.otttv.pw/iptv/A4YKA85FN8C7W4/9314/index.m3u8"
        source: playlistUrl
        onError: console.log("Error:", errorString)
        
        
    }

    // Виведення відео на екран
    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        source: mediaPlayer
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        Button {
            text: "Play"
            onClicked: mediaPlayer.play()
        }

        Button {
            text: "Pause"
            onClicked: mediaPlayer.pause()
        }

        Button {
            text: "Next"
            onClicked: {
                // Тут можна додати логіку для наступного елементу
            }
        }

        Button {
            text: "Previous"
            onClicked: {
                // Тут можна додати логіку для попереднього елементу
            }
        }
    }
}


