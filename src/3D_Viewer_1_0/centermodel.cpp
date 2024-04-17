#include "centermodel.h"

void center_model(filedata_t *file_data) {
  double minX, maxX, minY, maxY, minZ, maxZ;
  find_min_max_coords(file_data, &minX, &minY, &minZ, &maxX, &maxY, &maxZ);

  double centerX = minX + (maxX - minX) / 2;
  double centerY = minY + (maxY - minY) / 2;
  double centerZ = minZ + (maxZ - minZ) / 2;

  for (unsigned int i = 1; i < file_data->count_of_vertexes; ++i) {
    file_data->matrix_3d.matrix[i][0] -= centerX;
    file_data->matrix_3d.matrix[i][1] -= centerY;
    file_data->matrix_3d.matrix[i][2] -= centerZ;
  }

  double max = dmax(&minX, &minY, &minZ, &maxX, &maxY, &maxZ);
  double scale = (SCALE_VALUE + SCALE_VALUE) / max;
  scale_model(&file_data->matrix_3d, scale);
}

void find_min_max_coords(filedata_t *file_data, double *minX, double *minY,
                         double *minZ, double *maxX, double *maxY,
                         double *maxZ) {
  *minX = file_data->matrix_3d.matrix[1][0];
  *maxX = file_data->matrix_3d.matrix[1][0];
  *minY = file_data->matrix_3d.matrix[1][1];
  *maxY = file_data->matrix_3d.matrix[1][1];
  *minZ = file_data->matrix_3d.matrix[1][2];
  *maxZ = file_data->matrix_3d.matrix[1][2];

  for (unsigned int i = 1; i < file_data->count_of_vertexes; ++i) {
    double x = file_data->matrix_3d.matrix[i][0];
    double y = file_data->matrix_3d.matrix[i][1];
    double z = file_data->matrix_3d.matrix[i][2];

    *minX = (x < *minX) ? x : *minX;
    *minY = (y < *minY) ? y : *minY;
    *minZ = (z < *minZ) ? z : *minZ;

    *maxX = (x > *maxX) ? x : *maxX;
    *maxY = (y > *maxY) ? y : *maxY;
    *maxZ = (z > *maxZ) ? z : *maxZ;
  }
}

double dmax(double *minX, double *minY, double *minZ, double *maxX,
            double *maxY, double *maxZ) {
  double dmax = 0, dx = 0, dy = 0, dz = 0;
  dx = *maxX - *minX;
  dy = *maxY - *minY;
  dz = *maxZ - *minZ;
  dmax = dx;
  if (dy > dmax) dmax = dy;
  if (dz > dmax) dmax = dz;
  return dmax;
}
