#include "DeletePage.h"
#include <qmessagebox.h>
#include <qdebug.h>
#include <string>
#include <QSqlQuery>
#include "FormHomePage.h"
using namespace std;

DeletePage::DeletePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.label->setText("������Ҫ��ѯ��ѧ��:");
	ui.pushButton_2->setText("������һ��");
	ui.lineEdit->setText("2018023417");
	ui.label_11->setText("");
	connect(ui.pushButton_2, &QPushButton::clicked, this, &DeletePage::close);
	connect(ui.SearchButton, &QPushButton::clicked, this, &DeletePage::DataSearch);
}

void DeletePage::DataSearch()
{
	qDebug() << "OK";
	QString num = ui.lineEdit->text();
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

	if (num.length())
	{
		QString num = ui.lineEdit->text();
		QString temp_qt = "select *from `password`.`studentinformation`WHERE studentinformation.`ѧ��`=" + num;
		QSqlQuery query1(temp_qt);
		while (query1.next())
		{
			/*qDebug() << query1.value(0).toString() << query1.value(1).toString();*/
			ui.label_11->setText(query1.value(0).toString());
			ui.label_12->setText(query1.value(1).toString());
			ui.label_13->setText(query1.value(2).toString());
			ui.label_14->setText(query1.value(6).toString());
			ui.label_15->setText(query1.value(7).toString());
			ui.label_16->setText(query1.value(3).toString());
			ui.label_17->setText(query1.value(4).toString());
			ui.label_18->setText(query1.value(5).toString());
		}
	}
	
	else
	{
		QMessageBox::warning(this, tr("Warning"), tr("ѧ�Ų���Ϊ��"));
	}

}

DeletePage::~DeletePage()
{
}
