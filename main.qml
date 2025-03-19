import QtQuick 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "IPTV Player"

    MediaPlayer {
        id: mediaPlayer
        autoPlay: true
        loops: MediaPlayer.Infinite
        source: playlist_manager.currentStream

        onError: console.log("Error:", errorString)
    }

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        source: mediaPlayer
    }

    footer: Rectangle {
        height: 50
        color: "#333"
        width: parent.width

        Row {
            anchors.centerIn: parent
            spacing: 10

            Button {
                text: "Previous"
                onClicked: playlist_manager.previousStream()
            }

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
                onClicked: playlist_manager.nextStream()
            }
        }
    }
}

