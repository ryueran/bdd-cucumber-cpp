#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include <QtTest/QtTest>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <stdexcept>
#include <mywindow.hpp>

using cucumber::ScenarioScope;

struct MyWindowCtx {
    MyWindow *NaviWin = nullptr;
};

static QApplication *app;
static int global_argc = 1;
static char *global_argv[] = { (char *)"test", nullptr };

GIVEN("^Application started$") {
    ScenarioScope<MyWindowCtx> context;
    if (!app) {  
        app = new QApplication(global_argc, global_argv);
    }
    if (!context->NaviWin) {
        context->NaviWin = new MyWindow();
    }
    context->NaviWin->show();
    QTest::qWait(2000);
}


WHEN("^User clicks \"(.*)\" button$") {
    REGEX_PARAM(std::string, buttonText);
    ScenarioScope<MyWindowCtx> context;
    // find button
    QPushButton *button = context->NaviWin->findChild<QPushButton *>();
    QVERIFY(button);  // verify that button exists

    // find textfeld
    QLineEdit *field1 = context->NaviWin->findChild<QLineEdit *>();
    QLineEdit *field2 = context->NaviWin->findChild<QLineEdit *>();
    QVERIFY(field1);
    QVERIFY(field2);

    // trigger button click
    QTest::mouseClick(button, Qt::LeftButton);

    // time window for UI display
    QTest::qWait(5000);
}

THEN("^\"(.*)\" should display \"(.*)\"$") {
    REGEX_PARAM(std::string, fieldName);
    REGEX_PARAM(std::string, expectedText);
    ScenarioScope<MyWindowCtx> context;
    QLineEdit *field = context->NaviWin->findChild<QLineEdit *>(QString::fromStdString(fieldName));
    
    QVERIFY(field);
    QCOMPARE(field->text().toStdString(), expectedText);
}
