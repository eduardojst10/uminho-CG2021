//
// Created by eduardo on 07/03/21.
//

#include "plano.h"

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
 * Função que gera plano
 * @param path
 * @param x
 */
void geraPlano(char* path, float x){
    write_plano(path,x,0.0f,x);
}