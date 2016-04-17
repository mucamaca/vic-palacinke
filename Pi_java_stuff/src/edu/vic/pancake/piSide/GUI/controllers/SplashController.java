package edu.vic.pancake.piSide.GUI.controllers;

import edu.vic.pancake.piSide.GUI.GuiMain;
import edu.vic.pancake.piSide.GUI.Screens;
import javafx.fxml.FXML;
import javafx.scene.input.MouseEvent;

public class SplashController {
    @FXML
    public void onTap(MouseEvent e){
        GuiMain.guiMain.switchScreen(Screens.INSERT_MONEY);
    }
}
