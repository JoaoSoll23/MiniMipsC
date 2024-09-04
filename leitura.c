#include <stdio.h>
#include <stdlib.h>

int main(void){

    //Faz a leitura do arquivo, caso dê erro, retorna a mensagem avisando
    FILE *file = fopen("programa_k_vezes_n.mem", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[17];

    // Lê cada linha do arquivo
    while (fgets(linha, sizeof(linha), file)) {
        // Remove o caractere de nova linha, se presente
        linha[strcspn(linha, "\n")] = '\0';
    }
    
    fclose(file);

    return 0;
}
