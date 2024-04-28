#include "realplaycards.h"

// Buffer1 contains cards with special effect
// Buffer2 contains cards without special effect
void realplaycards(card* buffer1, card* buffer2, player** person,
                   pile*** discard, pile*** stock, int* attack,
                   int* orderstatus, int* skipstatus, FILE* filename) {
  int temp = 1;   // temp can help decide which card the player wants to play
  int judge = 0;  // judge can help judge whether the person is able to play
  if (buffer1->rank == 2 || buffer1->rank == 3) {  // Attacking card in effect
    printf("\n\nLast player played a:");
    printcardinconsole(*buffer1);
    printf("\n\nYou have to play 2 or 3 or 7 or Jack or Queen");
    for (int i = 0; i < (*person)->cardnumber; i++) {  // Deciding if can play
      if (isaction((*person)->playercard[i]) == 1 ||
          isattack((*person)->playercard[i]) == 1) {
        temp = choosecard();
        judge = 1;
        break;
      }
    }
    if (judge == 1) {
      while ((isattack((*person)->playercard[temp]) == 0 &&
              isaction((*person)->playercard[temp]) == 0 && temp != -1) ||
             ((temp > (*person)->cardnumber) || temp < -1)) {
        printf("\nThis card can't be played, choose again\n");
        temp = choosecard();  // Asking for correct input
      }
      if (temp == -1) {
        judge = 0;
      }  // The player choose to draw cards
      else {
        if (isattack((*person)->playercard[temp]) == 1) {
          playspecial(buffer1, buffer2, person, discard, filename, temp);
        } else if (isaction((*person)->playercard[temp]) == 1) {
          card storecard = *buffer1;  // Action card doesn't cancel attack
          playspecial(buffer1, buffer2, person, discard, filename, temp);
          judgeffect(attack, orderstatus, skipstatus, buffer1, person,
                     filename);
          printf(
              "\n\nNow player%d has to draw %d cards if you can't play any "
              "card",
              (*person)->ID, *attack);
          fprintf(filename,
                  "\n\nNow player%d has to draw %d cards if you can't play any "
                  "card",
                  (*person)->ID, *attack);
          *buffer1 = storecard;
          *buffer2 = storecard;
          return;
        }
      }
    }
  } else {  // Regular card in effect
    printf("\n\nLast player played a:");
    printcardinconsole(*buffer2);
    if (buffer1->rank == QUEEN || buffer1->rank == JACK) {
      *buffer1 = (card){0, 0};
    }  // Do not judge the action effect again
    for (int i = 0; i < (*person)->cardnumber; i++) {
      if (equalcards((*person)->playercard[i], *buffer2) == 1) {
        temp = choosecard();
        judge = 1;
        break;
      }
    }  // Deciding if can play
    if (judge == 1) {
      while (
          (!equalcards((*person)->playercard[temp], *buffer2) && temp != -1) ||
          (temp > (*person)->cardnumber) || temp < -1) {
        printf("\nThis card can't be played, choose again\n");
        temp = choosecard();
      }  // Asking for correct input
      if (temp == -1) {
        judge = 0;  // The player choose to draw cards
      } else {
        if ((*person)->playercard[temp].rank == 2 ||
            (*person)->playercard[temp].rank == 3) {
          playregular(buffer1, buffer2, person, discard, filename, temp);
          *attack = 0;  // Choose attack
        } else if (isaction((*person)->playercard[temp]) == 1) {
          playregular(buffer1, buffer2, person, discard, filename, temp);
          *attack = 1;  // Choose action
        } else {
          playregular(buffer1, buffer2, person, discard, filename, temp);
        }  // Choose regular
      }
    }
  }
  if (judge == 0) {  // If needs deal cards
    printf("\n\nNo cards can be played, player%d draws:", (*person)->ID);
    fprintf(filename,
            "\n\nNo cards can be played, player%d draws:", (*person)->ID);
    char mode = 'r';
    dealcards(stock, person, discard, *attack, filename, mode);
    getchar();
    *(buffer1) = (card){0, 0};
  }
  judgeffect(attack, orderstatus, skipstatus, buffer1, person, filename);
  printf("\n\nNow player%d has to draw %d cards if you can't play any card",
         (*person)->ID, *attack);
  fprintf(filename,
          "\n\nNow player%d has to draw %d cards if you can't play any card",
          (*person)->ID, *attack);
}
