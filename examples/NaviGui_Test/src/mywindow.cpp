#include "mywindow.hpp"
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

MyWindow::MyWindow() {
    setWindowTitle("JSON read example");
    resize(300, 150);

    button = new QPushButton("read json", this);
    field1 = new QLineEdit(this);
    field2 = new QLineEdit(this);
    field1->setPlaceholderText("data 1");
    field2->setPlaceholderText("data 2");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    layout->addWidget(field1);
    layout->addWidget(field2);
    setLayout(layout);

    connect(button, &QPushButton::clicked, this, &MyWindow::loadJson);
}

void MyWindow::loadJson() {
    QFile file("/home/muzi/Documents/front_end_test_cucumber/cucumber-cpp/data_utility/data.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Can't open JSON file");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (!doc.isObject()) {
        QMessageBox::warning(this, "error", "JSON format incorrect");
        return;
    }

    QJsonObject obj = doc.object();
    double value1 = obj.value("key1").toDouble();
    double value2 = obj.value("key2").toDouble();

    field1->setText(QString::number(value1));
    field2->setText(QString::number(value2));
}
