//
// Created by eduardo on 11/03/21.
//

#include "box.h"


// Esta função é responsável por calcular os pontos dos dois planos paralelos ao plano XY.
// Primeiro, trata do plano cujo Z > 0, e trata depois do plano cujo Z < 0.
// Nestes planos, Z é sempre constante.
void planesXY(std::ofstream& ficheiro, float x, float y, float z, int div) {
    // Ordem do processamento: começa no vértice inferior esquerdo, e vai processando uma linha de cada vez.
    // Nota : Vamos assumir que 'z' é o que foi passado como parâmetro pelo utilizador, e 'Z' vai ser z/2 ou -z/2.
    // Cálculos
    // Ponto inicial --> Xinicial : -x/2;
    //               --> Yinicial : -y/2;
    //               --> Zinicial : z/2;
    // Ordem dos pontos de acordo com a regra da mão direita.
    // Modo de funcionamento : Vamos ter um X e um Y atual, que é o X e o Y do quadrado anterior.
    // O X vai ser atualizado após cada quadrado, enquanto o Y só é atualizado quando mudamos de linha.
    // Nota : No instante inicial, damos ao X e Y atual o valor do X e Y inicial.
    //
    // Pontos do primeiro quadrado --> A : (Xatual, Yatual, Z)
    //                             --> B : (Xatual + (x/div), Yatual, Z)
    //                             --> C : (Xatual + (x/div), Yatual + (y/div), Z)
    //                             --> D : (Xatual, Yatual + (y/div), Z)
    //
    // Dividido nos dois triângulos --> T1.A : (Xatual, Yatual, Z)
    //                              --> T1.B : (Xatual + (x/div), Yatual, Z)
    //                              --> T1.C : (Xatual, Yatual + (y/div), Z)
    //
    //                              --> T2.A : (Xatual + (x/div), Yatual, Z)
    //                              --> T2.B : (Xatual + (x/div), Yatual + (y/div), Z)
    //                              --> T2.C : (Xatual, Yatual + (y/div), Z)
    //
    // O algoritmo vai ser baseado em 2 ciclo for. No caso do ciclo interior, cada iteração escreve os pontos
    // dos dois triângulos na mesma ordem indicada em cima, baseada na ordem indicada em cima.
    // Além disso, com o objetivo de poupar tempo de execução, em vez de fazermos estes dois ciclos para cada plano,
    // achamos outra solução, que é, ao escrevermos os pontos de um quadrado, escrevemos na mesma iteração do ciclo
    // os pontos representantes do quadrado da face oposta, cujas coordenadas são exatamente iguais, à exceção
    // da coordenada Z, que é o inverso (-Z). Deste modo, cada iteração vê-se responsável por dois quadrados, em vez
    // de apenas tratar de um, tornando o programa mais eficiente. No caso do ciclo exterior, cada iteração representa
    // uma linha de quadrados, e quando o ciclo terminar, ambas as faces vão estar definidas.

    float xAtual = -x/2, yAtual = -y/2, zAtual = z/2;
    for (int i=0; i<div; i++) {
        xAtual = -x/2;
        for (int j = 0; j<div; j++) {
            // Primeiro triângulo
            ficheiro << xAtual << ", " << yAtual << ", " << zAtual << "\n";
            ficheiro << xAtual + (x/div) << ", " << yAtual << ", " << zAtual << "\n";
            ficheiro << xAtual << ", " << yAtual + (y/div) << ", " << zAtual << "\n";

            // Primeiro triângulo inverso

            ficheiro << xAtual << ", " << yAtual << ", " << -zAtual << "\n";
            ficheiro << xAtual + (x/div) << ", " << yAtual << ", " << -zAtual << "\n";
            ficheiro << xAtual << ", " << yAtual + (y/div) << ", " << -zAtual << "\n";

            // Segundo triângulo
            ficheiro << xAtual + (x/div) << ", " << yAtual << ", " << zAtual << "\n";
            ficheiro << xAtual + (x/div) << ", " << yAtual + (y/div)<< ", " << zAtual << "\n";
            ficheiro << xAtual << ", " << yAtual + (y/div) << ", " << zAtual << "\n";

            // Segundo triângulo inverso
            ficheiro << xAtual + (x/div) << ", " << yAtual << ", " << -zAtual << "\n";
            ficheiro << xAtual + (x/div) << ", " << yAtual + (y/div)<< ", " << -zAtual << "\n";
            ficheiro << xAtual << ", " << yAtual + (y/div) << ", " << -zAtual << "\n";


            // Atualizar o xAtual
            xAtual += (x/div);
        }
        // Atualizar o yAtual
        yAtual += (y/div);
    }
}

