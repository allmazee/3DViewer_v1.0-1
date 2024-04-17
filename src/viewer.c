#include "viewer.h"

// int main() {
//  filedata_t filedata = {0};
//  // matrix_t M = {0};
//  int code = file_reader("objects/cube.obj", &filedata);
//  //center_model(&filedata);

//  return code;
// }

int file_reader(char *file_name, filedata_t *file_data) {
  FILE *ptr = NULL;
  int code = read_and_count(ptr, file_data, file_name);
  if (code == OK) {
    create_matrix(file_data->count_of_vertexes + 1, 3, &file_data->matrix_3d);
    code = read_and_save(ptr, file_name, file_data);
  }

  return code;
}

int read_and_save(FILE *ptr, char *filename, filedata_t *filedata) {
  int code = OK;
  ptr = fopen(filename, "r");
  if (ptr == NULL) {
    return EMPTY_FILE;
  }
  char line[255] = {0};
  double values[255] = {0};
  int i = 1;
  int vertex_count = 3;
  int polygons_counter = 0;
  filedata->polygons =
      (polygon_t *)malloc(sizeof(polygon_t) * (filedata->count_of_facets + 1));
  while (fgets(line, sizeof(line), ptr)) {
    if (line[0] == 'v' && line[1] == ' ') {
      code = save_matrix(line, values, &i, &filedata->matrix_3d, &vertex_count);
    } else if (line[0] == 'f' && line[1] == ' ') {
      code = save_polygons(line, &polygons_counter, filedata);
    }
    if (code != OK) {
      break;
    }
  }
  return code;
}

int save_polygons(char *line, int *polygons_counter, filedata_t *filedata) {
  int code = OK;
  char line_copy[255] = {0};
  strcpy(line_copy, line);
  filedata->polygons[*polygons_counter].number_of_vertexes_in_facets = 0;
  char *token = strtok(line, " ");
  while (token != NULL) {
    token = strtok(NULL, " ");
    if (token != NULL) {
      filedata->polygons[*polygons_counter].number_of_vertexes_in_facets++;
    }
  }
  filedata->polygons[*polygons_counter].vertexes = (int *)malloc(
      sizeof(unsigned int) *
      filedata->polygons[*polygons_counter].number_of_vertexes_in_facets);
  char *token_2 = strtok(line_copy, " ");
  int k = 0;
  while (token_2 != NULL) {
    token_2 = strtok(NULL, " ");
    if (token_2 != NULL) {
      filedata->polygons[*polygons_counter].vertexes[k] = atoi(token_2);
    }
    k++;
  }
  if (k < 2) {
    code = POLYGON_COUNT_ERROR;
  }
  (*polygons_counter)++;
  return code;
}

int save_matrix(char *line, double *values, int *i, matrix_t *M,
                int *vertex_count) {
  int code = OK;
  int numbers_found = 0;
  char *token = strtok(line, " ");
  while (token != NULL) {
    token = strtok(NULL, " ");
    if (token != NULL) {
      values[numbers_found++] = strtod(token, NULL);
    }
  }
  if (numbers_found != 3) {
    code = VERTEX_COUNT_ERROR;
  }
  int v = 0;
  if (*i < M->rows) {
    for (int j = 0; j < *vertex_count; j++) {
      M->matrix[*i][j] = values[v];
      v++;
    }
    (*i)++;
  }
  return code;
}

int read_and_count(FILE *ptr, filedata_t *file_data, char *filename) {
  char ch[200] = {0};
  ptr = fopen(filename, "r");
  if (ptr == NULL) {
    return FILE_NOT_FOUND;
  }
  while (!feof(ptr)) {
    if (fgets(ch, 3, ptr)) {
      if (ch[0] == 'v' && ch[1] == ' ') {
        file_data->count_of_vertexes++;
      } else if (ch[0] == 'f' && ch[1] == ' ') {
        file_data->count_of_facets++;
      }
    }
  }
  fclose(ptr);
  if (file_data->count_of_vertexes < 3 || file_data->count_of_facets < 1) {
    return EMPTY_FILE;
  }
  return OK;
}

void create_matrix(int rows, int columns, matrix_t *result) {
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->cols = columns;
    double **matrix = (double **)calloc(rows, sizeof(double *));
    double *values = (double *)calloc(rows * columns, sizeof(double));
    if (matrix != NULL && values != NULL) {
      for (int i = 0; i < rows; i++) {
        matrix[i] = values + columns * i;
      }
      result->matrix = matrix;
    } else {
      free(matrix);
      free(values);
      remove_matrix(result);
    }
  } else {
    result->matrix = NULL;
  }
}

void remove_matrix(matrix_t *A) {
  if (is_null(A) == OK) {
    if (A->matrix) {
      if (A->matrix[0]) free(A->matrix[0]);
      free(A->matrix);
      if (A->rows) {
        A->rows = 0;
      }
      if (A->cols) {
        A->cols = 0;
      }
      A->matrix = NULL;
    }
  }
}

void remove_polygons(polygon_t *polygon, int p_counter) {
  for (int i = 0; i < p_counter; i++) {
    free(polygon[i].vertexes);
    polygon[i].vertexes = NULL;
  }
  polygon->number_of_vertexes_in_facets = 0;
}

int is_null(matrix_t *A) { return A->matrix != NULL ? OK : INCORRECT_MATRIX; }
