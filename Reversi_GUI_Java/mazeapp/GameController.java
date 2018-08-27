/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.nio.channels.AlreadyBoundException;
import java.util.ArrayList;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.image.ImageView;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.StrokeLineCap;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 * startController class
 */
public class GameController implements Initializable {
    @FXML
    private HBox root;
    @FXML
    private char currentType;
    @FXML
    private ReversiBoard reversiBoard;
    @FXML
    private Board board;
    @FXML
    private Button close;
    @FXML
    private Text messageText;
    @FXML
    private Text messageText1;
    @FXML
    private Text messageText2;
    @FXML
    private Integer sizeOfBoard;
    @FXML
    private Color colorFirstPlayer;
    @FXML
    private Color colorSecondPlayer;
    @FXML
    private boolean flag;
    @FXML
    private boolean flagX;
    @FXML
    private boolean flagO;
    @FXML
    private char restType;
    @Override
    /**
     * initialize the current UI
     */
    public void initialize(URL location, ResourceBundle resources) {
        flagO = false;
        flagX = false;
        flag = true;
        load(new File("configu.txt"));
        board= new Board(sizeOfBoard);
        restType = 'O';
        currentType='X';
        this.reversiBoard = new ReversiBoard(board,colorFirstPlayer, colorSecondPlayer);  
        reversiBoard.setPrefWidth(400);
        reversiBoard.setPrefHeight(400);
        root.widthProperty().addListener((observable, oldValue, newValue) -> {
            double boardNewWidth = newValue.doubleValue() - 120;
            reversiBoard.setPrefWidth(boardNewWidth);       
            reversiBoard.draw();
            });         
        root.heightProperty().addListener((observable, oldValue, newValue) -> {  
            reversiBoard.setPrefHeight(newValue.doubleValue());              
            reversiBoard.draw();    
            }); 
        root.getChildren().add(0, reversiBoard);    
        startGame();
    }
    
    public void startGame(){
    	reversiBoard.draw();
        GameFlow gameFlow= new GameFlow(board, reversiBoard);
        showStatus('X');
        //ArrayList<Point> op =gameFlow.clickOptions(currentType);
        reversiBoard.setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent event) {
                reversiBoard.draw();
                showStatus(currentType);
                Point move = new Point((int)event.getY()/reversiBoard.getCellHeight(),
                		(int)event.getX()/reversiBoard.getCellWidth());
                ArrayList<Point> op =gameFlow.clickOptions(currentType);
                for (int i = 0; i < op.size(); i++) {
                	Rectangle rect = new Rectangle(reversiBoard.getCellWidth(),
                    		reversiBoard.getCellHeight(),Color.BLACK);
                	rect.setStroke(Color.WHITE);
                    reversiBoard.add(rect ,op.get(i).getY() , op.get(i).getX());
                }
                int result = gameFlow.moveOneStep(move.getX(), move.getY(), currentType, op);
                checkResult(result);
                }
            }
            );
    }
    
    /**
     * check the result of the game flow.
     * @param result - the result of the gameFlow
     */
    public void checkResult(int result){
        if (result == 0){
            if(currentType=='O')
                flagO = false;
            else if (currentType=='X')
                flagX = false;
            reversiBoard.draw();
            setCurrentTurn();
            flag = false;
        } else if(result ==1){
            flag = true;
        } else if (result == 2){
            if(currentType=='O')
                flagO = true;
            else
                flagX = true;
            setCurrentTurn();
            flag = false;
        }
        if(flagX&&flagO || board.fullBoard()){
                end();
            }

         }
    
    
    /**
     * load the file for configurations
     * @param filename - the file name
     */
    public void load(File filename) {
        if (!filename.exists()) {
            sizeOfBoard=4;
            colorFirstPlayer=Color.RED;
            colorSecondPlayer=Color.YELLOW; 
        } else {
        BufferedReader is=null;
        
        try{
            is=new BufferedReader(new InputStreamReader(new FileInputStream(filename)));
            String line;
            String confi[]=new String[3];
            int i=0;
            while((line=is.readLine())!=null){
                confi[i]=line;
                i++;
            }
            sizeOfBoard=Integer.parseInt(confi[0]);
	        colorFirstPlayer=(Color.web(confi[1]));
	        colorSecondPlayer=(Color.web(confi[2]));        
	    } catch (IOException e) {
	        // TODO Auto-generated catch block
	        e.printStackTrace();
	    }
        }
    }
   
    /**
     * get the mazeBoard
     * @return the maze board
     */
    public ReversiBoard getMazeBoard(){
        return this.reversiBoard;
    }
    @FXML
    /**
     * set the current turn of the player
     */
    public void setCurrentTurn(){
    	showStatus(restType);
        if(currentType =='X'){
            this.currentType = 'O';
            this.restType = 'X';
        }
        else {
            this.currentType = 'X';
            this.restType = 'O';
        }
    }
    /**
     * show the current status of the game
     * @param currPlayer the current player
     */
    public void showStatus(char currPlayer){
    	 messageText.setText("current type:"+currPlayer);
         messageText.setFill(reversiBoard.getCurrentPlayer(currPlayer).getColor());
         messageText1.setText("X player score: " + board.getCounterx());
         messageText2.setText("O player score: " + board.getCountero());
    }
    @FXML
    /**
     * end the game
     */
    public void end(){
        String msg = "";
        ImageView iv=null;
        if(board.getCountero()>board.getCounterx()){
            msg = "O you are the winner with: "+board.getCountero()+" point";
            iv = new ImageView(getClass().getResource("sapir.png").toExternalForm());
        }
        else if(board.getCountero()<board.getCounterx()){
            msg = "X you are the winner with: "+board.getCounterx()+" point";
            iv = new ImageView(getClass().getResource("hadas.png").toExternalForm());
        }
        else if(board.getCountero()==board.getCounterx()){
            msg = "it is a tie!";
        }
        Alert alert= new Alert(AlertType.INFORMATION);
        alert.setHeaderText(msg);
        alert.setTitle("Game Over!");
        if(iv!= null)
        	alert.setGraphic(iv);
        alert.show();
        endGame();
    }
    @FXML    
    public void endGame(){
    	Stage stage = (Stage) close.getScene().getWindow();
        stage.hide();    	
    }
}

