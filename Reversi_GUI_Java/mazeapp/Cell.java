/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

/**
 * 
 * class of Cell
 *
 */
public class Cell {
    private char val;
    private int posR;
    private int posC;
    /**
     * constructor
     * @param posRo position row 
     * @param posCo position column
     */
    public Cell(int posRo,int posCo) {
        val=0;
        posR=posRo;
        posC=posCo;
    }
    /**
     * defult constructor
     */
    public Cell(){}

    /**
     * check if the cell value is x
     * @return true if it is, else - false
     */
    public boolean isX(){
        if (val=='X')
            return true;
        else
            return false;
    }
    /**
     * check if the cell value is O
     * @return true if it is, else - false
     */    
    public boolean isO(){
        if (val=='O')
            return true;
        else
            return false;
    }
    /**
     * check if the cell value is clear
     * @return true if it is, else - false
     */
    public boolean isClear(){
        if(val==0)
            return true;
        else
            return false;
    }
    /**
     * change the value of the cell 
     */
    public void changeVal(){
        if((isClear())==false)
            if(isX())
                changeValToO();
            else
                changeValToX();
    }
    /**
     * change the value of the cell to x 
     */
    public void changeValToX(){
        setVal('X');
    }
    /**
     * change the value of the cell to O 
     */
    public void changeValToO(){
        setVal('O');
    }
    /**
     * change the value of the cell 
     */
    public void setVal(char v) {
        val=v;
    }
    /**
     * get the value of the cell
     * @return char type
     */
    public char getVal(){
        return val;
    }
    /**
     * restart the cell value
     */
    public void restartCell(){
        val=0;
    }
}
