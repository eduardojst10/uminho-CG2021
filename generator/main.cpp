#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "models/plano.h"
#include "models/box.h"
#include "editor/editor.h"

using namespace std;


int main(int argc, char** argv) {

    vector<string> validos = {"plane", "box","sphere","cone"};

    if(argc > 1 && validaModelo(argv[1],validos)){

        if(strcmp(argv[1],"plane")==0){
            geraPlano(argv[3],atof(argv[2]));
        }

        if(strcmp(argv[1],"box")==0){
            box(argv[4],atof(argv[0]),atof(argv[1]),atof(argv[2]),atof(argv[3]));
        }

        if(strcmp(argv[1],"sphere")==0){}

        if(strcmp(argv[1],"cone")==0){}
    }else{
        cout << "Input não tem formato requerido" << "\n";

    }

    return 0;

}
