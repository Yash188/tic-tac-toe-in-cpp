#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Turn{

    char player;
    int position;

};

bool CheckPlayerWin( vector<Turn> &playerMoves){
    bool hasWon = false;
    set<int> allMoves;

    for(auto mov : playerMoves){
        allMoves.emplace(mov.position);
    }

    //checking diagonal conditions
    if(allMoves.count(1) == 1 && allMoves.count(5) == 1 && allMoves.count(9) == 1){
        hasWon = true;
    }

    if(allMoves.count(3) == 1 && allMoves.count(5) == 1 && allMoves.count(7) == 1){
        hasWon = true;
    }

    //vertical consitions
    if(allMoves.count(1) == 1 && allMoves.count(4) == 1 && allMoves.count(7) == 1){
        hasWon = true;
    }

    if(allMoves.count(2) == 1 && allMoves.count(5) == 1 && allMoves.count(8) == 1){
        hasWon = true;
    }

    if(allMoves.count(3) == 1 && allMoves.count(6) == 1 && allMoves.count(9) == 1){
        hasWon = true;
    }

    // horizontal conditions
    if(allMoves.count(1) == 1 && allMoves.count(2) == 1 && allMoves.count(3) == 1){
        hasWon = true;
    }

    if(allMoves.count(4) == 1 && allMoves.count(5) == 1 && allMoves.count(6) == 1){
        hasWon = true;
    }

    if(allMoves.count(7) == 1 && allMoves.count(8) == 1 && allMoves.count(9) == 1){
        hasWon = true;
    }


    return hasWon;
}


void PrintHeader(){

    cout << "=============================================================="<< endl;
    cout << "\t\t Tic Tac Toe"<< endl;
    cout << "=============================================================="<< endl;

    cout << endl;
    cout << "Player 1 : x"<<endl;
    cout << "Player 2 : o"<<endl;
    cout << endl;
}

void PrintGameOverPanel(){

    cout << "=============================================================="<< endl;
    cout << "\t\t Game Over"<< endl;
    cout << "=============================================================="<< endl;

    cout << endl;
    cout << endl;
}

bool CheckWin(vector<Turn> &turnList){

    // will check if x has won the game
    vector<Turn> xMoves;
    for(auto mov : turnList){
        if(mov.player == 'x'){
            xMoves.push_back(mov);
        }
    }

    if(xMoves.size() >=3){
        if(CheckPlayerWin(xMoves)){
            cout << endl;
            cout << "x has won the game"<<endl;
             return false;
        }
    }

    // x has not won check o
    vector<Turn> oMoves;
    for(auto mov : turnList){
        if(mov.player == 'o'){
            oMoves.push_back(mov);
        }
    }

    if(oMoves.size() >= 3){
        if(CheckPlayerWin(xMoves)){
                cout << endl;
            cout << "o has won the game"<<endl;
             return false;
        }
    }

    // no one has won yet

    //check tie condition
    if(turnList.size() == 9){
            cout << endl;
        cout << "Game Tied"<<endl;
         return false;
    }

    return true;
}


bool IsValidEntry(vector<Turn> &turnList,int _turnInput){
    bool isValid = true;
    for(auto entry : turnList){
        if(entry.position == _turnInput){
            isValid = false;
        }
    }

    return isValid;
}

int main()
{
    vector<Turn> turnList;
    PrintHeader();

    cout << "Game Starts with player 1's (x) turn"<<endl;
    cout << "Enter position from 1 to 9 both inclusive to make your turn "<<endl;
    cout << endl;
    char currentTurn = 'x';

    do{

        cout << currentTurn << "'s turn : ";

        int turnInput;
        cin >> turnInput;
        while(turnInput < 1 || turnInput > 9 || !IsValidEntry(turnList,turnInput)){
            cout << "Invalid Input! Please enter valid Input again : ";
            cin >> turnInput;
        }


        Turn lastTurn;
        lastTurn.player = currentTurn;
        lastTurn.position = turnInput;

        if(currentTurn == 'o'){
            currentTurn = 'x';
        }else{
            currentTurn = 'o';
        }
        turnList.push_back(lastTurn);

    }while(CheckWin(turnList));

    PrintGameOverPanel();
    return 0;
}
