/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
/**
 * Main class
 */
public class Main extends Application {
    @Override
    /**
     * start the application by primaryStage stage
     */
    public void start(Stage primaryStage) {
        try {
            HBox root = (HBox) FXMLLoader.load(getClass().getResource("Reversi.fxml"));
            BackgroundFill myBF = new BackgroundFill(Color.CADETBLUE, new CornerRadii(1),
                    new Insets(0.0,0.0,0.0,0.0));
            root.setBackground(new Background(myBF));
            
            Scene scene = new Scene(root, 400, 400);
            
            scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
            primaryStage.setTitle("Reversi game");
            
            primaryStage.setScene(scene);
            primaryStage.show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    /**
     * launch the start
     * @param args - the command args
     */
    public static void main(String[] args) {
        launch(args);
    }
}
