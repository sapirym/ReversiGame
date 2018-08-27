/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import java.util.*;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Scanner;

import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

/**
 * 
 * GameFlow class
 *
 */
public class GameFlow {
    private Logic rule;
    private Board board;
    private char dummy;
    private GridPane maze;

    /**
     * constructor for GameFlow
     * @param b - the board
     * @param maze1 - the GridPane
     */
    public GameFlow(Board b, GridPane maze1) {
        rule = new Logic(b);
        board = b;
        maze = maze1;
    }
    /**
     * check the option of the user
     * @param type - check it by type
     * @return array of all the possible points
     */
    public ArrayList<Point> clickOptions(char type) {
        ArrayList<Point> op = new ArrayList<Point>();
        for (int i = 0; i < board.getSize(); i++) {
            for (int j = 0; j < board.getSize(); j++) {
                // send a clean cell and check is option
                if (board.getCell(i, j).isClear()) {
                    ArrayList<Point> p = rule.optionCell(i, j, type);
                    if (!p.isEmpty()) {
                        // add to the option possible move points
                        op.add(new Point(i, j));
                    }
                }
            }
        }
        return op;
    }
    
    /**
     * do the turn of the player
     * @param numX - the x value of the point
     * @param numY - the x value of the point
     * @param type - the sign of the player
     * @param op - the array of options
     * @return flag if the turn is good or not
     */
    public int moveOneStep(int numX, int numY, char type, ArrayList<Point> op) {
        boolean flag = false;
        if (!op.isEmpty()) {
            for (int i = 0; i < op.size(); i++) {
                if (op.get(i).getX() == numX && op.get(i).getY() == numY) {
                    ArrayList<Point> p = rule.optionCell(numX, numY, type);
                    // update the choose cells
                    rule.updateVector(p, type);
                    // update the cell himself
                    board.updateCell(numX, numY, type);
                    p.add(new Point(numX, numY));
                    ((ReversiBoard) maze).updateBoard(p, type);
                    ((ReversiBoard) maze).draw();
                    flag = true;
                    return 0;
                }
            }
            return 1;
        } else {
            return 2;
        }
    }
}
