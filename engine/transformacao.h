//
// Created by eduardo on 28/03/21.
//

#ifndef GENERATOR_TRANSFORMACAO_H
#define GENERATOR_TRANSFORMACAO_H
#include <vector>


struct transformacao {
        float matriz[4][4];
        float time;
        std::vector<float> * pontos;
};

typedef struct transformacao * TRANSFORMACAO;


TRANSFORMACAO init_transformacao();
TRANSFORMACAO scale(float x, float y, float z);
TRANSFORMACAO translate(float x,float y,float z);
TRANSFORMACAO rotateX(float x, float y,float z,float angle);
TRANSFORMACAO rotateY(float x, float y,float z,float angle);
TRANSFORMACAO rotateZ(float x, float y,float z,float angle);
TRANSFORMACAO escolheRotate(float x,float y, float z,float  angle);
TRANSFORMACAO rotation_time(double x, double y, double z, double time);
TRANSFORMACAO translate_time(double time);
float * get_matrix(TRANSFORMACAO t);
float * calc_curve(TRANSFORMACAO t);
float * invert_order_matrix(float m[4][4]);
float * calc_rotation_time(TRANSFORMACAO t);
float to_radial(float angle);


#endif //GENERATOR_TRANSFORMACAO_H
