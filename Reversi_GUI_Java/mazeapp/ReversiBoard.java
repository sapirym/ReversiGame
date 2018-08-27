/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import java.io.IOException;
import java.util.ArrayList;

import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

/**
 * 
 * MazeBoard class
 *
 */
public class ReversiBoard extends GridPane {
    private Board board;
    private int cellHeight;
    private int cellWidth;
    private Color colorFirst;
    private Color colorSecond;
    private Player xPlayer, oPlayer;
    private boolean flag;

    /**
     * set the color of the first player
     * @param c color
     */
    public void setFirstColor(Color c) {
        colorFirst = c;
    }
    /**
     * set the color of the second player
     * @param c color
     */
    public void setSecondColor(Color c) {
        colorSecond = c;
    }
    /**
     * set the board
     * @param b - the board
     */
    public void setBoard(Board b) {
        board = b;
        int height = (int) this.getPrefHeight();
        int width = (int) this.getPrefWidth();
        cellHeight = height / board.getSize();
        cellWidth = width / board.getSize();
    }

    /**
     * constructor of mazeBoard
     * @param board - the board
     * @param firstc - the first color
     * @param seconfc - the second color
     */
    public ReversiBoard(Board board, Color firstc, Color seconfc) {
        this.setPrefWidth(400);
        this.setPrefHeight(400);
        
        this.board = board;
        colorFirst = firstc;
        colorSecond = seconfc;
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("ReversiBoard.fxml"));
        fxmlLoader.setRoot(this);
        fxmlLoader.setController(this);
        try {
            Parent scene = fxmlLoader.load();
        } catch (IOException exception) {
            throw new RuntimeException(exception);
        }
        int height = (int) this.getPrefHeight();
        int width = (int) this.getPrefWidth();
        cellHeight = height / board.getSize();
        cellWidth = width / board.getSize();
        xPlayer = new Player(true, 'X', colorFirst, this, new Point(getCellWidth(), getCellHeight()));
        oPlayer = new Player(false, 'O', colorSecond, this, new Point(getCellWidth(), getCellHeight()));
     }

    /**
     * get the height of the cell
     * @return the height of the cell
     */
    public int getCellHeight() {
        int height = (int) this.getPrefHeight();
        cellHeight = height / board.getSize();
        return cellHeight;

    }
    /**
     * get the width of the cell
     * @return the width of the cell
     */
    public int getCellWidth() {
        int width = (int) this.getPrefWidth();
        cellWidth = width / board.getSize();
        return cellWidth;
    }
    /**
     * draw the current board
     */
    public void draw() {
        this.getChildren().clear();
        for (int i = 0; i < board.getSize(); i++) {
            for (int j = 0; j < board.getSize(); j++) {
            	Rectangle rect = new Rectangle(getCellWidth(), getCellHeight(), Color.BLANCHEDALMOND);
                this.add(rect, j, i);
                rect.setStroke(Color.BLACK);
                if (board.getCell(i, j).getVal() == 'X') {
                    xPlayer.draw(j, i);
                } else if (board.getCell(i, j).getVal() == 'O') {
                    oPlayer.draw(j, i);
                } else if (board.getCell(i, j).getVal() == 'C') {
                }
            }
        }
    }
    
    /**
     * get the current player
     * @param type the char type of the player
     * @return the player
     */
    public Player getCurrentPlayer(char type) {
        if (type == 'X')
            return xPlayer;
        else
            return oPlayer;
    }
    /**
     * set the cell value
     * @param i - index
     * @param j - index
     * @param player - the player type
     */
    public void setCell(int i, int j, char player) {
        board.updateCell2(i, j, player);
    }
    /**
     * update the board
     * @param p - the array
     * @param type - the 
     */
    public void updateBoard(ArrayList<Point> p, char type) {
        for (int i = 0; i < p.size(); ++i) {
            setCell(p.get(i).getX(), p.get(i).getY(), type);
        }
    }
}
