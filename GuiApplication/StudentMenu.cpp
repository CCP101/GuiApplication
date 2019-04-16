#include "StudentMenu.h"



StudentMenu::StudentMenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.Exit, &QPushButton::clicked, this, &StudentMenu::close);
	connect(ui.EnterButton, &QPushButton::clicked, this, &StudentMenu::ShowFormPage);
	connect(ui.DeleteButton, &QPushButton::clicked, this, &StudentMenu::ShowDeletePage);
}

void StudentMenu::ShowFormPage()
{
	/*view = new StudentMenu();*/
	view.show();//����ָ�����ʾ��ҳ��
}

void StudentMenu::ShowDeletePage()
{
	view2.show();
}

StudentMenu::~StudentMenu()
{
}
