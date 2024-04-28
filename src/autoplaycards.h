#ifndef AUTOPLAYCARDS_H
#define AUTOPLAYCARDS_H
#include <string.h>

#include "comparecards.h"
#include "dealcards.h"
#include "playcardsbasic.h"
void autoplaycards(card* buffer1, card* buffer2, player** person,
                   pile*** discard, pile*** stock, int* attack,
                   int* orderstatus, int* skipstatus, FILE* filename);
#endif
