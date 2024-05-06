#include <QApplication>
#include <QMainWindow>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QMainWindow window;
  window.setWindowTitle("STL Viewer");

  window.show();
  return app.exec();
}
