//
// Created by eduardo on 09/03/21.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glew.h>
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
#include "transformacao.h"
#include "catmull.h"

using namespace std;

SCENE models_scene = NULL;


void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
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
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}



vector<VERTICE> fill_Model(string modelo){
    modelo = "../../FILES/" + modelo;
    //cout << modelo << "\n";
    vector<VERTICE> model;
    ifstream file(modelo);
    string linha;
    string token_del = ",";
    int nr_vertices,pos;
    if(file.is_open()){
        getline(file,linha);
        nr_vertices = atoi(linha.c_str());//const char* to str


        while(getline(file,linha)){
            VERTICE v = (VERTICE) malloc(sizeof(struct vertice));
            //float x
            pos = linha.find(token_del);
            string coord_x = linha.substr(0,pos);
            v->pontos[0] = atof(coord_x.c_str());
            linha.erase(0, pos + token_del.length());




            //float y
            pos = linha.find(token_del);
            string coord_y = linha.substr(0,pos);
            v->pontos[1] = atof(coord_y.c_str());
            linha.erase(0, pos + token_del.length());



            //float z
            pos = linha.find(token_del);
            string coord_z = linha.substr(0,pos);
            v->pontos[2] = atof(coord_z.c_str());
            linha.erase(0, pos + token_del.length());

            v->pontos[3] = 1.0;

            //cout << v->pontos[0] << "," << v->pontos[1] << "," << v->pontos[2] << "," << v->pontos[3] << endl;

            model.push_back(v);
        }

    }else {
        cout << "ERRO AO LER FICHEIRO" << endl;
    }
    file.close();

    return model;
}



/**
 * Função que vai ver o modelo e preencher o vector com os vértices, auxiliar de parse_All_models(vector<string> modelos)
 * @param modelo
 * @return
 */

//operacao --> ”cone.3d”;translate:X=1,Y=0,Z=0;translate:X=0,Y=1,Z=0;
//        s --> translate:X=1,Y=0,Z=0;translate:X=0,Y=1,Z=0;


