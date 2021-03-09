//
// Created by eduardo on 09/03/21.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>n
#include <cstring>
#include <iosfwd>
#include "engine.h"

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if(h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}



std::vector<Vertice> renderModel(std::string modelo){
    m = "../files/" + modelo;
    std::vector<Vertice> model;
    ifstream file(m);
    if(files.is_open()){
        int nr_vertices = atoi(getline(file,linha));
        Vertice *v;
        while(getline(file,linha)){
                coord_x = strsep(linha,",");
                v->x = atof(coord_x);
                coord_y = strsep(linha,",");
                v->y = atof(coord_y);
                coord_z = strsep(linha,",");
                v->z = atof(coord_z);
                model.push_back(v);
        }

    }

    return model;


}



std::vector<string> parseXml(std::string file){
    TiXmlDocument doc(file);
    doc.LoadFile();
    std::vector<string> res;
    TiXmlElement* root = doc.FirstChildElement("scene");
    if(root){
        TiXmlElement* model = root -> FirstChildElement();
        if(model){
            //needs further testing
            res.push_back(model->Attribute());

            TiXmlElement* nextModel = model -> NextSiblingElement();

            while(nextModel){
                model = nextModel;
                nextModel = model -> NextSiblingElement();
                res.push_back(model->Attribute());
            }
        }
    }

    return res;
}


void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(5.0,5.0,5.0,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);

    //Eixos
    glBegin(GL_LINES)
    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-100.0f, 0.0f, 0.0f);
    glVertex3f( 100.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -100.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();



    // put drawing instructions here


    // End of frame
    glutSwapBuffers();
}



// write function to process keyboard events




int main(int argc, char **argv) {

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI-UM");

// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);


// put here the registration of the keyboard callbacks



//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
