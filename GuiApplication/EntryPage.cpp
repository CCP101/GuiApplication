#include "EntryPage.h"
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
}

void EntryPage::ConfirmEntry()
{

}

EntryPage::~EntryPage()
{
}
