//
// Created by eduardo on 11/03/21.
//

#include <string>
#ifndef GENERATOR_BOX_H
#define GENERATOR_BOX_H

void planesXZ(std::string file, float x, float y, float z, int div);
void planesYZ(std::string file, float x, float y, float z, int div);
void planesXY(std::string file, float x, float y, float z, int div);
void box(std::string file, float x, float y, float z, int div);

#endif //GENERATOR_BOX_H

