//
// Created by eduardo on 28/03/21.
//
#include <GL/glew.h>
#include <GL/glut.h>
#include "transformacao.h"
#include "catmull.h"
#include <cmath>
#include <math.h>
#include <iostream>


/**
 * Inicia uma matriz ID
 * @return
 */

TRANSFORMACAO init_transformacao(){
    TRANSFORMACAO  t = (TRANSFORMACAO) malloc(sizeof (struct transformacao));
    for(int l=0;l<4;l++){
        for(int c=0;c<4;c++){
            if(l==c) t->matriz[l][c] = 1; //matriz identidade

            else t->matriz[l][c] = 0;
        }
    }
    t->time = 0;
    t->pontos = nullptr;
    return t;
}

/**
 * Criar Matriz de escala
 * @param x
 * @param y
 * @param z
 * @return
 */
TRANSFORMACAO scale(float x, float y, float z){
    TRANSFORMACAO t =init_transformacao();
    t->matriz[0][0] = t->matriz[0][0]*x;
    t->matriz[1][1] = t->matriz[1][1]*y;
    t->matriz[2][2] = t->matriz[2][2]*z;
    return t;
}
/**
 * Criar matriz de translação
 * @param x
 * @param y
 * @param z
 * @return
 */
TRANSFORMACAO translate(float x,float y,float z){
    TRANSFORMACAO  t = init_transformacao();
    t->matriz[0][3]=x;
    t->matriz[1][3]=y;
    t->matriz[2][3]=z;
    return t;
}

/**
 * Criar Matriz de rotacao no eixo do X
 * @param x
 * @param y
 * @param z
 * @param angle
 * @return
 */
TRANSFORMACAO rotateX(float x, float y,float z,float angle){
    TRANSFORMACAO t = init_transformacao();
    float radiano = angle / 360.f * M_PI * 2;
    t->matriz[0][0]= 1;
    t->matriz[0][1]= 0;
    t->matriz[0][2]= 0;

    t->matriz[1][0]=0;
    t->matriz[1][1]=cos(radiano);
    t->matriz[1][2]=-sin(radiano);

    t->matriz[2][0]=0;
    t->matriz[2][1]=sin(radiano);
    t->matriz[2][2]=cos(radiano);
    return t;
}

/**
 * Criar Matriz de rotacao no eixo do Y
 * @param x
 * @param y
 * @param z
 * @param angle
 * @return
 */

TRANSFORMACAO  rotateZ(float x,float y, float z,float  angle){
    TRANSFORMACAO t = init_transformacao();
    float radiano = angle / 360.f * M_PI * 2;
    t->matriz[0][0]= cos(radiano);
    t->matriz[0][1]= 0;
    t->matriz[0][2]= sin(radiano);

    t->matriz[1][0]=0;
    t->matriz[1][1]=1;
    t->matriz[1][2]=0;

    t->matriz[2][0]=-sin(radiano);
    t->matriz[2][1]=0;
    t->matriz[2][2]=cos(radiano);
    return t;
}

/**
 * Criar Matriz de rotacao no eixo do Z
 * @param x
 * @param y
 * @param z
 * @param angle
 * @return
 */

TRANSFORMACAO rotateY(float x,float y, float z,float  angle){
    TRANSFORMACAO t = init_transformacao();
    float radiano = angle / 360.f * M_PI * 2;
    t->matriz[0][0]= cos(radiano);
    t->matriz[0][1]= -sin(radiano);
    t->matriz[0][2]= 0;

    t->matriz[1][0]=sin(radiano);
    t->matriz[1][1]=cos(radiano);
    t->matriz[1][2]=0;

    t->matriz[2][0]=0;
    t->matriz[2][1]=0;
    t->matriz[2][2]=1;
    return t;
}


TRANSFORMACAO escolheRotate(float x,float y, float z,float  angle) {
    if (x == 1) return rotateX(x, y, z, angle);
    if (y == 1) return rotateY(x, y, z, angle);
    if (z == 1) return rotateZ(x, y, z, angle);

    else {
        std::cout << "ERRO"<< "\n";
        return NULL;

    }
}


TRANSFORMACAO translate_time(double time){
    TRANSFORMACAO t = init_transformacao();
    t->time = time;
    t->pontos = new std::vector<float>();
    return t;
}

float * get_matrix(TRANSFORMACAO t) {
    if (t->time > 0) return calcula_curve(t);
    else return invert_order_matrix(t->matriz);
}

float * calcula_curve(TRANSFORMACAO t) {
    float * r;

    if (t->pontos) r = calcula_catmull(t->time,t->pontos);
    else r = calcula_rotation_time(t);

    return r;
}

float * invert_order_matrix(float m[4][4]){
    static float r[4*4];

    for (int i = 0; i < 4*4; ++i) {
        r[i] = m[i%4][i/4];
    }

    return r;
}

float * calcula_rotation_time(TRANSFORMACAO t) {
    float x = t->matriz[0][0];
    float y = t->matriz[0][1];
    float z = t->matriz[0][2];
    float angle = to_radial(glutGet(GLUT_ELAPSED_TIME) * 360.f / t->time);
    float aux[4][4];
    TRANSFORMACAO ta = init_transformacao();
    ta=escolheRotate(x,y,z,angle);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            aux[i][j]=ta->matriz[i][j];
    

    return invert_order_matrix(aux);
}

float to_radial(float angle) {
    return angle / 360.f * M_PI * 2;
}