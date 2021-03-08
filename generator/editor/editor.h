//
// Created by eduardo on 07/03/21.
//
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <iosfwd>
#ifndef PROJETOCG2021_EDITOR_H
#define PROJETOCG2021_EDITOR_H


void write_ponto(std::string f,float x,float y,float z);
int validaModelo(char *input, std::vector<std::string> accepted_inputs);

#endif //PROJETOCG2021_EDITOR_H
