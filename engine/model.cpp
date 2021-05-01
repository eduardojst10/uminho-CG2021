//
// Created by eduardo on 11/03/21.
//

#include <GL/glew.h>
#include <GL/glut.h>
#include "model.h"
#include "engine.h"
#include "transformacao.h"
#include <vector>
#include <iostream>
#include <cstdlib>



MODEL init_model(){
    MODEL m = (MODEL) malloc(sizeof(struct model));
    m->pontos = new std::vector<VERTICE>();
    m->transformacoes = new std::vector<TRANSFORMACAO>();
    return m;
}

void add_Vertices(MODEL m, std::vector<VERTICE> v) {
    if (m) {
        for (int i = 0; i < v.size(); i++) {
            m->pontos->push_back(v[i]);

        }
    }

}

/**
 * Função que adiciona um transformacao
 * @param g
 * @param t
 */
void add_transformacao(MODEL m,std::vector<TRANSFORMACAO> t){
    if(m){
        for(TRANSFORMACAO tr: t)
            m->transformacoes->push_back(tr);

    }
}


/**
 * Funcao que aplica uma transformacao a um vértice
 * @param v
 * @param t
 */
void transforma_vertice(VERTICE  v, TRANSFORMACAO t){
    VERTICE vertice = (VERTICE)malloc(sizeof(struct vertice));
    for(int i=0;i<4;i++){
        vertice->pontos[i] = 0;
    }


    for(int l=0;l<4;++l){ //vertice vai ficar com a transformacao
        for(int c=0;c<4;++c){
            vertice->pontos[l]+= t->matriz[l][c] * v->pontos[c];


        }
        std::cout << "\n";
    }

    for(int j=0; j<4;++j){
        v->pontos[j]=vertice->pontos[j];

    }

}


bool tem_Transformacoes(MODEL m){
    return !m->transformacoes->empty();
}

/**
 * Funcao que aplica todas as transformacoes a todos os vertices que o model tem
 * @param m
 */
void aplica_transformacoesm(MODEL m){
    //std::cout << m->transformacoes->size() << "\n";
    if(m->transformacoes->empty()) std::cout << "SEM TRANSFORMACOES" << "\n";
    else
    {
        for (int i = 0; i < m->transformacoes->size(); ++i) {
            TRANSFORMACAO t = m->transformacoes->at(i);
            //std::cout << "ITERACAO:" << i << "\n";
            //printMatriz(t);
            for (int v = 0; v < m->pontos->size(); v++) {
                VERTICE vertice = (VERTICE) malloc(sizeof(struct vertice));
                vertice = m->pontos->at(v);
                //std::cout << v << "\n";
                transforma_vertice(vertice, t);
            }

            //std::cout << "AQUI 5" << "\n";
        }
    }
}

/**
 * Funçao que desenha o modelo
 * @param m
 */


void drawModel(MODEL model){
    glBegin(GL_TRIANGLES);

    for(int i=0; i<model->pontos->size();i+=3){
        VERTICE v = model->pontos->at(i);
        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f(v->pontos[0], v->pontos[1], v->pontos[2]);
        v = model->pontos->at(i+1);
        //glColor3f(1.0f,0.0f,1.0f);
        glVertex3f(v->pontos[0], v->pontos[1], v->pontos[2]);
        v= model->pontos->at(i+2);
        //glColor3f(0.0f,1.0f,1.0f);
        glVertex3f(v->pontos[0], v->pontos[1], v->pontos[2]);

    }
    glEnd();
}

void printMatriz(TRANSFORMACAO t){
    for(int l = 0; l<4;l++){
        for(int c=0;c<4;c++){
            std::cout << "|" << t->matriz[l][c] << "|";
        }
        std::cout << "\n";
    }
}


void init_vbo_model(MODEL m) {
    if (m) {
        std::vector<float> vertices;

        for (int i = 0; i < m->pontos->size(); ++i){
            for (int j = 0; j< 4; j++)
            {
                VERTICE v;
                v=m->pontos->at(i);
                vertices.push_back(v->pontos[j]);
            }
            
        }


        float * aux = &vertices[0];

        glGenBuffers(1, m->vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m->vertexBuffer[0]);
        glBufferData(GL_ARRAY_BUFFER, m->pontos->size() * sizeof(float), aux, GL_STATIC_DRAW);
    }
}


void draw_modelVBO(MODEL m) {

    std::vector<float> vertices;

    for (int i = 0; i < m->pontos->size(); ++i){
        for (int j = 0; j< 4; j++)
        {
            VERTICE v;
            v=m->pontos->at(i);
            vertices.push_back(v->pontos[j]);
        }
            
   }

    glBindBuffer(GL_ARRAY_BUFFER,m->vertexBuffer[0]);
    glVertexPointer(3,GL_FLOAT,0, 0);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}