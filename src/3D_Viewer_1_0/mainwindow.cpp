#include "mainwindow.h"

#include <iostream>

#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  loadSettings();
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}

void MainWindow::connectSignal() {
  connect(ui->lineEdit_x, &QLineEdit::textChanged, this,
          &MainWindow::updateScrollBar);
  connect(ui->lineEdit_y, &QLineEdit::textChanged, this,
          &MainWindow::updateScrollBar);
  connect(ui->lineEdit_z, &QLineEdit::textChanged, this,
          &MainWindow::updateScrollBar);
  connect(ui->lineEdit_x_2, &QLineEdit::textChanged, this,
          &MainWindow::updateScrollBar);
  connect(ui->lineEdit_y_2, &QLineEdit::textChanged, this,
          &MainWindow::updateScrollBar);
  connect(ui->lineEdit_z_2, &QLineEdit::textChanged, this,
          &MainWindow::updateScrollBar);
  connect(ui->lineEdit_scale, &QLineEdit::textChanged, this,
          &MainWindow::updateScrollBar);
}

void MainWindow::on_pushButton_clicked() {
  check_if_filedata_filled();
  QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "~/",
                                                  "OBJ Files (*.obj)");
  if (filename.isEmpty()) {
    ui->fileNameLineEdit->setText("File not chosen.");
    return;
  }
  ui->glwidget->loadFile(filename);
  int flag = OK;
  int code = file_reader(ui->glwidget->currentFilename.toUtf8().data(),
                         &ui->glwidget->file_data);

  if (code == FILE_NOT_FOUND) {
    ui->fileNameLineEdit->setText("File not found.");
    check_if_filedata_filled();
    flag = ERROR;
  } else if (code == EMPTY_FILE) {
    ui->fileNameLineEdit->setText("File is empty.");
    check_if_filedata_filled();
    flag = ERROR;
  } else if (code == POLYGON_COUNT_ERROR) {
    ui->fileNameLineEdit->setText("Incorrect polygon setting.");
    check_if_filedata_filled();
    flag = ERROR;
  } else if (code == VERTEX_COUNT_ERROR) {
    ui->fileNameLineEdit->setText("Incorrect vertex setting.");
    check_if_filedata_filled();
    flag = ERROR;
  } else if (code == ERROR) {
    ui->fileNameLineEdit->setText("Unidefined symbols.");
    check_if_filedata_filled();
    flag = ERROR;
  }

  if (flag != OK) {
    return;
  }
  center_model(&ui->glwidget->file_data);
  QString fileNameOnly = QFileInfo(filename).fileName();
  ui->fileNameLineEdit->setText(fileNameOnly);
  ui->lineEdit_vertexes->setText(
      QString::number(ui->glwidget->file_data.count_of_vertexes));
  ui->lineEdit_edges->setText(
      QString::number(ui->glwidget->file_data.count_of_facets));
  connectSignal();
  ui->glwidget->fileSelected = true;
  ui->glwidget->update();
}

void MainWindow::check_if_filedata_filled() {
  if (is_null(&ui->glwidget->file_data.matrix_3d) == OK) {
    remove_matrix(&ui->glwidget->file_data.matrix_3d);
    remove_polygons(ui->glwidget->file_data.polygons,
                    ui->glwidget->file_data.count_of_facets);
    free(ui->glwidget->file_data.polygons);
    ui->glwidget->file_data = {0, 0, {0, 0, 0}, 0};
  }
}

void MainWindow::updateScrollBar(const QString &value) {
  double doubleValue = value.toDouble();
  if (sender() == ui->lineEdit_x) {
    ui->x_axis_ScrollBar->setValue(static_cast<int>(doubleValue));
  } else if (sender() == ui->lineEdit_y) {
    ui->y_axis_ScrollBar->setValue(static_cast<int>(doubleValue));
  } else if (sender() == ui->lineEdit_z) {
    ui->z_axis_ScrollBar->setValue(static_cast<int>(doubleValue));
  } else if (sender() == ui->lineEdit_x_2) {
    ui->x_axis_ScrollBar_2->setValue(static_cast<int>(doubleValue));
  } else if (sender() == ui->lineEdit_y_2) {
    ui->y_axis_ScrollBar_2->setValue(static_cast<int>(doubleValue));
  } else if (sender() == ui->lineEdit_z_2) {
    ui->z_axis_ScrollBar_2->setValue(static_cast<int>(doubleValue));
  } else if (sender() == ui->lineEdit_scale) {
    ui->scale_ScrollBar->setValue(static_cast<int>(doubleValue));
  }
}

