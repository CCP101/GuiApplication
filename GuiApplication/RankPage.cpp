#include "RankPage.h"
#include <QtSql>
#include <QSqlQuery>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


RankPage::RankPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromUtf8("Dialog"));
	ui.CstudyButton->setText("��C���Կ���ɼ�����");
	ui.EnglishButton->setText("��Ӣ��ɼ�����");
	ui.MathButton->setText("���ߵ���ѧ�ɼ�����");
	ui.pushButton->setText("��C���Կ���ɼ�����");
	ui.pushButton_2->setText("��Ӣ��ɼ�����");
	ui.pushButton_3->setText("���ߵ���ѧ�ɼ�����");
	ui.EXIT->setText("������һ��");
	connect(ui.EXIT, &QPushButton::clicked, this, &RankPage::close);
	connect(ui.CstudyButton, &QPushButton::clicked, this, &RankPage::RankDesign);
	connect(ui.EnglishButton, &QPushButton::clicked, this, &RankPage::RankEnglish);
	connect(ui.MathButton, &QPushButton::clicked, this, &RankPage::RankMath);
	connect(ui.pushButton, &QPushButton::clicked, this, &RankPage::RankDesignDown);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &RankPage::RankEnglishDown);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &RankPage::RankMathDown);
}

void RankPage::RankDesign()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//���ض˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");     //�������ݿ������˺ŵ�����
	bool ok = db.open();
	if (ok)
	{
		qDebug() << "OK";
	}
	else
	{
		qDebug() << "False";
	}//�������ݿ��������
	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
		ui.tableView->setModel(model);
		QSqlQuery query("show tables from `password`.`studentinformation`");
		QString temp = "SELECT * FROM `password`.`studentinformation` ORDER BY `C���Գ�����Ƴɼ�` ";//sqlĬ������Ϊ����
		QSqlQuery query1(temp);
		model->setQuery(temp);
		ui.tableView->setModel(model);
		db.close();
	}
	else
	{
		qDebug() << "fail";
	}
}

void RankPage::RankEnglish()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//���ض˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");     //�������ݿ������˺ŵ�����
	db.open();
	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
		ui.tableView->setModel(model);
		QSqlQuery query("show tables from `password`.`studentinformation`");
		QString temp = "SELECT * FROM `password`.`studentinformation` ORDER BY `��ѧӢ��ɼ�` ";
		QSqlQuery query1(temp);
		model->setQuery(temp);
		ui.tableView->setModel(model);
		db.close();
	}
	else
	{
		qDebug() << "fail";
	}
}

void RankPage::RankMath()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//���ض˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");     //�������ݿ������˺ŵ�����
	db.open();
	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
		ui.tableView->setModel(model);
		QSqlQuery query("show tables from `password`.`studentinformation`");
		QString temp = "SELECT * FROM `password`.`studentinformation` ORDER BY `�ߵ���ѧ�ɼ�`";
		QSqlQuery query1(temp);
		model->setQuery(temp);
		ui.tableView->setModel(model);
		db.close();
	}
	else
	{
		qDebug() << "fail";
	}
}

void RankPage::RankDesignDown()
{
	//SELECT * FROM `password`.`studentinformation` 
	//FORM C���Կγ��� �Ƴɼ�
	//ORDER BY C���Կγ���Ƴɼ� DESC
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//���ض˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");//�������ݿ������˺ŵ�����
	db.open();
	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
		ui.tableView->setModel(model);
		QSqlQuery query("show tables from `password`.`studentinformation`");
		QString temp = "SELECT * FROM `password`.`studentinformation` ORDER BY `C���Գ�����Ƴɼ�` DESC LIMIT 0,1000 ";//DESCΪ����ؼ���
		QSqlQuery query1(temp);
		model->setQuery(temp);
		ui.tableView->setModel(model);
		db.close();
	}
	else
	{
		qDebug() << "fail";
	}
}

void RankPage::RankEnglishDown()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//���ض˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");//�������ݿ������˺ŵ�����
	db.open();
	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
		ui.tableView->setModel(model);
		QSqlQuery query("show tables from `password`.`studentinformation`");
		QString temp = "SELECT * FROM `password`.`studentinformation` ORDER BY `��ѧӢ��ɼ�` DESC LIMIT 0,1000";
		QSqlQuery query1(temp);
		model->setQuery(temp);
		ui.tableView->setModel(model);
		db.close();
	}
	else
	{
		qDebug() << "fail";
	}
}

void RankPage::RankMathDown()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//���ض˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");//�������ݿ������˺ŵ�����
	db.open();
	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
		ui.tableView->setModel(model);
		QSqlQuery query("show tables from `password`.`studentinformation`");
		QString temp = "SELECT * FROM `password`.`studentinformation` ORDER BY `�ߵ���ѧ�ɼ�` DESC LIMIT 0,1000";
		QSqlQuery query1(temp);
		model->setQuery(temp);
		ui.tableView->setModel(model);
		db.close();
	}
	else
	{
		qDebug() << "fail";
	}
}
RankPage::~RankPage()
{
}
