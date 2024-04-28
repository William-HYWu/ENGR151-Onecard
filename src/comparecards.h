#ifndef COMPARECARDS_H
#define COMPARECARDS_H
#include <stdio.h>

#include "printcard.h"
#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11
#define SPADES 1
#define HEARTS 2
#define DIAMONDS 3
#define CLUBS 4

int comparecards(card card1, card card2);
int equalcards(card card1, card card2);
#endif