void MainWindow::rotateModel(char axis, int value) {
  if (axis == 'x') {
    if (value != ui->glwidget->rotate.ox) {
      ui->glwidget->rotate.ox = value;
      rotation_by_ox(&ui->glwidget->file_data.matrix_3d,
                     ui->glwidget->rotate.ox - ui->glwidget->rotate.prevX);
      ui->glwidget->rotate.prevX = ui->glwidget->rotate.ox;
    }
  } else if (axis == 'y') {
    if (value != ui->glwidget->rotate.oy) {
      ui->glwidget->rotate.oy = value;
      rotation_by_oy(&ui->glwidget->file_data.matrix_3d,
                     ui->glwidget->rotate.oy - ui->glwidget->rotate.prevY);
      ui->glwidget->rotate.prevY = ui->glwidget->rotate.oy;
    }
  } else if (axis == 'z') {
    if (value != ui->glwidget->rotate.oz) {
      ui->glwidget->rotate.oz = value;
      rotation_by_oz(&ui->glwidget->file_data.matrix_3d,
                     ui->glwidget->rotate.oz - ui->glwidget->rotate.prevZ);
      ui->glwidget->rotate.prevZ = ui->glwidget->rotate.oz;
    }
  }
  ui->glwidget->update();
}

void MainWindow::on_x_axis_ScrollBar_valueChanged(int value) {
  rotateModel('x', value);
  ui->lineEdit_x->setText(QString::number(value));
}

void MainWindow::on_y_axis_ScrollBar_valueChanged(int value) {
  rotateModel('y', value);
  ui->lineEdit_y->setText(QString::number(value));
}

void MainWindow::on_z_axis_ScrollBar_valueChanged(int value) {
  rotateModel('z', value);
  ui->lineEdit_z->setText(QString::number(value));
}

void MainWindow::moveModel(char axis, int value) {
  if (axis == 'x') {
    if (value != ui->glwidget->move.ox) {
      ui->glwidget->move.ox = static_cast<double>(value) / 100.;
      move_x(&ui->glwidget->file_data.matrix_3d,
             ui->glwidget->move.ox - ui->glwidget->move.mvPrevX);
      ui->glwidget->move.mvPrevX = ui->glwidget->move.ox;
    }
  } else if (axis == 'y') {
    if (value != ui->glwidget->move.oy) {
      ui->glwidget->move.oy = static_cast<double>(value) / 100.;
      move_y(&ui->glwidget->file_data.matrix_3d,
             ui->glwidget->move.oy - ui->glwidget->move.mvPrevY);
      ui->glwidget->move.mvPrevY = ui->glwidget->move.oy;
    }
  } else if (axis == 'z') {
    if (value != ui->glwidget->move.oz) {
      ui->glwidget->move.oz = static_cast<double>(value) / 100.;
      move_z(&ui->glwidget->file_data.matrix_3d,
             ui->glwidget->move.oz - ui->glwidget->move.mvPrevZ);
      ui->glwidget->move.mvPrevZ = ui->glwidget->move.oz;
    }
  }

  ui->glwidget->update();
}

void MainWindow::on_x_axis_ScrollBar_2_valueChanged(int value) {
  moveModel('x', value);
  ui->lineEdit_x_2->setText(QString::number(value));
}

void MainWindow::on_y_axis_ScrollBar_2_valueChanged(int value) {
  moveModel('y', value);
  ui->lineEdit_y_2->setText(QString::number(value));
}

void MainWindow::on_z_axis_ScrollBar_2_valueChanged(int value) {
  moveModel('z', value);
  ui->lineEdit_z_2->setText(QString::number(value));
}

void MainWindow::on_scale_ScrollBar_valueChanged(int value) {
  ui->lineEdit_scale->setText(QString::number(value));
  if (value == 0) {
    return;
  }
  double scaleFactor = 1.0;
  if (value > prevScale) {
    scaleFactor = 1.1;
  } else if (value < prevScale) {
    scaleFactor = 0.9;
  }
  prevScale = scaleFactor;
  scale_model(&ui->glwidget->file_data.matrix_3d, scaleFactor * prevScale);
  prevScale = value;
  ui->glwidget->update();
}

void MainWindow::on_radioButton_parallel_clicked() {
  ui->glwidget->projection = 0;
  ui->glwidget->update();
}

void MainWindow::on_radioButton_central_clicked() {
  ui->glwidget->projection = 1;
  ui->glwidget->update();
}

void MainWindow::on_radioButton_solid_clicked() {
  ui->glwidget->line_solid = true;
  ui->glwidget->update();
}

void MainWindow::on_radioButton_dashed_clicked() {
  ui->glwidget->line_solid = false;
  ui->glwidget->update();
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
  ui->glwidget->line_thickness = static_cast<GLfloat>(value / 5.);
  ui->glwidget->update();
}

void MainWindow::on_radioButton_none_clicked() {
  ui->glwidget->vertex_display = none;
  ui->glwidget->update();
}

void MainWindow::on_radioButton_circle_clicked() {
  ui->glwidget->vertex_display = circle;
  ui->glwidget->update();
}

void MainWindow::on_radioButton_square_clicked() {
  ui->glwidget->vertex_display = square;
  ui->glwidget->update();
}

void MainWindow::on_horizontalSlider_vertex_size_valueChanged(int value) {
  ui->glwidget->vertex_size = static_cast<GLfloat>(value);
  ui->glwidget->update();
}

