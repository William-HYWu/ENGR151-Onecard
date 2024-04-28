#include "autoplaycards.h"
// Buffer1 contains the card with special effect
// Buffer2 contains the card without special effect
//  The algorithm for this function is provided in the README
void autoplaycards(card* buffer1, card* buffer2, player** person,
                   pile*** discard, pile*** stock, int* attack,
                   int* orderstatus, int* skipstatus, FILE* filename) {
  // temp can be used to judge whether the person is able to playcards or not
  int temp = (*person)->cardnumber;
  if (buffer1->rank == 2 || buffer1->rank == 3) {  // Attacking card in effect
    for (int i = 0; i < (*person)->cardnumber; i++) {
      if (isattack((*person)->playercard[i]) == 1) {  // Attack
        playspecial(buffer1, buffer2, person, discard, filename, i);
        break;
      } else if (isaction((*person)->playercard[i]) == 1) {  // Action
        card storecard = *buffer1;
        playspecial(buffer1, buffer2, person, discard, filename, i);
        judgeffect(attack, orderstatus, skipstatus, buffer1, person, filename);
        printf(
            "\n\nNow player%d has to draw %d cards if you can't play any card",
            (*person)->ID, *attack);
        fprintf(
            filename,
            "\n\nNow player%d has to draw %d cards if you can't play any card",
            (*person)->ID, *attack);
        *buffer1 = storecard;
        *buffer2 = storecard;
        return;
      }
    }
  } else {
    if (buffer1->rank == QUEEN || buffer1->rank == JACK) {
      buffer1->rank = 0;
      buffer1->suit = 0;
    }  // Do not judge the action effect again
    for (int i = 0; i < (*person)->cardnumber; i++) {
      if (equalcards((*person)->playercard[i], *buffer2) == 1) {
        if ((*person)->playercard[i].rank == 2 ||
            (*person)->playercard[i].rank == 3) {  // Attack
          playregular(buffer1, buffer2, person, discard, filename, i);
          *attack = 0;
          break;
        } else if (isaction((*person)->playercard[i]) == 1) {  // Action
          playregular(buffer1, buffer2, person, discard, filename, i);
          *attack = 1;
          break;
        } else {  // Regular
          playregular(buffer1, buffer2, person, discard, filename, i);
          break;
        }
      }
    }
  }
  if (temp == (*person)->cardnumber) {  // If need deal cards
    char mode = 'a';
    printf("\n\nNo cards can be played, player%d draws:", (*person)->ID);
    fprintf(filename,
            "\n\nNo cards can be played, player%d draws:", (*person)->ID);
    dealcards(stock, person, discard, *attack, filename, mode);
    buffer1->rank = 0;
    buffer1->suit = 0;
  }
  judgeffect(attack, orderstatus, skipstatus, buffer1, person, filename);
  printf("\n\nNow player%d has to draw %d cards if you can't play any card",
         (*person)->ID, *attack);
  fprintf(filename,
          "\n\nNow player%d has to draw %d cards if you can't play any card",
          (*person)->ID, *attack);
}
