//
// Created by eduardo on 11/03/21.
//

#include "cone.h"

void cone(std::string file, float radius, float height, int slices, int stacks) {
    //Abrir o ficheiro
    std::string path = "../../FILES/" + file;

    std::ofstream ficheiro;
    ficheiro.open(path);

    int nrVert = (slices * stacks - 1) * 6 + 2 * 3 * slices;
    ficheiro << nrVert << "\n";


    // Para calcularmos os pontos que constituem o cone, o processo vai ser constituído por duas fases, à semelhança
    // da esfera: primeiro iremos calcular os pontos usando coordenadas polares, e em seguida convertemos essas
    // coordenadas polares para coordenadas cartesianas.
    // Numa primeira fase, vamos começar por definir os pontos da base. A base vai ser composta por um número de
    // triângulos igual ao número de slices recebido em argumento.
    // Para definir estes triângulos, vamos tomar a sua altura como 0. Depois, basta calcular as coordenadas polares
    // de cada um tomando como o ângulo inicial 0, e ir incrementando esse ângulo por 2PI/slices em cada triângulo.
    // Este vai ser o princípio usado por todo o cone, aplicado a cada stack. A única coisa que muda entre as
    // diferentes stacks é a altura e o raio. O raio vai ser decrementado à medida que vamos subindo em termos de altura,
    // e vai ser : alturaNova = alturaAtual + alturaTotal/stacks; raioNovo = raioAtual + raioTotal/stacks;
    //
    // Altura na base : 0; Ângulo inicial : 0;
    // Base --> Primeiro triângulo --> A : (0, 0, 0) --> origem
    //                                 B : (radius, angle + 2PI/slices, 0)
    //                                 C : (radius, angle, 0)
    // Para concluir a base, basta fazer um ciclo com a fórmula de cima, e a cada iteração do ciclo, aumenta o ângulo.
    //
    // Inicialização das variáveis --> alturaAtual : 0; alturaNova : alturaAtual + height/stacks;
    //                             --> raioAtual : radius; raioNovo : raioAtual - radius/stacks;
    //                             --> anguloAtual : 0; anguloNovo : anguloAtual + 2PI/slices;
    // Corpo do cone --> Primeiro quadrado --> A : (raioAtual, anguloAtual, alturaAtual)
    //                                     --> B : (raioAtual, anguloNovo, alturaAtual)
    //                                     --> C : (raioNovo, anguloNovo, alturaNova)
    //                                     --> D : (raioNovo, anguloAtual, alturaNova)
    //
    // Corpo do cone --> Primeiro triângulo --> A
    //                                      --> B
    //                                      --> C
    //               --> Segundo triângulo  --> C
    //                                      --> D
    //                                      --> A
    //
    //
    // Vamos ter um ciclo para a base, que gera todos os triângulos para a base.
    // Depois vamos ter dois ciclos for a processar a superfície do cone.
    // A cada iteração do ciclo exterior, vamos gerar uma stack. No caso do ciclo interior, vamos processar um
    // par de triângulos por iteração. No ciclo interior vamos aumentar o ângulo a cada iteração, e este vai ser
    // resetado a cada iteração do ciclo exterior. No exterior vamos atualizar a altura e raio atuais a cada iteração
    // e voltamos a calcular a altura e raio novos, de forma a simplificar os cálculos.
    // Além disso, o que o vai ser feito no ciclo interior vai ser a conversão de coordenadas polares para coordenadas
    // cartesianas, antes de as escrever no ficheiro.
    // Para finalizar é necessário acrescentar que os dois ciclos da superfície apenas vão tratar de (stacks-1) stacks
    // A última stack é especial, como deixamos de ter pares de triângulos e passamos apenas a ter um triângulo por slice.
    // Além disso, todos estes triângulos partilham o ponto (0, 0, height). Por isso, no final existe um ciclo dedicado
    // a processar esta stack.

    // Variáveis utilizadas no programa:
    float anguloAtual, anguloNovo;
    float alturaAtual, alturaNova;
    float raioAtual, raioNovo;

    // ciclo da base
    anguloAtual = 0;
    anguloNovo = anguloAtual + (2 * M_PI) / slices;
    float x = 0, y = 0, z = 0;
    for (int i = 0; i < slices; i++) {
        // Polares
        // A : origem (Nota: A origem está em cartesianas)
        // B : (radius, anguloAtual)
        // C : (radius, anguloNovo)

        // Conversão de polares para cartesianas
        // A : (0,0,0)
        // B : (radius*cos(anguloNovo), radius*sin(anguloNovo), 0)
        // C : (radius*cos(anguloAtual), radius*sin(anguloAtual), 0)

        //Triângulo ABC
        ficheiro << x << ", " << y << ", " << z << "\n";
        ficheiro << radius * cos(anguloNovo) << ", " << radius * sin(anguloNovo) << ", " << z << "\n";
        ficheiro << radius * cos(anguloAtual) << ", " << radius * sin(anguloAtual) << ", " << z << "\n";

        // atualização das variáveis
        anguloAtual = anguloNovo;
        anguloNovo += (2 * M_PI) / slices;
    }

    //ciclo da superfície
    anguloAtual = 0;
    anguloNovo = anguloAtual + (2 * M_PI) / slices;
    alturaAtual = 0;
    alturaNova = alturaAtual + height / stacks;
    raioAtual = radius;
    raioNovo = raioAtual - radius / stacks;
    for (int j = 0; j < stacks - 1; j++) {
        //reset do ângulo
        anguloAtual = 0;
        anguloNovo = anguloAtual + (2 * M_PI) / slices;
        for (int k = 0; k < slices; k++) {
            // Polares
            // A : (raioAtual, anguloAtual, alturaAtual)
            // B : (raioAtual, anguloNovo, alturaAtual)
            // C : (raioNovo, anguloNovo, alturaNova)
            // D : (raioNovo, anguloAtual, alturaNova)

            // Conversão de polares para cartesianas
            // A : (raioAtual*cos(anguloAtual), raioAtual*sin(anguloAtual), alturaAtual)
            // B : (raioAtual*cos(anguloNovo), raioAtual*sin(anguloNovo), alturaAtual)
            // C : (raioNovo*cos(anguloNovo), raioNovo*sin(anguloNovo), alturaNova)
            // D : (raioNovo*cos(anguloAtual), raioNovo*sin(anguloAtual), alturaNova)

            //Primeiro triângulo - ABC
            ficheiro << raioAtual * cos(anguloAtual) << ", " << raioAtual * sin(anguloAtual) << ", " << alturaAtual
                     << "\n";
            ficheiro << raioAtual * cos(anguloNovo) << ", " << raioAtual * sin(anguloNovo) << ", " << alturaAtual
                     << "\n";
            ficheiro << raioNovo * cos(anguloNovo) << ", " << raioNovo * sin(anguloNovo) << ", " << alturaNova << "\n";

            //Segundo triângulo
            ficheiro << raioNovo * cos(anguloNovo) << ", " << raioNovo * sin(anguloNovo) << ", " << alturaNova << "\n";
            ficheiro << raioNovo * cos(anguloAtual) << ", " << raioNovo * sin(anguloAtual) << ", " << alturaNova
                     << "\n";
            ficheiro << raioAtual * cos(anguloAtual) << ", " << raioAtual * sin(anguloAtual) << ", " << alturaAtual
                     << "\n";

            //Atualizar o ângulo
            anguloAtual = anguloNovo;
            anguloNovo += (2 * M_PI) / slices;
        }
        //Atualizar o raio e a altura
        alturaAtual = alturaNova;
        alturaNova += height / stacks;
        raioAtual = raioNovo;
        raioNovo -= radius / stacks;
    }

    //ciclo do último stack
    anguloAtual = 0;
    anguloNovo = anguloAtual + (2 * M_PI) / slices;
    for (int i = 0; i < slices; i++) {
        // Polares
        // A : (0,0)
        // B : (raio, anguloAtual)
        // C : (radius, anguloNovo)

        // Conversão de polares para cartesianas
        // A : (0,0, alturaAtual)
        // B : (raioAtual*cos(anguloAtual), raioAtual*sin(anguloAtual), alturaAtual)
        // C : (raioAtual*cos(anguloNovo), raioAtual*sin(anguloNovo), alturaAtual)

        //Triângulo - ABC
        ficheiro << x << ", " << y << ", " << height << "\n";
        ficheiro << raioAtual * cos(anguloAtual) << ", " << raioAtual * sin(anguloAtual) << ", " << alturaAtual << "\n";
        ficheiro << raioAtual * cos(anguloNovo) << ", " << raioAtual * sin(anguloNovo) << ", " << alturaAtual << "\n";

        // atualização das variáveis
        anguloAtual = anguloNovo;
        anguloNovo += (2 * M_PI) / slices;
    }

    ficheiro.close();
}

