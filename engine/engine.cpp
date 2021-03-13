//
// Created by eduardo on 09/03/21.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include "tinyxml/tinyxml.cpp"
#include "tinyxml/tinyxml.h"
#include "tinyxml/tinyxmlerror.cpp"
#include "tinyxml/tinyxmlparser.cpp"
#include "tinyxml/tinystr.cpp"
#include "tinyxml/tinystr.h"
#include "engine.h"
#include "scene.h"
#include "model.h"
using namespace std;


SCENE models_scene = NULL;




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

/**
 * Função que vai ver o modelo e preencher o vector com os vértices, auxiliar de parse_All_models(vector<string> modelos)
 * @param modelo
 * @return
 */

vector<vertice> fill_Model(string modelo){
    modelo = "../files_draw/" + modelo;
    vector<vertice> model;
    ifstream file(modelo);
    string linha;
    string token_del = ",";
    int nr_vertices,pos;
    if(file.is_open()){
        getline(file,linha);
        nr_vertices = atoi(linha.c_str());//const char* to str

        vertice v;
        while(getline(file,linha)){
                //float x
                pos = linha.find(token_del);
                string coord_x = linha.substr(0,pos);
                linha.erase(0, pos + token_del.length());
                v.x = atof(coord_x.c_str());


                //float y
                pos = linha.find(token_del);
                string coord_y = linha.substr(0,pos);
                linha.erase(0, pos + token_del.length());
                v.y = atof(coord_y.c_str());


                //float z
                pos = linha.find(token_del);
                string coord_z = linha.substr(0,pos);
                linha.erase(0, pos + token_del.length());
                v.z = atof(coord_z.c_str());


                model.push_back(v);
        }

    }else {
        cout << "ERRO AO LER FICHEIRO" << endl;
    }
    file.close();

    return model;
}



/**
 * Função que de um vector de modelos(representados por string) nos dá uma SCENE que é o que vai ser apresentado no ecrã
 * @param modelos
 * @return
 */

SCENE parse_All_models(vector<string> modelos){
    models_scene = init_scene();
    int i;
    cout << modelos[0] << "\n";
    vector<vertice> pontos;
    for(i=0;i<modelos.size();i++){
        cout << "aqui" << "\n";
        pontos = fill_Model(modelos[i]);
        MODEL m = init_model();
        add_Vertices(m,pontos);
        add_model(models_scene,m);
    }

    return models_scene;
}


/**
 * Função que dá parse do ficheiro XML
 * @param file
 * @return
*/


vector<string> parseXml(const char* file) {
    TiXmlDocument doc(file);
    bool valido = doc.LoadFile();
    vector<string> res;
    if (valido) {
        TiXmlElement *root = doc.FirstChildElement("scene");
        if (root) {
            TiXmlElement *model = root->FirstChildElement("model");
            if (model) {
                //needs further testing
                res.push_back(model->Attribute("file"));

                TiXmlElement *nextModel = model->NextSiblingElement("model");

                while (nextModel) {
                    model = nextModel;
                    nextModel = model->NextSiblingElement("model");
                    res.push_back(model->Attribute("file"));
                }
            }
        }
    }else{
        std::cout << "Erro a dar parse XML" << "\n";
    }
    return res;
}


/**
 * Função que faz loading do modelo a desenhar e escereve em memória os vértices deste
 * @param file
*/

void execut(const char* file){
    models_scene = parse_All_models(parseXml(file));
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
    glBegin(GL_LINES);
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
    draw_scene(models_scene);

    // End of frame
    glutSwapBuffers();
}



// write function to process keyboard events




int main(int argc, char **argv) {
    std::cout << argv[1] <<"\n";


    if(argc>1) execut(argv[1]);


    //vector<string> s1 = parseXml(argv[1]);
    //vector<vertice> v = fill_Model(s1[0]);

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI-UM");

    //if (argc > 1) execut(argv[1]);

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
