#include "CalculationPage.h"
#include <qsqlquery.h>

CalculationPage::CalculationPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton->setText("������һ��");
}

void CalculationPage::CalculatingGrades()
{
	QString temp = "SELECT AVG(`�ߵ���ѧ�ɼ�`) AS OrderAverage FROM `password`.`studentinformation`";
	QSqlQuery query1(temp);
}

CalculationPage::~CalculationPage()
{
}
