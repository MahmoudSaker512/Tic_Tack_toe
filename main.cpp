/**
 * @file 	main.c
 * @brief Main Source file.
 *
 * This file contains The Main Code of Tic Tac Toe Game
 *
 * @author [Tic Tac Boom Team]
 * @date [27 APR 2024]
 *
 * @SWversion 1.0.0
 *
 */
 /*==================================================================================================================================*/

 /* ===================================================================================================
                                            Includes
    ===================================================================================================*/
#include "App.h"
 /* ===================================================================================================
                                            Main Code
    ===================================================================================================*/
int main()
{
	TicTacToe game; // Instantiate TicTacToe object with default constructor
	int choice = 1;
	int choice_start = 1 ; 
	unsigned char Computer = 'X'; // This is only an intialization 
	unsigned char Human = 'O';    // """"""""""""""""""""""""""""""

	std::cout << "Choose mode: \n1. Play against computer\n2. Play against friend\n";
	std::cin >> choice;

	if (choice == 1) {
		std::cout<<"Choose who starts : \n1. Computer starts\n2. Human starts\n";
		std::cin>> choice_start;
		if (choice_start==1)
			{
				Human    = PLAYER_O;
				Computer = PLAYER_X;
			}
		else if (choice_start == 2)
			{
				Human    = PLAYER_X;
				Computer = PLAYER_O;
			}
		else 
		    {
				std::cout<< " invalide input will play by defult \n"; /* We can use random here*/
			}

	    while (true) {
	        std::cout << "Current board:" << std::endl;
	        game.printBoard(game.board);
			
	        if (RemPlays <= 4 && game.isWinner(game.board, Human) ) {
	            std::cout << "You win!" << std::endl;
	            break;
	        }
	        if ( RemPlays <= 4 && game.isWinner(game.board, Computer)) {
	            std::cout << "Computer wins!" << std::endl;
	            break;
	        }
	        if (!RemPlays) // what if not reaching here 
	        {
	            std::cout << "It's a tie!" << std::endl;
	            break;
	        }

	        if (game.getCurrentPlayer() == Human)
	        {
	            game.humanMove(game.board, Human);
	        }
	        else if (game.getCurrentPlayer() == Computer)
	        {
				std::cout << "Computer's move:" << std::endl;
	            game.computerMove(Computer);
	        }
	    }
	}
	else if (choice == 2) {
	    while (true) {
	        std::cout << "Current board:" << std::endl;
	        game.printBoard(game.board);

	        if (game.isWinner(game.board, PLAYER_X) && RemPlays <= 4) {
	            std::cout << "Player X wins!" << std::endl;
	            break;
	        }
	        if (game.isWinner(game.board, PLAYER_O) && RemPlays <= 4) {

	            std::cout << "Player O wins!" << std::endl;
	            break;
	        }
	        if (!RemPlays)
	        {
	            std::cout << "It's a tie!" << std::endl;
	            break;
	        }
	        unsigned char currentPlayer = game.getCurrentPlayer();
	        game.humanMove(game.board, currentPlayer);
	    }
	}
	else {
	    std::cout << "Invalid choice! Exiting..." << std::endl;
	}

	return 0;

}

