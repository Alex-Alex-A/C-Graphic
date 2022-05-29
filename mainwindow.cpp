#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = b = c = "";       // устанавливаем "пустые" строки
}

void MainWindow::Prepare_String(QLineEdit *le) {
    QString str = le->text();
    QString tmpl = "^[\\+|\\-]?\\d*$";     // проверяем на цыфры
    QRegExp *q = new QRegExp(tmpl);

    if (!str.isEmpty()) {
        if (q->indexIn(str) != -1) {
            str = str.left(3);               // усекаем длину строки до 3
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
        QMessageBox::information(this, tr("Не введён параметр!!!"), tr("Необходимо ввести параметр a !"));
        return;
    }
    if (b.length() < 1) {
        QMessageBox::information(this, tr("Не введён параметр!!!"), tr("Необходимо ввести параметр b !"));
        return;
    }
    if (c.length() < 1) {
        QMessageBox::information(this, tr("Не введён параметр!!!"), tr("Необходимо ввести параметр c !"));
        return;
    }

#define  ERROR_1   if (!ok) {\
                   QMessageBox::information(this, tr("Ошибка!!!"), tr("Не удалось пребразовать строку в число..."));\
                   return; }\

    bool ok;
    double aa = a.toDouble(&ok);
    if (ok && aa == 0) {
        QMessageBox::information(this, tr("Неверный параметр!!!"), tr("a не должен быть равен 0 !"));
        return;
    }
    ERROR_1
    double bb = b.toDouble(&ok);
    ERROR_1
    double cc = c.toDouble(&ok);
    ERROR_1

    double D = qPow (bb, 2.0);
    D -= 4.0 * aa * cc;

#define  MESSAGE_1  QMessageBox msgBox;\
                    msgBox.setText(str);\
                    msgBox.exec();

    if (D > 0) {
        double R1 = (-bb + qSqrt(D)) / (2.0 * aa);
        double R2 = (-bb - qSqrt(D)) / (2.0 * aa);
        QString str = "Имеется два корня:  " + QString::number(R1) + "  и  " + QString::number(R2);
        MESSAGE_1
    }
    if (D == 0) {
        QString str = "Имеется единственный корень:  " + QString::number(-bb / (2.0 * aa));
        MESSAGE_1
    }
    if (D < 0) {
        QString str = "Уравнение не имеет действительных корней";
        MESSAGE_1
    }
}

void MainWindow::on_pushButton_clicked()
{
    Calculate();
}

MainWindow::~MainWindow()
{
    delete ui;
}



