//
// Created by eduardo on 11/03/21.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdlib>
#include <string>
#include <vector>
#include "engine.h"
#include "transformacao.h"

#ifndef GENERATOR_MODEL_H
#define GENERATOR_MODEL_H

struct model {
    std::vector<VERTICE> * pontos;
    std::vector<TRANSFORMACAO> * transformacoes;
    GLuint vertexBuffer[1];
};
typedef struct model * MODEL;

MODEL init_model();
void add_Vertices(MODEL m, std::vector<VERTICE> v);
void add_transformacao(MODEL m,std::vector<TRANSFORMACAO> t);
bool tem_Transformacoes(MODEL m);
void transforma_vertice(VERTICE v, TRANSFORMACAO t);
void aplica_transformacoesm(MODEL m);
void drawModel(MODEL m);
void printMatriz(TRANSFORMACAO t);
void init_vbo_model(MODEL m);
void draw_modelVBO(MODEL m);

#endif