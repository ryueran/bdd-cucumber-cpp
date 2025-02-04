#ifndef TEST_MYWINDOW_HPP
#define TEST_MYWINDOW_HPP

#include <QTest>
#include "mywindow.hpp"

class TestMyWindow : public QObject {
    Q_OBJECT  // ✅ 确保 Q_OBJECT 在 .hpp 里

private slots:
    void testButtonClick();
};

#endif // TEST_MYWINDOW_HPP
