#include <stdio.h>
#include <stdlib.h>

const int FULL_RECT = -1;

typedef struct {
	char ** gfx;
	int largura;
	int altura;
	
} Tela;

void limpar(Tela * tela) {
	int x, y;
	for (y = 0; y < tela->altura; y++) {
		for(x = 0; x < tela->largura; x++) {
			tela->gfx[x][y] = ' ';
		}
	}
}

Tela * criar_tela(int largura, int altura) {
	int x, y;
	Tela * tela = (Tela*) malloc( sizeof(Tela) );
	tela->largura = largura;
	tela->altura = altura;
	
	tela->gfx = (char**) malloc(largura * sizeof(char *));			//alocamento X (colunas)
	for (x = 0; x < largura; x++) {
		tela->gfx[x] = (char*) malloc(altura * sizeof(char));	//alocamento Y (linhas)
	}

	limpar(tela);
	
	return tela;
}
/*
void deletar_tela(Tela * tela) {
	for (x = 0; x < tela->largura; x++) {
		free(tela->gfx[x]);
	}
	free(tela->gfx);
}
*/
void linhaH(Tela * tela, int y, int x1, int x2) {
	int x;
	
	if (x2 == -1) x2 = tela->largura;		//FULL_RECT = -1
	else x2++;
	
	for (x = x1; x < x2; x++) {
		tela->gfx[x][y] = '-';
	}
}

void linhaV(Tela * tela, int x, int y1, int y2) {
	int y;
	
	if (y2 == -1) y2 = tela->altura;
	else y2++;
	
	for (y = y1; y < y2; y++) {
		tela->gfx[x][y] = '|';
	}
}

void dot(Tela * tela, int x, int y) {
	tela->gfx[x][y] = 'O';
}
void retangulo(Tela * tela, int x0, int y0, int w, int h) {
	linhaV(tela, x0, y0, y0 + h);
	linhaV(tela, x0 + w, y0, y0 + h);
	
	linhaH(tela, y0, x0, x0 + w);
	linhaH(tela, y0 + h, x0, x0 + w);
	
}
void desenhar(Tela * tela) {
	int x, y;
	for (y = 0; y < tela->altura; y++) {
		for(x = 0; x < tela->largura; x++) {
			printf("%c", tela->gfx[x][y]);
		}
		printf("\n");
	}
}

