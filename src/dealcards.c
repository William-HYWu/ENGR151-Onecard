#include "dealcards.h"
// This function can deal the cards to a single player
// stock is the stock pile of the cards
// discard is the discarded pile of the cards
// c is the card intended to deal
// d is the number of deck of cards(used to restore the stock and discard pile)
void dealcards(pile*** stock, player** player1, pile*** discard, int c,
               FILE* filename, char mode) {
  for (int i = 0; i < c; i++) {
    drawcards(stock, player1, discard, filename, mode);
  }
}
