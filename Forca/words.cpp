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
		{ "LEÃO", "LEAO", "Animal" },
		{ "MACACO", "MACACO", "Animal" },
		{ "RATO", "RATO", "Animal" },
		{ "TIGRE", "TIGRE", "Animal" },
		{ "URSO", "URSO", "Animal" },
		{ "VACA", "VACA", "Animal" },
		{ "ZEBRA", "ZEBRA", "Animal" },

		{ "ALEMANHA", "ALEMANHA", "País" },
		{ "ARGENTINA", "ARGENTINA", "País" },
		{ "BRASIL", "BRASIL", "País" },
		{ "CANADÁ", "CANADA", "País" },
		{ "ESPANHA", "ESPANHA", "País" },
		{ "FRANÇA", "FRANCA", "País" },
		{ "ÍNDIA", "INDIA", "País" },
		{ "INGLATERRA", "INGLATERRA", "País" },
		{ "ITÁLIA", "ITALIA", "País" },
		{ "MÉXICO", "MEXICO", "País" },
		{ "PORTUGAL", "PORTUGAL", "País" },

		{ "C++", "C++", "Linguagem de Programação" },
		{ "GO", "GO", "Linguagem de Programação" },
		{ "JAVA", "JAVA", "Linguagem de Programação" },
		{ "JAVASCRIPT", "JAVASCRIPT", "Linguagem de Programação" },
		{ "KOTLIN", "KOTLIN", "Linguagem de Programação" },
		{ "LUA", "LUA", "Linguagem de Programação" },
		{ "PERL", "PERL", "Linguagem de Programação" },
		{ "PHP", "PHP", "Linguagem de Programação" },
		{ "PYTHON", "PYTHON", "Linguagem de Programação" },
		{ "RUBY", "RUBY", "Linguagem de Programação" },
		{ "RUST", "RUST", "Linguagem de Programação" },
		{ "SCALA", "SCALA", "Linguagem de Programação" },
		{ "SWIFT", "SWIFT", "Linguagem de Programação" },
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
			//se esta letra já foi advinhada
			if (*(obj->matchings + i))
				//escreve a letra
				std::cout << " " << *(obj->word + i) << " ";
			else 
				//escreve um traço
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