#include "pile.h"

// Initialize card pile, allocate memory
void initpile(pile** head) {
  *head = calloc(1, sizeof(pile));
  if (*head == NULL) {
    fprintf(stderr, "error in allocating memory");
    exit(-1);
  }
  (*head)->elem = calloc(6, sizeof(card));
  if ((*head)->elem == NULL) {
    fprintf(stderr, "error in allocating memory");
    exit(-1);
  }
  (*head)->number = 0;
}

// Delete card pile, free memory
void deletpile(pile** head) {
  free((*head)->elem);
  free(*head);
  free(head);
}

// Add card to the pile
void addcard(pile** head, card addedcard) {
  (*head)->number++;
  //+6 is to ensure there won't be a overflow somehow
  if ((*head)->number % 6 == 5) {
    (*head)->elem =
        realloc((*head)->elem, (size_t)((*head)->number + 6) * sizeof(card));
    if ((*head)->elem == NULL) {
      fprintf(stderr, "error in allocating memory");
      exit(-1);
    }
  }
  (*head)->elem[(*head)->number - 1] = addedcard;
}

// Remove card from the pile
void removecard(pile** head) {
  if ((*head)->number == 0) return;
  for (int i = 0; i < (*head)->number; i++) {
    *((*head)->elem + i) = *((*head)->elem + i + 1);
  }
  (*head)->number--;
  if ((*head)->number % 6 == 5) {
    (*head)->elem =
        realloc((*head)->elem, (size_t)((*head)->number + 6) * sizeof(card));
    if ((*head)->elem == NULL) {
      fprintf(stderr, "error in allocating memory");
      exit(-1);
    }
  }
}
