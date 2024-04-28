# ENGR151 Project2

## Description

Project2 course outcome for ENGR151 in UM-SJTU JI. Incoming students of JI should not refer to this repo when completing the project. Any misconduct detected will be considered as violation to honor code, and will receive heavy punishment.
## Author

Name: Haoyang Wu

Email: william-wu@sjtu.edu.cn

## Usage
This project simulates the OneCard(UNO) game.
One Card is a simple game played by n persons over a pre-decided number of rounds r. A total of d decks of Poker cards, excluding Jokers, are shuffled and c cards are offered to each player.

## Input
1. Command line input:
- -h:  print help message
- --log filename: write the logs in filename (default: onecard.log)
- -n n|--player-number=n: n players, n must be larger than 2 (default: 4)
- -c c|--initial-cards=c: deal c cards per player, c must be at least 2 (default: 5)
- -d d|--decks=d: use d decks 52 cards each, d must be at least 2 (default: 2)
- -r r|--rounds=r: play r rounds, r must be at least 1 (default: 1)
- -a|--auto: run in demo mode(AI will play)
2. In real mode, the player must enter a number to decide which card to play.
- For instance, if the player wants to play the third card on his hand, the player has to enter 3
- The program allows players to enter 0 to choose not to play a card and draw the card.

## Compiling and running
OK.

## Brief Documentation
1. The card has a certain order:  Spades < Hearts < Diamonds < Clubs                                      
    2 < 3 <...< 10 < Jack < Queen < King < Ace
    This order is only useful in deciding the first player in each round.
    The game starts with the player that draws the card with the least order.
2. At the end of the game the players who lose receive penalty points equal to the number
    cards left on their hand.
3. Special card effects:
    Attack:
    - Cards with rank 2: the next player draws two cards from the stockpile;
    - Cards with rank 3: the next player draws three cards from the stockpile;
     Defense:
     - Cards with rank 7: cancel an attack, i.e. do not draw any card if a 2 or a 3 was played before;
     Action:
     - Queen cards: reverse the playing order from counter-clockwise to clockwise or clockwise to counter-clockwise;
      - Jack cards: skip the next player;
4. Notes on Cards and attacks
    - The effect of the attack cards is cumulative.
    - A Queen or a Jack, of the same suit as the previous card, can be played to redirect an attack on the previous player, or the player after the next one, respectively;
    - When attacked, a player not playing a special card (2, 3, 7, Q, J) must draw cards from the stockpile, before ending his turn.
    - The initially drawed card doesn't have special effect, it only decides the rank and suit the first player needs to play.
    - The Jack and Queen cards can be played subsequently, meanwhile, the effect of the previous attacks stays the same,  i.e. if the last player plays 2 of spades and now player1 has to draw 2 cards, player1 can play Jack and redirect the attack on player3, player3 can still play Jack and redirect the attack to player 5.
5. Notes on ascii art
    - To prevent the log file from too long, I only print the ascii art of the card when a player plays a card, the setting is rather easy to change---just switch the printcard function to printasciicard
6. When you are in the player vs player(real) mode, you are allowed to enter 0 to skip playing cards and just draw the cards. When you finished drawing cards, press any key to proceed to the next player.
7. If you want to see the process of playing the cards, add -D PLAY when compiling the project.(However, the sleep()function might not work the same on different systems.)
8. The code quality checks said that I missed a brace for a else, but I actually added the brace for that shell.
## Programming layers
### Layer 1---Basics
- printcard.c---functions used to display cards in different conditions.
    printcard---print card in both console and log file
    printcardinconsole---print card in the console
    printcardinfile---print card in the file
- player.c---handle player-related operations
    Initialize---Initialize player circular doubly linked list
    addplayer---Add a player to the list
    freeplayer---Free the memory of the list
    nextplayer---Decide who is the next player to play
    removeplayercards---remove the cards of one player
    displaycards---display the cards on the player's hand
    - Calls: printcard
- pile.c---handle card pile-related operations 
    initpile---Initialize card pile, allocate memory
    deletpile---Delete card pile, free memory
    addcard---Add cards to the pile
    removecard---Remove cards in the pile
    inpile---Decide if a card is in the pile
    - Calls:
    - -compeletequal
- comparecards.c---Functions to compare two cards
- printhelp.c---Print the help message
- gameround.c---Judge if someone wins and count the penalty points
- clearscreen.c---The function to clear the console
### Layer2---Initialization of game
- shuffle.c---functions to shuffle and reshuffle the card pile
    shuffle---Shuffle the cards in the form of decks
    Initshuffle---Add the shuffle result to the stock
    - Calls: 
    - -shuffle
    - -addcard
    - -initpile
    - -printcard
    - -printcardinfile
    reshuffle---The function to reshuffle cards when the stockpile exhausted
    - Calls:
    - -shuffle
    - -addcard
    - -initpile
    - deletpile
    - -printcard
    - -printcardinfile
### Layer3---Functions that only draw cards
- Drawcards.c---function to draw the card
    drawcards---draw one card from the stock pile
    - Calls:
    - reshuffle
    - removecard
    - printcard
    - inpile
- Dealcards.c---function to deal card to one player
    dealcards
    - Calls:
    - drawcards
- Decideplayer.c---functions to decide the first player
    discardcards---discard the card into discard pile
    - Calls:
    - addcards
    decideplayer---decide the first player
    - Calls:
    - comparecards
    - drawcards
    - addcard
### Layer4---Functions related to playing cards
- playcardsbasic.c---functions that initialize playing cards
    myalloc---Packing the allocating memory
    judgeffect---Judge the effect of the card played
    - Calls:
    - nextplayer
    choosecard---ask the player to choose a card
    playspecial---if the player plays a special card
    playregular---if the player plays a regular card
    isattack---if the card is an attacking card
    isaction---if the card is an action card
- autoplaycards.c---function to play the cards in auto mode(algorithm explained below)
    - Calls:
    - equalcards
    - dealcards
    - addcard
    - removecard
    - judgeffect
    - removeplayercards
    - displaycards
    - printcard
- realplaycards.c---function to play the cards in real mode
    - Calls:
    - equalcards
    - dealcards
    - addcard
    - removecard
    - judgeffect
    - removeplayercards
    - displaycards
    - printcard
    - choosecard
### Layer5---Two modes that have all the previous functions within it 
- auto.c: function to play in auto mode
- real.c---play in realmode

### Layer6---Full program
- main.c

## Algorithm Explained
### Function: Autoplaycards

If there is an attack in effect(buffer1 has card in attacking effect)
- If the person can play 2,3,7
    - The previously played card is discarded
    - Attacking effect changed
    - Rank and suit need to be matched changed
    - Play the card(player card goes into buffer)

- If the person can play Queen or Jack
    - The previously played card is discarded
    - The previous attack effect shouldn't change
    - Rank and suit need to be matched changed
    - The next player changed
    - Play the card(player card goes into buffer)

If there is no attack in effect
- If there is an action card in effect(buffer1 has card in action effect)
    - Don't judge its effect again
- If there isn't an action card in effect
    - If the person plays an attacking card
        - The previously played card is discarded
        - Attacking effect changed
        - Rank and suit need to be matched changed
        - Play the card(player card goes into buffer)
    - If the person plays an action card
        - The previous card is discarded
        - Rank and suit need to be matched changed
        - Action effect changed
        - Play the card(player card goes into buffer)
    - If the person plays a regular card
        - The previous card is discarded
        - Rank and suit need to be matched changed
        - Action effect not changed
        - Play the card(player card goes into buffer)
Judge if the player need to draw cards
Finally, judge the attacking&action effect