/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_1;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *logoutButton;
    QPushButton *pushButton;
    QPushButton *SwitchPlat_Button;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *deviceListButton;
    QPushButton *shareDevListButton;
    QPushButton *alarmListButton;
    QPushButton *setAlarmReadButton;
    QPushButton *showAlarmPicButton;
    QPushButton *getCameraInfoButton;
    QPushButton *updateCameraInfoButton;
    QPushButton *deviceInfoButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *switchVideoLevelButton;
    QPushButton *startRealPlayButton;
    QPushButton *stopRealPlayButton;
    QPushButton *capturePictureButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *osdLabel;
    QPushButton *pauseButton;
    QPushButton *playBackListButton;
    QPushButton *resumeButton;
    QPushButton *startPlayBackButton;
    QPushButton *stopPlayBackButton;
    QLineEdit *PbEndTime;
    QLineEdit *PbStartTime;
    QPushButton *setPlayBackTimeButton;
    QCheckBox *videoRecordBox;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *switchSoundButton;
    QSlider *setVolumeSlider;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *startVoiceTalkButton;
    QPushButton *stopVoiceTalkButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QPushButton *defenceOnButton;
    QPushButton *defenceOffButton;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_5;
    QWidget *previewWindow;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_ZoomIn;
    QPushButton *pushButton_DR;
    QPushButton *pushButton_ZoomOut;
    QPushButton *pushButton_DL;
    QPushButton *pushButton_FocusNear;
    QPushButton *pushButton_FocusFar;
    QPushButton *pushButton_UR;
    QPushButton *pushButton_U;
    QPushButton *pushButton_Wiper;
    QPushButton *pushButton_Light;
    QPushButton *pushButton_UL;
    QPushButton *pushButton_L;
    QPushButton *pushButton_R;
    QPushButton *pushButton_D;
    QPushButton *pushButton_IrisStart;
    QPushButton *pushButton_IrisStop;
    QPushButton *pushButton_Auto;
    QGroupBox *groupBox_10;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *pushAlarmCheckBox;
    QCheckBox *pushDevStatusCheckBox;
    QCheckBox *pushTransparentChannelCheckBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *startPushRecvButton;
    QPushButton *stopPushRecvButton;
    QTabWidget *tabWidget;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 666);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(MainWindow);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox_1 = new QGroupBox(MainWindow);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setMinimumSize(QSize(300, 0));
        groupBox_1->setMaximumSize(QSize(300, 16777215));
        horizontalLayout_2 = new QHBoxLayout(groupBox_1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginButton = new QPushButton(groupBox_1);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout->addWidget(loginButton);

        logoutButton = new QPushButton(groupBox_1);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        horizontalLayout->addWidget(logoutButton);

        pushButton = new QPushButton(groupBox_1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        SwitchPlat_Button = new QPushButton(groupBox_1);
        SwitchPlat_Button->setObjectName(QString::fromUtf8("SwitchPlat_Button"));

        horizontalLayout->addWidget(SwitchPlat_Button);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_1);

        groupBox_2 = new QGroupBox(MainWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        deviceListButton = new QPushButton(groupBox_2);
        deviceListButton->setObjectName(QString::fromUtf8("deviceListButton"));

        gridLayout_3->addWidget(deviceListButton, 0, 0, 1, 1);

        shareDevListButton = new QPushButton(groupBox_2);
        shareDevListButton->setObjectName(QString::fromUtf8("shareDevListButton"));

        gridLayout_3->addWidget(shareDevListButton, 0, 2, 1, 1);

        alarmListButton = new QPushButton(groupBox_2);
        alarmListButton->setObjectName(QString::fromUtf8("alarmListButton"));

        gridLayout_3->addWidget(alarmListButton, 5, 0, 1, 1);

        setAlarmReadButton = new QPushButton(groupBox_2);
        setAlarmReadButton->setObjectName(QString::fromUtf8("setAlarmReadButton"));

        gridLayout_3->addWidget(setAlarmReadButton, 5, 2, 1, 1);

        showAlarmPicButton = new QPushButton(groupBox_2);
        showAlarmPicButton->setObjectName(QString::fromUtf8("showAlarmPicButton"));

        gridLayout_3->addWidget(showAlarmPicButton, 5, 3, 1, 1);

        getCameraInfoButton = new QPushButton(groupBox_2);
        getCameraInfoButton->setObjectName(QString::fromUtf8("getCameraInfoButton"));

        gridLayout_3->addWidget(getCameraInfoButton, 1, 2, 1, 1);

        updateCameraInfoButton = new QPushButton(groupBox_2);
        updateCameraInfoButton->setObjectName(QString::fromUtf8("updateCameraInfoButton"));

        gridLayout_3->addWidget(updateCameraInfoButton, 1, 3, 1, 1);

        deviceInfoButton = new QPushButton(groupBox_2);
        deviceInfoButton->setObjectName(QString::fromUtf8("deviceInfoButton"));

        gridLayout_3->addWidget(deviceInfoButton, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(MainWindow);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(300, 16777215));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        switchVideoLevelButton = new QPushButton(groupBox_3);
        switchVideoLevelButton->setObjectName(QString::fromUtf8("switchVideoLevelButton"));

        horizontalLayout_3->addWidget(switchVideoLevelButton);

        startRealPlayButton = new QPushButton(groupBox_3);
        startRealPlayButton->setObjectName(QString::fromUtf8("startRealPlayButton"));

        horizontalLayout_3->addWidget(startRealPlayButton);

        stopRealPlayButton = new QPushButton(groupBox_3);
        stopRealPlayButton->setObjectName(QString::fromUtf8("stopRealPlayButton"));

        horizontalLayout_3->addWidget(stopRealPlayButton);

        capturePictureButton = new QPushButton(groupBox_3);
        capturePictureButton->setObjectName(QString::fromUtf8("capturePictureButton"));

        horizontalLayout_3->addWidget(capturePictureButton);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(MainWindow);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(300, 16777215));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        osdLabel = new QLabel(groupBox_4);
        osdLabel->setObjectName(QString::fromUtf8("osdLabel"));
        osdLabel->setLayoutDirection(Qt::LeftToRight);
        osdLabel->setTextFormat(Qt::AutoText);
        osdLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(osdLabel, 1, 3, 1, 1);

        pauseButton = new QPushButton(groupBox_4);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        gridLayout->addWidget(pauseButton, 1, 0, 1, 1);

        playBackListButton = new QPushButton(groupBox_4);
        playBackListButton->setObjectName(QString::fromUtf8("playBackListButton"));

        gridLayout->addWidget(playBackListButton, 0, 0, 1, 1);

        resumeButton = new QPushButton(groupBox_4);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));

        gridLayout->addWidget(resumeButton, 1, 1, 1, 1);

        startPlayBackButton = new QPushButton(groupBox_4);
        startPlayBackButton->setObjectName(QString::fromUtf8("startPlayBackButton"));

        gridLayout->addWidget(startPlayBackButton, 0, 1, 1, 1);

        stopPlayBackButton = new QPushButton(groupBox_4);
        stopPlayBackButton->setObjectName(QString::fromUtf8("stopPlayBackButton"));

        gridLayout->addWidget(stopPlayBackButton, 0, 3, 1, 1);

        PbEndTime = new QLineEdit(groupBox_4);
        PbEndTime->setObjectName(QString::fromUtf8("PbEndTime"));

        gridLayout->addWidget(PbEndTime, 2, 3, 1, 1);

        PbStartTime = new QLineEdit(groupBox_4);
        PbStartTime->setObjectName(QString::fromUtf8("PbStartTime"));

        gridLayout->addWidget(PbStartTime, 2, 1, 1, 1);

        setPlayBackTimeButton = new QPushButton(groupBox_4);
        setPlayBackTimeButton->setObjectName(QString::fromUtf8("setPlayBackTimeButton"));

        gridLayout->addWidget(setPlayBackTimeButton, 2, 0, 1, 1);

        videoRecordBox = new QCheckBox(groupBox_4);
        videoRecordBox->setObjectName(QString::fromUtf8("videoRecordBox"));

        gridLayout->addWidget(videoRecordBox, 3, 0, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(MainWindow);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        switchSoundButton = new QRadioButton(groupBox_5);
        switchSoundButton->setObjectName(QString::fromUtf8("switchSoundButton"));

        horizontalLayout_9->addWidget(switchSoundButton);

        setVolumeSlider = new QSlider(groupBox_5);
        setVolumeSlider->setObjectName(QString::fromUtf8("setVolumeSlider"));
        setVolumeSlider->setEnabled(false);
        setVolumeSlider->setMaximum(99);
        setVolumeSlider->setTracking(true);
        setVolumeSlider->setOrientation(Qt::Horizontal);
        setVolumeSlider->setInvertedAppearance(false);
        setVolumeSlider->setInvertedControls(false);
        setVolumeSlider->setTickPosition(QSlider::NoTicks);
        setVolumeSlider->setTickInterval(0);

        horizontalLayout_9->addWidget(setVolumeSlider);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        startVoiceTalkButton = new QPushButton(groupBox_5);
        startVoiceTalkButton->setObjectName(QString::fromUtf8("startVoiceTalkButton"));

        horizontalLayout_8->addWidget(startVoiceTalkButton);

        stopVoiceTalkButton = new QPushButton(groupBox_5);
        stopVoiceTalkButton->setObjectName(QString::fromUtf8("stopVoiceTalkButton"));

        horizontalLayout_8->addWidget(stopVoiceTalkButton);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(groupBox_5);

        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        defenceOnButton = new QPushButton(groupBox);
        defenceOnButton->setObjectName(QString::fromUtf8("defenceOnButton"));

        gridLayout_4->addWidget(defenceOnButton, 0, 1, 1, 1);

        defenceOffButton = new QPushButton(groupBox);
        defenceOffButton->setObjectName(QString::fromUtf8("defenceOffButton"));

        gridLayout_4->addWidget(defenceOffButton, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBox);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox_7 = new QGroupBox(MainWindow);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_7);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(3, 20, 3, 20);
        previewWindow = new QWidget(groupBox_7);
        previewWindow->setObjectName(QString::fromUtf8("previewWindow"));
        previewWindow->setMinimumSize(QSize(320, 240));
        previewWindow->setMaximumSize(QSize(320, 240));

        horizontalLayout_5->addWidget(previewWindow);


        verticalLayout_5->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(MainWindow);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        sizePolicy.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_8);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_ZoomIn = new QPushButton(groupBox_8);
        pushButton_ZoomIn->setObjectName(QString::fromUtf8("pushButton_ZoomIn"));

        gridLayout_2->addWidget(pushButton_ZoomIn, 3, 1, 1, 1);

        pushButton_DR = new QPushButton(groupBox_8);
        pushButton_DR->setObjectName(QString::fromUtf8("pushButton_DR"));

        gridLayout_2->addWidget(pushButton_DR, 2, 2, 1, 1);

        pushButton_ZoomOut = new QPushButton(groupBox_8);
        pushButton_ZoomOut->setObjectName(QString::fromUtf8("pushButton_ZoomOut"));

        gridLayout_2->addWidget(pushButton_ZoomOut, 3, 0, 1, 1);

        pushButton_DL = new QPushButton(groupBox_8);
        pushButton_DL->setObjectName(QString::fromUtf8("pushButton_DL"));

        gridLayout_2->addWidget(pushButton_DL, 2, 0, 1, 1);

        pushButton_FocusNear = new QPushButton(groupBox_8);
        pushButton_FocusNear->setObjectName(QString::fromUtf8("pushButton_FocusNear"));

        gridLayout_2->addWidget(pushButton_FocusNear, 4, 0, 1, 1);

        pushButton_FocusFar = new QPushButton(groupBox_8);
        pushButton_FocusFar->setObjectName(QString::fromUtf8("pushButton_FocusFar"));

        gridLayout_2->addWidget(pushButton_FocusFar, 4, 1, 1, 1);

        pushButton_UR = new QPushButton(groupBox_8);
        pushButton_UR->setObjectName(QString::fromUtf8("pushButton_UR"));

        gridLayout_2->addWidget(pushButton_UR, 0, 2, 1, 1);

        pushButton_U = new QPushButton(groupBox_8);
        pushButton_U->setObjectName(QString::fromUtf8("pushButton_U"));

        gridLayout_2->addWidget(pushButton_U, 0, 1, 1, 1);

        pushButton_Wiper = new QPushButton(groupBox_8);
        pushButton_Wiper->setObjectName(QString::fromUtf8("pushButton_Wiper"));

        gridLayout_2->addWidget(pushButton_Wiper, 3, 2, 1, 1);

        pushButton_Light = new QPushButton(groupBox_8);
        pushButton_Light->setObjectName(QString::fromUtf8("pushButton_Light"));

        gridLayout_2->addWidget(pushButton_Light, 4, 2, 1, 1);

        pushButton_UL = new QPushButton(groupBox_8);
        pushButton_UL->setObjectName(QString::fromUtf8("pushButton_UL"));

        gridLayout_2->addWidget(pushButton_UL, 0, 0, 1, 1);

        pushButton_L = new QPushButton(groupBox_8);
        pushButton_L->setObjectName(QString::fromUtf8("pushButton_L"));

        gridLayout_2->addWidget(pushButton_L, 1, 0, 1, 1);

        pushButton_R = new QPushButton(groupBox_8);
        pushButton_R->setObjectName(QString::fromUtf8("pushButton_R"));

        gridLayout_2->addWidget(pushButton_R, 1, 2, 1, 1);

        pushButton_D = new QPushButton(groupBox_8);
        pushButton_D->setObjectName(QString::fromUtf8("pushButton_D"));

        gridLayout_2->addWidget(pushButton_D, 2, 1, 1, 1);

        pushButton_IrisStart = new QPushButton(groupBox_8);
        pushButton_IrisStart->setObjectName(QString::fromUtf8("pushButton_IrisStart"));

        gridLayout_2->addWidget(pushButton_IrisStart, 5, 0, 1, 1);

        pushButton_IrisStop = new QPushButton(groupBox_8);
        pushButton_IrisStop->setObjectName(QString::fromUtf8("pushButton_IrisStop"));

        gridLayout_2->addWidget(pushButton_IrisStop, 5, 1, 1, 1);

        pushButton_Auto = new QPushButton(groupBox_8);
        pushButton_Auto->setObjectName(QString::fromUtf8("pushButton_Auto"));

        gridLayout_2->addWidget(pushButton_Auto, 5, 2, 1, 1);


        verticalLayout_5->addWidget(groupBox_8);

        groupBox_10 = new QGroupBox(MainWindow);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(groupBox_10);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 301, 41));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        pushAlarmCheckBox = new QCheckBox(horizontalLayoutWidget);
        pushAlarmCheckBox->setObjectName(QString::fromUtf8("pushAlarmCheckBox"));

        horizontalLayout_10->addWidget(pushAlarmCheckBox);

        pushDevStatusCheckBox = new QCheckBox(horizontalLayoutWidget);
        pushDevStatusCheckBox->setObjectName(QString::fromUtf8("pushDevStatusCheckBox"));

        horizontalLayout_10->addWidget(pushDevStatusCheckBox);

        pushTransparentChannelCheckBox = new QCheckBox(horizontalLayoutWidget);
        pushTransparentChannelCheckBox->setObjectName(QString::fromUtf8("pushTransparentChannelCheckBox"));

        horizontalLayout_10->addWidget(pushTransparentChannelCheckBox);

        horizontalLayoutWidget_2 = new QWidget(groupBox_10);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 80, 301, 41));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        startPushRecvButton = new QPushButton(horizontalLayoutWidget_2);
        startPushRecvButton->setObjectName(QString::fromUtf8("startPushRecvButton"));

        horizontalLayout_11->addWidget(startPushRecvButton);

        stopPushRecvButton = new QPushButton(horizontalLayoutWidget_2);
        stopPushRecvButton->setObjectName(QString::fromUtf8("stopPushRecvButton"));

        horizontalLayout_11->addWidget(stopPushRecvButton);


        verticalLayout_5->addWidget(groupBox_10);


        horizontalLayout_4->addLayout(verticalLayout_5);

        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(tabWidget);


        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Open SDK Demo", 0, QApplication::UnicodeUTF8));
        groupBox_1->setTitle(QApplication::translate("MainWindow", "Mid Page", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        logoutButton->setText(QApplication::translate("MainWindow", "Logout", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "TokenUpdate", 0, QApplication::UnicodeUTF8));
        SwitchPlat_Button->setText(QApplication::translate("MainWindow", "SwitchPlat", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Data", 0, QApplication::UnicodeUTF8));
        deviceListButton->setText(QApplication::translate("MainWindow", "DeviceList", 0, QApplication::UnicodeUTF8));
        shareDevListButton->setText(QApplication::translate("MainWindow", "ShareDevList", 0, QApplication::UnicodeUTF8));
        alarmListButton->setText(QApplication::translate("MainWindow", "AlarmList", 0, QApplication::UnicodeUTF8));
        setAlarmReadButton->setText(QApplication::translate("MainWindow", "AlarmSetRead", 0, QApplication::UnicodeUTF8));
        showAlarmPicButton->setText(QApplication::translate("MainWindow", "AlarmPic", 0, QApplication::UnicodeUTF8));
        getCameraInfoButton->setText(QApplication::translate("MainWindow", "DevDetailInfo", 0, QApplication::UnicodeUTF8));
        updateCameraInfoButton->setText(QApplication::translate("MainWindow", "DevDetailUpdate", 0, QApplication::UnicodeUTF8));
        deviceInfoButton->setText(QApplication::translate("MainWindow", "ChannelInfo", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "RealPlay", 0, QApplication::UnicodeUTF8));
        switchVideoLevelButton->setText(QApplication::translate("MainWindow", "SwitchDef", 0, QApplication::UnicodeUTF8));
        startRealPlayButton->setText(QApplication::translate("MainWindow", "StartPlay", 0, QApplication::UnicodeUTF8));
        stopRealPlayButton->setText(QApplication::translate("MainWindow", "StopPlay", 0, QApplication::UnicodeUTF8));
        capturePictureButton->setText(QApplication::translate("MainWindow", "CapturePic", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "PlayBack", 0, QApplication::UnicodeUTF8));
        osdLabel->setText(QApplication::translate("MainWindow", "00:00:00", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QApplication::translate("MainWindow", "PausePlay", 0, QApplication::UnicodeUTF8));
        playBackListButton->setText(QApplication::translate("MainWindow", "PlayBackList", 0, QApplication::UnicodeUTF8));
        resumeButton->setText(QApplication::translate("MainWindow", "ResumePlay", 0, QApplication::UnicodeUTF8));
        startPlayBackButton->setText(QApplication::translate("MainWindow", "StartPlayBack", 0, QApplication::UnicodeUTF8));
        stopPlayBackButton->setText(QApplication::translate("MainWindow", "StopPlayBack", 0, QApplication::UnicodeUTF8));
        setPlayBackTimeButton->setText(QApplication::translate("MainWindow", "SelectDate", 0, QApplication::UnicodeUTF8));
        videoRecordBox->setText(QApplication::translate("MainWindow", "Video Record", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "VoiceTalk", 0, QApplication::UnicodeUTF8));
        switchSoundButton->setText(QApplication::translate("MainWindow", "Sound", 0, QApplication::UnicodeUTF8));
        startVoiceTalkButton->setText(QApplication::translate("MainWindow", "StartVoiceTalk", 0, QApplication::UnicodeUTF8));
        stopVoiceTalkButton->setText(QApplication::translate("MainWindow", "StopVoiceTalk", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Device Defence", 0, QApplication::UnicodeUTF8));
        defenceOnButton->setText(QApplication::translate("MainWindow", "Defence", 0, QApplication::UnicodeUTF8));
        defenceOffButton->setText(QApplication::translate("MainWindow", "Undefence", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Preview", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "PTZ Control", 0, QApplication::UnicodeUTF8));
        pushButton_ZoomIn->setText(QApplication::translate("MainWindow", "ZOOMIN", 0, QApplication::UnicodeUTF8));
        pushButton_DR->setText(QApplication::translate("MainWindow", "RightDown", 0, QApplication::UnicodeUTF8));
        pushButton_ZoomOut->setText(QApplication::translate("MainWindow", "ZOOMOUT", 0, QApplication::UnicodeUTF8));
        pushButton_DL->setText(QApplication::translate("MainWindow", "LeftDown", 0, QApplication::UnicodeUTF8));
        pushButton_FocusNear->setText(QApplication::translate("MainWindow", "FOCUSNEAR", 0, QApplication::UnicodeUTF8));
        pushButton_FocusFar->setText(QApplication::translate("MainWindow", "FOCUSFAR", 0, QApplication::UnicodeUTF8));
        pushButton_UR->setText(QApplication::translate("MainWindow", "RightTop", 0, QApplication::UnicodeUTF8));
        pushButton_U->setText(QApplication::translate("MainWindow", "Top", 0, QApplication::UnicodeUTF8));
        pushButton_Wiper->setText(QApplication::translate("MainWindow", "WIPER", 0, QApplication::UnicodeUTF8));
        pushButton_Light->setText(QApplication::translate("MainWindow", "LIGHT", 0, QApplication::UnicodeUTF8));
        pushButton_UL->setText(QApplication::translate("MainWindow", "LeftTop", 0, QApplication::UnicodeUTF8));
        pushButton_L->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_R->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        pushButton_D->setText(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
        pushButton_IrisStart->setText(QApplication::translate("MainWindow", "IRISSTARTUP", 0, QApplication::UnicodeUTF8));
        pushButton_IrisStop->setText(QApplication::translate("MainWindow", "IRISSTOPDOWN", 0, QApplication::UnicodeUTF8));
        pushButton_Auto->setText(QApplication::translate("MainWindow", "AUTO", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Push Message", 0, QApplication::UnicodeUTF8));
        pushAlarmCheckBox->setText(QApplication::translate("MainWindow", "Alarm", 0, QApplication::UnicodeUTF8));
        pushDevStatusCheckBox->setText(QApplication::translate("MainWindow", "DevOffline", 0, QApplication::UnicodeUTF8));
        pushTransparentChannelCheckBox->setText(QApplication::translate("MainWindow", "TransparentChannel", 0, QApplication::UnicodeUTF8));
        startPushRecvButton->setText(QApplication::translate("MainWindow", "OpenPush", 0, QApplication::UnicodeUTF8));
        stopPushRecvButton->setText(QApplication::translate("MainWindow", "ClosePush", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
