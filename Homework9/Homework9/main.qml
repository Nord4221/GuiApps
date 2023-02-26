import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Organizer 1.0

Window
{
    id : _window
    width: 300
    height: _columnlayout.height
    title: qsTr("Task input")
    Organizer
    {
        id: _organizerobj

        onFileOpenedChanged:
        {
            if(_isInitSuccess)
                _textEdit.text = "               File Opened"
            else
                Qt.quit()
        }
    }

    ColumnLayout
    {
        id : _columnlayout
        spacing: 2
        TextField
        {
            width: _window.width
            id: _textEdit
            //placeholderText: "Input (date ), (task origin), (task progress);"
            inputMask: "99.99.99___aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa___9 "
        }
        MyButton
        {
            id: _pushButtonAdd
            text: "Add task"
            onClicked:
            {
               _organizerobj.slotOpenDataFile()
               _organizerobj.slotAddNewTask(_textEdit.text)
            }
        }
    }
    visible: true

}
