#include "mywindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWindow window;
    window.show();
    return app.exec();
}

// 关键：确保 MOC 处理 `mywindow.hpp`
#include "mywindow.moc"
