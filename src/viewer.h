#ifndef VIEWER_H
#define VIEWER_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define ERROR 2
#define FILE_NOT_FOUND 3
#define EMPTY_FILE 4
#define POLYGON_COUNT_ERROR 5
#define VERTEX_COUNT_ERROR 6

#define SUCCESS 1
#define FAILURE 0

// #define M_PI 3.141592653589793

#define SCALE_VALUE 1

typedef struct Matrix {
  double **matrix;
  int rows;
  int cols;
} matrix_t;

/**
 * @brief структура полигона
 *
 * @param vertexes - массив номеров вершин, которые мы будем хранить для
 * соединений
 * @param number_of_vertexes_in_facets - кол-во вершин необходимых для
 * соединения
 */
typedef struct facets {
  int *vertexes;
  unsigned number_of_vertexes_in_facets;
} polygon_t;

/**
 * @brief структура для считывания файла
 *
 * @param count_of_vertexes - кол-во вершин
 * @param count_of_facets - кол-во полигонов
 * @param matrix_3d - матрица, где индекс строки = индекс вершины, выделение
 * памяти для рядов - count_of_vertexes + 1
 * @param polygons - массив структур, размер count_of_facets + 1
 */
typedef struct filedata {
  unsigned int count_of_vertexes;
  unsigned int count_of_facets;
  matrix_t matrix_3d;
  polygon_t *polygons;
} filedata_t;

typedef struct rotate_model {
  double ox;
  double oy;
  double oz;
  double prevX;
  double prevY;
  double prevZ;
} rotation;

typedef struct move_model {
  double ox;
  double oy;
  double oz;
  double mvPrevX;
  double mvPrevY;
  double mvPrevZ;
} movement;

int file_reader(char *file_name, filedata_t *file_data);
void create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);
void remove_polygons(polygon_t *polygon, int p_counter);
int is_null(matrix_t *A);
int read_and_count(FILE *ptr, filedata_t *file_data, char *filename);
int read_and_save(FILE *ptr, char *filename, filedata_t *filedata);
int save_polygons(char *line, int *polygons_counter, filedata_t *filedata);
int save_matrix(char *line, double *values, int *i, matrix_t *M,
                int *vertex_count);

void print_matrix(matrix_t *M);
void print_polygons(filedata_t *file_data);

void move_x(matrix_t *A, double a);
void move_y(matrix_t *A, double a);
void move_z(matrix_t *A, double a);

void rotation_by_ox(matrix_t *A, double angle);
void rotation_by_oy(matrix_t *A, double angle);
void rotation_by_oz(matrix_t *A, double angle);

void scale_model(matrix_t *A, double scale);

#endif  // VIEWER_H
