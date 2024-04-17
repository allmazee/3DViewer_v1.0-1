#ifndef CENTERMODEL_H
#define CENTERMODEL_H

#include "glwidget.h"

void center_model(filedata_t *file_data);
void find_min_max_coords(filedata_t *file_data, double *minX, double *minY,
                         double *minZ, double *maxX, double *maxY,
                         double *maxZ);
double dmax(double *minX, double *minY, double *minZ, double *maxX,
            double *maxY, double *maxZ);

#endif  // CENTERMODEL_H
