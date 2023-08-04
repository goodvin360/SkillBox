import QtQuick 2.15
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
//            height: 200
            anchors.right: parent.right
            anchors.left: parent.left
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
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenterOffset: -200
            icon.width: 100
                    icon.height: 100
                    icon.color: "transparent"
                    icon.source: "icons/play.PNG"
            Layout.columnSpan: 1
                        Layout.rowSpan: 1
                        Layout.row: 2
                        Layout.column: 1
        }

        Button
        {
            id: name2
//            text: qsTr("Pause")
            font.pointSize: 24;
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenterOffset: -75
            icon.width: 100
                    icon.height: 100
                    icon.color: "transparent"
                    icon.source: "icons/pause.PNG"
            Layout.columnSpan: 1
                        Layout.rowSpan: 1
                        Layout.row: 2
                        Layout.column: 2
        }

        Button
        {
            id: name3
//            text: qsTr("Stop")
            font.pointSize: 24;
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenterOffset: 75
            icon.width: 100
                    icon.height: 100
                    icon.color: "transparent"
                    icon.source: "icons/stop.PNG"
            Layout.columnSpan: 1
                        Layout.rowSpan: 1
                        Layout.row: 2
                        Layout.column: 3
        }

        Button
        {
            id: name4
//            text: qsTr("Rewind")
            font.pointSize: 24;
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenterOffset: 200
            icon.width: 100
                    icon.height: 100
                    icon.color: "transparent"
                    icon.source: "icons/rewind.PNG"
            Layout.columnSpan: 1
                        Layout.rowSpan: 1
                        Layout.row: 2
                        Layout.column: 4
        }

        ProgressBar
        {
            value: 0.5
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 200
            anchors.right: parent.right
            anchors.left: parent.left
            Layout.columnSpan: 4
                        Layout.rowSpan: 1
                        Layout.row: 3
                        Layout.column: 1
        }

    }

}
