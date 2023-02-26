import QtQuick 2.0

BorderImage
{
    property alias text: _txt.text
    signal clicked
    source: "qrc:///png-clipart-buttons-buttons.png"
    width: _txt.width+15; height: _txt.height+15
    border.left: 5; border.top: 5
    border.right: 5; border.bottom: 5
    Text
    {
        id: _txt
        anchors.centerIn: parent
    }
    MouseArea
    {
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
