
 #include <QtGui>
 #include <QtGui/QMouseEvent>
 #include "window.h"

 Window::Window()
 {
     this->setAttribute(Qt::WA_Hover);

     vbox = new QVBoxLayout(this);

     Login = new QLineEdit;
     vbox->addWidget(Login);
     Login->setText("Логин");
     Login->setFocus();

     pass = new QLineEdit;
     vbox->addWidget(pass);
     pass->setText("Пароль");
     pass->setEchoMode(QLineEdit::Password);

     ql = new QLabel(this);
     ql->setFrameStyle(QFrame::Panel | QFrame::Sunken);
     ql->setText(tr("Вход"));
     ql->setAlignment(Qt::AlignCenter);
     ql->setMaximumWidth(170);
     ql->setMaximumHeight(38);
     vbox->addWidget(ql);

     is_hover = false;
     not_logged_in = false;
     setWindowTitle(tr("Authentication"));
 }


 void Window::CheckPass() {             // проверяем логин и пароль
    if ("log" == Login->text() &&
            "pas" == pass->text()) {

        auto effect = new QGraphicsOpacityEffect(this);
        effect->setOpacity(1);
        Login->setGraphicsEffect(effect);

        auto effect2 = new QGraphicsOpacityEffect(this);
        effect2->setOpacity(1);
        pass->setGraphicsEffect(effect2);

        auto effect3 = new QGraphicsOpacityEffect(this);
        effect3->setOpacity(1);
        ql->setGraphicsEffect(effect3);

        auto animations = new QSequentialAnimationGroup(Login);
        //animations->addPause(3000);
        auto opacityAnimation = new QPropertyAnimation(effect, "opacity", animations);
        opacityAnimation->setDuration(2000);
        opacityAnimation->setStartValue(1.0);
        opacityAnimation->setEndValue(0.0);
        opacityAnimation->setEasingCurve(QEasingCurve::OutQuad);
        animations->addAnimation(opacityAnimation);

        auto animations2 = new QSequentialAnimationGroup(pass);
        auto opacityAnimation2 = new QPropertyAnimation(effect2, "opacity", animations2);
        opacityAnimation2->setDuration(2000);
        opacityAnimation2->setStartValue(1.0);
        opacityAnimation2->setEndValue(0.0);
        opacityAnimation2->setEasingCurve(QEasingCurve::OutQuad);
        animations2->addAnimation(opacityAnimation2);

        auto animations3 = new QSequentialAnimationGroup(ql);
        auto opacityAnimation3 = new QPropertyAnimation(effect3, "opacity", animations3);
        opacityAnimation3->setDuration(2000);
        opacityAnimation3->setStartValue(1.0);
        opacityAnimation3->setEndValue(0.0);
        opacityAnimation3->setEasingCurve(QEasingCurve::OutQuad);
        animations3->addAnimation(opacityAnimation3);

        animations->start();
        animations2->start();
        animations3->start();

        not_logged_in = true;
        update();
    }
    else {
        QPropertyAnimation *anim = new QPropertyAnimation(Login, "pos", this);
        anim->setDuration(110);
        anim->setStartValue(QPoint(240, 135));
        anim->setEndValue(QPoint(245, 135));
        anim->start();

        anim->setStartValue(QPoint(245, 135));
        anim->setEndValue(QPoint(235, 135));
        anim->start();

        anim->setStartValue(QPoint(235, 135));
        anim->setEndValue(QPoint(240, 135));
        anim->start();

        QPropertyAnimation *anim2 = new QPropertyAnimation(pass, "pos", this);
        anim2->setDuration(110);
        anim2->setStartValue(QPoint(240, 205));
        anim2->setEndValue(QPoint(245, 205));
        anim2->start();

        anim2->setStartValue(QPoint(245, 205));
        anim2->setEndValue(QPoint(235, 205));
        anim2->start();

        anim2->setStartValue(QPoint(235, 205));
        anim2->setEndValue(QPoint(240, 205));
        anim2->start();

        QPropertyAnimation *anim3 = new QPropertyAnimation(ql, "pos", this);
        anim3->setDuration(110);
        anim3->setStartValue(QPoint(240, 285));
        anim3->setEndValue(QPoint(245, 285));
        anim3->start();

        anim3->setStartValue(QPoint(245, 285));
        anim3->setEndValue(QPoint(235, 285));
        anim3->start();

        anim3->setStartValue(QPoint(235, 285));
        anim3->setEndValue(QPoint(240, 285));
        anim3->start();
    }
 }


void Window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (!not_logged_in) {
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(Qt::white));
        painter.setPen(QPen(Qt::white));
    }
    else {
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(QColor(228, 236, 239, 255)));
        painter.setPen(QPen(QColor(228, 236, 239, 255)));
    }
    painter.drawRoundRect(QRect(170, 110, 300, 250), 5, 5);

    if (!not_logged_in) {
        if (!is_hover) {
            painter.setBrush(QBrush(Qt::white));
            painter.setPen(QPen(Qt::red));
            painter.drawRect(QRect(240, 285, 170, 38));
        }
        else {
            painter.setBrush(QBrush(Qt::red));
            painter.setPen(QPen(Qt::red));
            painter.drawRect(QRect(240, 285, 170, 38));
        }
    }
    else
        painter.setPen(QPen(Qt::white));
}

void Window::resizeEvent(QResizeEvent *)
{
    Login->resize(170, 38);
    pass->resize(170, 38);
    Login->move(240, 135);
    pass->move(240, 205);
    ql->move(240, 285);
}

void Window::moveEvent(QMoveEvent *)
{
    Login->move(240, 135);
    pass->move(240, 205);
    ql->move(240, 285);
}


bool Window::event(QEvent *event)
{
    QHoverEvent *hevent;

    switch(event->type())
        {
        case QEvent::HoverEnter:
            return true;
            break;
        case QEvent::HoverLeave:
            return true;
            break;
        case QEvent::HoverMove:
            hevent = static_cast<QHoverEvent*>(event);
            vP = hevent->oldPos();
            if (vP.x() > 240 && vP.x() < 240 + 170 && vP.y() > 285 && vP.y() < 285 + 38) {
                is_hover = true;
            }
            else
                is_hover = false;
            update();

            return true;
            break;

    case QEvent::MouseButtonPress:
        if (is_hover)
            CheckPass();
        return true;
        break;

        default:
            break;
        }
        return QWidget::event(event);
}


void Window::mouseMoveEvent(QMouseEvent *mEvent)
{
    QPoint vP = mEvent->pos();

    if (vP.x() > 240 && vP.x() < 285 && vP.y() > 38 && vP.y() < 170)
        is_hover = true;
    else
        is_hover = false;
}



