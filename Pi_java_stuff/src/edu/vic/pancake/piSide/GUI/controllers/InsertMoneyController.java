package edu.vic.pancake.piSide.GUI.controllers;

import edu.vic.pancake.piSide.GUI.GuiMain;
import edu.vic.pancake.piSide.GUI.ScreenListener;
import edu.vic.pancake.piSide.GUI.Screens;
import javafx.application.Platform;

/**
 * A class that checks if enough money has been inserted.
 */
public class InsertMoneyController implements Runnable, ScreenListener{
    public InsertMoneyController() {
        GuiMain.controllers.put("InsertMoney", this);
    }

    private void onAllMoneyInserted(){
        GuiMain.guiMain.switchScreen(Screens.SELECT_SAUCE);
    }

    @Override
    public void run() {
        //Listen to money inserter, when ok, call onAllMoney and return
        try {
            Thread.sleep(2000);
        } catch (InterruptedException ignored) {}
        Platform.runLater(this::onAllMoneyInserted);
    }

    @Override
    public void onScreenSwitched(Screens screen) {
        if (screen == Screens.INSERT_MONEY){
            new Thread(this).start();
        }
    }
}
