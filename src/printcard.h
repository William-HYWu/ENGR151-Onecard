#ifndef PRINTCARD_H
#define PRINTCARD_H
#include <stdio.h>
#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11
#define SPADES 1
#define HEARTS 2
#define DIAMONDS 3
#define CLUBS 4

typedef struct generate_card_struct {
  int rank, suit;
} card;

void printcard(card cards, FILE* filename);
void printcardinconsole(card cards);
void printcardinfile(card cards, FILE* filename);
void printasciicard(card cards, FILE* filename);
#endif
