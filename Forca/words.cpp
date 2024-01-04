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
}