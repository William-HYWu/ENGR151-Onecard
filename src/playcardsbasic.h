#ifndef PLAYCARDSBASIC_H
#define PLAYCARDSBASIC_H
#include <string.h>

#include "pile.h"
#include "player.h"

typedef card deck[52];

void myalloc(void** pointer, size_t size);
void judgeffect(int* attack, int* orderstatus, int* skipstatus, card* buffer,
                player** person, FILE* filename);
int choosecard(void);
void playspecial(card* buffer1, card* buffer2, player** person, pile*** discard,
                 FILE* filename, int i);
void playregular(card* buffer1, card* buffer2, player** person, pile*** discard,
                 FILE* filename, int i);
int isattack(card playercard);
int isaction(card playercard);
#endif