void MainWindow::on_pushButton_edge_color_clicked() {
  ui->glwidget->edge_color = QColorDialog::getColor();
  ui->glwidget->update();
}

void MainWindow::on_pushButton_vertex_color_clicked() {
  ui->glwidget->vertex_color = QColorDialog::getColor();
  ui->glwidget->update();
}

void MainWindow::on_pushButton_vertex_color_2_clicked() {
  ui->glwidget->back_color = QColorDialog::getColor();
  ui->glwidget->update();
}

void MainWindow::on_pushButton_screenshot_clicked() {
  QString name = QFileDialog::getSaveFileName();
  if (!name.isEmpty()) {
    ui->glwidget->grab().save(name);
  }
}

void MainWindow::saveSettings() {
  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     ORGANIZATION_NAME, APPLICATION_NAME);
  settings.beginGroup("Colors");
  settings.setValue("EdgeColor", ui->glwidget->edge_color);
  settings.setValue("VertexColor", ui->glwidget->vertex_color);
  settings.setValue("BackColor", ui->glwidget->back_color);
  settings.endGroup();

  settings.beginGroup("DisplaySettings");
  settings.setValue("ProjectionMode", ui->glwidget->projection);
  settings.setValue("LineSolid", ui->glwidget->line_solid);
  settings.setValue("VertexDisplay",
                    static_cast<int>(ui->glwidget->vertex_display));
  settings.setValue("LineThickness", ui->horizontalSlider->value());
  settings.setValue("VertexSize", ui->horizontalSlider_vertex_size->value());
  settings.endGroup();
}

void MainWindow::loadSettings() {
  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     ORGANIZATION_NAME, APPLICATION_NAME);
  settings.beginGroup("Colors");
  ui->glwidget->edge_color =
      settings.value("EdgeColor", QColor(Qt::black)).value<QColor>();
  ui->glwidget->vertex_color =
      settings.value("VertexColor", QColor(Qt::black)).value<QColor>();
  ui->glwidget->back_color =
      settings.value("BackColor", QColor(Qt::blue)).value<QColor>();
  settings.endGroup();

  settings.beginGroup("DisplaySettings");
  ui->glwidget->projection = settings.value("ProjectionMode", 0).toInt();
  ui->radioButton_parallel->setChecked(ui->glwidget->projection == 0);
  ui->radioButton_central->setChecked(ui->glwidget->projection != 0);

  ui->glwidget->line_solid = settings.value("LineSolid", true).toBool();
  ui->radioButton_solid->setChecked(ui->glwidget->line_solid);
  ui->radioButton_dashed->setChecked(!ui->glwidget->line_solid);

  ui->glwidget->vertex_display =
      static_cast<MyDisplay>(settings.value("VertexDisplay", 0).toInt());
  ui->radioButton_none->setChecked(ui->glwidget->vertex_display == none);
  ui->radioButton_square->setChecked(ui->glwidget->vertex_display == square);
  ui->radioButton_circle->setChecked(ui->glwidget->vertex_display == circle);

  int lineThickness = settings.value("LineThickness", 0).toInt();
  ui->horizontalSlider->setValue(lineThickness);

  int vertexSize = settings.value("VertexSize", 0).toInt();
  ui->horizontalSlider_vertex_size->setValue(vertexSize);

  settings.endGroup();
}

void MainWindow::on_pushButton_gif_clicked() {
  QDateTime currentDate = QDateTime::currentDateTime();
  QString formattedTime = currentDate.toString("yyyy-MM-dd hh.mm.ss");
  QString namePattern = "Screen Cast " + formattedTime + ".gif";
  QString gifname = QFileDialog::getSaveFileName(
      this, tr("Save a gif animation"), namePattern, tr("gif (*.gif)"));
  if (gifname != "") {
    ui->pushButton_gif->setDisabled(true);
    save_gif(gifname);
  }
}

void MainWindow::save_gif(QString gifname) {
  QImage image(ui->glwidget->size(), QImage::Format_RGBA8888);
  QImage scaledImage;
  QPainter painter(&image);
  painter.setCompositionMode(QPainter::CompositionMode_Source);
  QTime time;
  GifWriter gif;
  GifBegin(&gif, gifname.toUtf8().data(), 640, 480, 10);

  for (int i = 1; i <= 50; i++) {
    ui->pushButton_gif->setText(QString::number(i / 10) + "s");
    ui->glwidget->render(&painter);
    scaledImage = image.scaled(640, 480);
    GifWriteFrame(&gif, scaledImage.bits(), 640, 480, 10);
    time = QTime::currentTime().addMSecs(100);
    while (QTime::currentTime() < time)
      QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
  }
  ui->pushButton_gif->setText("GIF");
  GifEnd(&gif);
  QMessageBox messageBoxGif;
  messageBoxGif.information(0, "", "Gif animation saved successfully");
  ui->pushButton_gif->setEnabled(true);
}
