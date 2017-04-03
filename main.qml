import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import org.QrtiDDS 1.0

ApplicationWindow {
    id: root
    title: qsTr("Qt rti DDS Messager")
    minimumHeight: 600
    minimumWidth: 900

    maximumWidth: Screen.width
    maximumHeight: Screen.height
    visible: true

    property string myName : "thurberdog"
    property variant mySettingsWindow

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }


   // Connections { target: rxMsg; onGotNewData: console.log("Signal happened"); }

    TabView{
        id: myTabs
        anchors.fill: parent
        Tab{
            title: "Message"
            Column {
                anchors.fill: parent
                anchors.margins: 3
                width: parent.width
                height: parent.height
                spacing: 3

                TextArea{
                    id: rcvMsgs
                    height: 0.88 * parent.height
                    readOnly: true
                    width: parent.width
                }


                TextField {
                    id: publish_message
                    text: ""
                    width: parent.width
                    onAccepted: {
                        if (text){
                            msgHandler.writeData(root.myName + ": " + text);
                            publish_message.text = "";
                        }
                    }
                }

                Button{
                    id: publish_messageBtn
                    text: "Publish Message to DDS"
                    width: parent.width
                    onClicked: {
                        if (publish_message.text){
                            msgHandler.writeData(root.myName + ": " + publish_message.text);
                            publish_message.text = "";
                        }
                    }
                }

                //handle Messages comming via C++
                QrtiDDShandler{
                    id: msgHandler
                    onNewRcvdDataAvailable: rcvMsgs.append(data);
                }

            }
        }
        Tab {
            title: "Settings"
            Column {
                anchors.fill: parent
                anchors.margins: 3
                width: parent.width
                height: parent.height
                spacing: 3

                TextField {
                    id: myName
                    text: root.myName
                    width: parent.width
                    onAccepted: {
                        if (text){
                            root.myName = text;
                            messageDialog.show(qsTr("Name successfully changed"))
                        }
                    }
                }

                Button{
                    id: setName
                    text: "Set Chat Name"
                    width: parent.width
                    onClicked: {
                        if (myName.text){
                            root.myName = myName.text
                            messageDialog.show(qsTr("Name successfully changed"))
                        }
                    }
                }
                MessageDialog {
                    id: messageDialog
                    title: qsTr("Successful")

                    function show(caption) {
                        messageDialog.text = caption;
                        messageDialog.open();
                    }
                }
            }
        }
    }
}
