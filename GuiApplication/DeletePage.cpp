#include "DeletePage.h"

DeletePage::DeletePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.label->setText("������Ҫ��ѯ��ѧ��:");
	connect(ui.pushButton_2, &QPushButton::clicked, this, &DeletePage::close);
}

DeletePage::~DeletePage()
{
}
