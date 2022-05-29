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

void MainWindow::on_pushButton_add_clicked()
{
    QString s = ui->plainTextEdit_2->toPlainText() + ui->plainTextEdit->toPlainText();
    ui->plainTextEdit_2->setPlainText(s);
}


void MainWindow::on_pushButton_replace_clicked()
{
    QString s = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit_2->setPlainText(s);
}


void MainWindow::on_pushButton_add_html_clicked()
{
    //QTextDocument d;
    //QString str; // = "<font color='red'>Hello</font>";


    QFileInfo fi("example.html");
        QUrl srcUrl = QUrl::fromLocalFile(fi.absoluteFilePath());
        QFile file("example.html");
        if (file.open(QIODevice::ReadOnly)) {
            QString str(file.readAll());
            ui->plainTextEdit_2->setPlainText("");
            ui->plainTextEdit_2->appendHtml(str);
        }


    //d.setHtml(str);
    //QTextEdit qe;
    //qe.setHtml(str);

    //QPlainTextDocumentLayout lo(&d);
    //d.setDocumentLayout(NULL);

     //QAbstractTextDocumentLayout* layout = d.documentLayout();
     //d.setDocumentLayout(layout);

    //QAbstractTextDocumentLayout* lo = d.documentLayout();
    //ui->plainTextEdit_2->setDocument(&d);
    //ui->plainTextEdit_2->setPlainText("");
    //ui->plainTextEdit_2->appendHtml(str);

    //ui->plainTextEdit_2->appendPlainText(str);
}

