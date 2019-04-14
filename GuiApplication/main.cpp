#include "GuiApplication.h"
#include <QtWidgets/QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QApplication a(argc, argv);
	GuiApplication w;
	w.show();
	
	return a.exec();
}
