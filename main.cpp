/*
Lógica principal do programa, que permite codificar e decodificar mensagens em imagens no formato ".ppm".

Função principal "main":
    - Se a opção escolhida for codificar:
        - Para codificar, é verificado se a quantia de argumentos estão corretos, com um arquivo de entrada e outro de saída. Após isso, é criada uma instância da classe "image" e os dados da imagem original são lidos. Por fim, é construído um array de inteiros que representam a mensagem, sendo implementado na imagem a partir da modificação dos pixels.

    - Se a opção escolhida for decodificar:
        - Para decodificar, é necessário passar como argumento um arquivo que já possua mensagem. Novamente, é criada uma instância da classe "image", para ler os dados. Por último, a mensagem é extraída da imagem a partir da leitura do pixels e exibida na linha de comando.
*/

#include "classe.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

int main(int argc, char *argv[]) {
    std::cout << "Quer decodificar(d), quer codificar(c): ";
    char v;
    std::cin >> v;
    if(v == 'c' || v == 'C') {
        if (argc != 3) {
            std::cerr << "Uso: " << argv[0] << " <arquivo_original.ppm> <arquivo_resultante.ppm>\n";
            return 1;
        }

        std::ifstream arquivoOriginal(argv[1], std::ios::binary);
        if (!arquivoOriginal) {
            std::cerr << "Erro: arquivo original não existe.\n";
            return 1;
        }

        std::ifstream arquivoResultante(argv[2], std::ios::binary);
        if (arquivoResultante) {
            char escolha;
            std::cout << "Atenção: arquivo resultante já existe. Deseja sobrescrevê-lo? (s/n): ";
            std::cin >> escolha;
            if (escolha != 's' && escolha != 'S') {
                std::cerr << "Operação cancelada. Arquivo resultante não foi sobrescrito.\n";
                return 1;
            }
        }

        std::string mensagem;
        std::cout << "Digite uma mensagem (máximo 255 caracteres): ";
        std::getline(std::cin >> std::ws, mensagem);
        if (mensagem.length() > 255) {
            mensagem = mensagem.substr(0, 255);
        }

        image imagem;
        imagem.pegarDadosImagem(arquivoOriginal);
        int tamanhoMensagem = mensagem.length();
        int *letra = new int[tamanhoMensagem * 8+8];
        
        ConstruirArrayDaMensagem(const_cast<char*>(mensagem.c_str()), tamanhoMensagem, letra);
        ImplementarMensagemNaImagem(imagem.get_pixels(), letra, tamanhoMensagem, imagem);

        std::ofstream arquivoSaida(argv[2], std::ios::binary);
        imagem.salvarImagem(arquivoSaida);
    

        std::cout << "Mensagem codificada com sucesso na imagem.\n";
        return 0;
    
    } 
    else if(v == 'd' || v == 'D') {
         if (argc != 2) {
            std::cerr << "Uso: " << argv[0] << " <arquivo_original.ppm>\n";
            return 1;
        }

        std::ifstream arquivoOriginal(argv[1], std::ios::binary);
        if (!arquivoOriginal) {
            std::cerr << "Erro: arquivo original não existe.\n";
            return 1;
        }
       
   
        int y=0;
        char a[255];    
        image imagem;
        imagem.pegarDadosImagem(arquivoOriginal); 
    
        ExtrairMensagemDaImagem(imagem.get_pixels(),imagem.get_largura(),imagem.get_altura(),y,a); 
        std::cout << "Mensagem decodificada: ";
        for(int i = 1;i<y+1;i++){
            std::cout << a[i];
        }
        std::cout << std::endl;
        return 0;
    }
    else {
        std::cout << "Erro: escolha não corresponde a nenhuma das opções.\n";
        return 0;
    }
}