#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QString>
#include <QTextStream>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <algorithm>

#include "centermodel.h"
#include "gif.h"
#include "glwidget.h"

#define ORGANIZATION_NAME "gloombodya"
#define ORGANIZATION_DOMAIN "gloom.bodya"
#define APPLICATION_NAME "3D Viewer"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void connectSignal();
  void on_pushButton_clicked();
  void rotateModel(char axis, int value);

  void on_x_axis_ScrollBar_valueChanged(int value);

  void on_y_axis_ScrollBar_valueChanged(int value);

  void on_z_axis_ScrollBar_valueChanged(int value);

  void updateScrollBar(const QString &value);

  void moveModel(char axis, int value);

  void on_x_axis_ScrollBar_2_valueChanged(int value);

  void on_y_axis_ScrollBar_2_valueChanged(int value);

  void on_z_axis_ScrollBar_2_valueChanged(int value);

  void on_scale_ScrollBar_valueChanged(int value);

  void on_radioButton_parallel_clicked();

  void on_radioButton_central_clicked();

  void on_radioButton_solid_clicked();

  void on_radioButton_dashed_clicked();

  void on_horizontalSlider_valueChanged(int value);

  void on_radioButton_none_clicked();

  void on_radioButton_circle_clicked();

  void on_radioButton_square_clicked();

  void on_horizontalSlider_vertex_size_valueChanged(int value);

  void on_pushButton_edge_color_clicked();

  void on_pushButton_vertex_color_clicked();

  void on_pushButton_vertex_color_2_clicked();

  void on_pushButton_screenshot_clicked();

  void saveSettings();
  void loadSettings();

  void on_pushButton_gif_clicked();
  void save_gif(QString gifname);

 private:
  Ui::MainWindow *ui;
  QButtonGroup group;
  double prevScale = 1.0;

  void check_if_filedata_filled();
};
#endif  // MAINWINDOW_H
