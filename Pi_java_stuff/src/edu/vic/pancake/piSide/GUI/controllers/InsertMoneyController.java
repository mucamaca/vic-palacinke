package edu.vic.pancake.piSide.GUI.controllers;

import edu.vic.pancake.piSide.GUI.GuiMain;
import edu.vic.pancake.piSide.GUI.ScreenListener;
import edu.vic.pancake.piSide.GUI.Screens;

/**
 * A class that checks if enough money has been inserted.
 */
public class InsertMoneyController implements Runnable, ScreenListener{
    public InsertMoneyController() {
        GuiMain.controllers.put("InsertMoney", this);
    }

    @Override
    public void run() {

    }

    @Override
    public void onScreenSwitched(Screens screen) {
        if (screen == Screens.INSERT_MONEY){
            new Thread(this).start();
        }
    }
}
