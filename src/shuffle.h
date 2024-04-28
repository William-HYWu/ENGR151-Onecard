#ifndef SHUFFLE_H
#define SHUFFLE_H
#include <time.h>
#include <unistd.h>

#include "pile.h"
#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11
#define SPADES 1
#define HEARTS 2
#define DIAMONDS 3
#define CLUBS 4

typedef card deck[52];

void shuffle(card* firstcard);
void Initshuffle(pile*** stock, int d, pile*** discard, FILE* filename,
                 char mode);
void reshuffle(pile*** stock, pile*** discard, FILE* filename, char mode);
#endif
