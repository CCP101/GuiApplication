#include "FormHomePage.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


FormHomePage::FormHomePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton->setText("������һ��");
	connect(ui.pushButton, &QPushButton::clicked, this, &FormHomePage::close);
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
	}
	else
	{
		qDebug() << "False";
	}
	//����Ϊ��ʼ����������

	if (db.open())
	{
		qDebug() << "success!";
		QSqlQueryModel *model = new QSqlQueryModel();
		model->setQuery("SELECT * FROM `password`.`studentinformation` LIMIT 0,1000");
		ui.tableView->setModel(model);
		QSqlQuery query("show tables from `password`.`studentinformation`");
		while (query.next())
		{
			qDebug() << query.value(0).toString();
		}
		QSqlQuery query1("select *from `password`.`studentinformation`");
		while (query1.next())
		{
			qDebug() << query1.value(0).toString() << query1.value(1).toString();
		}
		db.close();
	}
	else
	{
		qDebug() << "fail";
	}
}

FormHomePage::~FormHomePage()
{
}
