//
// Created by eduardo on 25/04/21.
//

#include "bezierPatch.h"
#define N 1024

struct matriz{
    float points[4][4];
};

struct patchBezier{
    int number_patches;
    int number_controlPoints;
    int* index_ControlPoints[16];
    float* values_ControlPoints[3];

};

BezierPatch init_BezierPatch(){
    BezierPatch bp;
    for(int i = 0; i< 16;i++){
        bp->index_ControlPoints[i] = (int*) malloc(sizeof (int));
    }
    return bp;
}

BezierPatch  read_file(char* filename){
    BezierPatch bp;
    FILE *fbp = fopen(filename, "r");

    if(!fbp){
        std:: cout << "No such file or directory" << std::endl;
        exit(EXIT_FAILURE);
    }
    char* linha = (char*) malloc(sizeof(char *));
    bp->number_patches = atoi(fgets(linha,N,fbp)); //tenho numero de patches - 2

    for(int i = 0; i<bp->number_patches;i++) {
        char *indexPatches = fgets(linha, N, fbp);
        char *value;
        int c = 0;                                            //Preenchos os meus indices para cada patch
        while ((value = strsep(&indexPatches, ","))) {
            bp->index_ControlPoints[i][c] = atoi(value);
            c++;
        }
    }

    bp->number_controlPoints = atoi(fgets(linha,N,fbp));
    for(int l = 0; l< bp->number_controlPoints; l++){
        char *valuesControl = fgets(linha, N, fbp);
        char *value;
        int v = 0;                                            //Preenchos os meus indices para cada patch
        while ((value = strsep(&valuesControl, ","))) {
            bp->values_ControlPoints[l][v] = atof(value);
            v++;
        }

    }
    fclose(fbp);
    return bp;

}


void completeModel_BezierPatch(BezierPatch bp,std::string file,int tesselation,std::string filename){
    std::string path = "../../FILES/" + file;
    std::ofstream ficheiro;
    ficheiro.open(path);


    int matriz_bezier[4][4] = {{-1,3,-3,1},{3,-6,3,0},{-3,3,0,0},{1,0,0,0}}; //matriz com os coeficientes do polinómio

    MATRIZ matriz_resultado;


    //for each patch vamos criar as matrizes u, v e p de modo a realizar a fórmula do p(t)
    for (int i = 0; i < bp->number_patches; ++i) {
        //matriz vetor u e vetor v
        //in patches we use u
        //tesselation = divisions
        for (int u = 0; u <= tesselation; u++) {
            for (int v = 0; v = tesselation; v++) {
                //VETOR u - constante para todas as curvas
                MATRIZ  vetor_u;
                vetor_u->points[0][0] = pow(u*1/tesselation,3);
                vetor_u->points[0][1] = pow(u*1/tesselation,2);
                vetor_u->points[0][2] = pow(u*1/tesselation,1);
                vetor_u->points[0][3] = 1;


                //Como fazer para a v?
            }
        }
        //Pontos das curvas de bezier
        MATRIZ pBezierTesselation;
    }

    //FAZER FUNÇAO PARA MULTIPLICAÇAO DE MATRIZES
}