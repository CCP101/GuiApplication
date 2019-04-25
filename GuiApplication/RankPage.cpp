#include "RankPage.h"
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
	ui.EXIT->setText("������һ��");
	connect(ui.EXIT, &QPushButton::clicked, this, &RankPage::close);
}

RankPage::~RankPage()
{
}
