#include <QAction>
#include <QApplication>
#include <QIcon>
#include <QLabel>
#include <QLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QSurfaceFormat>
#include <QTimer>
#include <QToolBar>
#include <QWidget>
#include <Qt>

#ifndef QT_NO_OPENGL
#include "stl_widget.h"
#endif

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QMainWindow main_window;
  main_window.setWindowTitle("STL Viewer");

  main_window.show();

  // Create buttons for toolbar
  QAction *action_open = new QAction("action_open", &main_window);
  QAction *action_clear = new QAction("action_clear", &main_window);
  QAction *action_rotate_x = new QAction("action_rotate_x", &main_window);
  QAction *action_rotate_y = new QAction("action_rotate_y", &main_window);
  QAction *action_rotate_z = new QAction("action_rotate_z", &main_window);
  QAction *action_export = new QAction("action_export", &main_window);

  // Set icons for buttons
  // Ugly paths, fix later
  QIcon open_icon;
  open_icon.addFile(QString::fromUtf8("../../icons/open.png"), QSize(),
                    QIcon::Normal, QIcon::Off);
  action_open->setIcon(open_icon);
  QIcon clear_icon;
  clear_icon.addFile(QString::fromUtf8("../../icons/clear.png"), QSize(),
                     QIcon::Normal, QIcon::Off);
  action_clear->setIcon(clear_icon);
  QIcon rotate_x_icon;
  rotate_x_icon.addFile(QString::fromUtf8("../../icons/rotate_x.png"), QSize(),
                        QIcon::Normal, QIcon::Off);
  action_rotate_x->setIcon(rotate_x_icon);
  QIcon rotate_y_icon;
  rotate_y_icon.addFile(QString::fromUtf8("../../icons/rotate_y.png"), QSize(),
                        QIcon::Normal, QIcon::Off);
  action_rotate_y->setIcon(rotate_y_icon);
  QIcon rotate_z_icon;
  rotate_z_icon.addFile(QString::fromUtf8("../../icons/rotate_z.png"), QSize(),
                        QIcon::Normal, QIcon::Off);
  action_rotate_z->setIcon(rotate_z_icon);
  QIcon export_icon;
  export_icon.addFile(QString::fromUtf8("../../icons/export.png"), QSize(),
                      QIcon::Normal, QIcon::Off);
  action_export->setIcon(export_icon);

  // Create main toolbar
  QToolBar *main_toolbar = new QToolBar("main_toolbar", &main_window);
  main_toolbar->setFloatable(false);
  main_toolbar->setMovable(false);
  main_toolbar->addAction(action_open);
  main_toolbar->addAction(action_clear);
  // main_toolbar->addAction(action_rotate_x); // TODO: Implement rotation
  // main_toolbar->addAction(action_rotate_y);
  // main_toolbar->addAction(action_rotate_z);
  main_toolbar->addAction(action_export);
  main_toolbar->setStyleSheet("background-color: white");

  QSurfaceFormat format;
  format.setDepthBufferSize(24);
  QSurfaceFormat::setDefaultFormat(format);

#ifndef QT_NO_OPENGL
  StlWidget *stl_widget = new StlWidget(&main_window);
  main_window.setCentralWidget(stl_widget);
  main_window.addToolBar(Qt::ToolBarArea::TopToolBarArea, main_toolbar);
#else
  QLabel note("OpenGL Support required");
  note.show();
#endif
  return app.exec();
}
