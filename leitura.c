#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para determinar o tipo de instrução com base no opcode
const char* determine_instruction_type(unsigned int opcode) {
    switch (opcode) {
        case 0b0100:
            return "0"; //0 tipo I
        case 0b1011:
            return "0";
        case 0b1111:
            return "0";
        case 0b1000:
            return "0";
        case 0b0010:
            return "1"; //1 tipo J
        case 0b0000:
            return "2"; //tipo R
        // Adicione outros opcodes conforme necessário
        default:
            return "3"; // Qualquer outro opcode não identificado
    }
}

int main(void){

  setlocale(LC_ALL, "Portuguese");

      // Abre o arquivo para leitura
    FILE *file = fopen("programa_k_vezes_n.mem", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

        struct instrucao{
        char inst_char[17];
        int opcode;
        int rs;
        int rt;
        int rd;
        int funct;
        int imm;
        int addr
    };

    struct instrucao inst_name;

    // Lê cada linha do arquivo
    while (fgets(inst_name.inst_char, sizeof(inst_name.inst_char), file)) {
        // Remove o caractere de nova linha, se presente
        inst_name.inst_char[strcspn(inst_name.inst_char, "\n")] = '\0';

    // Verifica se a linha tem exatamente 16 bits
    if (strlen(inst_name.inst_char) != 16) {
        // Se a linha não tiver 16 caracteres, ignorar e continuar para a próxima
        printf("\n");//para ignorar
        continue;
    }

    //verificar opcode

        // Separa o opcode (4 primeiros bits)
        char opcode[5] = {0}; // 4 bits + 1 para o caractere nulo
        strncpy(opcode, inst_name.inst_char, 4);       // Copia os 4 primeiros bits para o opcode

        // Converte o opcode para número inteiro
        unsigned int opcode_num = (unsigned int)strtol(opcode, NULL, 2);

        // Determina o tipo de instrução
        const char* tipo_instrucao = determine_instruction_type(opcode_num);

    //verifica o tipo de instrução para armazenar os dados nas variáveis corretas
    if (strcmp(tipo_instrucao, "0") == 0) {
                // É do tipo I: separar os campos (rs, rt, imm)
                char opcode[5] = {0};// 4 bits + 1 para nulo
                char rs[4] = {0};   // 3 bits + 1 para nulo
                char rt[4] = {0};   // 3 bits + 1 para nulo
                char imm[7] = {0};  // 6 bits + 1 para nulo

                // Copia os bits correspondentes para os campos
                strncpy(opcode, inst_name.inst_char, 4);   // Bits 1 a 4 (opcode)
                strncpy(rs, inst_name.inst_char + 4, 3);   // Bits 5 a 7 (rs)
                strncpy(rt, inst_name.inst_char + 7, 3);   // Bits 8 a 10 (rt)
                strncpy(imm, inst_name.inst_char + 10, 6); // Bits 11 a 16 (imm)

                // Converte os campos para inteiros e armazena na estrutura
                inst_name.opcode = (int)strtol(opcode, NULL, 2);
                inst_name.rs = (int)strtol(rs, NULL, 2);
                inst_name.rt = (int)strtol(rt, NULL, 2);
                inst_name.imm = (int)strtol(imm, NULL, 2);

                // Imprime os valores extraídos
            printf("Tipo I - opcode: %d, rs: %d, rt: %d, imm: %d\n", inst_name.opcode, inst_name.rs, inst_name.rt, inst_name.imm);
            }

     else if (strcmp(tipo_instrucao, "1") == 0) {

        // Declaração dos campos para instruções tipo J
        char opcode[5] = {0};  // 4 bits + 1 para nulo
        char addr[13] = {0};   // 12 bits + 1 para nulo

        // Copia os bits correspondentes para os campos
        strncpy(opcode, inst_name.inst_char, 4);    // Bits 1 a 4 (opcode)
        strncpy(addr, inst_name.inst_char + 4, 12); // Bits 5 a 16 (addr)

        // Converte os campos para inteiros e armazena na estrutura
        inst_name.opcode = (int)strtol(opcode, NULL, 2);
        inst_name.addr = (int)strtol(addr, NULL, 2);

        // Imprime os valores extraídos
        printf("Tipo J - opcode: %d, addr: %d\n", inst_name.opcode, inst_name.addr);
            }

     else if(strcmp(tipo_instrucao, "2") == 0){
                 // É do tipo R: separar os campos (rs, rt, rd, e funct)
                char opcode[5] = {0};// 4 bits + 1 para nulo
                char rs[4] = {0};   // 3 bits + 1 para nulo
                char rt[4] = {0};   // 3 bits + 1 para nulo
                char rd[4] = {0};  // 3 bits + 1 para nulo
                char funct[4] = {0}; //3 bits + 1 para nulo

                // Copia os bits correspondentes para os campos
                strncpy(opcode, inst_name.inst_char, 4);    // Bits 1 a 4 (opcode)
                strncpy(rs, inst_name.inst_char + 4, 3);    // Bits 5 a 7 (rs)
                strncpy(rt, inst_name.inst_char + 7, 3);    // Bits 8 a 10 (rt)
                strncpy(rd, inst_name.inst_char + 10, 3);   // Bits 11 a 13 (rd)
                strncpy(funct, inst_name.inst_char + 13, 3); // Bits 14 a 16 (funct)

                // Converte os campos para inteiros e armazena na estrutura
                inst_name.opcode = (int)strtol(opcode, NULL, 2);
                inst_name.rs = (int)strtol(rs, NULL, 2);
                inst_name.rt = (int)strtol(rt, NULL, 2);
                inst_name.rd = (int)strtol(rd, NULL, 2);
                inst_name.funct = (int)strtol(funct, NULL, 2);

                // Imprime os valores extraídos
    printf("Tipo R - opcode: %d, rs: %d, rt: %d, rd: %d, funct: %d\n", inst_name.opcode, inst_name.rs, inst_name.rt, inst_name.rd, inst_name.funct);
            }

            else{
            printf("Tipo de instrução não identificada.\n");
     }
}

    fclose(file);

    return 0;
}
