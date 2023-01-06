# Snake-Game
Snake is a classic video game where the player controls a snake that moves around the screen and picks up items while avoiding obstacles. In a Snake game written in C, the player uses the arrow keys to control the direction of the snake's movement. As the snake moves, it leaves a trail behind it, and the player must navigate the snake through the screen without running into the walls or its own tail. The snake grows in length each time it picks up an item, which can be a piece of fruit or some other item. The game ends when the snake crashes into an obstacle or its own tail. The goal of the game is to score as many points as possible by collecting items and surviving for as long as possible.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The given code is a Snake game implemented in C language. The main function consists of an infinite loop that performs the following operations:

Calls the check function to check if the snake has eaten the fruit yet or not. If the snake has eaten the fruit, the fruit function is called to spawn a new fruit.
Calls the set_board function to set the board and update the boundary, fruit, and snake.
Calls the print function to print the 2D array representing the board.
Calls the input function to get the input from the user and update the position of the snake accordingly.
Calls the game_over function to check if the snake has touched the boundary or if the user has pressed the 'x' key. If either of these conditions is true, the game is over and the program exits.
The set_board function initializes the board with '#' characters representing the boundary and ' ' characters representing empty spaces. It then places the snake at its current position using the '0' character and the fruit at its current position using the '@' character.

The fruit function generates random coordinates for the fruit to spawn at.

The print function prints the 2D array representing the board to the screen.

The game_over function checks if the snake has touched the boundary or if the user has pressed the 'x' key. If either of these conditions is true, the game is over and the program exits.

The check function checks if the snake has eaten the fruit yet or not. If the snake has eaten the fruit, the fruit function is called to spawn a new fruit.

The input function gets the input from the user and updates the position of the snake accordingly. The getch function is used to get the input from the user without the need to press the 'enter' key.

Overall, this code implements a basic Snake game where the player can move the snake around the screen using the arrow keys and score points by collecting fruits. The game ends when the snake touches the boundary or the user presses the 'x' key.
