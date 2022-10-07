 #ifndef WINDOW_H
 #define WINDOW_H

#include <QMainWindow>
#include <QtWidgets>

 //class QComboBox;
 class QLineEdit;

 class Window : public QWidget
 //class Window : public QMainWindow
 {
     Q_OBJECT

 public:
     Window();

 private:
     QVBoxLayout *vbox;
     QLineEdit *Login;
     QLineEdit *pass;
     QPushButton *button;
     QLabel *ql;
     QPoint vP;
     bool is_hover;
     bool not_logged_in;

     void CheckPass();

 protected:
      void paintEvent(QPaintEvent *event) override;
      void resizeEvent(QResizeEvent *event) override;
      void moveEvent(QMoveEvent *event) override;
      void mouseMoveEvent(QMouseEvent *event) override;
      bool event(QEvent *event) override;
 };

 #endif
