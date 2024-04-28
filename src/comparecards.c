#include "comparecards.h"

int comparecards(card card1, card card2) {
  if (card1.suit < card2.suit) {
    return 0;
  } else if (card1.suit > card2.suit) {
    return 1;
  } else {
    if (card1.rank < card2.rank) {
      return 0;
    } else {
      return 1;
    }
  }
}

int equalcards(card card1, card card2) {
  if (card1.suit == card2.suit || card1.rank == card2.rank)
    return 1;
  else
    return 0;
}
