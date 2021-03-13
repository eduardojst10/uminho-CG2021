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


void drawModel(MODEL m){
    glBegin(GL_TRIANGLES);
    vertice v;
    for(int i=0; i<m->pontos->size();i+=3){
        v = m->pontos->at(i);
        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f(v.x,v.y,v.z);
        v = m->pontos->at(i+1);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f(v.x,v.y,v.z);
        v= m->pontos->at(i+2);
        glColor3f(0.0f,1.0f,1.0f);
        glVertex3f(v.x,v.y,v.z);
    }
    glEnd();
}


