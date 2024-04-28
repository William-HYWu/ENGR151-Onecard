#include "drawcards.h"

// This function can draw a card from the stock pile
void drawcards(pile*** stock, player** person, pile*** discard, FILE* filename,
               char mode) {
  (*person)->cardnumber++;
  if ((*person)->cardnumber % 6 == 5) {
    (*person)->playercard =
        realloc((*person)->playercard,
                (size_t)((*person)->cardnumber + 6) * sizeof(card));
    if ((*person)->playercard == NULL) {
      fprintf(stderr, "error");
      exit(-1);
    }
  }
  (*person)->playercard[(*person)->cardnumber - 1] = (**stock)->elem[0];
  printcard((*person)->playercard[(*person)->cardnumber - 1], filename);
  removecard(*stock);
  if ((**stock)->number == 0) {
    reshuffle(stock, discard, filename, mode);
    printf("\nPlayer%d continue draws:", (*person)->ID);
    fprintf(filename, "\nPlayer%d continue draws:", (*person)->ID);
  }
}
