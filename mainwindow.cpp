#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = b = c = "";       // устанавливаем "пустые" строки
    ui->radioButton->setChecked(true);
    is_degree = true;
}

void MainWindow::Prepare_String(QLineEdit *le) {
    QString str = le->text();
    QString tmpl = "^[\\+|\\-]?\\d*([\\.|,]?\\d*)$";     // проверяем на цыфры, в т.ч. и вещественные
    QRegExp *q = new QRegExp(tmpl);

    if (!str.isEmpty()) {
        if (q->indexIn(str) != -1) {
            str = str.left(10);               // усекаем длину строки до 10
            le->setText(str);
        }
        else {
            str = str.left(str.length() - 1);  // уменьшаем длину строки на 1, если введён нечисловой символ
            le->setText(str);
        }
    }
    delete q;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) {
    Prepare_String(ui->lineEdit);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1) {
    Prepare_String(ui->lineEdit_2);
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1) {
    Prepare_String(ui->lineEdit_3);
}

void MainWindow::Calculate() {
    a = ui->lineEdit->text();
    b = ui->lineEdit_2->text();
    c = ui->lineEdit_3->text();

    if (a.length() < 1) {
        QMessageBox::information(this, tr("Не введён параметр!!!"), tr("Необходимо ввести параметр !"));
        return;
    }
    if (b.length() < 1) {
        QMessageBox::information(this, tr("Не введён параметр!!!"), tr("Необходимо ввести параметр !"));
        return;
    }
    if (c.length() < 1) {
        QMessageBox::information(this, tr("Не введён параметр!!!"), tr("Необходимо ввести параметр !"));
        return;
    }

#define  ERROR_1   if (!ok) {\
                   QMessageBox::information(this, tr("Ошибка!!!"), tr("Не удалось пребразовать строку в число..."));\
                   return; }\

    bool ok;
    double aa = a.toDouble(&ok);
    ERROR_1
    double bb = b.toDouble(&ok);
    ERROR_1
    double cc = c.toDouble(&ok);
    ERROR_1

    double angle = cc;
    if (is_degree)                        // если установлены градусы
        angle = angle * 3.1416 / 180.0;   // то переводим градусы в радианы

    double side = qSqrt(qPow (aa, 2.0) + qPow (bb, 2.0) - 2.0 * aa * bb * qCos(angle));

#define  MESSAGE_1  QMessageBox msgBox;\
                    msgBox.setText(str);\
                    msgBox.exec();

    QString str = "Третья сторона равна:  " + QString::number(side);
    MESSAGE_1
}

void MainWindow::on_pushButton_clicked()
{
    Calculate();
}

void MainWindow::on_radioButton_clicked()   // "переключатель"   градусы <-> радианы  по нажатию на радиобаттон
{
    if (is_degree == true) {
        is_degree = false;
        ui->radioButton->setText("радианы");
    } else {
        is_degree = true;
        ui->radioButton->setText("градусы");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}





