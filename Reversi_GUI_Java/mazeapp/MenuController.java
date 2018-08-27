/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

import com.sun.glass.ui.Window.Level;
import com.sun.media.jfxmedia.logging.Logger;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class MenuController implements Initializable {
    @FXML
    private HBox root;

	@FXML
	/**
	 * end function game
	 */
	protected void end(){
	        System.exit(0);
	}
    @FXML
    /**
     * when the button of configuration is clicked,
     *  this function is called
     */
    protected void confi(){
            try {
                GridPane root1 = (GridPane)FXMLLoader.load(getClass().getResource("conFxml.fxml"));
                BackgroundFill myBF = new BackgroundFill(Color.CADETBLUE, new CornerRadii(1),
                        new Insets(0.0,0.0,0.0,0.0));
                root1.setBackground(new Background(myBF));
                Scene scene = new Scene(root1, 600, 400);
                Stage stage = new Stage();
                stage.setTitle("Configuration Window");
                stage.setScene(scene);
                stage.show();
            } catch (IOException e) {
            	e.printStackTrace();
            }

    }
  
    @FXML
    /**
     * start the UI
     */
    protected void start(){
        try {
            HBox root1 = (HBox)FXMLLoader.load(getClass().getResource("startFxml.fxml"));
            BackgroundFill myBF = new BackgroundFill(Color.CADETBLUE, new CornerRadii(1),
                    new Insets(0.0,0.0,0.0,0.0));
            root1.setBackground(new Background(myBF));
            Scene scene = new Scene(root1, 600, 400);
            Stage stage = new Stage();
            stage.setTitle("start Window");
            stage.setScene(scene);
            
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    /**
     * initilize - we dont need it
     */
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        
    }
}
