#ifndef ENGINE_CATMULL_H
#define ENGINE_CATMULL_H
#include "transformacao.h"

float * calcula_catmull(float time, std::vector<float> * v);
void add_points_catmull(TRANSFORMACAO t, float x,float y, float z);

#endif //ENGINE_CATMULL_H