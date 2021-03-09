//
// Created by eduardo on 07/03/21.
//

#include "../editor/editor.h"
#include "plano.h"

/**
 * Função que gera plano
 * @param path
 * @param x
 */
void geraPlano(char* path, float x){
    write_plano(path,x,0.0f,x);
}