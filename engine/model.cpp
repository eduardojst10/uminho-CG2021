//
// Created by eduardo on 11/03/21.
//

#include "model.h"
#include "engine.h"
#include <vector>
#include <cstdlib>
#include <GL/gl.h>

struct model {
    std::vector<vertice> * pontos;
};



MODEL init_model(){
    MODEL m = (MODEL) malloc(sizeof(struct model));
    m->pontos = new std::vector<vertice>();
    return m;
}

void add_Vertices(MODEL m, std::vector<vertice> v) {
    if (m) {
        for (int i = 0; i < v.size(); i++) {
            m->pontos->push_back(v[i]);

        }
    }

}
/*

void drawModel(MODEL m){
    glBegin(GL_TRIANGLES);
    for(int i=0; i< m->pontos->size();i+=3){
        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f(m->pontos[i].x,m->pontos[i].y,m->pontos[i].z);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f(m->pontos[i+1].x,m->pontos[i+1].y,m->pontos[i+1].z);
        glColor3f(0.0f,1.0f,1.0f);
        glVertex3f(m->pontos[i+2].x,m->pontos[i+2].y,m->pontos[i+2].z);
    }
    glEnd();
}
 */
