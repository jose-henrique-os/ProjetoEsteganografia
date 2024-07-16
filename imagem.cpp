#include "classe.h"
#include <sstream>

/*
Destrutor da classe "image":
    - Libera a memória alocada para o array dinâmico de pixels, verificando se o ponteiro "pixels" não é nulo antes de liberar memória.
*/
image::~image() {
    if (pixels) {
        for (int i = 0; i < altura; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }
}

/*
Função "pegarDadosImagem":
    - A partir da imagem, é lida a sua largura, altura e valor máximo de cor. Após isso, é feita uma alocação de memória e o preenchimento do array de pixels com base nos dados fornecidos pelo arquivo.
*/
void image::pegarDadosImagem(std::ifstream &arquivo) {
    std::string p3;
    arquivo >> p3 >> largura >> altura;
    int max_valor;
    arquivo >> max_valor;

    pixels = new Pixel*[altura];
    for (int i = 0; i < altura; i++) {
        pixels[i] = new Pixel[largura];       
    }
     for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
 
            arquivo >> pixels[i][j].r ;
            arquivo >> pixels[i][j].g ;
            arquivo >> pixels[i][j].b ;
        }
     }    
}

/*
Função "salvarImagem":
    - Cria uma imagem com os novos valores RGB em um arquivo de saída, no formato ".ppm".
*/
void image::salvarImagem(std::ofstream &arquivo) {
    arquivo << "P3\n" << largura << " " << altura << "\n255\n";
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            arquivo << pixels[i][j].r << " ";
            arquivo << pixels[i][j].g << " ";
            arquivo << pixels[i][j].b << " ";
        }
        arquivo << "\n";
    }
}