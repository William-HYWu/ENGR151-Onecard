CC=gcc
CFLAGS= -std=c11 -Wall -Werror -Wextra -Wconversion -Wno-unused-result -Wvla -Wpedantic -lm -g
PLAY= -D PLAY
MAIN=src/main.c
PLAYCARDS=src/playcards.c
PRINTCARD=src/printcard.c
SHUFFLE=src/shuffle.c
PRINTHELP=src/printhelp.c
COMPARE = src/comparecards.c
PILE = src/pile.c
PLAYER = src/player.c
DEAL = src/dealcards.c
DRAW = src/drawcards.c
DECIDE = src/decideplayer.c
PLAYBASIC = src/playcardsbasic.c
AUTOPLAY=src/autoplaycards.c
REALPLAY=src/realplaycards.c
ROUND = src/gameround.c
AUTO = src/auto.c
REAL = src/real.c
CLEAR = src/clearscreen.c
TEST = src/test.c
.PHONY: clean all

all: onecard

check-asan-lsan-ubsan: $(SOURCE)
	clang -DDEBUG -g -fsanitize=address,leak,undefined,integer,bounds,float-divide-by-zero,float-cast-overflow -fno-omit-frame-pointer -fno-sanitize-recover=all -o check-asan-lsan-ubsan $(MAIN) $(PRINTCARD) $(SHUFFLE) $(PRINTHELP) $(COMPARE) $(PLAYER) $(PILE) $(DEAL) $(DRAW) $(DECIDE) $(PLAYBASIC) $(ROUND) $(AUTO) $(AUTOPLAY) $(REALPLAY) $(REAL) $(CLEAR)

check-msan: $(SOURCE)
	clang -DDEBUG -g -fsanitize=memory -fno-omit-frame-pointer -fsanitize-memory-track-origins -fPIE -pie -o check-msan $(MAIN) $(PRINTCARD) $(SHUFFLE) $(PRINTHELP) $(COMPARE) $(PLAYER) $(PILE) $(DEAL) $(DRAW) $(DECIDE) $(PLAYBASIC) $(ROUND) $(AUTO) $(AUTOPLAY) $(REALPLAY) $(REAL) $(CLEAR)

onecard: $(SOURCE)
	$(CC) -o onecard $(MAIN) $(PRINTCARD) $(SHUFFLE) $(PRINTHELP) $(COMPARE) $(PLAYER) $(PILE) $(DEAL) $(DRAW) $(DECIDE) $(PLAYBASIC) $(ROUND) $(AUTO) $(AUTOPLAY) $(REALPLAY) $(REAL) $(CLEAR) $(CFLAGS)

clean:
	$(RM) *.o *~ onecard
	/*abc*/
