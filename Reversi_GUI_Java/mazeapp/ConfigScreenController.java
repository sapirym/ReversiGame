/**
 * sapir yamin 316251818
 * hadas berger: 316590215
 */
package mazeapp;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.URL;
import java.util.ResourceBundle;

import javax.security.auth.login.Configuration;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.ColorPicker;
import javafx.scene.control.ComboBox;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class ConfigScreenController implements Initializable {
    @FXML
    private Text messageText;
    @FXML
    private ComboBox<Integer> value;
    @FXML
    private ColorPicker color;
    @FXML
    private ColorPicker color1;
    @FXML
    public Button save1;

    @FXML
    /**
     * save the file
     * @throws IOException
     */
    protected void save() throws IOException {
        Integer vSize = value.getValue();
        Color c, c2;
        c = color.getValue();
        c2 = color1.getValue();
        File filename = new File("configu.txt");
        PrintWriter os = null;
        try {
            os = new PrintWriter(new OutputStreamWriter(new FileOutputStream(filename)));
            os.printf("%d\n", vSize);
            os.printf("%s\n", c);
            os.printf("%s\n", c2);
        } catch (IOException e) {
            e.printStackTrace();
            ;
        } finally {
            if (os != null) {
                os.close();
                Stage stage = (Stage) save1.getScene().getWindow();
                stage.hide();
            }
        }
    }

    @Override
    /**
     * initialize the screen
     */
    public void initialize(URL location, ResourceBundle resources) {
        File filename = new File("configu.txt");
        if (!filename.exists()) {
            value.setValue(4);
            color.setValue(Color.RED);
            color1.setValue(Color.YELLOW);
        } else {
            BufferedReader is = null;
            try {
                is = new BufferedReader(new InputStreamReader(new FileInputStream(filename)));
                String line;
                String confi[] = new String[3];
                int i = 0;
                while ((line = is.readLine()) != null) {
                    confi[i] = line;
                    i++;
                }
                value.setValue(Integer.parseInt(confi[0]));
                color.setValue(Color.web(confi[1]));
                color1.setValue(Color.web(confi[2]));

            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}
