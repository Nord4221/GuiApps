import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Organizer 1.0

Window
{
    id : _window
    width: _columnlayout.width
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
        onDateStatus:
        {
            if(!_isDateCorrect)
                _labelDate.color = "red"
            else
                _labelDate.color = "black"
        }
        onDescStatus:
        {
            if(!_isDescriptionCorrect)
                _labelDescription.color = "red"
            else
                _labelDescription.color = "black"
        }
        onStateStatus:
        {
            if(!_isStateCorrect)
                _labelStatus.color = "red"
            else
                _labelStatus.color = "black"
        }
        onTaskAmountCurrent:
        {
            _textTaskCounter.text = _currentAmount
        }
    }

    ColumnLayout
    {
        id : _columnlayout
        spacing: 2
        RowLayout
        {
            Text
            {
                id : _labelDate
                text: qsTr("Date")
                Layout.minimumWidth: 60
            }
            TextField
            {
                id: _textFieldDate
                inputMask: "99.99.9999"
            }
        }

        RowLayout
        {
            Text
            {
                id : _labelDescription
                text: qsTr("Description")
                Layout.minimumWidth: 60
            }
            TextField
            {
                id: _textFieldTaskDescription
                inputMask: "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            }
        }
        RowLayout
        {
            Text
            {
                id : _labelStatus
                text: qsTr("Status")
                Layout.minimumWidth: 60
            }
            TextField
            {
                id: _textFieldTaskStatus
                inputMask: "99"
            }
        }
        MyButton
        {
            id: _pushButtonAdd
            text: "Add task"
            onClicked:
            {
               _organizerobj.slotOpenDataFile()
               _organizerobj.slotCheckDate(_textFieldDate.text)
               _organizerobj.slotCheckDescription(_textFieldTaskDescription.text)
               _organizerobj.slotCheckTaskState(_textFieldTaskStatus.text)
               _organizerobj.slotAddNewTask()
            }
        }
        RowLayout
        {
            Text
            {
                text: qsTr("Task count = ")
                Layout.minimumWidth: 60
            }
            Text
            {
                id: _textTaskCounter
            }
        }
    }
    visible: true

}
