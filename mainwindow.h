#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QStringListModel>
#include <QStringList>
#include <QList>
#include <QStandardItemModel>

//#include <QItemDelegate>
//#include <QPolygonF>
//#include <QPointF>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//===============================================================

class PLanguage {
private:
    int m_id;
    QString m_lang_name;
    QString m_lang_img;
    QList<QStandardItem*> items;
public:
    PLanguage(int id, QString lang_name, QString lang_img, QStandardItemModel *qst) {
        m_id = id;
        m_lang_name = lang_name;
        m_lang_img = lang_img;
        items.append(new QStandardItem(m_lang_name));
        items.append(new QStandardItem(QIcon(m_lang_img), ""));
        qst->appendRow(items);
    }
};

//===============================================================


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton1_UP_clicked();
    void on_pushButton1_DOWN_clicked();
    void on_pushButton2_UP_clicked();
    void on_pushButton2_DOWN_clicked();
    void on_pushButton3_UP_clicked();
    void on_pushButton3_DOWN_clicked();
    void on_pushButton4_UP_clicked();
    void on_pushButton4_DOWN_clicked();
    void on_pushButton5_UP_clicked();
    void on_pushButton5_DOWN_clicked();
    void on_pushButton6_UP_clicked();
    void on_pushButton6_DOWN_clicked();

    void on_tableView_pressed(const QModelIndex &index);
    void on_pushButton_Rem_Row_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    int row_index;
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    PLanguage *plg1;
    PLanguage *plg2;
    PLanguage *plg3;
    PLanguage *plg4;
    PLanguage *plg5;
    PLanguage *plg6;
};


#endif // MAINWINDOW_H
