#include "viewer.h"

/*
 * @brief оцентровка фигуры при открытии
 * формула для нахождения центра по Х (подходит и для У и Z)
 * minX + (maxX - minX) / 2 = centerX
 *
 * подходит и для У и Z
 * x -= centerX
 */

void move_x(matrix_t *A, double a) {
  for (int i = 1; i < A->rows; i++) {
    A->matrix[i][0] += a;
  }
}

void move_y(matrix_t *A, double a) {
  for (int i = 1; i < A->rows; i++) {
    A->matrix[i][1] += a;
  }
}

void move_z(matrix_t *A, double a) {
  for (int i = 1; i < A->rows; i++) {
    A->matrix[i][2] += a;
  }
}

void rotation_by_ox(matrix_t *A, double angle) {
  angle *= M_PI / 180;
  for (int i = 1; i < A->rows; i++) {
    double temp_y = A->matrix[i][1];
    double temp_z = A->matrix[i][2];
    A->matrix[i][1] = cos(angle) * temp_y - sin(angle) * temp_z;
    A->matrix[i][2] = sin(angle) * temp_y + cos(angle) * temp_z;
  }
}

void rotation_by_oy(matrix_t *A, double angle) {
  angle *= M_PI / 180;
  for (int i = 1; i < A->rows; i++) {
    double temp_x = A->matrix[i][0];
    double temp_z = A->matrix[i][2];
    A->matrix[i][0] = cos(angle) * temp_x + sin(angle) * temp_z;
    A->matrix[i][2] = -sin(angle) * temp_x + cos(angle) * temp_z;
  }
}

void rotation_by_oz(matrix_t *A, double angle) {
  angle *= M_PI / 180;
  for (int i = 1; i < A->rows; i++) {
    double temp_x = A->matrix[i][0];
    double temp_y = A->matrix[i][1];
    A->matrix[i][0] = cos(angle) * temp_x - sin(angle) * temp_y;
    A->matrix[i][1] = sin(angle) * temp_x + cos(angle) * temp_y;
  }
}

void scale_model(matrix_t *A, double scale) {
  for (int i = 1; i < A->rows; i++) {
    A->matrix[i][0] = A->matrix[i][0] * scale;
    A->matrix[i][1] = A->matrix[i][1] * scale;
    A->matrix[i][2] = A->matrix[i][2] * scale;
  }
}
