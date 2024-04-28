#ifndef PILE_H
#define PILE_H
#include <stdlib.h>

#include "comparecards.h"

typedef struct cardpile {
  int number;
  card* elem;
} pile;

void initpile(pile** head);
void deletpile(pile** head);
void addcard(pile** head, card addedcard);
void removecard(pile** head);
#endif
