#include <iostream>
#include <cstdlib>
#include <ctime>

void gameMenu();
void displayBoard(char ArrBoard[3][3]);
void computerChoice(char ArrBoard[3][3]);
void player1Choice(char ArrBoard[3][3]);
void player2Choice(char ArrBoard[3][3]);
void gameLogic(char ArrBoard[3][3]);

using namespace std;

int p1Score = 0, p2Score = 0, compScore = 0, checkBoard = 0;
char arrayMoves[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char p1;

int main()
{
    int gameMode;
    char ArrBoard[3][3] ={{'1', '2', '3'},      // Array the will map the structure of the board
                          {'4', '5', '6'},
                          {'7', '8', '9'}};

    gameMenu();

    cout << "Enter the number of your choice: ";
    cin >> gameMode;

    switch(gameMode){
        case 1:
            displayBoard(ArrBoard);

            while(p1Score == 0 && compScore == 0){
                player1Choice(ArrBoard);    // Function call for player 1's input
                displayBoard(ArrBoard);     // Displays the updated board
                gameLogic(ArrBoard);        // Function for the logic of the gamne

                if(p1Score != 0 || compScore != 0 || checkBoard == 9 ){
                    break;
                }

                computerChoice(ArrBoard);    // Function call for player 2's input
                displayBoard(ArrBoard);     // Displays the updated board
                gameLogic(ArrBoard);
            }

            cout << endl;
            if(p1Score > compScore){
                cout << "Player 1 wins\n";
            }
            else if(p1Score < compScore){
                cout << "Player 2 wins\n";
            }
            else{
                cout << "No one win\n";
            }
            break;

        case 2:
            displayBoard(ArrBoard); // Displays the board for the game

            while(p1Score == 0 && p2Score == 0){
                player1Choice(ArrBoard);    // Function call for player 1's input
                displayBoard(ArrBoard);     // Displays the updated board
                gameLogic(ArrBoard);        // Function for the logic of the gamne

                if(p1Score != 0 || p2Score != 0 || checkBoard == 9 ){
                    break;
                }

                player2Choice(ArrBoard);    // Function call for player 2's input
                displayBoard(ArrBoard);     // Displays the updated board
                gameLogic(ArrBoard);
            }

            cout << endl;
            if(p1Score > p2Score){
                cout << "Player 1 wins\n";
            }
            else if(p1Score < p2Score){
                cout << "Computer wins\n";
            }
            else{
                cout << "No one win\n";
            }
            break;

        case 0:
            return 0;
            break;

        default:
            cout << "Invalid Input";
    }
}

void gameMenu(){
    cout << "[1] - V S  C O M P U T E R\n\n";
    cout << "[2] - M U L T I P L A Y E R\n\n";
    cout << "[0] - E X I T\n\n";
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
    top:
    // Ask input for player 1
    cout << "\n";
    cout << "Player 1, Enter your move: ";
    cin >> p1;

    if(p1 == '1' && ArrBoard[0][0] != 'O' &&  ArrBoard[0][0] != 'X'){
        ArrBoard[0][0] = 'X';
        checkBoard++;
    }
    else if(p1 == '2' && ArrBoard[0][1] != 'O' && ArrBoard[0][1] != 'X'){
        ArrBoard[0][1] = 'X';
        checkBoard++;
    }
    else if(p1 == '3' && ArrBoard[0][2] != 'O' && ArrBoard[0][2] != 'X'){
        ArrBoard[0][2] = 'X';
        checkBoard++;
    }
    else if(p1 == '4' && ArrBoard[1][0] != 'O' && ArrBoard[1][0] != 'X'){
        ArrBoard[1][0] = 'X';
        checkBoard++;
    }
    else if(p1 == '5' && ArrBoard[1][1] != 'O' && ArrBoard[1][1] != 'X'){
        ArrBoard[1][1] = 'X';
        checkBoard++;
    }
    else if(p1 == '6' && ArrBoard[1][2] != 'O' && ArrBoard[1][2] != 'X'){
        ArrBoard[1][2] = 'X';
        checkBoard++;
    }
    else if(p1 == '7' && ArrBoard[2][0] != 'O' && ArrBoard[2][0] != 'X'){
        ArrBoard[2][0] = 'X';
        checkBoard++;
    }
    else if(p1 == '8' && ArrBoard[2][1] != 'O' && ArrBoard[2][1] != 'X'){
        ArrBoard[2][1] = 'X';
        checkBoard++;
    }
    else if(p1 == '9' && ArrBoard[2][2] != 'O' && ArrBoard[2][2] != 'X'){
        ArrBoard[2][2] = 'X';
        checkBoard++;
    }
    else{
        cout << "Invalid Input\n";
        system("PAUSE");
        displayBoard(ArrBoard);
        goto top;
    }
}

void computerChoice(char ArrBoard[3][3]){
    int pos, moveCtr = 0, randNum;

    // Find the postion of the move chose by player 1
    for(int i = 0; i < 9; i++){
        if(arrayMoves[i] == p1){
            pos = i;
            break;
        }
    }

    arrayMoves[pos] = 'X';      // Change the valuse of the certain positon into player 1's move

    for(int i = 0; i < 9; i++){
        if(arrayMoves[i] == 'X'){
            moveCtr++;
        }
    }

    cout << "\nComputer Move\n";

    top:
    srand(time(NULL));
    randNum = 0 + (rand() % 8);     // Random number generator

    // For computer's move
    if(moveCtr == 1){
        if(arrayMoves[randNum] == '1'){
            ArrBoard[0][0] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '2'){
            ArrBoard[0][1] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '3'){
            ArrBoard[0][2] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '4'){
            ArrBoard[1][0] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '5'){
            ArrBoard[1][1] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '6'){
            ArrBoard[1][2] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '7'){
            ArrBoard[2][0] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '8'){
            ArrBoard[2][1] = 'O';
            checkBoard++;
        }
        else if(arrayMoves[randNum] == '9'){
            ArrBoard[2][2] = 'O';
            checkBoard++;
        }
        else{
            goto top;
        }
    }
    else if(moveCtr > 1){
        if((ArrBoard[0][0] == 'X' && ArrBoard[0][1] == 'X' && ArrBoard[0][2] != 'O') ||
           (ArrBoard[2][0] == 'X' && ArrBoard[1][1] == 'X' && ArrBoard[0][2] != 'O') ||
           (ArrBoard[1][2] == 'X' && ArrBoard[2][2] == 'X' && ArrBoard[0][2] != 'O')){
            ArrBoard[0][2] = 'O';
        }
        //else if(ArrBoard[2][0] == 'X' && ArrBoard[2][1] == 'X' && ArrBoard[0][2] != 'O'){
        //    ArrBoard[0][2] = 'O';
        //}
    }

    // Display the computer's move
    cout << "Computer chose: " << randNum + 1 << endl;
    arrayMoves[randNum] = 'O';

    moveCtr = 0;
}

void player2Choice(char ArrBoard[3][3]){
    char p2;

    top:
    // Ask input for player 2
    cout << "\n";
    cout << "Player 2, Enter your move: ";
    cin >> p2;

    if(p2 == '1' && ArrBoard[0][0] != 'X' && ArrBoard[0][0] != 'O'){
        ArrBoard[0][0] = 'O';
        checkBoard++;
    }
    else if(p2 == '2' && ArrBoard[0][1] != 'X' && ArrBoard[0][1] != 'O'){
        ArrBoard[0][1] = 'O';
        checkBoard++;
    }
    else if(p2 == '3' && ArrBoard[0][2] != 'X' && ArrBoard[0][2] != 'O'){
        ArrBoard[0][2] = 'O';
        checkBoard++;
    }
    else if(p2 == '4' && ArrBoard[1][0] != 'X' && ArrBoard[1][0] != 'O'){
        ArrBoard[1][0] = 'O';
        checkBoard++;
    }
    else if(p2 == '5' && ArrBoard[1][1] != 'X' && ArrBoard[1][1] != 'O'){
        ArrBoard[1][1] = 'O';
        checkBoard++;
    }
    else if(p2 == '6' && ArrBoard[1][2] != 'X' && ArrBoard[1][2] != 'O'){
        ArrBoard[1][2] = 'O';
        checkBoard++;
    }
    else if(p2 == '7' && ArrBoard[2][0] != 'X' && ArrBoard[2][0] != 'O'){
        ArrBoard[2][0] = 'O';
        checkBoard++;
    }
    else if(p2 == '8' && ArrBoard[2][1] != 'X' && ArrBoard[2][1] != 'O'){
        ArrBoard[2][1] = 'O';
        checkBoard++;
    }
    else if(p2 == '9' && ArrBoard[2][2] != 'X' && ArrBoard[2][2] != 'O'){
        ArrBoard[2][2] = 'O';
        checkBoard++;
    }
    else{
        cout << "Invalid Input\n";
        system("PAUSE");
        displayBoard(ArrBoard);
        goto top;
    }
}

void gameLogic(char ArrBoard[3][3]){
    if((ArrBoard[0][0] == 'X' && ArrBoard[0][1] == 'X' && ArrBoard[0][2] == 'X') ||
       (ArrBoard[1][0] == 'X' && ArrBoard[1][1] == 'X' && ArrBoard[1][2] == 'X') ||
       (ArrBoard[2][0] == 'X' && ArrBoard[2][1] == 'X' && ArrBoard[2][2] == 'X') ||
       (ArrBoard[0][0] == 'X' && ArrBoard[1][0] == 'X' && ArrBoard[2][0] == 'X') ||
       (ArrBoard[0][1] == 'X' && ArrBoard[1][1] == 'X' && ArrBoard[2][1] == 'X') ||
       (ArrBoard[0][2] == 'X' && ArrBoard[1][2] == 'X' && ArrBoard[2][2] == 'X') ||
       (ArrBoard[0][0] == 'X' && ArrBoard[1][1] == 'X' && ArrBoard[2][2] == 'X') ||
       (ArrBoard[0][2] == 'X' && ArrBoard[1][1] == 'X' && ArrBoard[2][0] == 'X')
       ){
            p1Score++;
        }

    else if((ArrBoard[0][0] == 'O' && ArrBoard[0][1] == 'O' && ArrBoard[0][2] == 'O') ||
       (ArrBoard[1][0] == 'O' && ArrBoard[1][1] == 'O' && ArrBoard[1][2] == 'O') ||
       (ArrBoard[2][0] == 'O' && ArrBoard[2][1] == 'O' && ArrBoard[2][2] == 'O') ||
       (ArrBoard[0][0] == 'O' && ArrBoard[1][0] == 'O' && ArrBoard[2][0] == 'O') ||
       (ArrBoard[0][1] == 'O' && ArrBoard[1][1] == 'O' && ArrBoard[2][1] == 'O') ||
       (ArrBoard[0][2] == 'O' && ArrBoard[1][2] == 'O' && ArrBoard[2][2] == 'O') ||
       (ArrBoard[0][0] == 'O' && ArrBoard[1][1] == 'O' && ArrBoard[2][2] == 'O') ||
       (ArrBoard[0][2] == 'O' && ArrBoard[1][1] == 'O' && ArrBoard[2][0] == 'O')
       ){
            p2Score++;
            compScore++;
        }
}
