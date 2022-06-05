#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void Parse::Process() {
    for (size_t i = 0; i < match1.size(); i++) {
        parsedStr.replace(match1.at(i).first, match1.at(i).second);   // заменяем все вхождения по шаблону match1
    }
}


void MainWindow::on_plainTextEdit_textChanged()
{
    QString s = ui->plainTextEdit->toPlainText();
    Parse p(s);
    p.Process();
    s = p.GetParsed();
    ui->plainTextEdit_2->setPlainText(s);
}

