#include "test_mywindow.hpp"

void TestMyWindow::testButtonClick() {
    MyWindow window;
    window.show();

    // 找到按钮
    QPushButton *button = window.findChild<QPushButton *>();
    QVERIFY(button);  // 确保按钮存在

    // 找到文本框
    QLineEdit *field1 = window.findChild<QLineEdit *>();
    QLineEdit *field2 = window.findChild<QLineEdit *>();
    QVERIFY(field1);
    QVERIFY(field2);

    // 触发按钮点击
    QTest::mouseClick(button, Qt::LeftButton);

    // 确保 UI 事件循环处理完
    QTest::qWait(500);  // 等待 500ms，确保 JSON 解析完毕

    // 检查文本框是否更新
    QVERIFY(!field1->text().isEmpty());
    QVERIFY(!field2->text().isEmpty());
}

QTEST_MAIN(TestMyWindow)

#include "moc_mywindow.cpp"
#include "moc_test_mywindow.cpp"
