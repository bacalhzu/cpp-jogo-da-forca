#include <iostream>
#include <random>
#include "words.h"

namespace Word {

	Word PLAYABLE_WORDS[50]
	{
		{ "AMARELO", "AMARELO", "Cor" },
		{ "AZUL", "AZUL", "Cor" },
		{ "BEGE", "BEGE", "Cor" },
		{ "BRANCO", "BRANCO", "Cor" },
		{ "CINZA", "CINZA", "Cor" },
		{ "DOURADO", "DOURADO", "Cor" },
		{ "LARANJA", "LARANJA", "Cor" },
		{ "MARROM", "MARROM", "Cor" },
		{ "PRETO", "PRETO", "Cor" },
		{ "ROSA", "ROSA", "Cor" },
		{ "ROXO", "ROXO", "Cor" },
		{ "VERDE", "VERDE", "Cor" },
		{ "VERMELHO", "VERMELHO", "Cor" },

		{ "CACHORRO", "CACHORRO", "Animal" },
		{ "CAVALO", "CAVALO", "Animal" },
		{ "COELHO", "COELHO", "Animal" },
		{ "ELEFANTE", "ELEFANTE", "Animal" },
		{ "GATO", "GATO", "Animal" },
		{ "GIRAFA", "GIRAFA", "Animal" },
		{ "LE�O", "LEAO", "Animal" },
		{ "MACACO", "MACACO", "Animal" },
		{ "RATO", "RATO", "Animal" },
		{ "TIGRE", "TIGRE", "Animal" },
		{ "URSO", "URSO", "Animal" },
		{ "VACA", "VACA", "Animal" },
		{ "ZEBRA", "ZEBRA", "Animal" },

		{ "ALEMANHA", "ALEMANHA", "Pa�s" },
		{ "ARGENTINA", "ARGENTINA", "Pa�s" },
		{ "BRASIL", "BRASIL", "Pa�s" },
		{ "CANAD�", "CANADA", "Pa�s" },
		{ "ESPANHA", "ESPANHA", "Pa�s" },
		{ "FRAN�A", "FRANCA", "Pa�s" },
		{ "�NDIA", "INDIA", "Pa�s" },
		{ "INGLATERRA", "INGLATERRA", "Pa�s" },
		{ "IT�LIA", "ITALIA", "Pa�s" },
		{ "M�XICO", "MEXICO", "Pa�s" },
		{ "PORTUGAL", "PORTUGAL", "Pa�s" },

		{ "C++", "C++", "Linguagem de Programa��o" },
		{ "GO", "GO", "Linguagem de Programa��o" },
		{ "JAVA", "JAVA", "Linguagem de Programa��o" },
		{ "JAVASCRIPT", "JAVASCRIPT", "Linguagem de Programa��o" },
		{ "KOTLIN", "KOTLIN", "Linguagem de Programa��o" },
		{ "LUA", "LUA", "Linguagem de Programa��o" },
		{ "PERL", "PERL", "Linguagem de Programa��o" },
		{ "PHP", "PHP", "Linguagem de Programa��o" },
		{ "PYTHON", "PYTHON", "Linguagem de Programa��o" },
		{ "RUBY", "RUBY", "Linguagem de Programa��o" },
		{ "RUST", "RUST", "Linguagem de Programa��o" },
		{ "SCALA", "SCALA", "Linguagem de Programa��o" },
		{ "SWIFT", "SWIFT", "Linguagem de Programa��o" },
	};

	Word randomWordFromList(Word* words) {
		Word* word{};

		//get a random number
		srand(time(NULL));
		unsigned short rngIndex = rand();
		do {
			rngIndex = rand() % 51;

			//get the word based in the random number
			word = (words + rngIndex);
		} while (word->wasAlreadyPlayed);

		//set the chosen word to alreadyPlayed true
		word->wasAlreadyPlayed = true;

		//return a word value
		return *word;
	}

	void displayWord(Word* obj) {

		//mostra o tema da palavra
		std::cout << "Tema: " << obj->theme;
		std::cout << std::endl << std::endl;

		//percorre cada letra
		for (int i = 0; i < strlen(obj->word); i++) 
			//se esta letra j� foi advinhada
			if (*(obj->matchings + i))
				//escreve a letra
				std::cout << " " << *(obj->word + i) << " ";
			else 
				//escreve um tra�o
				std::cout << " _ ";
	}

	bool checkWord(Word* obj, char search) {
		bool matched{ false };

		//percorre cada letra da string
		for (int i = 0; i < strlen(obj->word); i++)
			//se o caractere da string limpa bater com o caractere buscado
			if (*(obj->cleanWord + i) == search) {
				//atualiza a lista de match
				*(obj->matchings + i) = search;
				//retorna que teve match
				matched = true;
			}

		return matched;
	}

	bool checkWin(Word* obj) {
		bool matched{ true };

		//percorre cada letra da string
		for (int i = 0; i < strlen(obj->word); i++) {
			//salva se o indice teve match
			matched = *(obj->matchings + i);
			//se encontrou um caratere sem match sai do loop ja
			if (!matched)
				break;
		}
			
		return matched;
	}
}