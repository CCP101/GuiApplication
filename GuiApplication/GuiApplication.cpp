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
	view = new StudentMenu();
	view->show();
	//ָ��д���½�����
}

//void GuiApplication::InitMySql()
//{
//	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//	db.setHostName("localhost");
//	db.setPort(3306);
//	db.setDatabaseName("mysql");
//	db.setUserName("root");
//	db.setPassword("kuandong1227");     //�������ݿ������˺ŵ�����
//	bool ok = db.open();
//	if (ok)
//	{
//		qDebug() << "OK";
//		ui.label_2->setText("OK");
//	}
//	else
//	{
//		qDebug() << "False";
//		ui.label_2->setText("false");
//	}
//}
//
//void GuiApplication::connectMysql()
//{
//	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//	db.setHostName("localhost");
//	db.setPort(3306);
//	db.setDatabaseName("mysql");
//	db.setUserName("root");
//	db.setPassword("kuandong1227");     //�������ݿ������˺ŵ�����
//	bool ok = db.open();
//	if (ok)
//	{
//		qDebug() << "OK";
//		ui.label_2->setText("OK");
//	}
//	else
//	{
//		qDebug() << "False";
//		ui.label_2->setText("false");
//	}
//	//��ʼ�����ݿ�����
//
//	if (db.open())
//	{
//		qDebug() << "success!";
//		QSqlQueryModel *model = new QSqlQueryModel();
//		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
//		ui.tableView->setModel(model);
//		QSqlQuery query("show tables from `password`.`studentinformation`");
//		while (query.next())
//		{
//			qDebug() << query.value(0).toString();
//		}
//		QSqlQuery query1("select *from `password`.`studentinformation`");
//		while (query1.next())
//		{
//			qDebug() << query1.value(0).toString() << query1.value(1).toString();
//		}
//		db.close();
//	}
//	else
//	{
//		qDebug() << "fail";
//	}
//}