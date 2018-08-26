

#include <iostream>
#include "Player.h"

Player::Player(bool myTurn,char typeUser) {
    myTurn=0;
    val=typeUser;
}

void Player::printPlayerTurn() {
    cout<<val<<": Its your move."<<endl;
}

bool Player::isMyTurn(){
    return myTurn;
}
char Player::getVal(){
    return val;
}

void Player::setMyTurn(int num){
    myTurn=num;
}

void Player::winGame(){
    cout<<endl<<val<<" You are the winner!";
}

Player::Player() {}