vector<MODEL> get_Models(vector<string> operacoes) {
    vector<MODEL> modelos;

    for (string str: operacoes) {
        MODEL mo = init_model();
        cout << str << "\n";

        //TRATAMENTO DO FILE .3D
        char *modelo, *campos;
        char *op = &str[0];
        modelo = strsep(&op, ";");


        std::string modelo_str = modelo;
        vector<VERTICE> vertices_modelo = fill_Model(modelo_str);



        if (vertices_modelo.empty()) cout << "FILE EMPTY" << endl; //SE O FICHEIRO NAO EXISTIR
        add_Vertices(mo, vertices_modelo);


        vector<char *> transformacao; //translate:X=1,Y=0,Z=0
        while ((campos = strsep(&op, ";")) != NULL) {
            transformacao.push_back(campos);

        }

        vector<TRANSFORMACAO> transformacoes;
        //para cada transformacao

        //”cone.3d”;translate:time=10:X=0,Y=1,Z=0:X=1,Y=2,Z=3:;translate:X=0,Y=1,Z=0;
        for(char* s: transformacao){

            char* tipo_transformacao = strdup(strsep(&s,":"));
            char *sl;
            TRANSFORMACAO t = init_transformacao();

            if(strcmp(tipo_transformacao,"translate")==0){
                char* als;

                vector<std::string> times;
                vector<std::string> points;
                while((als = strsep(&s,":"))) {
                    char* t = strsep(&als,"=");
                    if (strcmp(t,"time")==0) {//time=10
                        char *coef = strdup(als);
                        std::string str(coef);
                        // Vector of string to save tokens

                        // stringstream class check1
                        std::stringstream check1(coef);
                        std::string intermediate;

                        // Tokenizing w.r.t. space '='
                        while (getline(check1, intermediate, '=')) {
                            times.push_back(intermediate);
                        }
                        //Get Points de catmull
                        char* pts;
                        while ((pts = strsep(&als,","))) { // X = 1 OU Y = 0 OU Z = 0
                            char *coef = strdup(pts);
                            std::string str(coef);
                            // Vector of string to save tokens

                            // stringstream class check1
                            std::stringstream check1(coef);
                            std::string intermediate;

                            // Tokenizing w.r.t. space '='
                            while (getline(check1, intermediate, '=')) {
                                points.push_back(intermediate);
                            }
                        }


                    }else{ // normal
                        char* pts;
                        while ((pts = strsep(&als,","))) { // X = 1 OU Y = 0 OU Z = 0
                            char *coef = strdup(pts);
                            std::string str(coef);
                            // Vector of string to save tokens

                            // stringstream class check1
                            std::stringstream check1(coef);
                            std::string intermediate;

                            // Tokenizing w.r.t. space '='
                            while (getline(check1, intermediate, '=')) {
                                points.push_back(intermediate);
                            }
                        }

                    }
                }

                if(!times.empty()){ //CASO O TIME > 0
                    float tempo = atof(times[1].c_str());
                    t = translate_time(tempo);
                    vector<float> pontos;
                    //vou buscar os pontos
                    for(int i = 0 ; i < points.size();i++){
                        if((i % 2) == 1){
                            pontos.push_back(atof(points[i].c_str()));
                        }
                    }

                    //adiciono-os à transformacao
                    for(int i=0; i<pontos.size();i+3){
                        add_points_catmull(t,pontos.at(i),pontos.at(i+1),pontos.at(i+2));
                    }

                }else {
                    t = translate(atof(points[3].c_str()), atof(points[5].c_str()), atof(points[7].c_str()));
                    //printMatriz(t);
                }
            }

            if(strcmp(tipo_transformacao,"rotate")==0){
                vector<std::string> tokens;

                while ((sl = strsep(&s,","))){


                    char *coef = strdup(sl);
                    std::string str(coef);
                    // Vector of string to save tokens

                    // stringstream class check1
                    std::stringstream check1(coef);
                    std::string intermediate;

                    // Tokenizing w.r.t. space '='
                    while(getline(check1, intermediate, '=')){
                        tokens.push_back(intermediate);
                    }

                }

                if(strcmp(tokens[0].c_str(),"time")==0){
                    //calcula rotation_time
                    t = rotation_time(atof(tokens[3].c_str()), atof(tokens[5].c_str()), atof(tokens[7].c_str()),
                                       atof(tokens[1].c_str()));
                }else {

                    t = escolheRotate(atof(tokens[3].c_str()), atof(tokens[5].c_str()), atof(tokens[7].c_str()),
                                      atof(tokens[1].c_str()));
                    //printMatriz(t);
                }
            }

            if(strcmp(tipo_transformacao,"scale")==0){
                vector<std::string> tokens;

                while ((sl = strsep(&s,","))){
                    char *coef = strdup(sl);
                    std::string str(coef);
                    // Vector of string to save tokens

                    // stringstream class check1
                    std::stringstream check1(coef);
                    std::string intermediate;

                    // Tokenizing w.r.t. space '='
                    while(getline(check1, intermediate, '=')){
                        tokens.push_back(intermediate);
                    }
                }
                t = scale(atof(tokens[1].c_str()),atof(tokens[3].c_str()),atof(tokens[3].c_str()));
                //printMatriz(t);
            }
            transformacoes.push_back(t);
        }
        add_transformacao(mo,transformacoes);
        //CADA STRING UMA OPERACAO
        modelos.push_back(mo);
    }
    return modelos;
}



/**
 * Função que dá parse do ficheiro XML
 * @param file
 * @return vector<string>
*/

