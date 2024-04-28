#include "gameround.h"

// This function can decide if anyone wins
int gamerounds(int* r, player* person, int** playerpoints, int n,
               FILE* filename) {
  player* temp = person;
  while (temp->next != person) {
    if (temp->cardnumber == 0) {
      printf("\n\nIn this round, player%d wins!", temp->ID);
      int winner = temp->ID;
      fprintf(filename, "\n\nIn this round, player%d wins!", temp->ID);
      (*r)++;
      temp = person;
      // Find out the penalty points of the players
      while (temp->next != person) {
        temp->point += temp->cardnumber;
        printf("\n\nPlayer%d will receive %d points of penalty", temp->ID,
               temp->point);
        fprintf(filename, "\n\nPlayer%d will receive %d points of penalty",
                temp->ID, temp->point);
        temp = temp->next;
      }
      temp->point += temp->cardnumber;
      printf("\n\nPlayer%d will receive %d points of penalty", temp->ID,
             temp->point);
      fprintf(filename, "\n\nPlayer%d will receive %d points of penalty",
              temp->ID, temp->point);

      // Stores the points of the players in an array(playerpoints).
      while (temp->ID != 1) {
        temp = temp->next;
      }
      for (int i = 0; i < n; i++) {
        (*playerpoints)[i] += temp->point;
        temp = temp->next;
      }
      // Return winner ID
      return winner;
    }
    temp = temp->next;
  }
  // The while loop above cannot take into consider all the players, it doesn't
  // consider the last player in the linked list
  if (temp->cardnumber == 0) {
    printf("\n\nIn this round, player%d wins!", temp->ID);
    int winner = temp->ID;
    fprintf(filename, "\n\nIn this round, player%d wins!", temp->ID);
    (*r)++;
    temp = person;
    while (temp->next != person) {
      temp->point += temp->cardnumber;
      printf("\n\nPlayer%d will receive %d points of penalty", temp->ID,
             temp->point);
      fprintf(filename, "\n\nPlayer%d will receive %d points of penalty",
              temp->ID, temp->point);
      temp = temp->next;
    }
    temp->point += temp->cardnumber;
    printf("\n\nPlayer%d will receive %d points of penalty", temp->ID,
           temp->point);
    fprintf(filename, "\n\nPlayer%d will receive %d points of penalty",
            temp->ID, temp->point);
    while (temp->ID != 1) {
      temp = temp->next;
    }
    for (int i = 0; i < n; i++) {
      (*playerpoints)[i] += temp->point;
      temp = temp->next;
    }
    // Return winner ID
    return winner;
  }
  return 0;
}
