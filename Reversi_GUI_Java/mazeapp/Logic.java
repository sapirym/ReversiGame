/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import java.util.ArrayList;
/**
 * 
 * class of Logic
 *
 */
public class Logic {
    private Board board;
    /**
     * constructor of logic
     * @param b board
     */
    public Logic(Board b) { 
        board=b;
    }
    /**
     * default constructor
     */
    public Logic() {}
    
    /**
     * update the board by vector
     * @param p - the vector
     * @param type - the type of the player
     */
    public void updateVector(ArrayList<Point> p,char type){
        for (int i = 0; i < p.size(); ++i) {
            board.updateCell(p.get(i).getX(),p.get(i).getY(),type);
        }
    }

    /**
     * check the options of the cell
     * @param iStart - start of the range
     * @param jStart- start of the range
     * @param type - the char type
     * @return array of possible move
     */
    ArrayList<Point> optionCell(int iStart,int jStart,char type){
        char otherType;
        ArrayList<Point> op= new ArrayList<Point>() ;
        Point p[]=new Point[8] ;
        //all the cell direction to move to
        p[0]=new Point(-1,-1);
        p[1]=new Point(-1,0);
        p[2]=new Point(-1,1);
        p[3]=new Point(0,-1);
        p[4]=new Point(0,1);
        p[5]=new Point(1,-1);
        p[6]=new Point(1,0);
        p[7]=new Point(1,1);
        //check the propriety of the cell
        if(board.getCell(iStart,jStart).getVal()!=0 || !board.onTheBoard(iStart,jStart))
            return op;
        //temporary until we change at the end of the function
        board.updateCell(iStart,jStart,type);
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

            if(board.onTheBoard(i,j)&&board.getCell(i,j).getVal()==otherType){
                i+=xDirection;
                j+=yDirection;
                if(!board.onTheBoard(i,j))
                    continue;
                while (board.getCell(i,j).getVal()==otherType){
                    i+=xDirection;
                    j+=yDirection;
                    if(!board.onTheBoard(i,j))
                        break;
                }
                if(!board.onTheBoard(i,j))
                    continue;
                if(board.getCell(i,j).getVal()==type){
                    boolean check=true;
                    while (check){
                        i-=xDirection;
                        j-=yDirection;
                        if(i==iStart&&j==jStart)
                            break;
                        Point newp=new Point(i,j);
                        op.add(newp);
                    }
                }
            }

        }
        board.updateCell(iStart,jStart);
        return op;
    }
}
