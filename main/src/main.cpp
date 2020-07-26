#include <QApplication>
#include <QStyleFactory>
#include <QFile>

#include "MainWindow.h"

QString sheet = R"(* {
    background-color: rgb(63,67,67);
    color: white;
    selection-color: black;
    selection-background-color: orange;
    alternate-background-color: rgb(41,41,41);
}

*:disabled {
    color: gray;
}

QAbstractButton:checked {
    color: black;
    background-color: orange;
}

QDockWidget {
}

QDockWidget::title {
}

QMainWindow::separator {
    /*
    background: rgb(41,41,41);
    width: 2px;
    height: 2px;
    */
}

QMainWindow::separator:hover {
    /* background: orange; */
}

QStatusBar {
    /* border-top: 1px solid rgb(41,41,41); */
})";

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	app.setStyleSheet(sheet);

	MainWindow mainWindow{};
	mainWindow.show();


	return app.exec();
}