/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import javafx.scene.effect.DropShadow;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.paint.Color;

/**
 * 
 * player class
 *
 */
public class Player {
    private boolean myTurn;
    private char val;
    private GridPane gp;
    private int height;
    private int width;
    private Color color;
    private ImageView iv; 
    
    /**
     * constructor of player
     * @param myTurn1 - is it is his turn
     * @param typeUser - the char type
     * @param c - the color
     * @param gp1 - the grid
     * @param p - the point
     */
    public Player(boolean myTurn1,char typeUser, Color c, GridPane gp1, Point p) {
        myTurn=myTurn1;
        val=typeUser;
        this.gp = gp1;
        this.height = p.getY();
        this.width = p.getX();
        color = c;
    }
    
    /**
     * the player constructor
     * @param myTurn1 - is it is his turn
     * @param typeUser - thr char type
     * @param c - the color
     */
    public Player(boolean myTurn1,char typeUser, Color c){
    	myTurn=myTurn1;
        val=typeUser;
        color = c;
    }
    
    /**
     * draw the current player
     * @param col - column
     * @param row - row
     */
    public void draw(int col, int row) {
        ImageView imv = null;
        if(val == 'X')
            imv = new ImageView(getClass().getResource("hadas.png").toExternalForm());
        else if(val == 'O')
            imv  = new ImageView(getClass().getResource("sapir.png").toExternalForm());
        
        DropShadow b= new DropShadow();
        b.setColor(color);
        b.setOffsetX(row);
        b.setOffsetY(col);
        b.setRadius(((ReversiBoard)gp).getCellHeight()/4);
        b.setSpread(0.5);
        imv.setFitWidth(((ReversiBoard)gp).getCellWidth()/1.1);      
        imv.setFitHeight(((ReversiBoard)gp).getCellHeight()/1.1);
        imv.setEffect(b);
        gp.getChildren().remove(imv);    
        gp.add(imv, col, row);
    }
    
    /**
     * get the color of the player
     * @return the color
     */
    public Color getColor(){
    	return this.color;
    }
    
    /**
     * print thhe move
     */
    public void printPlayerTurn() {
        System.out.println(val+": Its your move.");
    }
     
    /**
     * @return boolean value if it his turn - true.
     */
    public boolean isMyTurn(){
        return myTurn;
    }
    /**
     * get the value
     * @return value of the player
     */
    public char getVal(){
        return val;
    }

    public void setMyTurn(int num){
        if (num==0)
            myTurn=false;
        else if(num==1)
            myTurn=true;
    }

    public void winGame(){
        System.out.println(val+" You are the winner!");
    }

    public Player() {}
}