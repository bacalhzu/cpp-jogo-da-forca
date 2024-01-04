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
}