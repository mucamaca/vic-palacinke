package edu.vic.pancake.piSide.GUI.controllers;

import javafx.fxml.FXML;
import javafx.scene.input.MouseEvent;

public class SplashController {
    @FXML
    public void onTap(MouseEvent e){
        GUIMain.guiMain.switchScreen();
    }
}
