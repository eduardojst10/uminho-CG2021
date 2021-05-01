#include <vector>
#include <string>
#include <cstring>

#include "models/plano.h"
#include "models/cone.h"
#include "models/sphere.h"
#include "models/box.h"
#include "bezierPatch.h"

using namespace std;

/**
 * Função que auxilia a validação do input do terminal
 * @param modelo a verificar
 * @param inputs válidos
 * @return
 */
int validaModelo(char *modelo, std::vector<std::string> inputs){
    int valida=0;
    for(int i=0; i<inputs.size();i++){
        if(strcmp(modelo,inputs.at(i).c_str()) == 0 )valida =1;
    }

    return valida;
}


int main(int argc, char** argv) {

    vector<string> validos = {"plane", "box","sphere","cone"};

    if(argc > 1 && validaModelo(argv[1],validos)){

        if(strcmp(argv[1],"plane")==0){
            geraPlano(argv[3],atof(argv[2]));
        }

        if(strcmp(argv[1],"box")==0){
            box(argv[6],atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));
        }

        if(strcmp(argv[1],"sphere")==0){
                sphere(argv[5],atof(argv[2]),atoi(argv[3]),atoi(argv[4]));
        }

        if(strcmp(argv[1],"cone")==0){
            cone(argv[6],atof(argv[2]),atof(argv[3]),atoi(argv[4]),atoi(argv[5]));

        }
    }else{
        cout << "Input não tem formato requerido" << "\n";

    }

    return 0;

}
