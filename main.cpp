//
//  main.cpp
//  FindTheGold
//
//  Copyright © 2018 Rheonda Ogletree. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int ROW = 8;
const int COL = 8;


void displayBoard(char questionBoard[ROW][COL]);
void printInstructions();
void randomSpot(char boardArray[ROW][COL]);
void playerGuess(char questionBoard[ROW][COL], char boardArray[ROW][COL]);
void finalBoard(char boardArray[ROW][COL]);


int main()
{
    srand(time(NULL));
    
    
    // Question Mark Array
    char questionBoard[ROW][COL] =
    {
        '?','?','?','?','?','?','?','?','?','?',
        '?','?','?','?','?','?','?','?','?','?',
        '?','?','?','?','?','?','?','?','?','?',
        '?','?','?','?','?','?','?','?','?','?',
        '?','?','?','?','?','?','?','?','?','?',
        '?','?','?','?','?','?','?','?','?','?',
        '?','?','?','?'
    };
    
    char boardArray[ROW][COL];
    
    char answer = 'n';
    // do while loop for the user to replay the game
    do
    {
        
        displayBoard(questionBoard);
        printInstructions();
        randomSpot(boardArray);
        playerGuess(boardArray, questionBoard);
        finalBoard(boardArray);
        
        cout << " Do you want to play again? [Y/N] " << endl;
        cin >> answer;
    }
    while (answer == 'Y' || answer == 'y');
    
    cout << "Good Job!" << endl;
    
    
    return 0;
}
//Displays Initial Board with Question Marks on Plot
void displayBoard(char questionBoard[ROW][COL])
{
    int r, c;
    
    cout << "   ";
    for (c = 0; c < COL; c++)
        cout << "  " << c + 1 << "  ";
    cout << endl;
    cout << "    _______________________________________ ";
    cout << endl;
    
    for ( r = 0; r < ROW; r++)
    {
        cout << r + 1 << " |";
        for ( c = 0; c < COL; c++)
        {
            cout << "  ?  ";
        }
        cout << endl;
    }
}

// Displays The Instruction Box
void printInstructions()
{
    cout << "    _______________________________________ " << endl;
    cout << "**  ************************************* **" << endl;
    cout << "**               Find Gold!               **" << endl;
    cout << "**           You have 5 guesses,          **" << endl;
    cout << "**             5 pieces of gold           **" << endl;
    cout << "**               and 1 bomb               **" << endl;
    cout << "**               Good Luck!               **" << endl;
    cout << "**  ************************************* **" << endl;
    
    cout << endl;
}

/* displays the board with the number perimeter and question marks in an array, when the gold is in the location a G is displayed, if there is a bomb a B is displayed*/
void finalBoard(char boardArray[ROW][COL])
{
    int r, c;
    
    cout << "    ";
    for (c = 0; c < COL; c++)
        cout << "  " << c + 1 << "  ";
    cout << endl;
    cout << "    _______________________________________ ";
    cout << endl;
    
    for(r = 0; r < ROW; r++)
    {
        cout << r + 1 << " | " ;
        for(c = 0; c < COL; c++)
        {
            if(boardArray[r][c] != 'G')
            {
                if(boardArray[r][c] != 'B')
                {
                    boardArray[r][c] = '?';
                }
            }
            cout << "  " << boardArray[r][c] << "  ";
        }
        cout << endl;
    }
}

void randomSpot(char boardArray[8][8])
{
    int gold = 0;
    int bomb = 0;
    
    do
    {
        int X = rand() % 8;
        int Y = rand() % 8;
        
        if(boardArray[X][Y] != 'G')
        {
            boardArray[X][Y] = 'G';
            gold++;
        }
    }
    while (gold <= 5);
    
    do
    {
        int coorX = rand() % 8;
        int coorY = rand() % 8;
        
        if (boardArray[coorX][coorY] != 'B')
        {
            boardArray[coorX][coorY] = 'B';
            bomb++;
        }
    }
    while (bomb != 1);
}
/* Runs through a if else statement loop, when gold is found the player gets another guess, if not the guess goes down
 if a bomb is found, the game ends and the player can choose to play again */
void playerGuess(char boardArray[ROW][COL], char questionBoard[ROW][COL])
{
    int guess = 5;
    int score = 0;
    int coorX, coorY;
    do
    {
        cout << "Enter x coordinate: ";
        cin >> coorX;
        
        cout << "Enter y coordinate: ";
        cin >> coorY;
        
        if(boardArray[coorX - 1][coorY - 1] == 'G')
        {
            questionBoard[coorX - 1][coorY - 1] = 'G';
            cout << "You Found Gold! Bonus Guess Earned!" << endl;
            guess++;
            score++;
        }
        
        else if(boardArray[coorX - 1][coorY - 1] == 'B')
        {
            questionBoard[coorX - 1][coorY- 1] = 'B';
            cout << "BOMB! GAME OVER!" << endl;
            break;
        }
        else
        {
            cout << "Too Bad..." << endl;
            guess--;
        }
        
        if (guess == 4)
        {
            cout << " 4 guesses left" << endl;
            cout << endl;
        }
        else if (guess == 3)
        {
            cout << " 3 guesses left" << endl;
            cout << endl;
        }
        else if (guess == 2)
        {
            cout << " 2 guesses left" << endl;
            cout << endl;
        }
        else if (guess == 1)
        {
            cout << " Only 1 guess left" << endl;
            cout << endl;
        }
        else if (guess == 0)
        {
            cout << " Game Over " << endl;
            cout << "You Found " << score << " Gold Piece(s)" << endl;
            cout << endl;
        }
    }
    while (guess > 0);
}
