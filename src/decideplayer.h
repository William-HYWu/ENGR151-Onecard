#ifndef DECIDEPLAYER_H
#define DECIDEPLAYER_H
#include "comparecards.h"
#include "drawcards.h"

void discardcards(player* person, pile*** discard);
player* decideplayer(pile** stock, pile** discard, player* player1, int n,
                     FILE* filename, char mode, int round, int winner);
#endif
