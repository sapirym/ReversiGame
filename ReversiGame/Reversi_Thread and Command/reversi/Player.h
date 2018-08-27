/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#ifndef EX3ADVENCED_PLAYER_H
#define EX3ADVENCED_PLAYER_H

#include <string>
using namespace std;

class Player {
public:
    /**
     * constructor.
     * @param myTurn
     * @param val
     */
    Player(bool myTurn,char val);
    Player();

    /**
     * print message
     */
    void printPlayerTurn();
    /**
     * @return 1 if is plater turn, 0- otherwise
     */
    bool isMyTurn();
    /**
     * @return player type
     */
    char getVal();
    /**
     *change the turn to other player
     * @param num
     */
    void setMyTurn(int num);
    /**
     * win message
     */
    void winGame();

private:
    bool myTurn;
    char val;
};


#endif //EX3ADVENCED_PLAYER_H