vector<string> parseXml(const char *file) {
    TiXmlDocument doc(file);
    bool valido = doc.LoadFile();
    vector<string> res;
    string elemAtual;
    vector<string> transforms;
    string tString;

    if (valido) {
        TiXmlElement *root = doc.FirstChildElement("scene");
        if (root) {
            TiXmlElement *group = root->FirstChildElement();

            while (group) {
                TiXmlElement *elem = group->FirstChildElement();
                TiXmlElement *model;

                while (true) {
                    if (elem) {
                        elemAtual = elem->Value();
                        if (elemAtual == "translate") {
                            tString = "translate:";
                            if (elem->Attribute("time")) {
                                tString = tString + "time=" + elem->Attribute("time") + ":";
                                // start reading the points
                                TiXmlElement *point = elem->FirstChildElement();
                                while(point) {
                                    if (point->Attribute("X")) tString = tString + "X=" + point->Attribute("X") + ",";
                                    else { tString = tString + "X=" + to_string(0) + ","; }
                                    if (point->Attribute("Y")) tString = tString + "Y=" + point->Attribute("Y") + ",";
                                    else { tString = tString + "Y=" + to_string(0) + ","; }
                                    if (point->Attribute("Z")) tString = tString + "Z=" + point->Attribute("Z") + ":";
                                    else { tString = tString + "Z=" + to_string(0) + ":";}
                                    point = point->NextSiblingElement();
                                }
                            } else {
                                // read a point
                                if (elem->Attribute("X")) tString = tString + "X=" + elem->Attribute("X") + ",";
                                else { tString = tString + "X=" + to_string(0) + ","; }
                                if (elem->Attribute("Y")) tString = tString + "Y=" + elem->Attribute("Y") + ",";
                                else { tString = tString + "Y=" + to_string(0) + ","; }
                                if (elem->Attribute("Z")) tString = tString + "Z=" + elem->Attribute("Z");
                                else { tString = tString + "Z=" + to_string(0); }
                            }
                            tString = tString + ";";
                            // push transform to vector
                            transforms.push_back(tString);
                        } else if (elemAtual == "rotate") {
                            tString = "rotate:";
                            if (elem->Attribute("angle")) tString = tString + "angle=" + elem->Attribute("angle") + ",";
                            else if (elem->Attribute("time")) tString = tString + "time=" + elem->Attribute("time") + ",";
                            if (elem->Attribute("axisX")) tString = tString + "X=" + elem->Attribute("axisX") + ",";
                            else { tString = tString + "X=" + to_string(0) + ","; }
                            if (elem->Attribute("axisY")) tString = tString + "Y=" + elem->Attribute("axisY") + ",";
                            else { tString = tString + "Y=" + to_string(0) + ","; }
                            if (elem->Attribute("axisZ")) tString = tString + "Z=" + elem->Attribute("axisZ");
                            else { tString = tString + "Z=" + to_string(0); }
                            tString = tString + ";";
                            transforms.push_back(tString);
                        } else if (elemAtual == "scale") {
                            tString = "scale:";
                            if (elem->Attribute("X")) tString = tString + "X=" + elem->Attribute("X") + ",";
                            else { tString = tString + "X=" + to_string(0) + ","; }
                            if (elem->Attribute("Y")) tString = tString + "Y=" + elem->Attribute("Y") + ",";
                            else { tString = tString + "Y=" + to_string(0) + ","; }
                            if (elem->Attribute("Z")) tString = tString + "Z=" + elem->Attribute("Z");
                            else { tString = tString + "Z=" + to_string(0); }
                            tString = tString + ";";
                            transforms.push_back(tString);
                        } else if (elemAtual == "models") {
                            model = elem->FirstChildElement();
                            while (model) {
                                tString = model->Attribute("file");
                                tString = tString + ";";
                                for (int i = 0; i < transforms.size(); i++) {
                                    tString = tString + transforms[i];
                                }
                                tString.pop_back();
                                res.push_back(tString);
                                model = model->NextSiblingElement("model");
                            }
                        } else if (elemAtual == "group") {
                            elem = elem->FirstChildElement();
                            continue;
                        }

                        elem = elem->NextSiblingElement();
                    } else break;
                }
                transforms.clear();
                group = group->NextSiblingElement();
            }
        }
    } else {
        cout << "Erro a dar parse XML" << "\n";
    }
    //for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
    return res;
}

/**
 * Função que de um vector de modelos(representados por string) nos dá uma SCENE que é o que vai ser apresentado no ecrã
 * @param modelos
 * @return struct scene
 */
SCENE fill_Scene(vector<MODEL> modelos) {
    models_scene = init_scene();
    for (MODEL m: modelos) {
        add_model(models_scene, m);
    }

    return models_scene;
}

/**
 * Função que faz loading do modelo a desenhar e escereve em memória os vértices deste
 * @param file
*/
void execut(const char *file) {
    models_scene = fill_Scene(get_Models(parseXml(file)));
}


void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(300.0f, 300.0f, 300.0f,
              0.0, 0.0, 0.0,
              0.0f, 1.0f, 0.0f);

    //Eixos
    glBegin(GL_LINES);
    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1000.0f, 0.0f, 0.0f);
    glVertex3f(1000.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1000.0f, 0.0f);
    glVertex3f(0.0f, 1000.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -1000.0f);
    glVertex3f(0.0f, 0.0f, 1000.0f);
    glEnd();

    // put drawing instructions here

    glPolygonMode(GL_FRONT, GL_LINE);  
    glColor3f(1,1,1);
    draw_scene(models_scene);

    // End of frame
    glutSwapBuffers();
}

void init(const char *file) {
    if (!models_scene ) {
        #ifndef __APPLE__
        glewInit();
        #endif
        glEnableClientState(GL_VERTEX_ARRAY);

        execut(file);

        init_vbo_scene(models_scene);
    }
}

int main(int argc, char **argv) {
    //std::cout << argv[1] << "\n";


    if (argc > 1) if (argc > 1) init(argv[1]);


    //vector<string> s1 = parseXml(argv[1]);
    //vector<vertice> v = fill_Model(s1[0]);

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM");

    //if (argc > 1) execut(argv[1]);

// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);




//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
