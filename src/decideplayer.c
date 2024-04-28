#include "decideplayer.h"

void discardcards(player* person, pile*** discard) {
  person->cardnumber--;
  addcard(*discard, person->playercard[person->cardnumber]);
  person->playercard[person->cardnumber].rank = 0;
  person->playercard[person->cardnumber].suit = 0;
}

player* decideplayer(pile** stock, pile** discard, player* player1, int n,
                     FILE* filename, char mode, int round, int winner) {
  if (round == 0) {
    player* temp = player1;
    // Draw the card for the first player
    printf("\n\nPlayer%d draws:", temp->ID);
    fprintf(filename, "\n\nPlayer%d draws:", temp->ID);
    drawcards(&stock, &temp, &discard, filename, mode);

    // Draw the cards for the rest player
    while (temp->next != player1) {
      temp = temp->next;
      printf("\n\nPlayer%d draws:", temp->ID);
      fprintf(filename, "\n\nPlayer%d draws:", temp->ID);
      drawcards(&stock, &temp, &discard, filename, mode);
    }
    temp = temp->next;

    // Compare the card between each two player, and increment the "Order" of
    // the player with the bigger card.
    player* temp1 = player1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp->Order += comparecards(temp->playercard[temp->cardnumber - 1],
                                    temp1->playercard[temp->cardnumber - 1]);
        temp1 = temp1->next;
      }
      temp = temp->next;
      temp1 = player1;
    }

    // Now discard the first cards they draw
    for (int i = 0; i < n; i++) {
      discardcards(temp, &discard);
      temp = temp->next;
    }
    // Now compare the "Order" of the players and decide who is the first player
    player* FirstPlayer = player1;
    for (int i = 0; i < n; i++) {
      if (FirstPlayer->Order == 1) {
        return FirstPlayer;
      }
      FirstPlayer = FirstPlayer->next;
    }
    printf("There's an error in deciding player!");
    return FirstPlayer;
  } else {
    player* temp = player1;
    while (temp->ID != winner) {
      temp = temp->next;
    }
    return temp;
  }
}
