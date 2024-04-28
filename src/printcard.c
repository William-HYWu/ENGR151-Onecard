#include "printcard.h"

// This function can print the card in the console and the file
void printcard(card cards, FILE* filename) {
  switch (cards.rank) {
    case ACE:
      printf("ACE ");
      fprintf(filename, "ACE ");
      break;
    case KING:
      printf("KING ");
      fprintf(filename, "KING ");
      break;
    case QUEEN:
      printf("QUEEN ");
      fprintf(filename, "QUEEN ");
      break;
    case JACK:
      printf("JACK ");
      fprintf(filename, "JACK ");
      break;
    default:
      printf("%d ", cards.rank);
      fprintf(filename, "%d ", cards.rank);
      break;
  }

  switch (cards.suit) {
    case 1:
      printf("of spades ");
      fprintf(filename, "of spades ");
      break;
    case 2:
      printf("of hearts ");
      fprintf(filename, "of hearts ");
      break;
    case 3:
      printf("of diamonds ");
      fprintf(filename, "of diamonds ");
      break;
    case 4:
      printf("of clubs ");
      fprintf(filename, "of clubs ");
      break;
  }
}
// This function can print the card in the console
void printcardinconsole(card cards) {
  printf("\n");
  printf(" _____ \n");
  switch (cards.rank) {
    case ACE:
      printf("|A    |\n");
      break;
    case KING:
      printf("|K    |\n");
      break;
    case QUEEN:
      printf("|Q    |\n");
      break;
    case JACK:
      printf("|J    |\n");
      break;
    default:
      if (cards.rank < 10) {
        printf("|%d    |\n", cards.rank);
      } else {
        printf("|%d   |\n", cards.rank);
      }
      break;
  }

  switch (cards.suit) {
    case 1:
      printf("| /.\\ |\n");
      printf("|(_._)|\n");
      printf("|  |  |\n");
      break;
    case 2:
      printf("|( v )|\n");
      printf("| \\ / |\n");
      printf("|  .  |\n");
      break;
    case 3:
      printf("| / \\ |\n");
      printf("| \\ / |\n");
      printf("|  .  |\n");
      break;
    case 4:
      printf("| ( ) |\n");
      printf("|(_ _)|\n");
      printf("|  |  |\n");
      break;
  }
  printf("|_____|\n");
}
// This function can print the card in the file
void printcardinfile(card cards, FILE* filename) {
  switch (cards.rank) {
    case ACE:
      fprintf(filename, "ACE ");
      break;
    case KING:
      fprintf(filename, "KING ");
      break;
    case QUEEN:
      fprintf(filename, "QUEEN ");
      break;
    case JACK:
      fprintf(filename, "JACK ");
      break;
    default:
      fprintf(filename, "%d ", cards.rank);
      break;
  }

  switch (cards.suit) {
    case 1:
      fprintf(filename, "of spades ");
      break;
    case 2:
      fprintf(filename, "of hearts ");
      break;
    case 3:
      fprintf(filename, "of diamonds ");
      break;
    case 4:
      fprintf(filename, "of clubs ");
      break;
  }
}

void printasciicard(card cards, FILE* filename) {
  printf("\n");
  fprintf(filename, "\n");
  printf("_______\n");
  fprintf(filename, " _____ \n");
  switch (cards.rank) {
    case ACE:
      printf("|A    |\n");
      fprintf(filename, "|A    |\n");
      break;
    case KING:
      printf("|K    |\n");
      fprintf(filename, "|K    |\n");
      break;
    case QUEEN:
      printf("|Q    |\n");
      fprintf(filename, "|Q    |\n");
      break;
    case JACK:
      printf("|J    |\n");
      fprintf(filename, "|J    |\n");
      break;
    default:
      if (cards.rank < 10) {
        printf("|%d    |\n", cards.rank);
        fprintf(filename, "|%d    |\n", cards.rank);
      } else {
        printf("|%d   |\n", cards.rank);
        fprintf(filename, "|%d   |\n", cards.rank);
      }
      break;
  }

  switch (cards.suit) {
    case 1:
      printf("| /.\\ |\n");
      printf("|(_._)|\n");
      printf("|  |  |\n");
      fprintf(filename, "| /.\\ |\n");
      fprintf(filename, "|(_._)|\n");
      fprintf(filename, "|  |  |\n");
      break;
    case 2:
      printf("|( v )|\n");
      printf("| \\ / |\n");
      printf("|  .  |\n");
      fprintf(filename, "|( v )|\n");
      fprintf(filename, "| \\ / |\n");
      fprintf(filename, "|  .  |\n");
      break;
    case 3:
      printf("| / \\ |\n");
      printf("| \\ / |\n");
      printf("|  .  |\n");
      fprintf(filename, "| / \\ |\n");
      fprintf(filename, "| \\ / |\n");
      fprintf(filename, "|  .  |\n");
      break;
    case 4:
      printf("| ( ) |\n");
      printf("|(_ _)|\n");
      printf("|  |  |\n");
      fprintf(filename, "| ( ) |\n");
      fprintf(filename, "|(_ _)|\n");
      fprintf(filename, "|  |  |\n");
      break;
  }
  printf("|_____|\n");
  fprintf(filename, "|_____|\n");
}
