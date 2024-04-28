#ifndef REALPLAYCARDS_H
#define REALPLAYCARDS_H
#include <string.h>

#include "dealcards.h"
#include "playcardsbasic.h"

void realplaycards(card* buffer1, card* buffer2, player** person,
                   pile*** discard, pile*** stock, int* attack,
                   int* orderstatus, int* skipstatus, FILE* filename);
#endif
