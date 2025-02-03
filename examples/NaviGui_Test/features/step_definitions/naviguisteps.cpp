#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include <QtTest/QtTest>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QThread>
#include <stdexcept>
#include "mywindow.hpp"

using cucumber::ScenarioScope;

struct MyWindowCtx {
    MyWindow NaviWin{};
};

static QApplication *app;
static int global_argc = 1;
static char *global_argv[] = { (char *)"test", nullptr };

class AppThread : public QThread {
public:
    void run() override {
        app = new QApplication(global_argc, global_argv);
        app->exec();  // 启动事件循环
    }
};

GIVEN("^应用已启动$") {
    ScenarioScope<MyWindowCtx> context;
    static AppThread appThread;

    if (!app) {
        appThread.start();  // 在新线程中启动 QApplication
    }
    context->NaviWin.show();
    QTest::qWait(100);  // 等待界面显示
}

WHEN("^用户点击 \"(.*)\" 按钮$") {
    REGEX_PARAM(std::string, buttonText);
    ScenarioScope<MyWindowCtx> context;
    QPushButton *button = context->NaviWin.findChild<QPushButton *>(QString::fromStdString(buttonText));
    if (button) {
        QTest::mouseClick(button, Qt::LeftButton);
        QTest::qWait(100);  // 等待按钮点击事件处理
    } else {
        throw std::runtime_error("按钮未找到：" + buttonText);
    }
}

THEN("^\"(.*)\" 应该显示 \"(.*)\"$") {
    REGEX_PARAM(std::string, fieldName);
    REGEX_PARAM(std::string, expectedText);
    ScenarioScope<MyWindowCtx> context;
    QLineEdit *field = context->NaviWin.findChild<QLineEdit *>(QString::fromStdString(fieldName));
    
    QVERIFY(field);  // 代替 assert(field)
    QCOMPARE(field->text().toStdString(), expectedText);  // 代替 assert
}
