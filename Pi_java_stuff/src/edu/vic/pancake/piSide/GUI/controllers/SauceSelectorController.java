package edu.vic.pancake.piSide.GUI.controllers;

import edu.vic.pancake.piSide.GUI.GuiMain;
import edu.vic.pancake.piSide.GUI.ScreenListener;
import edu.vic.pancake.piSide.GUI.Screens;
import javafx.fxml.FXML;
import javafx.scene.input.MouseEvent;

public class SauceSelectorController implements ScreenListener{
    public SauceSelectorController() {
        GuiMain.controllers.put("SauceSelector", this);
    }

    public void onSauceSelected(int sauce){
        //Handle stuff
    }

    @Override
    public void onScreenSwitched(Screens screen) {
        if (screen == Screens.SELECT_SAUCE){
            //Do shit
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
}
