#include <iostream>
#include <cstdlib>

void displayBoard(char ArrBoard[3][3]);
void player1Choice(char ArrBoard[3][3]);
void player2Choice(char ArrBoard[3][3]);

using namespace std;

int main()
{
    int p1Score = 0, p2Score = 0;
    char ArrBoard[3][3] ={{'1', '2', '3'},      // Array the will map the structure of the board
                          {'4', '5', '6'},
                          {'7', '8', '9'}};

    displayBoard(ArrBoard); // Displays the board for the game

    while(p1Score == 0 && p2Score == 0){
        player1Choice(ArrBoard);    // Function call for player 1's input
        displayBoard(ArrBoard);     // Displays the updated board

        player2Choice(ArrBoard);    // Function call for player 2's input
        displayBoard(ArrBoard);     // Displays the updated board
    }

    return 0;
}

void displayBoard(char ArrBoard[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << ArrBoard[i][j] << " ";

        }
        cout << endl;
    }
}

void player1Choice(char ArrBoard[3][3]){
    char p1;

    top:
    // Ask input for player 1
    cout << "\n\n\n";
    cout << "Player 1, Enter your move: ";
    cin >> p1;

    if(p1 == '1' && ArrBoard[0][0] != 'O' &&  ArrBoard[0][0] != 'X'){
        ArrBoard[0][0] = 'X';
    }
    else if(p1 == '2' && ArrBoard[0][1] != 'O' && ArrBoard[0][1] != 'X'){
        ArrBoard[0][1] = 'X';
    }
    else if(p1 == '3' && ArrBoard[0][2] != 'O' && ArrBoard[0][2] != 'X'){
        ArrBoard[0][2] = 'X';
    }
    else if(p1 == '4' && ArrBoard[1][0] != 'O' && ArrBoard[1][0] != 'X'){
        ArrBoard[1][0] = 'X';
    }
    else if(p1 == '5' && ArrBoard[1][1] != 'O' && ArrBoard[1][1] != 'X'){
        ArrBoard[1][1] = 'X';
    }
    else if(p1 == '6' && ArrBoard[1][2] != 'O' && ArrBoard[1][2] != 'X'){
        ArrBoard[1][2] = 'X';
    }
    else if(p1 == '7' && ArrBoard[2][0] != 'O' && ArrBoard[2][0] != 'X'){
        ArrBoard[2][0] = 'X';
    }
    else if(p1 == '8' && ArrBoard[2][1] != 'O' && ArrBoard[2][1] != 'X'){
        ArrBoard[2][1] = 'X';
    }
    else if(p1 == '9' && ArrBoard[2][2] != 'O' && ArrBoard[2][2] != 'X'){
        ArrBoard[2][2] = 'X';
    }
    else{
        cout << "Invalid Input\n";
        system("PAUSE");
        displayBoard(ArrBoard);
        goto top;
    }
}

void player2Choice(char ArrBoard[3][3]){
    char p2;

    // Ask input for player 2
    cout << "\n";
    cout << "Player 2, Enter your move: ";
    cin >> p2;

    if(p2 == '1'){
        ArrBoard[0][0] = 'O';
    }
    else if(p2 == '2'){
        ArrBoard[0][1] = 'O';
    }
    else if(p2 == '3'){
        ArrBoard[0][2] = 'O';
    }
    else if(p2 == '4'){
        ArrBoard[1][0] = 'O';
    }
    else if(p2 == '5'){
        ArrBoard[1][1] = 'O';
    }
    else if(p2 == '6'){
        ArrBoard[1][2] = 'O';
    }
    else if(p2 == '7'){
        ArrBoard[2][0] = 'O';
    }
    else if(p2 == '8'){
        ArrBoard[2][1] = 'O';
    }
    else if(p2 == '9'){
        ArrBoard[2][2] = 'O';
    }
}
