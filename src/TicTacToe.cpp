//============================================================================
// Name        : TicTacToe.cpp
// Author      : JulienRC
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : Tic-Tac-Toe in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


string board[10] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
string playerSign[2] = {"X", "O"};
string winner = "";

void printBoard();
bool isNotFinish();
string checkWinner();

int main() {

	int player = 0;

	int choice;

	do {
		//system("cls");
		printBoard();
		cout << "Turn : Player n° " << player + 1 << endl;
		cout << "Sign : " << playerSign[player] << endl;

		do {
			cout << "Select a free space to place a sign : ";
			cin >> choice;
		} while((choice < 1 || choice > 9) || (!board[choice].compare("-") == 0));

		board[choice] = playerSign[player];
		player = (player + 1) % 2;

	} while(isNotFinish());

	cout << "The match is finish !" << endl;

	printBoard();

	if(winner.compare("X") == 0)
		cout << "The player n° 1 is the winner" << endl;
	else if (winner.compare("O") == 0){
		cout << "The player n° 2 is the winner" << endl;
	}
	else {
		cout << "There is no winner" << endl;
	}


	return 0;
}

/**
 * Method to print the board in the console
 */
void printBoard(){
	cout << board[1] << " | " << board[2] << " | " << board[3] << "                        " << " 1 | 2 | 3 " << endl;
	cout << board[4] << " | " << board[5] << " | " << board[6] << "                        " << " 4 | 5 | 6 " << endl;
	cout << board[7] << " | " << board[8] << " | " << board[9] << "                        " << " 7 | 8 | 9 " << endl;
}

/**
 * Method to check if the game s finish
 * @return true if it's not finish, else otherwise
 */
bool isNotFinish(){
	winner = checkWinner();
	if(winner == "X" || winner == "O")
		return false;
	for(long unsigned int i = 1 ; i < sizeof(board)/sizeof(board[0]) ; i++) {
		if(board[i].compare("-") == 0) {
			return true;
		}
	}
	return false;
}

/**
 * Method to check if there is a winner
 * @return : X if the player 0 is the winner
 * 			 O if the player 1 if the winner
 * 			 E if there is no winner
 */
string checkWinner(){
	// VERTICAL
	if( (board[1].compare(board[4]) == 0) && (board[4].compare(board[7]) == 0) && ((board[1].compare("X") == 0 || board[1].compare("O"))) ){
		return board[1];
	} else if ( (board[2].compare(board[5]) == 0) && (board[5].compare(board[8]) == 0) && ((board[2].compare("X") == 0 || board[2].compare("O") == 0)) ){
		return board[2];
	} else if ( (board[3].compare(board[6]) == 0) && (board[6].compare(board[9]) == 0) && ((board[3].compare("X") == 0 || board[3].compare("O") == 0)) ){
		return board[3];
	}
	// HORIZONTAL
	else if ( (board[1].compare(board[2]) == 0) && (board[2].compare(board[3]) == 0) && ((board[1].compare("X") == 0 || board[1].compare("O") == 0)) ){
		return board[1];
	} else if ( (board[4].compare(board[5]) == 0) && (board[5].compare(board[6]) == 0) && ((board[4].compare("X") == 0 || board[4].compare("O") == 0)) ){
		return board[4];
	} else if ( (board[7].compare(board[8]) == 0) && (board[8].compare(board[9]) == 0) && ((board[7].compare("X") == 0 || board[7].compare("O") == 0)) ){
		return board[7];
	}
	// DIAGONAL
	else if ( (board[1].compare(board[5]) == 0) && (board[5].compare(board[9]) == 0) && ((board[1].compare("X") == 0 || board[1].compare("O") == 0)) ){
		return board[1];
	} else if ( (board[3].compare(board[5]) == 0) && (board[5].compare(board[7]) == 0) && ((board[3].compare("X") == 0 || board[3].compare("O") == 0)) ){
		return board[3];
	}
	return "E";
}


