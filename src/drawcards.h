#ifndef DRAWCARDS_H
#define DRAWCARDS_H
#include "player.h"
#include "shuffle.h"

void drawcards(pile*** stock, player** person, pile*** discard, FILE* filename,
               char mode);
#endif
