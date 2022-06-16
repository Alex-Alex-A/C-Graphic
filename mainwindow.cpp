#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>
#include <QTextEdit>
#include <QStatusBar>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMimeData>
#include <QMimeDatabase>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainMenu = this->menuBar();

    fMenu = mainMenu->addMenu("Файл");
    aMenu = mainMenu->addMenu("Справка");

    openfile = new QAction(tr("&Открыть"), this);
    openfile->setShortcuts(QKeySequence::Open);
    connect(openfile, &QAction::triggered, this, &MainWindow::fileOpen);
    fMenu->addAction(openfile);

    saveasfile = new QAction(tr("&Сохранить как"), this);
    saveasfile->setShortcuts(QKeySequence::SaveAs);
    connect(saveasfile, &QAction::triggered, this, &MainWindow::fileSaveAs);
    fMenu->addAction(saveasfile);

    about = new QAction(tr("&О программе"), this);
    connect(about, &QAction::triggered, this, &MainWindow::About);
    aMenu->addAction(about);
}


void MainWindow::fileOpen() {

    QFileDialog fileDialog(this, "Open File...");
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setMimeTypeFilters(QStringList()
                                  << "text/plain");

    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fn = fileDialog.selectedFiles().first();

    Parse_File (fn);  // отправляем полученный полный путь к файлу для открытия и парсинга
}

void MainWindow::fileSaveAs() {

    QFileDialog fileDialog(this, tr("Save as..."));
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QStringList mimeTypes;
    mimeTypes << "text/plain";
    fileDialog.setMimeTypeFilters(mimeTypes);
    if (fileDialog.exec() != QDialog::Accepted)
        return;

    const QString fn = fileDialog.selectedFiles().first();
}

void MainWindow::Parse_File (const QString& fn) {  // открываем и парсим html-файл сайта mail.ru

    QString outstr = "", common_str = "";
    QFile file(fn);
    if (file.open(QIODevice::ReadOnly)) {
        QString str(file.readAll());

        QRegExp rx("\"now\":\\{(.*)\"near\"");    // шаблон для поиска блока погоды в html
        int pos = 0;
        while ((pos = rx.indexIn(str, pos)) != -1) {
            outstr = rx.cap(1);                       // в outstr блок, содержащий данные о погоде
            pos += rx.matchedLength();
        }

        QRegularExpression rx_t("\"temp\":\"(.*?)\"");              // шаблон для поиска температуры
        QRegularExpressionMatch match = rx_t.match(outstr);
        if (match.hasMatch())
            common_str += "Температура: " + match.captured(1) + "\n";

        QRegularExpression rx_d("\"description\":\"(.*?)\"");       // шаблон для поиска общего описания
        match = rx_d.match(outstr);
        if (match.hasMatch())
            common_str += match.captured(1) + "\n";

        QRegularExpression rx_w("\"wind_description\":\"(.*?)\"");  // шаблон для поиска ветра
        match = rx_w.match(outstr);
        if (match.hasMatch())
            common_str += match.captured(1) + "\n";

        QRegularExpression rx_p("\"pressure\":\"(.*?)\"");          // шаблон для поиска атм. давления
        match = rx_p.match(outstr);
        if (match.hasMatch())
            common_str += "Атмосферное давление: " + match.captured(1) + "\n";

        QRegularExpression rx_currency("<div class=\"rate__currency svelte-19b6xeo\">(.*?)</div>");    // шаблон для поиска фрагмента курса доллара
        match = rx_currency.match(str);
        if (match.hasMatch())
            common_str += "Курс доллара: " + match.captured(1) + "\n";

        QMessageBox::information(NULL, "Погода и прочее:", common_str);
    }
    else
        QMessageBox::information(NULL, tr("Ошибка!"), tr("Файл не существует!"));
}

void MainWindow::About()
{
    QFile abouttxt(":about");  // читаем текст из "about.txt", ссылка на который в "textedit.qrc"

    if (!abouttxt.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(this, tr("Ошибка!!!"), tr("Не получается прочитать данные из ресурса"));

    else {
        QString s = "";
        QTextStream in(&abouttxt);
        while (!in.atEnd()) {
            QString line = in.readLine();
            s += line;
        }
        QMessageBox::information(this, tr("О программе из ресурса:"), s);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
















