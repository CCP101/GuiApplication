#include "GuiApplication.h"
#include "ui_StudentMenu.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

GuiApplication::GuiApplication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromUtf8("�����2018023417����׳"));
	QStringList drivers = QSqlDatabase::drivers();//��ӡMySQL�����鿴
	qDebug() << drivers;
	//InitMySql();
	connect(ui.startButton, &QPushButton::clicked, this, &GuiApplication::condButtonPressed);
	connect(ui.closeButton, &QPushButton::clicked, this, &GuiApplication::close);
	/*connect(ui.pushButton, &QPushButton::clicked, this, &GuiApplication::connectMysql);*/
	//setWindowFlags(Qt::FramelessWindowHint);//��������ʱ�ı߿�
}

void GuiApplication::condButtonPressed()
{
	qDebug("succeed");
	view = new StudentMenu(this);
	view->show();
	//ָ��д���½�����
}