void planesYZ(std::ofstream& ficheiro, float x, float y, float z, int div) {
    // Ponto fixo : X
    //
    // Ponto inicial --> Xinicial : x/2;
    //               --> Yinicial : -y/2;
    //               --> Zinicial : z/2;
    //
    // Pontos do primeiro quadrado --> A : (xAtual, yAtual, zAtual)
    //                             --> B : (xAtual, yAtual, zAtual - (z/div))
    //                             --> C : (xAtual, yAtual + (y/div), zAtual - (z/div))
    //                             --> D : (xAtual, yAtual + (y/div), zAtual)
    //
    // Dividido nos dois triângulos --> T1.A : (xAtual, yAtual, zAtual)
    //                              --> T1.B : (xAtual, yAtual, zAtual - (z/div))
    //                              --> T1.C : (xAtual, yAtual + (y/div), zAtual)
    //
    //                              --> T2.A : (xAtual, yAtual, zAtual - (z/div))
    //                              --> T2.B : (xAtual, yAtual + (y/div), zAtual - (z/div))
    //                              --> T2.C : (xAtual, yAtual + (y/div), zAtual)
    //

    float xAtual = x/2, yAtual = -y/2, zAtual = z/2;

    for (int i=0; i<div; i++) {
        zAtual = z/2;
        for (int j = 0; j<div; j++) {
            // Primeiro triângulo
            ficheiro << xAtual << ", " << yAtual << ", " << zAtual << "\n";
            ficheiro << xAtual << ", " << yAtual << ", " << zAtual - (z/div) << "\n";
            ficheiro << xAtual << ", " << yAtual + (y/div) << ", " << zAtual << "\n";

            // Primeiro triângulo inverso
            ficheiro << - xAtual << ", " << yAtual << ", " << zAtual << "\n";
            ficheiro << - xAtual << ", " << yAtual << ", " << zAtual - (z/div) << "\n";
            ficheiro << - xAtual << ", " << yAtual + (y/div) << ", " << zAtual << "\n";



            // Segundo triângulo
            ficheiro <<  xAtual << ", " << yAtual << ", " << zAtual - (z/div) << "\n";
            ficheiro <<  xAtual << ", " << yAtual + (y/div) << ", " << zAtual - (z/div) << "\n";
            ficheiro <<  xAtual << ", " << yAtual + (y/div) << ", " << zAtual << "\n";


            // Segundo triângulo inverso
            ficheiro <<  -xAtual << ", " << yAtual << ", " << zAtual - (z/div) << "\n";
            ficheiro <<  -xAtual << ", " << yAtual + (y/div) << ", " << zAtual - (z/div) << "\n";
            ficheiro <<  -xAtual << ", " << yAtual + (y/div) << ", " << zAtual << "\n";

            // Atualizar o zAtual
            zAtual -= (z/div);
        }
        // Atualizar o yAtual
        yAtual += (y/div);
    }

}

void planesXZ(std::ofstream& ficheiro, float x, float y, float z, int div) {
    // Ponto fixo : Y
    //
    // Ponto inicial --> Xinicial : -x/2;
    //               --> Yinicial : y/2;
    //               --> Zinicial : z/2;
    //
    // Pontos do primeiro quadrado --> A : (xAtual, yAtual, zAtual)
    //                             --> B : (xAtual + (x/div), yAtual, zAtual)
    //                             --> C : (xAtual + (x/div), yAtual, zAtual - (z/div))
    //                             --> D : (xAtual, yAtual, zAtual - (z/div))
    //
    // Dividido nos dois triângulos --> T1.A : (xAtual, yAtual, zAtual)
    //                              --> T1.B : (xAtual + (x/div), yAtual, zAtual)
    //                              --> T1.C : (xAtual, yAtual, zAtual - (z/div))
    //
    //                              --> T2.A : (xAtual + (x/div), yAtual, zAtual)
    //                              --> T2.B : (xAtual + (x/div), yAtual, zAtual - (z/div))
    //                              --> T2.C : (xAtual, yAtual, zAtual - (z/div))
    //

    float xAtual = -x/2, yAtual = y/2, zAtual = z/2;

    for (int i=0; i<div; i++) {
        xAtual = -x/2;
        for (int j = 0; j<div; j++) {
            // Primeiro triângulo
            ficheiro <<  xAtual << ", " << yAtual << ", " << zAtual  << "\n";
            ficheiro <<  xAtual + (x/div) << ", " << yAtual  << ", " << zAtual << "\n";
            ficheiro <<  xAtual << ", " << yAtual << ", " << zAtual - (z/div) << "\n";

            // Primeiro triângulo inverso

            ficheiro <<  xAtual << ", " << -yAtual << ", " << zAtual  << "\n";
            ficheiro <<  xAtual + (x/div) << ", " << -yAtual  << ", " << zAtual << "\n";
            ficheiro <<  xAtual << ", " << -yAtual << ", " << zAtual - (z/div) << "\n";

            // Segundo triângulo
            ficheiro <<  xAtual + (x/div) << ", " << yAtual << ", " << zAtual  << "\n";
            ficheiro <<  xAtual + (x/div) << ", " << yAtual  << ", " << zAtual - (z/div) << "\n";
            ficheiro <<  xAtual << ", " << yAtual << ", " << zAtual - (z/div) << "\n";


            // Segundo triângulo inverso
            ficheiro <<  xAtual + (x/div) << ", " << -yAtual << ", " << zAtual  << "\n";
            ficheiro <<  xAtual + (x/div) << ", " << -yAtual  << ", " << zAtual - (z/div) << "\n";
            ficheiro <<  xAtual << ", " << yAtual << ", " << -zAtual - (z/div) << "\n";


            // Atualizar o xAtual
            xAtual += (x/div);
        }
        // Atualizar o zAtual
        zAtual -= (z/div);
    }

}

void box(std::string file, float x, float y, float z, int div) {
    std::string path = "../../FILES/" + file;

    std::ofstream ficheiro;
    ficheiro.open(path);
    // Como primeiro passo, vamos calcular o número de vértices total que o ficheiro contém.
    // A fórmula usada: (div^2)*6 por face. Como são 6 faces, a fórmula é (div^2)*36
    int nrVert = (div*div)*36;
    ficheiro << nrVert << "\n";

    // Depois de escrever o número de vértices no ficheiro, basta chamar as funções auxiliares definidas em cima
    // e essas funções tratam de calcular e escrever no ficheiro.
    planesXY(ficheiro, x, y, z, div);
    planesXZ(ficheiro, x, y, z, div);
    planesYZ(ficheiro, x, y, z, div);

    ficheiro.close();
}