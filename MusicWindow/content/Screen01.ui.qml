/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5
import MusicWindow

Rectangle {
    width: Constants.width
    height: Constants.height
    color: "#000000"


    Text {
        width: 361
        height: 48
        color: "#fdfdfd"
        text: qsTr("Welcome to the music player")
        font.weight: Font.DemiBold
        anchors.verticalCenterOffset: -205
        anchors.horizontalCenterOffset: 1
        font.pointSize: 20
        anchors.centerIn: parent
        font.family: Constants.font.family
    }

    ListView {
        id: listView
        x: 613
        y: 393
        width: 227
        height: 278
        orientation: ListView.Vertical
        model: ListModel {
            ListElement {
                name: "1st song"
                colorCode: "blue"
            }

            ListElement {
                name: "2nd song"
                colorCode: "red"
            }

            ListElement {
                name: "3rd song"
                colorCode: "green"
            }

            ListElement {
                name: "4th song"
                colorCode: "yellow"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
    }
}
