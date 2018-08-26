/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#include "ComputerLogic.h"
#include "LogicBase.h"
#include <vector>
#include <map>
ComputerLogic::ComputerLogic(Board &b) {
    board=b;
}


void ComputerLogic::cleanVector(vector<Point> p,char type){
    char otherType;
    if(type == 'O'){
        otherType ='X';
    }else{
        otherType = 'O';
    }
    for (int i = 0; i < p.size(); ++i) {
        board.updateCell(p[i].getX()+1,p[i].getY()+1,otherType);
    }
}

vector<Point> ComputerLogic:: optionCell(int iStart,int jStart,char type,int print){
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
    return op;
}


void ComputerLogic:: updateVector(vector<Point> p,char type){
    for (int i = 0; i < p.size(); ++i) {
        board.updateCell2(p[i].getX(),p[i].getY(),type);

    }
}

Point ComputerLogic:: demoMove(vector<Point> p){
        vector<Point> humanVec;
        map<int,Point> finalMap;
        Board &b = board;

        for (int i = 0; i <p.size() ; ++i) {
            vector<Point> tempPoint =optionCell(p[i].getX(),p[i].getY(),'O',1);
            updateVector(tempPoint, 'O');
            board.updateCell2(p[i].getX(),p[i].getY(),'O');
            for (int k = 0; k < b.getSize(); k++) {
                for (int j = 0; j < b.getSize(); j++) {
                    //send a clean cell and check is option
                    if (board.getCell(k , j )->isClear()) {
                        vector<Point> options = optionCell(k, j, 'X',1);
                        if(!options.empty()){
                            humanVec.push_back(Point(k,j));
                        }
                    }
                }
            }
            int sum =0, calculate = 0;
            map<int,Point> counterMap;
            for (int k = 0; k < humanVec.size(); ++k) {
                vector<Point> temp = optionCell(humanVec[k].getX(),humanVec[k].getY(), 'X',1);
                sum = temp.size();
                calculate = sum + b.getCounterx()+1-b.getCountero();
                counterMap.insert(make_pair(calculate, humanVec[k]));
            }
            pair<int, Point> maxPoint;
            int maxScore=0;
            map<int ,Point>::iterator it = counterMap.begin();
            for (it=counterMap.begin(); it!=counterMap.end(); ++it){
                if((*it).first >maxScore){
                    maxPoint = (*it);
                    maxScore = (*it).first;
                }
            }
            std::map<int, Point>::iterator it2 = finalMap.begin();
            finalMap.insert(it2, std::pair<int,Point>(maxScore,p[i]));
            board.getCell(p[i].getX(),p[i].getY())->restartCell();
            cleanVector(tempPoint, 'O');
        }
        map<int, Point>::iterator it = finalMap.begin();
        pair<int,Point> finalMinPoint;
        int finaMinScore=10000;
        for (it=finalMap.begin(); it!=finalMap.end(); ++it){
            if((*it).first<finaMinScore){
                finaMinScore = (*it).first;
                finalMinPoint = (*it);
            }
        }
        return finalMinPoint.second;
}


int ComputerLogic:: playMove(char type,  vector<Point> op){
    if(op.empty()){
        screen.printString("computer has no more moves to do.\n");
        //cout<<"computer has no more moves to do."<<endl;
        return  1;
    }
    Point finalMove = demoMove(op);
    screen.printPoint("It's al move. Computer move is:",finalMove.getX()+1,finalMove.getY()+1);
    //cout<<"It's al move. Computer move is:"<<"("<<finalMove.getX()+1<<","<<finalMove.getY()+1<<")"<<endl<<endl;
    updateVector(optionCell(finalMove.getX(),finalMove.getY(),type,1), 'O');
    board.updateCell(finalMove.getX()+1,finalMove.getY()+1,'O');
    return 0;
}
