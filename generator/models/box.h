//
// Created by eduardo on 11/03/21.
//

#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iosfwd>
#ifndef GENERATOR_BOX_H
#define GENERATOR_BOX_H

void planesXZ(std::ofstream& ficheiro, float x, float y, float z, int div);
void planesYZ(std::ofstream& ficheiro, float x, float y, float z, int div);
void planesXY(std::ofstream& ficheiro, float x, float y, float z, int div);
void box(std::string file, float x, float y, float z, int div);

#endif //GENERATOR_BOX_H

