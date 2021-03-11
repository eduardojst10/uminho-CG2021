//
// Created by eduardo on 07/03/21.
//
#include "../editor/editor.h"

/**
 * Função que escreve os vértices no ficheiro
 * @param ficheiro
 * @param x
 * @param y
 * @param z
 */
void write_plano(std::string ficheiro, float x, float y, float z){
    std::string path = "../files/" + ficheiro;

    std::ofstream file;
    file.open(path);

    file << 6 << "\n";
    file << -x << ", " << y << ", " << -z << "\n";
    file << -x << ", " << y << ", " << z << "\n";
    file << x << ", " << y << ", " << z << "\n";
    file << -x << ", " << y << ", " << -z << "\n";
    file << x << ", " << y << ", " << z << "\n";
    file << x << ", " << y << ", " << -z << "\n";

    file.close();


}

/**
 * Função que escreve um ponto
 * @param ficheiro
 * @param x
 * @param y
 * @param z
 */
void write_ponto(std::string ficheiro, float x, float y, float z){
    std::string path = "../files/" + ficheiro;

    std::ofstream file;
    file.open(path);
    file << x << ", " << y << ", " << z << "\n";
    file.close();
}

/**
 * Função que escreve no inicio do ficheiro .3 o número de vértices que são escritos, Fundamental para dps representar no engine
 * @param ficheiro
 * @param vertices
 */

void write_vertices(std::string ficheiro, int vertices){
    std::string path = "../files/" + ficheiro;

    std::ofstream file;
    file.open(path);
    file << vertices << "\n";
    file.close();
}
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
