#include "EntryPage.h"
#include <QSqlQuery>
#include <QtSql>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

EntryPage::EntryPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.Exit->setText("������һ��");
	ui.ConfirmButton->setText("ȷ��¼��");
	connect(ui.Exit, &QPushButton::clicked, this, &EntryPage::close);
	connect(ui.ConfirmButton, &QPushButton::clicked, this, &EntryPage::ConfirmEntry);
}

void EntryPage::ConfirmEntry()
{
	QString num = ui.lineEdit->text();
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");//������
	db.setPort(3306);//�˿ں�
	db.setDatabaseName("mysql");
	db.setUserName("root");
	db.setPassword("kuandong1227");//�������ݿ������˺ŵ�����
	db.open();
	//QString number = ;
	//QString name = ui.lineEdit_2->text();
	//QString sex = ;
	//QString birthday = ui.lineEdit_4->text();
	//QString age = ui.lineEdit_5->text();
	//QString cscore = ui.lineEdit_6->text();
	//QString math = ui.lineEdit_7->text();
	//QString english = ui.lineEdit_8->text();
	QString temp = "INSERT INTO `password`.`studentinformation`(`ѧ��`, `����`, `�Ա�`, `C���Գ�����Ƴɼ�`, `�ߵ���ѧ�ɼ�`, `��ѧӢ��ɼ�`, `��������`, `����`)VALUES ( ";
	temp = temp + "'" + ui.lineEdit->text() + "'" + "," 
				+ "'" + ui.lineEdit_2->text() + "'" + ","
				+ "'" + ui.lineEdit_3->text() + "'" + ","
				+ "'" + ui.lineEdit_4->text() + "'" + ","
				+ "'" + ui.lineEdit_5->text() + "'" + ","
				+ "'" + ui.lineEdit_6->text() + "'" + ","
				+ "'" + ui.lineEdit_7->text() + "'" + ","
				+ "'" + ui.lineEdit_8->text() + "'" + ")";
	QSqlQuery query1(temp);
}

EntryPage::~EntryPage()
{
}
