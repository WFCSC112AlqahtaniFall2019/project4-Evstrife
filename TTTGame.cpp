/* Class: TicTacToe
 * Author: Siyu Wu
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    int row1, col1;
    int numPlayers;
    char playagain;


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
        //one player start
    else if (numPlayers == 1) {
        while (playagain != 'n') {
            srand(time(nullptr));
            int first = rand() % 2 + 1;
            cout << "You will be playing against the computer." << endl;
            game.initializeBoard(); //clears board
            //takes the player 1's inputs and creates a random generated number while there is not a winner
            while (!game.checkForWin()) {
                if (first == 1) {
                    cout << "Your turn" << endl;
                    cout << "Please enter row and column:" << endl;
                    cin >> row1 >> col1;
                    // check if the number player entered is reasonable
                    while (row1 > 3 || col1 > 3 || row1 < 1 || col1 < 1) {
                        cout << "Try again! The input can only be 1, 2, 3. " << endl;
                        cin >> row1 >> col1;
                    }
                    while (!game.placeMark(row1 - 1, col1 - 1)) {
                        cout << "This place was already filled." << endl;
                        cin >> row1 >> col1;
                    }
                    cout << "You:" << endl;
                    game.placeMark(row1 - 1, col1 - 1);
                    game.printBoard();
                    game.changePlayer();
                    first++;
                }
                if (game.checkForWin()) {
                    break;
                }
                if (game.isBoardFull()) {
                    break;
                }
                //this will run when it is the computers turn and then will decrease firstMove at the end of the turn to allow player 1 a turn
                if (first == 2) {
                    //randomly generate rows and cols
                    row1 = rand() % 3 + 1;
                    col1 = rand() % 3 + 1;
                    //if the place is filled, generate a new one
                    while (!game.placeMark(row1 - 1, col1 - 1)) {
                        row1 = rand() % 3 + 1;
                        col1 = rand() % 3 + 1;
                    }
                    cout << "Computer:" << endl;
                    game.placeMark(row1 - 1, col1 - 1);
                    game.printBoard();
                    game.changePlayer();
                    first--;
                    if (game.isBoardFull()) {
                        break;
                    }
                    if (game.checkForWin()) {
                        break;
                    }
                }
            }
            // print winner,
            game.changePlayer();
            if (game.getCurrentPlayerNumber() == 2) {
                cout << "You win!" << endl;
                game.printBoard();
                cout << "Play again? (Type 'y'for yes and 'n' for no)" << endl;
                cin >> playagain;
            } else {
                cout << "The computer win! " << endl;
                game.printBoard();
                cout << "Play again? (Type 'y'for yes and 'n' for no)" << endl;
                cin >> playagain;
            }
            //prints that there was a tie and asks if the user wants to play again
            if (game.isBoardFull()) {
                cout << "Game draw! Play again? (Type 'y'for yes and 'n' for no)" << endl;
                cin >> playagain;
            }
        }
    } else if (numPlayers == 2) {
        while (playagain != 'n') {
            cout << "The Game has Started! Player 1 goes first! Make sure to put a space between two numbers!" << endl;
            for (int i = 0; i < 9; i++) {
                //Because there's a total nine spaces in the board, no more than 9 times will needed.
                //check if the board full, if the board is full and no one has won, game draw
                if (game.isBoardFull()) {
                    cout << "Game draw! Play again? (Type 'y'for yes and 'n' for no)" << endl;
                    cin >> playagain;
                } else {
                    int row1, col1;
                    cout << "Enter row and column:" << endl;
                    // let player mark the board in turns
                    for (i = 0;; i++) {
                        cin >> row1 >> col1;
                        // check if the number player entered is reasonable
                        if (row1 > 3 || col1 > 3 || row1 < 1 || col1 < 1) {
                            cout << "Try again! The input can only be 1, 2, 3. " << endl;
                        } else if (!game.placeMark(row1 - 1, col1 - 1)) {
                            cout << "This place was already filled." << endl;
                        }
                        else {
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
            cout << "Play again? (Type 'y'for yes and 'n' for no)" << endl;
            cin >> playagain;
        }
    }
}

