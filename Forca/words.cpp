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
        { "Leão", "Animal" },
        { "Macaco", "Animal" },
        { "Rato", "Animal" },
        { "Tigre", "Animal" },
        { "Urso", "Animal" },
        { "Vaca", "Animal" },
        { "Zebra", "Animal" },

        { "Alemanha", "País" },
        { "Argentina", "País" },
        { "Brasil", "País" },
        { "Canadá", "País" },
        { "Espanha", "País" },
        { "França", "País" },
        { "Índia", "País" },
        { "Inglaterra", "País" },
        { "Itália", "País" },
        { "México", "País" },
        { "Portugal", "País" },

        { "C++", "Linguagem de Programação" },
        { "Go", "Linguagem de Programação" },
        { "Java", "Linguagem de Programação" },
        { "JavaScript", "Linguagem de Programação" },
        { "Kotlin", "Linguagem de Programação" },
        { "Lua", "Linguagem de Programação" },
        { "Perl", "Linguagem de Programação" },
        { "PHP", "Linguagem de Programação" },
        { "Python", "Linguagem de Programação" },
        { "Ruby", "Linguagem de Programação" },
        { "Rust", "Linguagem de Programação" },
        { "Scala", "Linguagem de Programação" },
        { "Swift", "Linguagem de Programação" },

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