#include "GuiApplication.h"
#include "ui_StudentMenu.h"
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
	InitMySql();
	connect(ui.startButton, &QPushButton::clicked, this, &GuiApplication::condButtonPressed);
	connect(ui.closeButton, &QPushButton::clicked, this, &GuiApplication::close);
	connect(ui.pushButton, &QPushButton::clicked, this, &GuiApplication::connectMysql);
	//setWindowFlags(Qt::FramelessWindowHint);//��������ʱ�ı߿�
}


void GuiApplication::condButtonPressed()
{
	//StudentMenu w;
	//w.show();
	qDebug("succeed");
	view = new StudentMenu();
	view->show();
}

void GuiApplication::InitMySql()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setPort(3306);
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");     //�������ݿ������˺ŵ�����
	bool ok = db.open();
	if (ok)
	{
		qDebug() << "OK";
		ui.label_2->setText("OK");
	}
	else
	{
		qDebug() << "False";
		ui.label_2->setText("false");
	}

}

void GuiApplication::connectMysql()
{
	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("select *form studentinformation");
		ui.tableView->setModel(model);
		db.close();
	}

	else
	{
		qDebug() << "fail";
	}
}