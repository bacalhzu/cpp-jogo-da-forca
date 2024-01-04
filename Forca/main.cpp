#include <iostream>
#include "words.h"

using namespace std;

int main(void) {
	system("chcp 1252 > nil");

	Word::Word* wordList { Word::PLAYABLE_WORDS };

	Word::Word currentWord{};

	currentWord = Word::randomWordFromList(wordList);
	cout << "Palavra: " << currentWord.word << "\nTema: " << currentWord.theme;


	return 0;
}