/*
Este arquivo de cabeçalho define a estrutura e as funções para manipulação de imagens.

Estrutura "Pixel": 
    - Representa um pixel da imagem com componentes de cor RGB.

Classe "image": 
    - Armazena os dados de uma imagem, incluindo largura, altura e um array dinâmico de pixels.
    - Construtor: Inicializa uma imagem vazia com largura e altura zero e pixels nulos.
    - Destrutor: Libera a memória alocada para os pixels.
    - Public: lê e retorna dados da imagem.
*/

#ifndef CLASSE_H
#define CLASSE_H

#include <fstream>
#include <string>

struct Pixel {
    int r, g, b;
};

class image {
    int largura, altura;
    Pixel **pixels;

public:
    image() : largura(0), altura(0), pixels(nullptr) {}
    ~image();

    void pegarDadosImagem(std::ifstream &arquivo);
    void salvarImagem(std::ofstream &arquivo);
    Pixel** get_pixels() { return pixels; }
    int get_largura() { return largura; }
    int get_altura() { return altura; }
    
};

void ConstruirArrayDaMensagem(char *mensagem, int tamanhoMensagem, int letra[]);
void ImplementarMensagemNaImagem(Pixel **pixels, int letra[], int tamanhoMensagem, image &img);
void ExtrairMensagemDaImagem(Pixel **pixels, int largura, int altura,int &y,char a[]);
void ReconstruirMensagem(char *mensagem, int tamanhoMensagem, int letra[]);

#endif