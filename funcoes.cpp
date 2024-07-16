#include "classe.h"
#include <cmath>
#include <iostream>
#include <cstring>

/*
Função "ConstruirArrayDaMensagem":
    - Converte a mensagem em um array de inteiros representando bits.
    - O array "letra" contém os bits da mensagem onde cada caractere é convertido em sua representação binária.
    - Cada caractere é processado bit a bit, começando com o tamanho da mensagem (em bytes) seguido pelos caracteres da mensagem.
*/
void ConstruirArrayDaMensagem(char *mensagem, int tamanhoMensagem, int letra[]) {
    letra[tamanhoMensagem*8+8];
    int k = -1;
    int p;
    for(int j=7;j<tamanhoMensagem*8+8;j=j+8){
        if(j==7){
            p = tamanhoMensagem;
        }
        else{
        p = mensagem[k];
        }
        for (int i = j;i>=j-7 ; i--) {
       
            letra[i]=p%2;
            if(p%2==1){
                p = (p-1)/2; 
            }
            else{
               p = p/2;
            }       
        }
        k++;
    }    
}

/*
Função "ImplementarMensagemNaImagem":
    - Codifica a mensagem na imagem, modificando os valores dos pixels.
    - Altera os bits menos significativos dos componentes RGB dos pixels para armazenar a mensagem.
    - Percorre os pixels da imagem e modifica os bits do RGB para corresponder aos bits da mensagem.
*/
void ImplementarMensagemNaImagem(Pixel **pixels, int letra[], int tamanhoMensagem, image &img) {
    int largura = img.get_largura();
    int altura = img.get_altura();
    int bit = 0;

    for (int i = 0; i < altura && bit < tamanhoMensagem * 8 +8; i++) {
        for (int j = 0; j < largura && bit < tamanhoMensagem * 8 +8; j++) {
            if (pixels[i][j].r%2 == 0 && letra[bit] != 0) {
                pixels[i][j].r += 1;
            }
            if (pixels[i][j].r%2 != 0 &&  letra[bit] == 0) {
                pixels[i][j].r -= 1;
            }
             bit = bit + 3;         
        }
    }
    bit = 1;
    for (int i = 0; i < altura && bit < tamanhoMensagem * 8 +8; i++) {
        for (int j = 0; j < largura && bit < tamanhoMensagem * 8 +8; j++) {
            if (pixels[i][j].g%2 == 0 && letra[bit] != 0) {
                pixels[i][j].g += 1;
            }
            if (pixels[i][j].g%2 != 0 &&  letra[bit] == 0) {
                pixels[i][j].g -= 1;
            }
             bit = bit + 3;         
        }
    }
    bit = 2;
     for (int i = 0; i < altura && bit < tamanhoMensagem * 8 +8; i++) {
        for (int j = 0; j < largura && bit < tamanhoMensagem * 8 +8; j++) {
            if (pixels[i][j].b%2 == 0 && letra[bit] != 0) {
                pixels[i][j].b += 1;
            }
            if (pixels[i][j].b%2 != 0 &&  letra[bit] == 0) {
                pixels[i][j].b -= 1;
            }
             bit = bit + 3;         
        }
    }
}

/*
Função "ExtrairMensagemDaImagem":
    - Extrai a mensagem codificada nos bits menos significativos dos componentes RGB da imagem.
    - Reconstrói a mensagem a partir dos bits extraídos, convertendo-os de volta em caracteres.
    - Percorre os pixels da imagem, extraindo os bits e reconstruindo a mensagem original.
*/

void ExtrairMensagemDaImagem(Pixel **pixels, int largura, int altura, int &y, char a[]) {
    int k =0;
    int dec[8];
    for(int i = 0;i<altura;i++){
         if(k>7){
                break;
            }
        for(int j = 0;j<largura;j++){
             if(pixels[i][j].r%2 == 1){
             dec[k]=1;
            
            }
            else{
            dec[k]=0;
            }
            k = k + 3;
             if(k>7){
                break;
            }
        }       
    }
    int p = 1;
    for(int i = 0;i<altura;i++){
         if(p>8){
                break;
            }
        for(int j = 0;j<largura;j++){
            if(pixels[i][j].g%2 == 1){
             dec[p]=1;
            
            }
            else{
            dec[p]=0;
            }
            p = p + 3;
             if(p>8){
                break;
            }
        }
    }
    int z = 2;
    for(int i = 0;i<altura;i++){
         if(z>6){
                break;
            }
        for(int j = 0;j<largura;j++){
             if(pixels[i][j].b%2 == 1){
             dec[z]=1;
            
            }
            else{
            dec[z]=0;
            }
            z = z + 3;
            if(z>6){
                break;
            }
        }       
    }
    y = 0;
    for(int i = 0;i<8;i++){
        if(i==0){
        y = y + dec[i]*2*2*2*2*2*2*2;
        }
        if(i==1){
        y = y + dec[i]*2*2*2*2*2*2;
        }
        if(i==2){
        y = y + dec[i]*2*2*2*2*2;
        }
        if(i==3){
        y = y + dec[i]*2*2*2*2;
        }
        if(i==4){
        y = y + dec[i]*2*2*2;
        }
        if(i==5){
        y = y + dec[i]*2*2;
        }
        if(i==6){
        y = y + dec[i]*2;
        }
        if(i==7){
        y = y + dec[i];
        }
    }
    int deca[y*8+8];
    k = 0;
    for(int i = 0;i<altura;i++){
        if(k>y*8+7){
                break;
            }
        for(int j = 0;j<largura;j++){
             deca[k]=(pixels[i][j].r%2);
            k = k + 3;
            if(k>y*8+7){
                break;
            }
        }
    }
    p = 1;
    for(int i = 0;i<altura;i++){
        if(p>y*8+7){
                break;
            }
        for(int j = 0;j<largura;j++){
             deca[p]=(pixels[i][j].g%2);
            p = p + 3;
            if(p>y*8+7){
                break;
            }
        }
    }
    z = 2;
    for(int i = 0;i<altura;i++){
        if(z>y*8+7){
                break;
            }
        for(int j = 0;j<largura;j++){
             deca[z]=(pixels[i][j].b%2);
            z = z + 3;
            if(z>y*8+7){
                break;
            }
        }
    }
    a[y+2] = {0};
    int m = 0;
    int t = 8;
    for(int j= 1;j<y+2;j++){
        m=0;
         for(int i = 0;i<8;i++){
        if(i==0){
        m = m + deca[t]*2*2*2*2*2*2*2;
        }
        if(i==1){
        m = m + deca[t]*2*2*2*2*2*2;
        }
        if(i==2){
        m = m + deca[t]*2*2*2*2*2;
        }
        if(i==3){
        m = m + deca[t]*2*2*2*2;
        }
        if(i==4){
        m = m + deca[t]*2*2*2;
        }
        if(i==5){
        m = m + deca[t]*2*2;
        }
        if(i==6){
        m = m + deca[t]*2;
        }
        if(i==7){
        m = m + deca[t];
        }
         t++;
        }
        a[j] = m;
    }
}