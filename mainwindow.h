#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <array>
#include <tuple>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
};


class Parse {
private:
    std::array<std::pair<QString, QString>, 4> match1 = {
                                                           std::make_pair("copyright", "©"),
                                                           std::make_pair("промилле", "‰"),
                                                           std::make_pair("евро", "€"),
                                                           std::make_pair("рублей", "₽")
                                                        };

    QString originStr;   // оригинальная строка, может пригодиться
    QString parsedStr;   // изменённая строка
public:
    Parse(const QString &s) { originStr = parsedStr = s; }
    QString& GetParsed() { return parsedStr; }
    void Process();
};



#endif // MAINWINDOW_H
