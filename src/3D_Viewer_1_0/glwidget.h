#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QtOpenGLWidgets>

extern "C" {
#include "../viewer.h"
}

enum MyDisplay { none = 0, circle, square };

class GLWidget : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit GLWidget(QWidget *parent = nullptr);
  void loadFile(const QString &filename);
  unsigned int getVertexCount();
  unsigned int getFacetCount();

  filedata_t file_data = {0, 0, {0, 0, 0}, 0};
  rotation rotate = {0, 0, 0, 0, 0, 0};
  movement move = {0, 0, 0, 0, 0, 0};

  QString currentFilename;
  double minX, maxX, minY, maxY;

  double scale_val = 1.0;
  double scale_x, scale_y, scale_z;

  int projection = 0;
  bool line_solid = true;  // dashed => false
  GLfloat line_thickness = 1.;
  int vertex_display = none;
  GLfloat vertex_size = 1.;
  QColor edge_color;
  QColor vertex_color;
  QColor back_color;
  bool fileSelected = false;

 protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

 private:
  //    QString currentFilename;
  //  double xRot, yRot;
  void setProjection();
  void drawVertices();
  void drawEdges();

 signals:
};

#endif  // GLWIDGET_H
