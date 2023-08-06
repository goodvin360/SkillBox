import QtQuick 2.15
import QtQuick.Window 2.15

//Window {
//    id: root
//    width: 640
//    height: 480
//    visible: true
//    title: "Make transition"

//    Rectangle {
//        id: scene
//        anchors.fill: parent
//        state: "LeftState"

//        Rectangle {
//            id: leftRectangle
//            x:100
//            y:200
//            color: "lightgrey"
//            width: 100
//            height: 100
//            border.color: "black"
//            border.width: 3
//            radius: 5

//            MouseArea {
//                anchors.fill: parent
//                onClicked: scene.state = "LeftState"
//            }
//        }

//        Rectangle {
//            id: rightRectangle
//            x:300
//            y:200
//            color: "lightgrey"
//            width: 100
//            height: 100
//            border.color: "black"
//            border.width: 3
//            radius: 5

//            MouseArea {
//                anchors.fill: parent
//                onClicked: scene.state = "RightState"
//            }
//        }

//        Rectangle {
//            id: ball
//            color: "darkgreen"
//            x: leftRectangle.x + 5
//            y: leftRectangle.y + 5
//            width: leftRectangle.width - 10
//            height: leftRectangle.height - 10
//            radius: width/2
//        }

//        states: [
//            State {
//                name: "RightState"
//                PropertyChanges {
//                    target: ball
//                    x: rightRectangle.x+5

//                }
//            } ,
//            State {
//                name: "LeftState"
//                PropertyChanges {
//                    target: ball
//                    x: leftRectangle.x+5
//                }
//            }

//        ]

//        transitions: [
//            Transition {
//                from: "LeftState"
//                to: "RightState"
//                NumberAnimation {
//                    properties: "x,y"
//                    duration: 1000
//                    easing.type: Easing.OutBounce
//                }

//            } ,
//            Transition {
//                from: "RightState"
//                to: "LeftState"
//                NumberAnimation {
//                    properties: "x,y"
//                    duration: 1000
//                    easing.type: Easing.InOutExpo
//                }

//            }
//        ]
//    }
//}






Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: "Make transition"

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "InitialState"

        Rectangle {
            id: leftRectangle
            Text {
                   id: leftName
                   anchors.centerIn: parent
                   text: "move"
                 }
            x:100
            y:200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            MouseArea {
                anchors.fill: parent
                onClicked: if(ball.x >= rightRectangle.x)
                           {
                               scene.state = "InitialState"
                           }
                            else
                           {
                               ball.x += 25
                               scene.state = "OtherState"
                           }
            }
        }

        Rectangle {
            id: rightRectangle
            Text {
                   id: rightName
                   anchors.centerIn: parent
                   text: "return"
                 }
            x:300
            y:200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "InitialState"
            }
        }

        Rectangle {
            id: ball
            color: "darkgreen"
            opacity: 0.5
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            radius: width/2
        }

        states: [
            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: ball.x  = leftRectangle.x + 5

                }
            } ,
            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x  = leftRectangle.x + 5
                }
            }

        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"
                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }

            }
        ]
    }
}
