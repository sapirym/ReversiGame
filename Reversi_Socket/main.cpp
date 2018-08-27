/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#include "Board.h"
#include "Game.h"
#include "Menu.h"
#define SIZE 8
using namespace std;

int main() {
    int size;
    /*do {
        cout << "Choose the Board size:" << endl;
        cin >> size;
        if(size<2|| size%2!=0){
            cout<<"that's not legal size. please try again. "<<endl;
        }
    }while (size<2|| size%2!=0);*/
    Board b(SIZE);
Menu menu(b);
menu.runMenu();
return 0;
}