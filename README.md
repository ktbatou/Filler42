# Filler42

Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.

Each successfully placed piece yields a number of points, and has only one player, the
goal of the game could be to get the best score possible. However, it is with two players
that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the
end of the game, the one with the most points wins the match...

the game looks like that :

<img src="image/fillerMap.png" alt="Filler map">

## In this Project :

In this Project I'm creating a winner player who must get the best score in all matches.


I used the Heatmap algorithm to find the right position for each piece to get closer to my enemy and surround him with my pieces so i can have more pieces than him, in this alogo I get the map and then surround My Player with ascending numbers :

<img src="image/heat.png" alt="Heatmap">

When i get a piece, i try to put it into the map and then calculate the score of that piece :

<img src="image/piece.png" alt="Piece">

in this case the score is : 7.
if there is an other position where the piece can get higher score than 7, we will take that position.
