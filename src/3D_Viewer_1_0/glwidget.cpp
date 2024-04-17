#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void GLWidget::loadFile(const QString &filename) { currentFilename = filename; }

unsigned int GLWidget::getVertexCount() { return file_data.count_of_vertexes; }

unsigned int GLWidget::getFacetCount() { return file_data.count_of_facets; }

void GLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void GLWidget::resizeGL(int w, int h) {}

void GLWidget::paintGL() {
  setProjection();
  glClearColor(back_color.redF(), back_color.greenF(), back_color.blueF(),
               1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  drawVertices();
  drawEdges();
  update();
}

void GLWidget::drawVertices() {
  if (vertex_display == none) {
    return;
  }
  if (vertex_display == circle) {
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }
  glPointSize(vertex_size);
  glColor3d(vertex_color.redF(), vertex_color.greenF(), vertex_color.blueF());
  glBegin(GL_POINTS);
  for (size_t i = 1; i <= file_data.count_of_vertexes; i++) {
    double x = file_data.matrix_3d.matrix[i][0];
    double y = file_data.matrix_3d.matrix[i][1];
    double z = file_data.matrix_3d.matrix[i][2];
    glVertex3d(x, y, z);
  }
  glEnd();
}

void GLWidget::drawEdges() {
  if (!fileSelected) {
    return;
  }
  glColor3d(edge_color.redF(), edge_color.greenF(), edge_color.blueF());
  glLineWidth(line_thickness);
  glLineStipple(1, 0x00F0);
  if (line_solid) {
    glDisable(GL_LINE_STIPPLE);
  } else {
    glEnable(GL_LINE_STIPPLE);
  }
  // size_t num_of_v_in_faces = 0;
  for (size_t i = 0; i < file_data.count_of_facets; ++i) {
    const auto &face = file_data.polygons[i];
    // if (face.number_of_vertexes_in_facets > 3) {
    //   num_of_v_in_faces = 3;
    // } else {
    //   num_of_v_in_faces = 2;
    // }
    glBegin(GL_LINES);
    const auto &first_point = face.vertexes[0];
    glVertex3d(file_data.matrix_3d.matrix[first_point][0],
               file_data.matrix_3d.matrix[first_point][1],
               file_data.matrix_3d.matrix[first_point][2]);
    for (size_t j = 1; j < 3; j++) {  // num_of_v_in_faces
      const auto &point = face.vertexes[j];
      glVertex3d(file_data.matrix_3d.matrix[point][0],
                 file_data.matrix_3d.matrix[point][1],
                 file_data.matrix_3d.matrix[point][2]);
      glVertex3d(file_data.matrix_3d.matrix[point][0],
                 file_data.matrix_3d.matrix[point][1],
                 file_data.matrix_3d.matrix[point][2]);
    }
    glVertex3d(file_data.matrix_3d.matrix[first_point][0],
               file_data.matrix_3d.matrix[first_point][1],
               file_data.matrix_3d.matrix[first_point][2]);
    glEnd();
  }
}

void GLWidget::setProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  GLfloat fov = 60.0 * M_PI / 180;
  GLfloat near = 1 / tan(fov / 2);
  if (projection == 0) {
    glOrtho(-2., 2., -2., 2., -10, 10.);
  } else {
    glFrustum(-0.8, 0.8, -0.8, 0.8, near, 100.);
    glTranslated(0, 0, -3);
  }
}
