#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <stdlib.h>

#include "printcard.h"

// Player with the highest order play cards first
// Point is the penalty point of each player
typedef struct generate_player_struct {
  int ID;
  int Order;
  int point;
  int cardnumber;
  card *playercard;
  struct generate_player_struct *prev;
  struct generate_player_struct *next;
} player;

player *Initialize(void);
void addplayer(player **player1, int ID);
void freeplayer(player **player1);
void nextplayer(player **nowplayer, int orderstatus, int *skipstatus,
                FILE *filename);
void removeplayercards(player **player1, int cardindex);
void displaycards(player **player1, FILE *filename);
#endif
