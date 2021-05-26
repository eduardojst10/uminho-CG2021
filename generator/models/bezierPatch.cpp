#include "bezierPatch.h"
#include <vector>
#include <iostream>
#include <fstream>
#define ELEM(row, col) \
        patch.at(row * (tesselation+1) + col)

MATRIX multiplyMatrices(MATRIX fstMatrix, MATRIX sndMatrix){
    MATRIX mult=(MATRIX) malloc(sizeof(struct matrix)); mult->lines = fstMatrix->lines; mult->cols = sndMatrix->cols;
    for(int a = 0; a < 4; a++)
        for(int b = 0; b < 4; b++)
            mult->values[a][b] = 0;

    for(int i = 0; i < fstMatrix->lines; ++i){
        for(int j = 0; j < sndMatrix->cols; ++j){
            for(int k = 0; k < fstMatrix->cols; ++k){
                mult->values[i][j] += fstMatrix->values[i][k] * sndMatrix->values[k][j];
            }

        }
    }
    return mult;
}

void patch(std::string fileout, int tesselation, std::string filename) {
    int num_patches, num_points;
    std::vector<VERTICE> control_points;
    std::vector<INDEXARR> indexes;
    std::vector<VERTICE> result;

    // read the file
    std::ifstream fbp;
    std::string pathIn = "../models/" + filename;
    fbp.open(pathIn);

    if(!(fbp.is_open())){
        std:: cout << "No such file or directory (input)" << std::endl;

        exit(EXIT_FAILURE);
    }

    // read number of patches
    std::string line;
    getline(fbp, line);
    num_patches = std::stoi(line);


    // read indexes
    for(int i=0; i<num_patches; i++) {
        INDEXARR arr = (INDEXARR) malloc(sizeof(struct indexArr));
        getline(fbp, line);

        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        int j = 0;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            //do something with token, in this case stof
            arr->ind[j] = std::stoi(token);
            line.erase(0, pos + delimiter.length());
            j++;
        }
        arr->ind[j] = std::stoi(line);

        indexes.push_back(arr);
    }

    // read number of control points
    getline(fbp, line);
    num_points = std::stoi(line);

    // read control points
    for(int i=0; i<num_points; i++) {
        getline(fbp, line);
        VERTICE v = (VERTICE) malloc(sizeof(struct vertice));

        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;

        // x
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        v->pontos[0] = std::stof(token);
        //std:: cout << v->pontos[0] << std::endl;
        line.erase(0, pos + delimiter.length());

        // y
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        v->pontos[1] = std::stof(token);
        //std:: cout << v->pontos[1] << std::endl;
        line.erase(0, pos + delimiter.length());

        // z
        v->pontos[2] = std::stof(line);
        //std:: cout << v->pontos[2] << std::endl;

        v->pontos[3] = 1.0;

        control_points.push_back(v);
    }


    // make the patches

    // bezier matrix
    float m[4][4] = {{-1.0f, 3.0f, -3.0f, 1.0f},
                     {3.0f, -6.0f, 3.0f, 0.0f},
                     {-3.0f, 3.0f, 0.0f, 0.0f},
                     {1.0f, 0.0f, 0.0f, 0.0f}};

    MATRIX bezier = (MATRIX) malloc(sizeof(struct matrix)); bezier->cols=4; bezier->lines=4;

    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            bezier->values[a][b] = m[a][b];
        }
    }

    // for each patch
    for(int globalIndex=0; globalIndex<num_patches; globalIndex++) {
        std::vector<VERTICE> patch;
        // points matrix
        MATRIX patchPoints_X = (MATRIX) malloc(sizeof(struct matrix)); patchPoints_X->cols=4; patchPoints_X->lines=4;
        MATRIX patchPoints_Y = (MATRIX) malloc(sizeof(struct matrix)); patchPoints_Y->cols=4; patchPoints_Y->lines=4;
        MATRIX patchPoints_Z = (MATRIX) malloc(sizeof(struct matrix)); patchPoints_Z->cols=4; patchPoints_Z->lines=4;
        INDEXARR arr = indexes.at(globalIndex);

        for(int i = 0; i<16; i++) {
            // get patch points
            int indX = i / 4; int indY = i % 4;
            VERTICE v = control_points.at(arr->ind[i]);

            patchPoints_X->values[indX][indY] = v->pontos[0];
            patchPoints_Y->values[indX][indY] = v->pontos[1];
            patchPoints_Z->values[indX][indY] = v->pontos[2];
            //std:: cout << v->pontos[0] << ", " << v->pontos[1] << ", " << v->pontos[2] << " -> " << indX << " " << indY << std::endl;
        }


        for(int u = 0; u <= tesselation; u++){
            for(int v = 0; v <= tesselation; v++){
                MATRIX uVetor = (MATRIX) malloc(sizeof(struct matrix)); uVetor->cols = 4; uVetor->lines = 1;
                uVetor->values[0][0] = pow(u * 1/(float)tesselation, 3);
                uVetor->values[0][1] = pow(u * 1/(float)tesselation, 2);
                uVetor->values[0][2] = pow(u * 1/(float)tesselation, 1);
                uVetor->values[0][3] = 1;
                //std:: cout << uVetor->values[0][0] << std::endl;

                MATRIX vVetor = (MATRIX) malloc(sizeof(struct matrix)); vVetor->cols = 1; vVetor->lines = 4;
                vVetor->values[0][0] = pow(v * 1/(float)tesselation, 3);
                vVetor->values[1][0] = pow(v * 1/(float)tesselation, 2);
                vVetor->values[2][0] = pow(v * 1/(float)tesselation, 1);
                vVetor->values[3][0] = 1;
                //std:: cout << vVetor->values[0][0] << std::endl;
                //std:: cout << bezier->values[0][0] << std::endl;



                //calcular ponto final do bezierPatch
                VERTICE vert = (VERTICE) malloc(sizeof(struct vertice));

                vert->pontos[0] = multiplyMatrices( multiplyMatrices( multiplyMatrices( multiplyMatrices(uVetor,bezier), patchPoints_X ), bezier ), vVetor)->values[0][0];
                vert->pontos[1] = multiplyMatrices( multiplyMatrices( multiplyMatrices( multiplyMatrices(uVetor,bezier), patchPoints_Y ), bezier ), vVetor)->values[0][0];
                vert->pontos[2] = multiplyMatrices( multiplyMatrices( multiplyMatrices( multiplyMatrices(uVetor,bezier), patchPoints_Z ), bezier ), vVetor)->values[0][0];
                //std:: cout << vert->pontos[0] << " " << vert->pontos[1] << " " << vert->pontos[2] << std::endl;
                patch.push_back(vert);
            }
        }

        // take the patch and form triangles
        for(int row=0; row<tesselation; row++) {
            for(int col=0; col<tesselation; col++) {
                // 1st triangle
                result.push_back(ELEM(row,col));
                result.push_back(ELEM(row+1,col));
                result.push_back(ELEM(row,col+1));

                // 2nd triangle
                result.push_back(ELEM(row+1,col));
                result.push_back(ELEM(row+1,col+1));
                result.push_back(ELEM(row,col));
            }
        }
    }


    // write to file
    std::string path = "../../FILES/" + fileout;

    std::ofstream ficheiro;
    ficheiro.open(path);

    int nrVert = (tesselation+1)*(tesselation+1)*num_patches;
    ficheiro << nrVert << "\n";

    for (VERTICE ver: result) {
        ficheiro <<  ver->pontos[0] << ", " << ver->pontos[1] << ", " << ver->pontos[2]  << "\n";
    }

    fbp.close();
    ficheiro.close();
}