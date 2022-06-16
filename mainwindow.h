#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
//#include <QStringListModel>
//#include <QStringList>
//#include <QList>
//#include <QStandardItemModel>

#include <QMap>
#include <QPointer>

//#include <QItemDelegate>
//#include <QPolygonF>
//#include <QPointF>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*/===============================================================//

//===============================================================/*/


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void fileOpen();
    void fileSaveAs();
    void About();

private:
    Ui::MainWindow *ui;

    QMenuBar *mainMenu;
    QMenu *fMenu;
    QMenu *aMenu;
    QAction *openfile;
    QAction *saveasfile;
    QAction *about;

    void Parse_File(const QString& fn);
};


#endif // MAINWINDOW_H
