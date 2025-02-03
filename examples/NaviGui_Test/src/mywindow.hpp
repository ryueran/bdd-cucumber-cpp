#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

class MyWindow : public QWidget {
    Q_OBJECT  // 关键：MOC 需要处理它

public:
    MyWindow() {
        setWindowTitle("JSON 读取示例");
        resize(300, 150);

        button = new QPushButton("读取 JSON", this);
        field1 = new QLineEdit(this);
        field2 = new QLineEdit(this);
        field1->setPlaceholderText("数据 1");
        field2->setPlaceholderText("数据 2");

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(button);
        layout->addWidget(field1);
        layout->addWidget(field2);
        setLayout(layout);

        connect(button, &QPushButton::clicked, this, &MyWindow::loadJson);
    }

private slots:
    void loadJson() {
        QFile file("data.json");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "无法打开 JSON 文件");
            return;
        }

        QByteArray jsonData = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(jsonData);
        if (!doc.isObject()) {
            QMessageBox::warning(this, "错误", "JSON 格式错误");
            return;
        }

        QJsonObject obj = doc.object();
        double value1 = obj.value("key1").toDouble();
        double value2 = obj.value("key2").toDouble();

        field1->setText(QString::number(value1));
        field2->setText(QString::number(value2));
    }

private:
    QPushButton *button;
    QLineEdit *field1;
    QLineEdit *field2;
};

#endif  // MYWINDOW_HPP
