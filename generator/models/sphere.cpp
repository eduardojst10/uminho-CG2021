//
// Created by eduardo on 11/03/21.
//


#include "sphere.h"
#include <cmath>
#include <math.h>

void sphere(std::string file, float radius, int slices, int stacks) {
    //Abrir o ficheiro
    std::string path = "../../FILES/" + file;

    std::ofstream ficheiro;
    ficheiro.open(path);

    int nrVert = (slices*stacks)*6;
    ficheiro << nrVert << "\n";

    // Para calcular os pontos dos triângulos que constituem a esfera, vamos divir o processo da seguinte forma:
    // Primeiro, vamos calcular as coordenadas dos triângulos com coordenadas esféricas. Depois de as calcularmos,
    // usamos as fórmulas trigonométricas para as transformarmos em coordenadas cartesianas, que por ventura vamos
    // gravar no ficheiro.
    //
    // As coordenadas no sistema esférico são compostas por: (r, teta, phi), em que r é o raio, teta é a longitude,
    // e phi é a latitude. Teta varia de -180 a 180, ou de -PI a PI. Phi varia de -90 a 90, ou de -PI/2 a PI/2.
    //
    // O primeiro cálculo dos pontos vai funcionar da seguinte forma: O raio é constante, por isso não vai ser alterado
    // em parte nenhuma do código. No caso dos ângulos, vamos começar nos ângulos mínimos de ambos os parâmetros,
    // isto é, -180 e -90. Depois, vamos calcular uma stack inteira de cada vez. Em termos de código, vamos fazer
    // dois ciclos, à semelhança da box, em que o ciclo exterior vai ser referente às stacks, e o interior refere-se
    // às slices. Em cada iteração do ciclo exterior, a latitude, ou o phi, vai ser incrementado por PI/stacks.
    // No caso da longitude, ela vai acabar por chegar ao seu valor máximo através das iterações do ciclo interior,
    // Por isso tem de ser resetada para o valor inicial.
    // Nas iterações dos ciclos interiores, a longitude vai ser incrementada por 2PI/slices a cada iteração.
    // No ciclo interior não vai ser alterado o valor da latitude.
    //
    // Regra da mão direita
    // Primeiro quadrado --> A: (radius, tetaAtual, phiAtual)
    //                   --> B: (radius, tetaNovo, phiAtual)
    //                   --> C: (radius, tetaNovo, phiNovo)
    //                   --> D: (radius, tetaAtual, phiNovo)

    float tetaInit = 0, phiInit = 0;
    float tetaAtual = tetaInit, phiAtual = phiInit;
    float tetaNovo = tetaAtual + (M_PI/slices), phiNovo = phiAtual + (2*M_PI/stacks);

    for(int i = 0; i<stacks; i++){
        // reset no teta
        tetaAtual = tetaInit; tetaNovo = tetaAtual + (M_PI/slices);
        for(int j = 0; j<slices; j++) {
            //Cálculo da tradução para cartesiano
            // A: (radius * sin(tetaAtual) * cos(phiAtual),
            //     radius * sin(tetaAtual) * sin(phiAtual),
            //     radius * cos(tetaAtual))
            //
            // B: (radius * sin(tetaNovo) * cos(phiAtual),
            //     radius * sin(tetaNovo) * sin(phiAtual),
            //     radius * cos(tetaNovo))
            //
            // C: (radius * sin(tetaNovo) * cos(phiNovo),
            //     radius * sin(tetaNovo) * sin(phiNovo),
            //     radius * cos(tetaNovo))
            //
            // D: (radius * sin(tetaAtual) * cos(phiNovo),
            //     radius * sin(tetaAtual) * sin(phiNovo),
            //     radius * cos(tetaAtual))

            //Primeiro triângulo - ABC
            ficheiro << radius * sin(tetaAtual) * cos(phiAtual) << ", "
                     << radius * cos(tetaAtual) << ", "
                     << radius * sin(tetaAtual) * sin(phiAtual) << "\n";

            ficheiro << radius * sin(tetaNovo) * cos(phiNovo) << ", "
                     << radius * cos(tetaNovo) << ", "
                     << radius * sin(tetaNovo) * sin(phiNovo) << "\n";

            ficheiro << radius * sin(tetaNovo) * cos(phiAtual) << ", "
                     << radius * cos(tetaNovo) << ", "
                     << radius * sin(tetaNovo) * sin(phiAtual) << "\n";

            //Segundo triângulo - CDA
            ficheiro << radius * sin(tetaNovo) * cos(phiNovo) << ", "
                     << radius * cos(tetaNovo) << ", "
                     << radius * sin(tetaNovo) * sin(phiNovo) << "\n";

            ficheiro << radius * sin(tetaAtual) * cos(phiAtual) << ", "
                     << radius * cos(tetaAtual) << ", "
                     << radius * sin(tetaAtual) * sin(phiAtual) << "\n";

            ficheiro << radius * sin(tetaAtual) * cos(phiNovo) << ", "
                     << radius * cos(tetaAtual) << ", "
                     << radius * sin(tetaAtual) * sin(phiNovo) << "\n";

            // Atualizar o Teta
            tetaAtual = tetaNovo; tetaNovo += (M_PI/slices);
        }
        // Atualizar o Phi
        phiAtual = phiNovo; phiNovo += (2*M_PI/stacks);
    }

    ficheiro.close();
}