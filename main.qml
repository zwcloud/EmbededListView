import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

ColumnLayout {
    Layout.fillHeight: true
    Label{
        text: 'objectList.rowCount = ' + objectList.rowCount()
        font.pointSize: 20
        Layout.leftMargin: 20
    }

    ListView {
        model: objectList
        Layout.fillHeight: true
        Layout.leftMargin: 20
        delegate: ColumnLayout {
            Label {
                text: 'obj_name = ' + obj_name + ', values rowCount = ' + obj_values.rowCount()
                font.pointSize: 15
            }

            Repeater {
                model: obj_values
                delegate: Label {
                    Layout.leftMargin: 20
                    text: 'values['+ index +'] of objectList[' + obj_index + ']= ' + int_value
                    font.pointSize: 12
                }
            }
        }
    }

}
