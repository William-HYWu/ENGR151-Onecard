#ifndef GAMEROUND_H
#define GAMEROUND_H
#include <string.h>

#include "pile.h"
#include "player.h"

int gamerounds(int* r, player* person, int** playerpoints, int n,
               FILE* filename);
#endif
