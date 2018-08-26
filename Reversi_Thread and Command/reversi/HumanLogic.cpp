/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#include <iostream>
#include <vector>
#include "HumanLogic.h"

HumanLogic::HumanLogic(Board &b) {
    board=b;
}

HumanLogic::HumanLogic() {}


void HumanLogic::updateVector(vector<Point> p,char type){
    for (int i = 0; i < p.size(); ++i) {
        board.updateCell(p[i].getX()+1,p[i].getY()+1,type);
    }
}

vector<Point> HumanLogic::optionCell(int iStart,int jStart,char type,int print){
    char otherType;
    vector<Point> op;
    Point p [8];
    //all the cell direction to move to
    p[0]=Point(-1,-1);
    p[1]=Point(-1,0);
    p[2]=Point(-1,1);
    p[3]=Point(0,-1);
    p[4]=Point(0,1);
    p[5]=Point(1,-1);
    p[6]=Point(1,0);
    p[7]=Point(1,1);
    //check the propriety of the cell
    if(board.getCell(iStart,jStart)->getVal()!=0 || !board.onTheBoard(iStart,jStart))
        return op;
    //temporary until we change at the end of the function
    board.updateCell(iStart+1,jStart+1,type);
    if(type=='X')
        otherType='O';
    else
        otherType='X';
    //run over all the cell range and check if there is cell with the opposite sign-
    //if there is we return their cooniture
    for (int k = 0; k < 8; ++k) {
        int i=iStart;
        int j=jStart;
        int xDirection=p[k].getX();
        int yDirection=p[k].getY();

        i+=xDirection;
        j+=yDirection;

        if(board.onTheBoard(i,j)&&board.getCell(i,j)->getVal()==otherType){
            i+=xDirection;
            j+=yDirection;
            if(!board.onTheBoard(i,j))
                continue;
            while (board.getCell(i,j)->getVal()==otherType){
                i+=xDirection;
                j+=yDirection;
                if(!board.onTheBoard(i,j))
                    break;
            }
            if(!board.onTheBoard(i,j))
                continue;
            if(board.getCell(i,j)->getVal()==type){
                bool check=1;
                while (check){
                    i-=xDirection;
                    j-=yDirection;
                    if(i==iStart&&j==jStart)
                        break;
                    op.push_back(Point(i,j));
                }
            }
        }

    }


    board.updateCell(iStart+1,jStart+1);
    if(!op.empty() && print==0){
        cout << "(" << iStart + 1 << "," << jStart + 1 << ")";
    }
    return op;
}





int HumanLogic::playMove(char type, vector<Point> op){
    int  flag=0;
    char dummy;
    if(!op.empty()){
        do {
            int numX =0, numY=0;
                //cout << endl << "Please enter your move- row col: (e.g. 3 4)";
            screen.printString("\nPlease enter your move- row col: (e.g. 3 4)");
                cin >> numX >> numY;
            screen.printString("\n");
            //cout<<endl;
            for (int i = 0; i < op.size(); i++) {
                //if the input match to the possible move points
                if (op[i].getX() == numX-1 && op[i].getY() == numY-1) {
                    vector<Point> p = optionCell(numX-1,numY-1,type,1);
                    //update the choose cells
                    updateVector(p, type);
                    //update the cell himself
                    board.updateCell(numX,numY,type);
                    flag = 1;
                    break;
                }
            }
            //if the input no good- give another chance
            if(flag==0)
                screen.printString("Try Again!\n");
                //cout<<"Try again!"<<endl;
        } while(flag==0);
        return 0;

    }else{
        screen.printString("\nYou can't do any move. the turn is over to the other player!\"\n"
                                   "                \" press any key and then enter to continue\n");
        //cout<<endl<<"You can't do any move. the turn is over to the other player!"
                //" press any key and then enter to continue"<<endl;
        cin>>dummy;
        return 1;
    }
}

void HumanLogic:: updateSpecificCell(int x, int y, char type){
    board.updateCell(x,y,type);
}

