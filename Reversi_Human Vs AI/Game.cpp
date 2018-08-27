

#include "Game.h"
#include "GameFlow.h"

Game::Game(Board &board1){
    board = board1;

}

void Game::initializeGame() {
    int  userChoose,flag=0;
    do {
        cout << "Choose (1) if you want to play against humen or (2) against computer:" << endl;
        cin >> userChoose;
        xPlayer = Player(1, 'X');
        oPlayer = Player(0, 'O');
        logicPlayer1 = new HumanLogic(board);
        if (userChoose == 1) {
            logicPlayer2 = new HumanLogic(board);
        } else if (userChoose == 2) {
            logicPlayer2 = new ComputerLogic(board);
        }
        if(userChoose!=1 && userChoose!=2)
            cout<<"Try again!"<<endl;
    } while(userChoose!=1 && userChoose!=2);

}



void Game::run(){
    int counter=0,flagO=0,flagX=0;
    GameFlow g(board, logicPlayer1, logicPlayer2);
    while(!board.fullBoard()) {
        if (xPlayer.isMyTurn()) {
            counter = g.playOneTurn('X');
            xPlayer.setMyTurn(0);
            oPlayer.setMyTurn(1);
            if (counter == 1)
                flagX = 1;
            else
                flagX = 0;
        } else if (oPlayer.isMyTurn()) {
            counter = g.playOneTurn('O');

            xPlayer.setMyTurn(1);
            oPlayer.setMyTurn(0);
            if (counter == 1)
                flagO = 1;
            else
                flagO = 0;
        }
        //If both players have no more moves to do
        if (flagO == 1 && flagX == 1)
            break;
    }

    board.printBoard();
    cout<<endl<<"Game Over!";

    //check who is the winner by compare the counters.
    if(board.getCountero()>board.getCounterx())
        cout<<endl<<"O You are the winner!"<<endl;
    else
        cout<<endl<<"X You are the winner!"<<endl;
}
Game::~Game(){
    delete logicPlayer1;
    delete logicPlayer2;
}