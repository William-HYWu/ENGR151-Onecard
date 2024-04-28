#ifndef REAL
#define REAL
#include <time.h>
#include <unistd.h>

#include "clearscreen.h"
#include "decideplayer.h"
#include "gameround.h"
#include "realplaycards.h"
int realplay(int d, int n, int c, int round, int** pointstore, FILE* filename,
             int winner);
#endif
