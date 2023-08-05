import QtQuick 2.12
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    GridLayout {
        id: grid
        anchors.fill: parent
        columns: 4
        rows: 3


        Rectangle
        {
            id: childWindow
            color: "lightblue"
            Layout.fillHeight: true
            Layout.fillWidth: true
//            width: 400
            height: 300
            visible: true
            Layout.columnSpan: 4
            Layout.rowSpan: 1
            Layout.row: 0
            Layout.column: 0
        }


        Button
        {
            id: name1
//            text: qsTr("Play")
            font.pointSize: 24;
            Layout.fillHeight: true
            Layout.fillWidth: true
            icon.height: Layout.preferredHeight
            icon.width: Layout.preferredWidth
            icon.color: "transparent"
            icon.source: "icons/play.PNG"
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 0
        }

        Button
        {
            id: name2
//            text: qsTr("Pause")
            font.pointSize: 24;
            Layout.fillHeight: true
            Layout.fillWidth: true
            icon.height: Layout.preferredHeight
            icon.width: Layout.preferredWidth
            icon.color: "transparent"
            icon.source: "icons/pause.PNG"
            Layout.columnSpan: 1
                        Layout.rowSpan: 1
                        Layout.row: 1
                        Layout.column: 1
        }

        Button
        {
            id: name3
//            text: qsTr("Stop")
            font.pointSize: 24;
            Layout.fillHeight: true
            Layout.fillWidth: true
            icon.height: Layout.preferredHeight
            icon.width: Layout.preferredWidth
            icon.color: "transparent"
            icon.source: "icons/stop.PNG"
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 2
        }

        Button
        {
            id: name4
//            text: qsTr("Rewind")
            font.pointSize: 24;
            Layout.fillHeight: true
            Layout.fillWidth: true
            icon.height: Layout.preferredHeight
            icon.width: Layout.preferredWidth
            icon.color: "transparent"
            icon.source: "icons/rewind.PNG"
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 3
        }

        ProgressBar {
            id: control
            value: 0.5
            padding: 2
            Layout.fillHeight: true
            Layout.fillWidth: true

            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 16
                color: "#e6e6e6"
                radius: 3
            }

            contentItem: Item {
                implicitWidth: 200
                implicitHeight: 14

                Rectangle {
                    width: control.visualPosition * parent.width
                    height: parent.height
                    radius: 2
                    color: "#17a81a"
                }
            }

            Layout.columnSpan: 4
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 0
        }

    }

}
