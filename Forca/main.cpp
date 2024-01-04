#include <iostream>
#include "words.h"

using namespace std;

int main(void) {
	system("chcp 1252 > nil");

	//pega a lista de palavras
	Word::Word* wordList { Word::PLAYABLE_WORDS };

	//pega uma palavra aleatória da lista
	Word::Word currentWord{};
	currentWord = Word::randomWordFromList(wordList);

	//pega a quantidade de caracteres da palabra
	unsigned short letterCount = strlen(currentWord.cleanWord);
	//instancia as matchs da palavra
	currentWord.matchings = new char[letterCount] {};

	//roda o jogo enquanto não há vitória
	do {
		//limpa a tela
		system("cls");

		//mostra a palavra
		displayWord(&currentWord);
		cout << endl << endl;

		//pede a letra para o usuário				
		char letterInput{};
		cout << "Entre com uma letra: ";
		cin >> letterInput;

		//move o caractere lowercase para uppercase
		letterInput = (int(letterInput) >= 97) ? letterInput - 32 : letterInput;

		//checa se tem a letra na palavra
		checkWord(&currentWord, letterInput);

	} while (!checkWin(&currentWord)); //verifica se não ganhou

	//limpa a tela
	system("cls");

	//mostra a palavra
	displayWord(&currentWord);
	cout << endl << endl;

	cout << "Meus parabéns! Você adivinhou a palavra!";
	cout << endl;

	//deleta a memoria alocada para os matchings
	delete[] currentWord.matchings;

	return 0;
}