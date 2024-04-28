#ifndef AUTO_H
#define AUTO_H
#include <time.h>
#include <unistd.h>

#include "autoplaycards.h"
#include "clearscreen.h"
#include "decideplayer.h"
#include "gameround.h"
int autoplay(int d, int n, int c, int round, int** pointstore, FILE* filename,
             int winner);
#endif
