#include <iostream>
namespace Word {

	struct Word {
		char word[15];
		char cleanWord[15];
		char theme[30];
		char* matchings;
		bool wasAlreadyPlayed{};
	};

    extern Word PLAYABLE_WORDS[];

    Word randomWordFromList(Word*);
	void displayWord(Word*);
	bool checkWord(Word*, char);
	bool checkWin(Word*);
}