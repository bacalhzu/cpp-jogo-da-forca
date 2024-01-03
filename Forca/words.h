namespace Word {

    struct Word {
        char word[15];
        char theme[30];
        bool wasAlreadyPlayed{};
    };

    extern Word PLAYABLE_WORDS[50];

    Word randomWordFromList(Word* words);
}