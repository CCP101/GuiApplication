#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GuiApplication.h"
#include "StudentMenu.h"
#include <QtSql>

namespace Ui
{
	class GuiApplication;
}

class GuiApplication : public QMainWindow
{
	Q_OBJECT

public:
	GuiApplication(QWidget *parent = Q_NULLPTR);
private Q_SLOT:
	void condButtonPressed();
	void connectMysql();
private:
	Ui::GuiApplicationClass ui;
	StudentMenu *view;
	QSqlDatabase db;//���ݿ���
	void InitMySql();//��ʼ�����ݿ�
};
