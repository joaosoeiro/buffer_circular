#include <stdio.h>
#include <stdlib.h>


//  CONSTANTES
#define		TAMANHO_DO_BUFFER		3	// Tamanho maximo de elementos suportados no buffer
#define		MAX_COMP_DA_STRING	    81
#define		SUCESSO			        0
#define		FALHA			        -1
#define		SAIR_LOOP               1



void	displayMainMenu(void);
int		getNumber(int* pNumber);


int main(void) {
	int	circularBuffer[TAMANHO_DO_BUFFER] = { 0 };	// Buffer circular vazio
	int	optionNumber	=	0;	// op�ao pra user input
	int	readIndex	    =	0;	// posicao do ponteiro read
	int	writeIndex	    =	0;	// posicao do ponteiro write
	int	bufferLength	=	0;	// Numero de elementos no buffer
    int loopStatus      =   0;  // Variavel de condi�ao do loop

	while (loopStatus != SAIR_LOOP) {
		displayMainMenu();
		getNumber(&optionNumber);  // Pega op�ao do usuario

	/* ---------------------------- OPCAO 1 - ESCREVER --------------------------- */

		if (optionNumber == 1) {
    		// Checando se o Buffer est� cheio
			if (bufferLength == TAMANHO_DO_BUFFER) {
				printf("\n    Buffer cheio!\n\n    ");
				getchar();
				continue;
			}

			printf("\n    Por favor insira um numero inteiro a ser armazenado\n\n    ");
			getNumber(&circularBuffer[writeIndex]);	 // Escreve o numero no endere�o do index do buffer (a posi�ao)

			bufferLength++;
			writeIndex++;	 //	Aumenta a posi�ao da escrita pra se preparar pra proxima entrada do usuario

			// Se o write for igual o tamanho do buffer (chegou no final dele), seta o valor de novo pra zero pra resetar a posicao
			if (writeIndex == TAMANHO_DO_BUFFER) {
				writeIndex = 0;
			}
		}

	/* ---------------------------- OPCAO 2 - LEITURA ---------------------------- */

		else if (optionNumber == 2) {
            // Checa se o buffer est� vazio
			if (bufferLength == 0) {
				printf("\n    Buffer esta vazio!\n\n    ");
				getchar();
				continue;
			}

			printf("\n    O valor contido no buffer e %d\n\n    ", circularBuffer[readIndex]);
			getchar();

			bufferLength--;	 //	Diminui o tamanho apos ler
			readIndex++;	 //	Aumenta a posi�ao do ponteiro de leitura pra se preparar pra proxima
            // Se o read for igual o tamanho do buffer (chegou no final dele), seta o valor de novo pra zero pra resetar a posicao
			if (readIndex == TAMANHO_DO_BUFFER) {
				readIndex = 0;
			}
		}

    /* ---------------------------- OPCAO 3 - SAIR ---------------------------- */

        else if (optionNumber == 3) {
            printf("\n    Obrigado por utilizar o buffer circular!\n\n");
            loopStatus = SAIR_LOOP;
            continue;
        }

	/* ----------------------------- OPCAO INVALIDA ---------------------------- */

		else {
			printf("\n    Numero de opcao invalido!\n\n    ");
			getchar();
		}
	}
}



//  Funcao  :   displayMainMenu()
//  Desc    :   Esta fun��o limpa a tela e exibe o menu principal
void displayMainMenu(void) {
	printf("\n======================= BUFFER CIRCULAR ======================\n\n");
	printf("    Escolha uma opcao:\n\n");
	printf("        1    Inserir Valor\n");
	printf("        2    Puxar valor\n");
	printf("        3    Sair\n");
	printf("\n==============================================================\n\n    ");
	printf("\n QUANTIDADE DE ELEMENTOS SUPORTADOS PELO BUFFER NO TOTAL: %d\n\n    ", TAMANHO_DO_BUFFER);
}



//  Funcao      :   getNumber()
//  Desc        :   Pega um inteiro como input do usuario
//  Parametros  :   int* pNumber: ponteiro para uma int pra armazenar o valor
//  Returns     :   int SUCCESSO: se o input for uma int
//                  int FALHA: se o input nao for uma int
int getNumber(int* pNumber) {
	// Um array de char pra armazenar a string
	char userInput[MAX_COMP_DA_STRING]	=	{ 0 };

	// Pegar input do usuario
	fgets(userInput, MAX_COMP_DA_STRING, stdin);

	// Analisa o input do usu�rio para um inteiro e armazena-o no parametro pNumber
	if (sscanf(userInput, "%d", pNumber) != 1) {
		return FALHA;
	}

	return SUCESSO;
}
