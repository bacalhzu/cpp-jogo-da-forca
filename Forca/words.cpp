#include <random>
#include "words.h"

namespace Word {

    Word PLAYABLE_WORDS[50] 
    {
        {"Amarelo", "Cor"},
        { "Azul", "Cor" },
        { "Bege", "Cor" },
        { "Branco", "Cor" },
        { "Cinza", "Cor" },
        { "Dourado", "Cor" },
        { "Laranja", "Cor" },
        { "Marrom", "Cor" },
        { "Preto", "Cor" },
        { "Rosa", "Cor" },
        { "Roxo", "Cor" },
        { "Verde", "Cor" },
        { "Vermelho", "Cor" },

        { "Cachorro", "Animal" },
        { "Cavalo", "Animal" },
        { "Coelho", "Animal" },
        { "Elefante", "Animal" },
        { "Gato", "Animal" },
        { "Girafa", "Animal" },
        { "Le�o", "Animal" },
        { "Macaco", "Animal" },
        { "Rato", "Animal" },
        { "Tigre", "Animal" },
        { "Urso", "Animal" },
        { "Vaca", "Animal" },
        { "Zebra", "Animal" },

        { "Alemanha", "Pa�s" },
        { "Argentina", "Pa�s" },
        { "Brasil", "Pa�s" },
        { "Canad�", "Pa�s" },
        { "Espanha", "Pa�s" },
        { "Fran�a", "Pa�s" },
        { "�ndia", "Pa�s" },
        { "Inglaterra", "Pa�s" },
        { "It�lia", "Pa�s" },
        { "M�xico", "Pa�s" },
        { "Portugal", "Pa�s" },

        { "C++", "Linguagem de Programa��o" },
        { "Go", "Linguagem de Programa��o" },
        { "Java", "Linguagem de Programa��o" },
        { "JavaScript", "Linguagem de Programa��o" },
        { "Kotlin", "Linguagem de Programa��o" },
        { "Lua", "Linguagem de Programa��o" },
        { "Perl", "Linguagem de Programa��o" },
        { "PHP", "Linguagem de Programa��o" },
        { "Python", "Linguagem de Programa��o" },
        { "Ruby", "Linguagem de Programa��o" },
        { "Rust", "Linguagem de Programa��o" },
        { "Scala", "Linguagem de Programa��o" },
        { "Swift", "Linguagem de Programa��o" },

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