package edu.vic.pancake.piSide.GUI.controllers;

import edu.vic.pancake.piSide.GUI.GuiMain;
import edu.vic.pancake.piSide.GUI.ScreenListener;
import edu.vic.pancake.piSide.GUI.Screens;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

public class SauceSelectorController implements ScreenListener{
    public BorderPane saucePanel1, saucePanel2, saucePanel3;
    private BorderPane [] panes = new BorderPane[3];

    public SauceSelectorController() {
        GuiMain.controllers.put("SauceSelector", this);
        panes[0] = saucePanel1;
        panes[1] = saucePanel2;
        panes[2] = saucePanel3;
    }

    private void onSauceSelected(int sauce){
        //Debug
        System.out.println("Selected sauce #" + sauce);
        //Handle stuff
    }

    @Override
    public void onScreenSwitched(Screens screen) {
        if (screen == Screens.SELECT_SAUCE){
            //Debug
            System.out.println("Sauce selector created");
            //Populate Text
            Properties selection = new Properties();
            try {
                FileInputStream prefFileInStream = new FileInputStream(new File("Selection.properties"));
                selection.load(prefFileInStream);
                prefFileInStream.close();
            } catch (FileNotFoundException e) {
                System.err.println("Today's selection file not found!");
                e.printStackTrace();
                return;
            } catch (IOException e) {
                System.err.println("Error while loading today's selection.");
                return;
            }
            setPanelText(saucePanel1, selection.getProperty("sauce1"));
            setPanelText(saucePanel2, selection.getProperty("sauce2"));
            setPanelText(saucePanel3, selection.getProperty("sauce3"));
            for (int i = 1; i < 4; i++){
                String fileName = selection.getProperty("sauce" + i + "Img");
                Image bgImage = new Image(fileName);

            }
        }
    }

    //Fxml has serious problems... You can't pass parameters...
    @FXML
    public void onSauce1Selected(MouseEvent e){
        onSauceSelected(1);
    }

    @FXML
    public void onSauce2Selected(MouseEvent e){
        onSauceSelected(2);
    }

    @FXML
    public void onSauce3Selected(MouseEvent e){
        onSauceSelected(3);
    }

    private void setPanelText(BorderPane pane, String text){
        for (Node node : pane.getChildren()){
            if (node instanceof Label){
                ((Label) node).setText(text);
            }
        }
    }
}
