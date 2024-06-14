/**
 * @file 	app.c
 * @brief APP Source file.
 *
 * This file contains The Application of Tic Tac Toe Game
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
                                               Global Variables
   ===================================================================================================*/
Move Current_Move;
unsigned char RemPlays = 9;
/* ===================================================================================================
                                              Function Definition
   ===================================================================================================*/

TicTacToe::TicTacToe()
{
		board = {
				   {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
				   {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
				   {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL} };

}
void TicTacToe::printBoard(const vector<vector<unsigned char>>& board) const
{
    for (unsigned char i = 0; i < BOARD_SIZE; ++i)
    {
        for (unsigned char  j = 0; j < BOARD_SIZE; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
// From where did you get the current move and doesn't we need the last move <maybe current untile we play>
bool TicTacToe::isWinner(const vector<vector<unsigned char>>& board, unsigned char player) const
{
	/* Check rows and columns */
    if (board[Current_Move.row][0] == player && board[Current_Move.row][1] == player && board[Current_Move.row][2] == player) return true;
    if (board[0][Current_Move.col] == player && board[1][Current_Move.col] == player && board[2][Current_Move.col] == player) return true;

    /* Check diagonals */
    if(Current_Move.row == Current_Move.col)
    {
    	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    		{
    			return true;
    		}
    	else
    		{

    		}
    }
    else
    {
				// Are we going to fill this gap ???
    }

    if((Current_Move.row == 0 && Current_Move.col == 2) || (Current_Move.row == 1 && Current_Move.col == 1) || (Current_Move.row == 2 && Current_Move.col == 0))
	{
    	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    		{
    			return true;
    		}
    	else
    		{

    		}
	}
    			return false;
}

int TicTacToe::evaluate(const vector<vector<unsigned char>>& board, char state_F) const
{
	if (state_F == PLAYER_O)
	{
    if (isWinner(board, PLAYER_O)) return 100; // Which board (should be diffrent..... ) are we working on and which current move ????
    if (isWinner(board, PLAYER_X)) return  0 ; // (becuase if we did some change here we do it in the original one)
    return 50 ; // Tie
	}

	if (state_F == PLAYER_X)
	{
    if (isWinner(board, PLAYER_X)) return 100; // Which board (should be diffrent..... ) are we working on and which current move ????
    if (isWinner(board, PLAYER_O)) return  0 ; // (becuase if we did some change here we do it in the original one)
    return 50 ; // Tie
	}
}

Move TicTacToe::findBestMove(vector<vector<unsigned char>>& board , unsigned char State_2)
{
	 int bestScore = INT_MIN;
	 Move bestMove;
	 bestMove.row = -1; // What if the position is wrong or already taken and some error happened 
	 bestMove.col = -1;
	    for (int i = 0; i < BOARD_SIZE; ++i)			// I want to find a Data Structer to optimize this
	    {
	        for (int j = 0; j < BOARD_SIZE; ++j)       // And This 
	        {
	            if (board[i][j] == EMPTY_CELL)		  // And This
	            {
	                board[i][j] = State_2;
	                int moveScore = minimax(board,RemPlays-1,false, INT_MIN, INT_MAX, State_2);
	                board[i][j] = EMPTY_CELL;
	                if (moveScore >= bestScore)
	                {
	                    bestScore = moveScore;
	                    bestMove.row = i;
	                    bestMove.col = j;
	                }
	            }
	        }
	    }

	    return bestMove;
}

int TicTacToe::minimax(vector<vector<unsigned char>>& board, unsigned char depth, bool isMaximizingPlayer, int alpha, int beta, unsigned char State_3)
{
    int score = evaluate(board,State_3);
    if (score != 50) return score;

	if (isBoardFull(board)) return 50;

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;
        for (int i = 0; i < BOARD_SIZE; ++i) {      // This is also related to the optmization 
            for (int j = 0; j < BOARD_SIZE; ++j) {  // This is also related to the optmization 
                if (board[i][j] == EMPTY_CELL) {
                    board[i][j] = State_3;
                    bestScore = std::max(bestScore, minimax(board,depth -1, false, alpha, beta,State_3)); // There was an infinte loop here
                    alpha = std::max(alpha, bestScore);
                    board[i][j] = EMPTY_CELL;
                    if (beta <= alpha) break; // Alpha-beta pruning Where does he break from a row ????
                }

            }
			if (beta <= alpha) break;
        }
        return bestScore;
    }
    else {
        int bestScore = INT_MAX;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
					if(State_3 == PLAYER_O)
                    board[i][j] = PLAYER_O;				// This needs optimization You can use State_3
					else 
					board[i][j] = PLAYER_X;
                    bestScore = std::min(bestScore, minimax(board,depth - 1, true, alpha, beta,State_3));
                    beta = std::min(beta, bestScore);
                    board[i][j] = EMPTY_CELL;
                    if (beta <= alpha) break; // Alpha-beta pruning
                }
            }
			if (beta <= alpha) break; // By this we can get out of all the possibelites of this condition
        }
        return bestScore;
    }
}
void TicTacToe::humanMove(vector<vector<unsigned char>>& board, unsigned char player)
{
	cout << "Enter your move (row and column): ";
	cin >> Current_Move.row >> Current_Move.col;
	while (Current_Move.row < 0 || Current_Move.row >= BOARD_SIZE || Current_Move.col < 0 || Current_Move.col >= BOARD_SIZE || board[Current_Move.row][Current_Move.col] != EMPTY_CELL)
	{
		cout << "Invalid move! Try again: ";
		cin >> Current_Move.row >> Current_Move.col;
	}
	board[Current_Move.row][Current_Move.col] = player;
	currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
	RemPlays--;
}

void TicTacToe::computerMove(unsigned char State)
{
	Move bestMove = findBestMove(board , State );
	board[bestMove.row][bestMove.col] = currentPlayer;
	currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
	RemPlays--;
}

bool TicTacToe::isBoardFull(const vector<vector<unsigned char>>& board) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			if (board[i][j] == EMPTY_CELL) return false;
		}
	}
	return true;
}

unsigned char TicTacToe::getCurrentPlayer() const
{
    return currentPlayer;
}

unsigned char TicTacToe::getCell(unsigned char row, unsigned char col) const
{
	return board[row][col];
}
