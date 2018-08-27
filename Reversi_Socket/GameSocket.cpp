
#include "GameSocket.h"


GameSocket::GameSocket(HumanLogic *player1) {
    player=player1;
}

Point GameSocket::playOneTurn(char type) {
    if (board.fullBoard()) {
        if (board.getCountero() > board.getCounterx()) {
            if (type == 'O')
                cout << endl << "O You are the winner!" << endl;
            else
                cout << endl << "you are the loser, O the winner!" << endl;
        } else {
            if (type == 'X')
                cout << endl << "X You are the winner!" << endl;
            else
                cout << endl << "you are the loser, X the winner!" << endl;
        }
        return Point(-3, -3);
    }
    board.printBoard();
    cout << type << ": Its your move." << endl;
    vector<Point> op;
    cout << "Your possible moves: ";
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            //send a clean cell and check is option
            if (board.getCell(i, j)->isClear()) {
                if (type == 'X') {
                    vector<Point> p = player->optionCell(i, j, type, 0);
                    if (!p.empty()) {
                        //print the option
                        op.push_back(Point(i, j));
                    }
                } else {
                    vector<Point> p = player->optionCell(i, j, type, 0);
                    if (!p.empty()) {
                        op.push_back(Point(i, j));
                    }
                }
            }
        }
    }
    int flag = 0;
    char dummy;
    if (!op.empty()) {
        do {
            int numX = 0, numY = 0;
            cout << endl << "Please enter your move- row col: (e.g. 3 4) ";
            cin >> numX >> numY;
            cout << endl;
            for (int i = 0; i < op.size(); i++) {
                //if the input match to the possible move points
                if (op[i].getX() == numX - 1 && op[i].getY() == numY - 1) {
                    vector<Point> p = player->optionCell(numX - 1, numY - 1, type, 1);
                    //update the choose cells
                    player->updateVector(p, type);
                    //update the cell himself
                    board.updateCell(numX, numY, type);
                    flag = 1;
                    return op[i];
                }
            }
            //if the input no good- give another chance
            if (flag == 0)
                cout << "Try again!" << endl;
        } while (flag == 0);
    } else {
        string s;
        s = "NoMove";
        cout << "there is no move for you this turn." << endl;
        return Point(-2, -2);
    }
}