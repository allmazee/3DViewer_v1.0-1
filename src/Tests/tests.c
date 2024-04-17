#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../viewer.h"

/**
 * @brief parser_test
 *
 */

START_TEST(parser_diamond) {
  filedata_t filedata = {0};
  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/diamond.obj");

  int err = file_reader(path, &filedata);

  ck_assert_int_eq(OK, err);
  ck_assert_int_eq(filedata.count_of_vertexes, 6);
  ck_assert_int_eq(filedata.count_of_facets, 9);

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, 9);
  free(filedata.polygons);
}
END_TEST

START_TEST(parser_file_not_found) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/nofile.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(FILE_NOT_FOUND, err);
  free(path);
}
END_TEST

START_TEST(parser_empty_file) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/nothing.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(EMPTY_FILE, err);
  free(path);
}
END_TEST

/**
 * @brief transformations_test
 *
 */

START_TEST(move_x_diamond) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/diamond.obj");
  int err = file_reader(path, &filedata);
  ck_assert_int_eq(OK, err);

  double a = 2.0;
  move_x(&filedata.matrix_3d, a);

  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[1][0], 0.000000E+00 + a,
                          1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[2][0], 45.0000 + a, 1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[3][0], 45.0000 + a, 1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[4][0], -45.0000 + a, 1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[5][0], -45.0000 + a, 1e-7);

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, filedata.count_of_facets);
  free(filedata.polygons);
}
END_TEST

START_TEST(move_y_diamond) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/diamond.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(OK, err);

  double a = 2.0;
  move_y(&filedata.matrix_3d, a);

  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[1][1], 0.0 + a, 1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[2][1], 45.0000 + a, 1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[3][1], -45.0000 + a, 1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[4][1], -45.0000 + a, 1e-7);

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, filedata.count_of_facets);
  free(filedata.polygons);
}
END_TEST

START_TEST(move_z_diamond) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/diamond.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(OK, err);

  double a = 2.0;
  move_z(&filedata.matrix_3d, a);

  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[1][2], 78.0000 + a, 1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[2][2], 0.000000E+00 + a,
                          1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[3][2], 0.000000E+00 + a,
                          1e-7);
  ck_assert_double_eq_tol(filedata.matrix_3d.matrix[4][2], 0.000000E+00 + a,
                          1e-7);

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, filedata.count_of_facets);
  free(filedata.polygons);
}
END_TEST

START_TEST(rotation_by_ox_cube) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/cube.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(OK, err);

  double angle = 120;
  rotation_by_ox(&filedata.matrix_3d, angle);

  double result[9][3] = {{0, 0, 0},
                         {1.000000, -1.321027, 0.504863},
                         {1.000000, 0.504863, 1.321027},
                         {-1.000000, 0.504863, 1.321027},
                         {-1.000000, -1.321027, 0.504863},
                         {1.000000, -0.504863, -1.321027},
                         {1.000000, 1.321027, -0.504863},
                         {-1.000000, 1.321027, -0.504863},
                         {-1.000000, -0.504863, -1.321027}};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; i < 3; i++) {
      ck_assert_float_eq_tol(result[i][j], filedata.matrix_3d.matrix[i][j],
                             1e-06);
    }
  }

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, filedata.count_of_facets);
  free(filedata.polygons);
}
END_TEST

START_TEST(rotation_by_oy_cube) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/cube.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(OK, err);

  double angle = 94;
  rotation_by_oy(&filedata.matrix_3d, angle);

  double result[9][3] = {{0, 0, 0},
                         {-1.067321, -1.000000, -0.927808},
                         {0.927808, -1.000000, -1.067321},
                         {1.067321, -1.000000, 0.927808},
                         {-0.927808, -1.000000, 1.067321},
                         {-1.067321, 1.000000, -0.927808},
                         {0.927808, 1.000000, -1.067321},
                         {1.067321, 1.000000, 0.927808},
                         {-0.927808, 1.000000, 1.067321}};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; i < 3; i++) {
      ck_assert_float_eq_tol(result[i][j], filedata.matrix_3d.matrix[i][j],
                             1e-06);
    }
  }

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, filedata.count_of_facets);
  free(filedata.polygons);
}
END_TEST

START_TEST(rotation_by_oz_cube) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/cube.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(OK, err);

  double angle = 100;
  rotation_by_oz(&filedata.matrix_3d, angle);

  double result[9][3] = {{0, 0, 0},
                         {0.811160, 1.158456, -1.000000},
                         {0.811160, 1.158456, 1.000000},
                         {1.158456, -0.811160, 1.000000},
                         {1.158456, -0.811160, -1.000000},
                         {-1.158456, 0.811160, -1.000000},
                         {-1.158456, 0.811160, 1.000000},
                         {-0.811160, -1.158456, 1.000000},
                         {-0.811160, -1.158456, -1.000000}};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; i < 3; i++) {
      ck_assert_float_eq_tol(result[i][j], filedata.matrix_3d.matrix[i][j],
                             1e-06);
    }
  }

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, filedata.count_of_facets);
  free(filedata.polygons);
}
END_TEST

START_TEST(scale_cube) {
  filedata_t filedata = {0};

  char *path = (char *)calloc(PATH_MAX, sizeof(char));
  strcat(path, "objects/cube.obj");

  int err = file_reader(path, &filedata);
  ck_assert_int_eq(OK, err);

  double value = 4;
  float prev = 2;

  scale_model(&filedata.matrix_3d, value * prev);

  double result[9][3] = {{0, 0, 0},
                         {8.00, -8.00, -8.00},
                         {8.00, -8.00, 8.00},
                         {-8.00, -8.00, 8.00},
                         {-8.00, -8.00, -8.00},
                         {8.00, 8.00, -8.00},
                         {8.00, 8.00, 8.00},
                         {-8.00, 8.00, 8.00},
                         {-8.00, 8.00, -8.00}};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; i < 3; i++) {
      ck_assert_float_eq_tol(result[i][j], filedata.matrix_3d.matrix[i][j],
                             1e-06);
    }
  }

  free(path);
  remove_matrix(&filedata.matrix_3d);
  remove_polygons(filedata.polygons, filedata.count_of_facets);
  free(filedata.polygons);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("unit_testing");
  TCase *tc1_1 = tcase_create("parser_test");
  TCase *tc1_2 = tcase_create("transformations_test");

  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, parser_diamond);
  tcase_add_test(tc1_1, parser_file_not_found);
  tcase_add_test(tc1_1, parser_empty_file);

  suite_add_tcase(s1, tc1_2);
  tcase_add_test(tc1_2, move_x_diamond);
  tcase_add_test(tc1_2, move_y_diamond);
  tcase_add_test(tc1_2, move_z_diamond);
  tcase_add_test(tc1_2, rotation_by_ox_cube);
  tcase_add_test(tc1_2, rotation_by_oy_cube);
  tcase_add_test(tc1_2, rotation_by_oz_cube);
  tcase_add_test(tc1_2, scale_cube);

  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}