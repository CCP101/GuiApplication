#include "CalculationPage.h"
#include <qsqlquery.h>
#include <qdebug.h>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CalculationPage::CalculationPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton->setText("������һ��");
	CalculatingGrades();
	//connect(ui.pushButton_2, &QPushButton::clicked, this, &CalculationPage::CalculatingGrades);
	connect(ui.pushButton, &QPushButton::clicked, this, &CalculationPage::close);
}

void CalculationPage::CalculatingGrades()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//���ض˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");//�������ݿ������˺ŵ�����
	db.open();
	QString temp2 = "SELECT AVG(`�ߵ���ѧ�ɼ�`) AS OrderAverage FROM `password`.`studentinformation`";
	QSqlQuery query2(temp2);
	while (query2.next())
	{
		QString temp3 = query2.value(0).toString();
		ui.label_5->setText(temp3);
	}

	QString temp = "SELECT AVG(`C���Գ�����Ƴɼ�`) AS OrderAverage FROM `password`.`studentinformation`";
	QSqlQuery query1(temp);
	while (query1.next())
	{
		QString temp1 = query1.value(0).toString();
		ui.label_3->setText(temp1);
	}

	QString temp4 = "SELECT AVG(`��ѧӢ��ɼ�`) AS OrderAverage FROM `password`.`studentinformation`";
	QSqlQuery query3(temp4);
	while (query3.next())
	{
		QString temp5 = query3.value(0).toString();
		ui.label_7->setText(temp5);
	}

}

CalculationPage::~CalculationPage()
{
}
