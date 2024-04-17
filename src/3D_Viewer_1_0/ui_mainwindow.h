/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  GLWidget *glwidget;
  QPushButton *pushButton;
  QLineEdit *fileNameLineEdit;
  QLabel *label_rotate_model;
  QLabel *label_x;
  QLabel *label_y;
  QLabel *label_z;
  QScrollBar *x_axis_ScrollBar;
  QScrollBar *y_axis_ScrollBar;
  QScrollBar *z_axis_ScrollBar;
  QLineEdit *lineEdit_x;
  QLineEdit *lineEdit_z;
  QLineEdit *lineEdit_y;
  QLabel *label_trans_model;
  QLabel *label_x_2;
  QLabel *label_y_2;
  QLabel *label_z_2;
  QScrollBar *x_axis_ScrollBar_2;
  QScrollBar *y_axis_ScrollBar_2;
  QScrollBar *z_axis_ScrollBar_2;
  QLineEdit *lineEdit_x_2;
  QLineEdit *lineEdit_y_2;
  QLineEdit *lineEdit_z_2;
  QLabel *label_trans_model_2;
  QScrollBar *scale_ScrollBar;
  QLineEdit *lineEdit_scale;
  QLabel *label_vertexes;
  QLabel *label_filename_2;
  QLineEdit *lineEdit_vertexes;
  QLineEdit *lineEdit_edges;
  QLabel *label_trans_model_3;
  QRadioButton *radioButton_parallel;
  QRadioButton *radioButton_central;
  QLabel *label_trans_model_4;
  QRadioButton *radioButton_solid;
  QRadioButton *radioButton_dashed;
  QLabel *label_trans_model_5;
  QSlider *horizontalSlider;
  QPushButton *pushButton_edge_color;
  QLabel *label_vertexes_draw;
  QRadioButton *radioButton_none;
  QRadioButton *radioButton_circle;
  QRadioButton *radioButton_square;
  QLabel *label_vertexes_size;
  QSlider *horizontalSlider_vertex_size;
  QPushButton *pushButton_vertex_color;
  QPushButton *pushButton_vertex_color_2;
  QPushButton *pushButton_screenshot;
  QPushButton *pushButton_gif;
  QMenuBar *menubar;
  QStatusBar *statusbar;
  QButtonGroup *buttonGroup;
  QButtonGroup *buttonGroup_3;
  QButtonGroup *buttonGroup_2;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName("MainWindow");
    MainWindow->resize(803, 612);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName("centralwidget");
    glwidget = new GLWidget(centralwidget);
    glwidget->setObjectName("glwidget");
    glwidget->setGeometry(QRect(270, 20, 520, 480));
    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName("pushButton");
    pushButton->setGeometry(QRect(10, 10, 80, 23));
    fileNameLineEdit = new QLineEdit(centralwidget);
    fileNameLineEdit->setObjectName("fileNameLineEdit");
    fileNameLineEdit->setGeometry(QRect(100, 10, 161, 23));
    label_rotate_model = new QLabel(centralwidget);
    label_rotate_model->setObjectName("label_rotate_model");
    label_rotate_model->setGeometry(QRect(10, 70, 241, 21));
    label_x = new QLabel(centralwidget);
    label_x->setObjectName("label_x");
    label_x->setGeometry(QRect(10, 100, 21, 16));
    label_y = new QLabel(centralwidget);
    label_y->setObjectName("label_y");
    label_y->setGeometry(QRect(10, 130, 21, 16));
    label_z = new QLabel(centralwidget);
    label_z->setObjectName("label_z");
    label_z->setGeometry(QRect(10, 160, 21, 16));
    x_axis_ScrollBar = new QScrollBar(centralwidget);
    x_axis_ScrollBar->setObjectName("x_axis_ScrollBar");
    x_axis_ScrollBar->setGeometry(QRect(30, 100, 171, 16));
    x_axis_ScrollBar->setMinimumSize(QSize(171, 0));
    x_axis_ScrollBar->setMinimum(-360);
    x_axis_ScrollBar->setMaximum(360);
    x_axis_ScrollBar->setOrientation(Qt::Horizontal);
    y_axis_ScrollBar = new QScrollBar(centralwidget);
    y_axis_ScrollBar->setObjectName("y_axis_ScrollBar");
    y_axis_ScrollBar->setGeometry(QRect(30, 130, 171, 16));
    y_axis_ScrollBar->setMinimum(-360);
    y_axis_ScrollBar->setMaximum(360);
    y_axis_ScrollBar->setOrientation(Qt::Horizontal);
    z_axis_ScrollBar = new QScrollBar(centralwidget);
    z_axis_ScrollBar->setObjectName("z_axis_ScrollBar");
    z_axis_ScrollBar->setGeometry(QRect(30, 160, 171, 16));
    z_axis_ScrollBar->setMinimum(-360);
    z_axis_ScrollBar->setMaximum(360);
    z_axis_ScrollBar->setOrientation(Qt::Horizontal);
    lineEdit_x = new QLineEdit(centralwidget);
    lineEdit_x->setObjectName("lineEdit_x");
    lineEdit_x->setGeometry(QRect(210, 100, 51, 21));
    lineEdit_z = new QLineEdit(centralwidget);
    lineEdit_z->setObjectName("lineEdit_z");
    lineEdit_z->setGeometry(QRect(210, 160, 51, 21));
    lineEdit_y = new QLineEdit(centralwidget);
    lineEdit_y->setObjectName("lineEdit_y");
    lineEdit_y->setGeometry(QRect(210, 130, 51, 21));
    label_trans_model = new QLabel(centralwidget);
    label_trans_model->setObjectName("label_trans_model");
    label_trans_model->setGeometry(QRect(20, 190, 241, 21));
    label_x_2 = new QLabel(centralwidget);
    label_x_2->setObjectName("label_x_2");
    label_x_2->setGeometry(QRect(10, 220, 21, 16));
    label_y_2 = new QLabel(centralwidget);
    label_y_2->setObjectName("label_y_2");
    label_y_2->setGeometry(QRect(10, 250, 21, 16));
    label_z_2 = new QLabel(centralwidget);
    label_z_2->setObjectName("label_z_2");
    label_z_2->setGeometry(QRect(10, 280, 21, 16));
    x_axis_ScrollBar_2 = new QScrollBar(centralwidget);
    x_axis_ScrollBar_2->setObjectName("x_axis_ScrollBar_2");
    x_axis_ScrollBar_2->setGeometry(QRect(30, 220, 171, 16));
    x_axis_ScrollBar_2->setMinimumSize(QSize(171, 0));
    x_axis_ScrollBar_2->setMinimum(-100);
    x_axis_ScrollBar_2->setMaximum(100);
    x_axis_ScrollBar_2->setOrientation(Qt::Horizontal);
    y_axis_ScrollBar_2 = new QScrollBar(centralwidget);
    y_axis_ScrollBar_2->setObjectName("y_axis_ScrollBar_2");
    y_axis_ScrollBar_2->setGeometry(QRect(30, 250, 171, 16));
    y_axis_ScrollBar_2->setMinimum(-100);
    y_axis_ScrollBar_2->setMaximum(100);
    y_axis_ScrollBar_2->setOrientation(Qt::Horizontal);
    z_axis_ScrollBar_2 = new QScrollBar(centralwidget);
    z_axis_ScrollBar_2->setObjectName("z_axis_ScrollBar_2");
    z_axis_ScrollBar_2->setGeometry(QRect(30, 280, 171, 16));
    z_axis_ScrollBar_2->setMinimum(-100);
    z_axis_ScrollBar_2->setMaximum(100);
    z_axis_ScrollBar_2->setOrientation(Qt::Horizontal);
    lineEdit_x_2 = new QLineEdit(centralwidget);
    lineEdit_x_2->setObjectName("lineEdit_x_2");
    lineEdit_x_2->setGeometry(QRect(210, 220, 51, 21));
    lineEdit_y_2 = new QLineEdit(centralwidget);
    lineEdit_y_2->setObjectName("lineEdit_y_2");
    lineEdit_y_2->setGeometry(QRect(210, 250, 51, 21));
    lineEdit_z_2 = new QLineEdit(centralwidget);
    lineEdit_z_2->setObjectName("lineEdit_z_2");
    lineEdit_z_2->setGeometry(QRect(210, 280, 51, 21));
    label_trans_model_2 = new QLabel(centralwidget);
    label_trans_model_2->setObjectName("label_trans_model_2");
    label_trans_model_2->setGeometry(QRect(10, 310, 241, 21));
    scale_ScrollBar = new QScrollBar(centralwidget);
    scale_ScrollBar->setObjectName("scale_ScrollBar");
    scale_ScrollBar->setGeometry(QRect(29, 340, 171, 16));
    scale_ScrollBar->setMinimum(-50);
    scale_ScrollBar->setMaximum(50);
    scale_ScrollBar->setSingleStep(1);
    scale_ScrollBar->setValue(1);
    scale_ScrollBar->setSliderPosition(1);
    scale_ScrollBar->setOrientation(Qt::Horizontal);
    lineEdit_scale = new QLineEdit(centralwidget);
    lineEdit_scale->setObjectName("lineEdit_scale");
    lineEdit_scale->setGeometry(QRect(210, 340, 51, 21));
    label_vertexes = new QLabel(centralwidget);
    label_vertexes->setObjectName("label_vertexes");
    label_vertexes->setGeometry(QRect(10, 40, 57, 15));
    label_filename_2 = new QLabel(centralwidget);
    label_filename_2->setObjectName("label_filename_2");
    label_filename_2->setGeometry(QRect(140, 40, 57, 15));
    lineEdit_vertexes = new QLineEdit(centralwidget);
    lineEdit_vertexes->setObjectName("lineEdit_vertexes");
    lineEdit_vertexes->setGeometry(QRect(70, 40, 61, 21));
    lineEdit_edges = new QLineEdit(centralwidget);
    lineEdit_edges->setObjectName("lineEdit_edges");
    lineEdit_edges->setGeometry(QRect(190, 40, 71, 21));
    label_trans_model_3 = new QLabel(centralwidget);
    label_trans_model_3->setObjectName("label_trans_model_3");
    label_trans_model_3->setGeometry(QRect(10, 370, 71, 21));
    radioButton_parallel = new QRadioButton(centralwidget);
    buttonGroup = new QButtonGroup(MainWindow);
    buttonGroup->setObjectName("buttonGroup");
    buttonGroup->addButton(radioButton_parallel);
    radioButton_parallel->setObjectName("radioButton_parallel");
    radioButton_parallel->setGeometry(QRect(90, 370, 81, 20));
    radioButton_central = new QRadioButton(centralwidget);
    buttonGroup->addButton(radioButton_central);
    radioButton_central->setObjectName("radioButton_central");
    radioButton_central->setGeometry(QRect(170, 370, 99, 20));
    label_trans_model_4 = new QLabel(centralwidget);
    label_trans_model_4->setObjectName("label_trans_model_4");
    label_trans_model_4->setGeometry(QRect(10, 400, 71, 21));
    radioButton_solid = new QRadioButton(centralwidget);
    buttonGroup_2 = new QButtonGroup(MainWindow);
    buttonGroup_2->setObjectName("buttonGroup_2");
    buttonGroup_2->addButton(radioButton_solid);
    radioButton_solid->setObjectName("radioButton_solid");
    radioButton_solid->setGeometry(QRect(90, 400, 71, 20));
    radioButton_dashed = new QRadioButton(centralwidget);
    buttonGroup_2->addButton(radioButton_dashed);
    radioButton_dashed->setObjectName("radioButton_dashed");
    radioButton_dashed->setGeometry(QRect(160, 400, 99, 20));
    label_trans_model_5 = new QLabel(centralwidget);
    label_trans_model_5->setObjectName("label_trans_model_5");
    label_trans_model_5->setGeometry(QRect(10, 430, 71, 21));
    horizontalSlider = new QSlider(centralwidget);
    horizontalSlider->setObjectName("horizontalSlider");
    horizontalSlider->setGeometry(QRect(80, 430, 71, 25));
    horizontalSlider->setOrientation(Qt::Horizontal);
    pushButton_edge_color = new QPushButton(centralwidget);
    pushButton_edge_color->setObjectName("pushButton_edge_color");
    pushButton_edge_color->setGeometry(QRect(160, 430, 100, 32));
    label_vertexes_draw = new QLabel(centralwidget);
    label_vertexes_draw->setObjectName("label_vertexes_draw");
    label_vertexes_draw->setGeometry(QRect(10, 460, 71, 21));
    radioButton_none = new QRadioButton(centralwidget);
    buttonGroup_3 = new QButtonGroup(MainWindow);
    buttonGroup_3->setObjectName("buttonGroup_3");
    buttonGroup_3->addButton(radioButton_none);
    radioButton_none->setObjectName("radioButton_none");
    radioButton_none->setGeometry(QRect(70, 460, 61, 20));
    radioButton_circle = new QRadioButton(centralwidget);
    buttonGroup_3->addButton(radioButton_circle);
    radioButton_circle->setObjectName("radioButton_circle");
    radioButton_circle->setGeometry(QRect(130, 460, 61, 20));
    radioButton_square = new QRadioButton(centralwidget);
    buttonGroup_3->addButton(radioButton_square);
    radioButton_square->setObjectName("radioButton_square");
    radioButton_square->setGeometry(QRect(190, 460, 71, 20));
    label_vertexes_size = new QLabel(centralwidget);
    label_vertexes_size->setObjectName("label_vertexes_size");
    label_vertexes_size->setGeometry(QRect(10, 490, 31, 21));
    horizontalSlider_vertex_size = new QSlider(centralwidget);
    horizontalSlider_vertex_size->setObjectName("horizontalSlider_vertex_size");
    horizontalSlider_vertex_size->setGeometry(QRect(50, 490, 91, 25));
    horizontalSlider_vertex_size->setOrientation(Qt::Horizontal);
    pushButton_vertex_color = new QPushButton(centralwidget);
    pushButton_vertex_color->setObjectName("pushButton_vertex_color");
    pushButton_vertex_color->setGeometry(QRect(160, 490, 101, 32));
    pushButton_vertex_color_2 = new QPushButton(centralwidget);
    pushButton_vertex_color_2->setObjectName("pushButton_vertex_color_2");
    pushButton_vertex_color_2->setGeometry(QRect(150, 520, 111, 32));
    pushButton_screenshot = new QPushButton(centralwidget);
    pushButton_screenshot->setObjectName("pushButton_screenshot");
    pushButton_screenshot->setGeometry(QRect(290, 520, 100, 32));
    pushButton_gif = new QPushButton(centralwidget);
    pushButton_gif->setObjectName("pushButton_gif");
    pushButton_gif->setGeometry(QRect(420, 520, 100, 32));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 803, 20));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName("statusbar");
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "3D Viewer", nullptr));
    pushButton->setText(
        QCoreApplication::translate("MainWindow", "Open file", nullptr));
    label_rotate_model->setText(
        QCoreApplication::translate("MainWindow", "Rotate Model", nullptr));
    label_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    label_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    label_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    label_trans_model->setText(
        QCoreApplication::translate("MainWindow", "Translate Model", nullptr));
    label_x_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    label_y_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    label_z_2->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    label_trans_model_2->setText(
        QCoreApplication::translate("MainWindow", "Scale Model", nullptr));
    label_vertexes->setText(
        QCoreApplication::translate("MainWindow", "Vertexes:", nullptr));
    label_filename_2->setText(
        QCoreApplication::translate("MainWindow", "Edges:", nullptr));
    label_trans_model_3->setText(
        QCoreApplication::translate("MainWindow", "Projection", nullptr));
    radioButton_parallel->setText(
        QCoreApplication::translate("MainWindow", "Parallel", nullptr));
    radioButton_central->setText(
        QCoreApplication::translate("MainWindow", "Central", nullptr));
    label_trans_model_4->setText(
        QCoreApplication::translate("MainWindow", "Edges Type", nullptr));
    radioButton_solid->setText(
        QCoreApplication::translate("MainWindow", "Solid", nullptr));
    radioButton_dashed->setText(
        QCoreApplication::translate("MainWindow", "Dashed", nullptr));
    label_trans_model_5->setText(
        QCoreApplication::translate("MainWindow", "Thickness", nullptr));
    pushButton_edge_color->setText(
        QCoreApplication::translate("MainWindow", "Edge Color", nullptr));
    label_vertexes_draw->setText(
        QCoreApplication::translate("MainWindow", "Vertexes", nullptr));
    radioButton_none->setText(
        QCoreApplication::translate("MainWindow", "None", nullptr));
    radioButton_circle->setText(
        QCoreApplication::translate("MainWindow", "Circle", nullptr));
    radioButton_square->setText(
        QCoreApplication::translate("MainWindow", "Square", nullptr));
    label_vertexes_size->setText(
        QCoreApplication::translate("MainWindow", "Size", nullptr));
    pushButton_vertex_color->setText(
        QCoreApplication::translate("MainWindow", "Vertex Color", nullptr));
    pushButton_vertex_color_2->setText(
        QCoreApplication::translate("MainWindow", "Set Background", nullptr));
    pushButton_screenshot->setText(
        QCoreApplication::translate("MainWindow", "Screeshot", nullptr));
    pushButton_gif->setText(
        QCoreApplication::translate("MainWindow", "GIF", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
