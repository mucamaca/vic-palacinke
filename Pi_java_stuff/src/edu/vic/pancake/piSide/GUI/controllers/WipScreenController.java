package edu.vic.pancake.piSide.GUI.controllers;

import edu.vic.pancake.piSide.GUI.GuiMain;
import edu.vic.pancake.piSide.GUI.ScreenListener;
import edu.vic.pancake.piSide.GUI.Screens;

public class WipScreenController implements ScreenListener{

    public WipScreenController() {
        GuiMain.controllers.put("Working", this);
    }

    @Override
    public void onScreenSwitched(Screens screen) {
        //TODO
    }
}
