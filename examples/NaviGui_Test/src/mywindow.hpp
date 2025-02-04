#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class MyWindow : public QWidget {
    Q_OBJECT  // MOC 

public:
    MyWindow();

private slots:
    void loadJson();

private:
    QPushButton *button;
    QLineEdit *field1;
    QLineEdit *field2;
};

#endif  // MYWINDOW_HPP
