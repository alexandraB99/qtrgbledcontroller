import QtQuick 2.6
import QtQuick.Controls 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("RGB LED Controller")

    Column {
        width: parent.width - 100
        height: 150
        anchors.centerIn: parent
        Row {
            Label {
                width: 150
                height: 50
                font.pixelSize: 24
                color: "red"
                verticalAlignment: Text.AlignVCenter
                text: "Red Color"
            }
            Slider {
                width: 360
                height: 50
                from: 0
                to: 255
                onValueChanged: {
                    RGBLedController.setRedColor(value);
                }
            }
        }
        Row {
            Label {
                width: 150
                height: 50
                font.pixelSize: 24
                color: "green"
                verticalAlignment: Text.AlignVCenter
                text: "Green Color"
            }
            Slider {
                width: 360
                height: 50
                from: 0
                to: 255
                onValueChanged: {
                    RGBLedController.setGreenColor(value);
                }
            }
        }
        Row {
            Label {
                width: 150
                height: 50
                font.pixelSize: 24
                color: "blue"
                verticalAlignment: Text.AlignVCenter
                text: "Blue Color"
            }
            Slider {
                width: 360
                height: 50
                from: 0
                to: 255
                onValueChanged: {
                    RGBLedController.setBlueColor(value);
                }
            }
        }
    }
}
