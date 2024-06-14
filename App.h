/**
 * @file 	App.h
 * @brief APP Header file.
 *
 * This file contains the declarations and definitions for the Application
 *
 * @author [Tic Tac Boom Team]
 * @date [27 APR 2024]
 *
 * @SWversion 1.0.0
 *
 */
/*==================================================================================================================================*/
#ifndef APP_H_
#define APP_H_

 /* ===================================================================================================
                                            Includes
    ===================================================================================================*/
#include <iostream>
#include <vector>

using namespace std;
/* ===================================================================================================
                                        Macro Definition
   ===================================================================================================*/
#define BOARD_SIZE   3
#define EMPTY_CELL  '-'
#define PLAYER_X    'X'
#define PLAYER_O    'O'

/* ===================================================================================================
                                        Type Definition
   ===================================================================================================*/

struct Move
{
	int row, col;
};

class TicTacToe
{
public:
    TicTacToe();
    void printBoard(const vector<vector<unsigned char>>& board) const;
    bool isWinner(const vector<vector<unsigned char>>& board, unsigned char player) const;
    int evaluate(const vector<vector<unsigned char>>& board,char state_F) const;
    Move findBestMove(vector<vector<unsigned char>>& board , unsigned char State_2);
    void humanMove(vector<vector<unsigned char>>& board, unsigned char player);
	bool isBoardFull(const vector<vector<unsigned char>>& board);
    void computerMove(unsigned char state);
    unsigned char getCurrentPlayer() const;
    unsigned char getCell(unsigned char row, unsigned char col) const;
    std::vector<std::vector<unsigned char>> board; // Tell mabrouk we know that board is 3 by 3
private:
    unsigned char currentPlayer = PLAYER_X; // just an instialization 
    int minimax(vector<vector<unsigned char>>& board, unsigned char depth, bool isMaximizingPlayer, int alpha, int beta, unsigned char State_3);
};


extern unsigned char RemPlays;


#endif /* APP_H_ */
