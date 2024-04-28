#include "player.h"

// This function can initialize the player list
player *Initialize(void) {
  player *player1 = NULL;
  player *player2 = NULL;
  player1 = (player *)calloc(1, sizeof(player));
  if (player1 == NULL) {
    fprintf(stderr, "Failed to assign memory!\n");
    exit(-1);
  }
  player2 = (player *)calloc(1, sizeof(player));
  if (player2 == NULL) {
    fprintf(stderr, "Failed to assign memory!\n");
    exit(-1);
  }
  player1->ID = 1;
  player1->Order = 0;
  player1->point = 0;
  player1->next = player2;
  player1->prev = player2;
  player1->cardnumber = 0;
  player1->playercard = calloc(6, sizeof(card));
  if (player1->playercard == NULL) {
    fprintf(stderr, "error in allocating memory");
  }
  player2->ID = 2;
  player2->Order = 0;
  player2->point = 0;
  player2->next = player1;
  player2->prev = player1;
  player2->cardnumber = 0;
  player2->playercard = calloc(6, sizeof(card));
  if (player2->playercard == NULL) {
    fprintf(stderr, "error in allocating memory");
  }
  return player1;
}

// This function can add a player to the player list
void addplayer(player **player1, int ID) {
  player *playeradd = calloc(1, sizeof(player));
  if (playeradd == NULL) {
    fprintf(stderr, "Failed to assign memory!\n");
    exit(-1);
  }
  player *last = *player1;
  while (last->next != *player1) {
    last = last->next;
  }
  playeradd->ID = ID;
  playeradd->point = 0;
  playeradd->Order = 0;
  playeradd->cardnumber = 0;
  playeradd->next = *player1;
  playeradd->prev = last;
  playeradd->playercard = calloc(6, sizeof(card));
  if (playeradd->playercard == NULL) {
    fprintf(stderr, "error in allocating memory");
  }
  (*player1)->prev = playeradd;
  last->next = playeradd;
}

// This function can delete the player list
void freeplayer(player **player1) {
  player *temp = NULL;
  while ((*player1)->next->next != *player1) {
    temp = (*player1)->next;
    (*player1)->next = (*player1)->next->next;
    (*player1)->next->prev = *player1;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp->playercard);
    free(temp);
  }
  temp = (*player1)->next;
  temp->next = NULL;
  temp->prev = NULL;
  (*player1)->next = NULL;
  (*player1)->prev = NULL;
  free(temp->playercard);
  free(temp);
  free((*player1)->playercard);
  free(*player1);
}

// This function can decide who is the next player
void nextplayer(player **nowplayer, int orderstatus, int *skipstatus,
                FILE *filename) {
  // When the number pointed by skipstatus is 1, that means the next player need
  // to be skipped
  if (*skipstatus == 1) {
    printf("\n\nSkip the next player!");
    fprintf(filename, "\n\nSkip the next player!");
    *nowplayer = (*nowplayer)->next->next;
    // Reset the skipstatus so the program won't keep skipping players.
    *skipstatus = 0;
    return;
  }
  // If orderstatus is 1,that means the order is the same as the initial order
  if (orderstatus == 0) {
    *nowplayer = (*nowplayer)->next;
    return;
  } else {
    *nowplayer = (*nowplayer)->prev;
    return;
  }
}

// If you want to remove the second card of the player, cardindex=1
void removeplayercards(player **player1, int cardindex) {
  (*player1)->cardnumber--;
  for (int i = cardindex; i < (*player1)->cardnumber; i++) {
    (*player1)->playercard[i] = (*player1)->playercard[i + 1];
  }
  if ((*player1)->cardnumber % 6 == 5) {
    (*player1)->playercard =
        realloc((*player1)->playercard,
                (size_t)((*player1)->cardnumber + 6) * sizeof(card));
    if ((*player1)->playercard == NULL) {
      fprintf(stderr, "failed to assign memory in removing player cards");
      exit(-1);
    }
  }
}

// This function can display the cards of the player
void displaycards(player **player1, FILE *filename) {
  if ((*player1)->cardnumber == 0) {
    printf("\n\nPlayer%d's cards are all played!", (*player1)->ID);
    fprintf(filename, "\n\nPlayer%d's cards are all played!", (*player1)->ID);
    return;
  }
  printf("\n\nPlayer%d have %d cards, they are: ", (*player1)->ID,
         (*player1)->cardnumber);
  fprintf(filename, "\n\nPlayer%d have %d cards, they are: ", (*player1)->ID,
          (*player1)->cardnumber);
  for (int i = 0; i < (*player1)->cardnumber; i++) {
    printcard((*player1)->playercard[i], filename);
  }
}
