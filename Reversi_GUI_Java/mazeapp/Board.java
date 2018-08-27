/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */

package mazeapp;
import java.util.ArrayList;
import java.util.List;

/**
 * class of Board
 */
public class Board {
    private int size;
    private Cell [][] arr;
    /**
     * constructor for Board
     */
    public Board(int sizeOfBoard){
        size=sizeOfBoard;
        arr= new Cell[sizeOfBoard][sizeOfBoard];
        for (int k = 0; k < size; k++) {
            arr[k]= new Cell[size];
        }
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                arr[i][j]= new Cell((i+1),(j+1));
        updateCell(size/2,size/2,'O');
        updateCell(size/2-1,size/2-1,'O');
        updateCell(size/2,size/2-1,'X');
        updateCell(size/2-1,size/2,'X');
    }
    /**
     * the method return if the board is boolean type
     * @return true if the board is full , elae - false
     */
    public boolean fullBoard(){
        if(getCounterx()+getCountero()==(size*size))
            return true;
        else
            return false;
    }
    
    /**
     * get the cell by index
     * @param row - the row
     * @param col - the column
     * @return the cell
     */
    public Cell getCell(int row,int col){
        return arr[row][col];
    }
    
    /**
     * update the cell
     * @param row - the row
     * @param col - the column
     * @param val - the value we want to change to
     */
    public void updateCell(int row,int col,char val) {
        if (arr[row][col].isClear()) {
            arr[row][col].setVal(val);
        } else {
            arr[row][col].changeVal();
            }
    }
    /**
     * update the cell
     * @param row - the row
     * @param col - the column
     * @param val - the value we want to change to
     */
    public void updateCell2(int row,int col,char val) {
            arr[row][col].setVal(val);
        }
    /**
     * update the cell
     * @param row - the row
     * @param col - the column
     * @param val - the value we want to change to
     */
    public void updateCell(int row,int col){
        arr[row][col].restartCell();

    }
    /**
     * defualt constructor
     */
    public Board() {}
    /**
     * get the scores of X type
     * @return number of scores
     */
    public int getCounterx() {
        int counter=0;
        for (int i = 0; i <size ; ++i) {
            for (int j = 0; j < size; ++j) {
                if(getCell(i,j).getVal()=='X')
                    counter++;

            }
        }
        return counter;
    }
    /**
     * get the scores of O type
     * @return number of scores
     */
    public int getCountero() {
        int counter=0;
        for (int i = 0; i <size ; ++i) {
            for (int j = 0; j < size; ++j) {
                if(getCell(i,j).getVal()=='O')
                    counter++;
            }
        }
        return counter;
    }
    /**
     * get the size of the board
     * @return size of the board
     */
    public int getSize(){
        return size;
    }
    /**
     * check if the point is on the board
     * @return true if it is on the board, else false
     */
    public boolean onTheBoard(int row, int col){
        if(row<0||row>=size||col<0||col>=size)
            return false;
        else
            return true;
    }
}
