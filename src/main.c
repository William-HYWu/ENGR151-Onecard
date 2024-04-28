#include "main.h"

int main(int argc, char* argv[]) {
  srand((unsigned int)(time(NULL)));
  int playerpoints[100] = {0};
  int* arraypointer = playerpoints;
  int winner = 0;
  int d = 2, n = 4, c = 5, r = 1;
  char logname[50] = "onecard.log";
  char mode = 'r';
  while (1) {
    int count = 0;
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"auto", no_argument, 0, 'a'},
        {"rounds=", required_argument, 0, 'r'},
        {"decks=", required_argument, 0, 'd'},
        {"initial-cards=", required_argument, 0, 'c'},
        {"player-number=", required_argument, 0, 'n'},
        {"log", required_argument, 0, 'l'},
        {NULL, 0, 0, 0},
    };
    int option_index = 0;
    count =
        getopt_long(argc, argv, "har:d:c:n:l:", long_options, &option_index);
    if (count == -1) break;
    switch (count) {
      case 'a':
        mode = 'a';
        break;
      case 'h':
        printhelp();
        return 0;
      case 'c':
        c = atoi(optarg);
        break;
      case 'd':
        d = atoi(optarg);
        break;
      case 'n':
        n = atoi(optarg);
        break;
      case 'r':
        r = atoi(optarg);
        break;
      case 'l':
        strcpy(logname, optarg);
        break;
      default:
        abort();
    }
  }
  FILE* filename = fopen(logname, "w");
  if (filename == NULL) {
    fprintf(stderr, "Error opening a file");
    exit(-1);
  }
  fprintf(filename,
          "This is the log file that records all the details of the game.\n\n");
  printf("Welcome to onecard!\n\n");
  fprintf(filename, "Welcome to onecard!\n\n");
  printf("----Initial setup----\n");
  fprintf(filename, "----Initial setup----\n");
  printf(
      "Number of rounds: %d\nNumber of decks: %d\nNumber of players: "
      "%d\nNumber of initial cards: %d\n",
      r, d, n, c);
  fprintf(filename,
          "Number of rounds: %d\nNumber of decks: %d\nNumber of players: "
          "%d\nNumber of initial cards: %d\n",
          r, d, n, c);
  if (mode == 'a') {  // If the mode is 'a', the game will be played by AI
    int round = 0;
    for (int i = 0; i < r; i++) {
      winner = autoplay(d, n, c, round, &arraypointer, filename, winner);
      round++;
      for (int j = 0; j < n; j++) {
        printf("\n\nPlayer%d now has -%d points", j + 1, playerpoints[j]);
        fprintf(filename, "\n\nPlayer%d now has -%d points", j + 1,
                playerpoints[j]);
      }
    }
  }
  if (mode == 'r') {  // If the mode is 'r', the game will be played by players
    int round = 0;
    for (int i = 0; i < r; i++) {
      winner = realplay(d, n, c, round, &arraypointer, filename, winner);
      for (int j = 0; j < n; j++) {
        printf("\n\nPlayer%d now has -%d points", j + 1, playerpoints[j]);
        fprintf(filename, "\n\nPlayer%d now has -%d points", j + 1,
                playerpoints[j]);
      }
    }
  }
  fclose(filename);
  return 0;
}
