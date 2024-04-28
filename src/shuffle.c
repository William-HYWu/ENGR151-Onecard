#include "shuffle.h"

// This function can shuffle one deck of cards
void shuffle(card* firstcard) {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    card temp;
    int random1 = 0, random2 = 0;
    random1 = rand() % 52;
    random2 = rand() % 52;
    temp = *(firstcard + random2);
    *(firstcard + random2) = *(firstcard + random1);
    *(firstcard + random1) = temp;
  }
}

// This function can initialize the shuffle process at the beginning of the game
void Initshuffle(pile*** stock, int d, pile*** discard, FILE* filename,
                 char mode) {
  printf("\nShuffling Cards...\nShuffle result:");
  fprintf(filename, "\nShuffling Cards...\nShuffle result:");
  deck decks[100] = {0};
  initpile(*(stock));
  initpile(*(discard));
  for (int deckindex = 1; deckindex <= d;
       deckindex++) {  // Initializing the decks
    for (int suitindex = 1; suitindex <= 4; suitindex++) {
      for (int rankindex = 1; rankindex <= 13; rankindex++) {
        decks[deckindex][rankindex - 1 + 13 * (suitindex - 1)].suit = suitindex;
        decks[deckindex][rankindex - 1 + 13 * (suitindex - 1)].rank =
            rankindex + 1;
      }
    }
  }
  for (int i = 1; i <= d; i++) {
    shuffle(&decks[i][0]);  // Shuffling the decks
#ifdef PLAY
    sleep(1);
#endif
  }
  for (int i = 1; i <= d; i++) {
    for (int j = 0; j <= 51; j++) {
      addcard(*(stock), decks[i][j]);  // Adding the cards to the stock pile
      if (mode == 'a') {
        printcard(decks[i][j], filename);
        if ((j + 1) % 10 == 0) {
          fprintf(filename, "\n");
        }
      }
      if (mode == 'r') {
        printcardinfile(decks[i][j], filename);
        if ((j + 1) % 10 == 0) {
          fprintf(filename, "\n");
        }
      }
    }
  }
}

// This function can reshuffle the discarded pile when the stock is used up, and
// then put them in the stock pile.
void reshuffle(pile*** stock, pile*** discard, FILE* filename, char mode) {
  printf("\nReshuffling Cards...\nShuffle result:");
  fprintf(filename, "\nReshuffling Cards...\nShuffle result:");
  for (int i = 0; i < 100; i++) {
    int random1 = 0, random2 = 0;
    random1 = rand() % (**discard)->number;
    random2 = rand() % (**discard)->number;
    card temp = (**discard)->elem[random1];
    (**discard)->elem[random1] = (**discard)->elem[random2];
    (**discard)->elem[random2] = temp;
  }
  for (int i = 0; i < (**discard)->number; i++) {
    addcard(*stock, (**discard)->elem[i]);
    if (mode == 'a') printcard((**discard)->elem[i], filename);
    if (mode == 'r') printcardinfile((**discard)->elem[i], filename);
    if ((i + 1) % 10 == 0) {
      fprintf(filename, "\n");
    }
  }
  // delete discard pile and reinitialize it
  deletpile(*discard);
  *discard = calloc(1, sizeof(pile*));
  if (*discard == NULL) {
    fprintf(stderr, "error in assigning discard");
    exit(-1);
  }
  initpile(*discard);
}
