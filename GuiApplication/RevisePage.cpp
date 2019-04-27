#include "RevisePage.h"
#include <qmessagebox.h>
#include <qdebug.h>
#include <string>
#include <QSqlQuery>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

RevisePage::RevisePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &RevisePage::close);
	connect(ui.pushButton, &QPushButton::clicked, this, &RevisePage::DateSearch);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &RevisePage::DataRevise);
}

void RevisePage::DateSearch()
{
	qDebug() << "OK";
	QString num = ui.lineEdit->text();
	QString number = ui.lineEdit_2->text();
	QString name = ui.lineEdit_3->text();
	QString sex = ui.lineEdit_4->text();
	QString birthday = ui.lineEdit_5->text();
	QString age = ui.lineEdit_6->text();
	QString cscore = ui.lineEdit_7->text();
	QString math = ui.lineEdit_8->text();
	QString english = ui.lineEdit_9->text();
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
	}//ȷ�����ݿ��������
	
	int flag = 0;
	if (num.length())
	{
		QString temp_qt = "select *from `password`.`studentinformation`WHERE studentinformation.`ѧ��`=" + num;
		QSqlQuery query1(temp_qt);
		ui.lineEdit_2->setText("no data");
		ui.lineEdit_3->setText("no data");
		ui.lineEdit_4->setText("no data");
		ui.lineEdit_5->setText("no data");
		ui.lineEdit_6->setText("no data");
		ui.lineEdit_7->setText("no data");
		ui.lineEdit_8->setText("no data");
		ui.lineEdit_9->setText("no data");
		while (query1.next())
		{
			/*qDebug() << query1.value(0).toString() << query1.value(1).toString();*/
			ui.lineEdit_2->setText(query1.value(0).toString());
			ui.lineEdit_3->setText(query1.value(1).toString());
			ui.lineEdit_4->setText(query1.value(2).toString());
			ui.lineEdit_5->setText(query1.value(6).toString());
			ui.lineEdit_6->setText(query1.value(7).toString());
			ui.lineEdit_7->setText(query1.value(3).toString());
			ui.lineEdit_8->setText(query1.value(4).toString());
			ui.lineEdit_9->setText(query1.value(5).toString());
			flag = 1;
		}
		if (flag == 0)
		{
			QMessageBox::warning(this, tr("Warning��"), tr("	�����ڸ���Ϣ��	"));
		}
	}
	else
	{
		QMessageBox::warning(this, tr("Warning��"), tr("	ѧ�Ų���Ϊ�գ�"));
	}
}

void RevisePage::DataRevise()
{
	QString num = ui.lineEdit->text();
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//�˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");//�������ݿ������˺ŵ�����
	db.open();
	QString temp_qt = "UPDATE `password`.`studentinformation` SET `ѧ��` = '"
		+ ui.lineEdit_2->text() + "'" + ",`����` = "
		+ "'" + ui.lineEdit_3->text() + "'" + ",`�Ա�` = "
		+ "'" + ui.lineEdit_4->text() + "'" + ",`C���Գ�����Ƴɼ�` = "
		+ "'" + ui.lineEdit_2->text() + "'" + ",`�ߵ���ѧ�ɼ�` = "
		+ "'" + ui.lineEdit_2->text() + "'" + ",`��ѧӢ��ɼ�` = "
		+ "'" + ui.lineEdit_9->text() + "'" + ",`��������` = "
		+ "'" + ui.lineEdit_5->text() + "'" + ",`����` = "
		+ "'" + ui.lineEdit_6->text();
	temp_qt=temp_qt + "' WHERE `ѧ��` = " + ui.lineEdit->text();
	QSqlQuery query1(temp_qt);
}

RevisePage::~RevisePage()
{
}
