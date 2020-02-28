#include "gchar.h"

int main() {
	Tela * tela = criar_tela(10, 10);
	linhaV(tela, 5, 2, FULL_RECT);
	dot(tela, 5, 5);
	retangulo(tela, 0, 0, 5, 5);
	desenhar(tela);
	
	
	
}
