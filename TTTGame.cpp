/* Class: TicTacToe
 * Author: Siyu Wu
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    int player;
    int numPlayers;
    string playagain = "Yes";


        TicTacToe game;
        //initialize the game board
        game.initializeBoard();
        //print the board
        game.printBoard();
        //user enter the number of players
        cout << "Please Enter you are 1 player or 2 players?" << endl;
        cin >> numPlayers;


        //check if the input is 1 or 2
        if (numPlayers != 1 && numPlayers != 2) {
            cout << "Please try again and enter either 1 or 2 players." << endl;
            return 0;
        }
        else if (numPlayers == 1){
            cout<< "You are playing against computer"<<endl;
            srand(time(0));
            player = rand()% 2;
            if(player == 1){
                game.changePlayer();
                cout << "You are player " << game.getCurrentPlayerNumber() << " playing as the o" << endl;
            }
        }

        else if (numPlayers == 2) {
            cout << "The Game has Started! Player 1 goes first! Make sure to put a space between two numbers!" << endl;
            for (int i = 0; i < 9; i++) {
                //Because there's a total nine spaces in the board, no more than 9 times will needed.
                //check if the board full, if the board is full and no one has won, game draw
                if (game.isBoardFull()) {
                    cout << "Game Draw!";
                    break;
                } else {
                    int row1, col1;
                    cout << "Enter row and column:" << endl;
                    // let player mark the board in turns
                    for (i = 0;; i++) {
                        cin >> row1 >> col1;
                        // check if the number player entered is reasonable
                        if (row1 > 3 || col1 > 3 || row1 < 1 || col1 < 1) {
                            cout << "Try again! The input can only be 1, 2, 3. " << endl;
                        }  else if (!game.placeMark(row1 - 1, col1 - 1)) {
                            cout << "This place was already filled." << endl;
                        } else {
                            break;
                        }
                    }
                    //place the mark for player on the board
                    game.placeMark(row1 - 1, col1 - 1);
                    game.printBoard();
                    //check for win by checking if there is a straight 3 same marks in a row or a column
                    if (game.checkForWin()) {
                        cout << "Player" << game.getCurrentPlayerNumber() << " wins!" << endl;
                        break;
                    }
                    //switch players
                    game.changePlayer();

                }
            }

        }



}