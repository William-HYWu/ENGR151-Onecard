#include "real.h"

int realplay(int d, int n, int c, int round, int** pointstore, FILE* filename,
             int winner) {
  char mode = 'r';
  int* attack = NULL;
  myalloc((void**)&attack, sizeof(int));
  int* orderstatus = NULL;
  myalloc((void**)&orderstatus, sizeof(int));
  int* skipstatus = NULL;
  myalloc((void**)&skipstatus, sizeof(int));
  pile** stock = NULL;
  myalloc((void**)&stock, sizeof(pile*));
  pile** discard = NULL;
  myalloc((void**)&discard, sizeof(pile*));
  player* player1 = Initialize();
  if (player1 == NULL) {
    fprintf(stderr, "error in allocating memory to player1");
    exit(-1);
  }
  card* buffer1 = NULL;  // The card in buffer1 should be considered with
                         // special effect
  myalloc((void**)&buffer1, sizeof(card));
  card* buffer2 = NULL;  // The card in buffer2 only decides the rank/suit the
                         // next player need to play
  myalloc((void**)&buffer2, sizeof(card));
  for (int i = 0; i < n - 2; i++) {
    addplayer(&player1, i + 3);
  }
  Initshuffle(&stock, d, &discard, filename, mode);
  printf("\n\nDealing cards...");
  fprintf(filename, "\n\nDealing cards...");
  for (int i = 0; i < n; i++) {
    printf("\n\nplayer%d draws:", player1->ID);
    fprintf(filename, "\n\nplayer%d draws:", player1->ID);
    dealcards(&stock, &player1, &discard, c, filename, mode);
    player1 = player1->next;
  }
  printf("\n\n--------------------------------------------");
  fprintf(filename, "\n\n--------------------------------------------");
  printf("\n\nDetermining players order...");
  fprintf(filename, "\n\nDetermining players order...");
  player* nowplayer =
      decideplayer(stock, discard, player1, n, filename, mode, round, winner);
  printf("\n\nThe game will start with player%d", nowplayer->ID);
  fprintf(filename, "\n\nThe game will start with player%d", nowplayer->ID);
  printf("\n\n--------------------------------------------");
  fprintf(filename, "\n\n--------------------------------------------");
  buffer1->rank = 0;
  buffer1->suit = 0;
  *attack = 1;
  *buffer2 = (*stock)->elem[0];  // Initializing the parameters used in playing
  printf("\n\nThe initial card is ");
  fprintf(filename, "\n\nThe initial card is ");
  printcard(*buffer2, filename);
  removecard(stock);
  addcard(discard, *buffer2);
  while (round != 1) {
    fprintf(filename, "\n\n--------------------------------------------");
    clearscreen();
    displaycards(&nowplayer, filename);  // Display the cards of the player
    realplaycards(buffer1, buffer2, &nowplayer, &discard, &stock, attack,
                  orderstatus, skipstatus, filename);  // Play cards
#ifdef PLAY
    sleep(1);
#endif
    winner = gamerounds(&round, nowplayer, pointstore, n, filename);
    if (winner != 0) break;
  }
  free(buffer1);
  free(buffer2);
  free(attack);
  free(skipstatus);
  free(orderstatus);
  freeplayer(&player1);
  deletpile(stock);
  deletpile(discard);
  return winner;
}
