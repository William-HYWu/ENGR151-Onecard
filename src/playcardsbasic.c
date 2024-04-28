#include "playcardsbasic.h"

// Packing the allotate memory process
void myalloc(void** pointer, size_t size) {
  *pointer = calloc(1, size);
  if (*pointer == NULL) {
    fprintf(stderr, "error in allocating memory");
    exit(-1);
  }
}

// This function can judge the attacking card effect and the action card effect
// now.
// The buffer is used to store the card just played by the last player.
void judgeffect(int* attack, int* orderstatus, int* skipstatus, card* buffer,
                player** person, FILE* filename) {
  if (buffer->rank == QUEEN) {
    printf("\n\nReverse order!");
    fprintf(filename, "\n\nReverse order!");
    *orderstatus = 1 - *orderstatus;
  } else if (buffer->rank == JACK) {
    *skipstatus = 1;
  } else if (buffer->rank == 2) {
    *attack += 2;
  } else if (buffer->rank == 3) {
    *attack += 3;
  } else if (buffer->rank == 7) {
    *attack = 1;
  } else {
    *attack = 1;
  }
  nextplayer(person, *orderstatus, skipstatus, filename);
}

// Ask user to choose the card
int choosecard(void) {
  int choice = 0;
  printf("\nPlease choose the card you want to play: ");
  if (scanf("%d", &choice) != 1) printf("error in scanf!");
  getchar();
  return choice - 1;
}

// This function can play special cards
void playspecial(card* buffer1, card* buffer2, player** person, pile*** discard,
                 FILE* filename, int i) {
  addcard(*discard, *buffer1);
  *buffer1 = (*person)->playercard[i];
  *buffer2 = (*person)->playercard[i];
  printf("\n\nplayer%d plays: ", (*person)->ID);
  fprintf(filename, "\n\nplayer%d plays: ", (*person)->ID);
  printasciicard((*person)->playercard[i], filename);
  removeplayercards(person, i);
}

// This function can play regular cards
void playregular(card* buffer1, card* buffer2, player** person, pile*** discard,
                 FILE* filename, int i) {
  addcard(*discard, *buffer2);
  *buffer2 = (*person)->playercard[i];
  *buffer1 = (*person)->playercard[i];
  printf("\n\nplayer%d plays: ", (*person)->ID);
  fprintf(filename, "\n\nplayer%d plays: ", (*person)->ID);
  printasciicard((*person)->playercard[i], filename);
  removeplayercards(person, i);
}

// This function can judge whether the player can play cards or not
int isattack(card playercard) {
  if (playercard.rank == 2 || playercard.rank == 3 || playercard.rank == 7) {
    return 1;
  } else {
    return 0;
  }
}

int isaction(card playercard) {
  if (playercard.rank == QUEEN || playercard.rank == JACK) {
    return 1;
  } else {
    return 0;
  }
}
