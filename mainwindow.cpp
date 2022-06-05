#include <QPainter>
#include <QDebug>
#include <QStandardItemModel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    row_index = -1;

    model = new QStandardItemModel(ui->tableView);
    model->setHorizontalHeaderLabels(QStringList() << "Prorgamming Language" << "Icon");

    plg1 = new PLanguage(0, "C++", "./img/c++.png", model);
    plg2 = new PLanguage(1, "C##", "./img/c#.png", model);
    plg3 = new PLanguage(2, "java", "./img/java.png", model);
    plg4 = new PLanguage(3, "js", "./img/js.png", model);
    plg5 = new PLanguage(4, "php", "./img/php.png", model);
    plg6 = new PLanguage(5, "python", "./img/python.png", model);

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

MainWindow::~MainWindow()
{
    delete plg1;
    delete plg2;
    delete plg3;
    delete plg4;
    delete plg5;
    delete plg6;
    delete ui;
}

void MainWindow::on_pushButton1_UP_clicked()
{
}

void MainWindow::on_pushButton1_DOWN_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 0 );
    model->insertRow( 1, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton2_UP_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 1 );
    model->insertRow( 0, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton2_DOWN_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 1 );
    model->insertRow( 2, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton3_UP_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 2 );
    model->insertRow( 1, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton3_DOWN_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 2 );
    model->insertRow( 3, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton4_UP_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 3 );
    model->insertRow( 2, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton4_DOWN_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 3 );
    model->insertRow( 4, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton5_UP_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 4 );
    model->insertRow( 3, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton5_DOWN_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 4 );
    model->insertRow( 5, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton6_UP_clicked()
{
    QList<QStandardItem*> itemUP = model->takeRow( 5 );
    model->insertRow( 4, itemUP );
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_pushButton6_DOWN_clicked()    {}

void MainWindow::on_tableView_pressed(const QModelIndex &index)
{
    row_index = index.row();  // получаем номер выделенной строки
}

void MainWindow::on_pushButton_Rem_Row_clicked()
{
    if (row_index != -1) {                     // если выделен хотя бы одна строка
        model->removeRow( row_index );
        ui->tableView->resizeRowsToContents();
        row_index = -1;                        // ставим в -1, чтоб исключить случайные удаления
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 1) {
        //QListView::setViewMode(QListView::IconMode);
    }
}


















