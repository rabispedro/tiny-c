#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 320
#define DATA_SIZE 4

#define DELIMITER ","

struct dado {
	long id;
	char nome[256], cpf[16];
} typedef Dado;

Dado *extrai_dado(char *linha);
void print_dados(Dado *dados[], const int tamanho);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Passe o nome do arquivo que deseja abrir como parametro\n");
		exit(1);
	}

	FILE *arquivo = fopen(argv[1], "r");

	if (arquivo == NULL) {
		fprintf(stderr, "Nao foi possivel abrir o arquivo csv '%s'", argv[1]);
		exit(1);
	}

	int index=0;
	long offset=0;
	char linha[BUFFER_SIZE];

	Dado **dados = (Dado**) malloc(sizeof(Dado*) * DATA_SIZE);

	if (dados == NULL) {
		fprintf(stderr, "Nao foi possivel alocar memoria pra armazenamento de dados.\n");
		exit(1);
	}

	// Primeira linha é o cabeçalho, ignorar os dados
	fgets(linha, BUFFER_SIZE, arquivo);
	printf("Cabecalho: %s\n", linha);
	
	while (!feof(arquivo)) {
		fgets(linha, BUFFER_SIZE, arquivo);

		index = offset % DATA_SIZE;
		Dado *dado = extrai_dado(linha);
		
		if (dado == NULL) {
			continue;
		}

		dados[index] = dado;

		// Operação em lotes (batch), a cada DATA_SIZE dados
		if (index == DATA_SIZE-1) {
			print_dados(dados, index);
			putchar('\n');
		}

		offset++;
	}

	// Ainda restou dados a serem processados
	print_dados(dados, index);

	printf("\nExtração de %ld dados.\n", offset);
	printf("Finalizou arquivo.\n");

	fclose(arquivo);

	return 0;
}

Dado *extrai_dado(char *linha) {
	Dado *dado = (Dado*) malloc(sizeof(Dado));
	char *palavra = NULL;

	if (dado == NULL) {
		fprintf(stderr, "Nao foi possivel alocar memoria pra leitura de dados.\n");
		exit(1);
	}

	if (linha == NULL) {
		return NULL;
	}

	// Extração de dados do arquivo
	palavra = strtok(linha, DELIMITER);

	if (palavra == NULL) {
		return NULL;
	}

	dado->id = atol(palavra);
	
	palavra = strtok(NULL, DELIMITER);

	if (palavra == NULL) {
		return NULL;
	}

	strcpy(dado->nome, palavra);

	palavra = strtok(NULL, DELIMITER);

	if (palavra == NULL) {
		return NULL;
	}

	strcpy(dado->cpf, palavra);

	// Tratamento de ENTER (LF ou LF+CR) no último dígito
	dado->cpf[strlen(dado->cpf)-1] = '\0';

	return dado;
}

void print_dados(Dado *dados[], const int tamanho) {
	for (int i=0; i<=tamanho; i++) {
		printf(
			"Dado { 'id': '%ld', 'nome': '%s', 'cpf': '%s' }\n",
			dados[i]->id,
			dados[i]->nome,
			dados[i]->cpf
		);
	}
}
