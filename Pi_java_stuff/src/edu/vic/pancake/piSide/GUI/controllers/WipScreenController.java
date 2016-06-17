package edu.vic.pancake.piSide.GUI.controllers;

import edu.vic.pancake.piSide.GUI.GuiMain;
import edu.vic.pancake.piSide.GUI.ScreenListener;
import edu.vic.pancake.piSide.GUI.Screens;
import javafx.concurrent.Task;
import javafx.scene.control.ProgressBar;

public class WipScreenController implements ScreenListener{
    public ProgressBar progressBar;
    private static final int STEPS = 10;

    public WipScreenController() {
        GuiMain.controllers.put("Working", this);
    }

    @Override
    public void onScreenSwitched(Screens screen) {
        if (screen == Screens.WORKING){
            Task<Void> updateTask = new Task<Void>() {
                @Override
                protected Void call() throws Exception {
                    for (int i = 0; i <= STEPS; i++){
                        updateProgress(i, STEPS);
                        Thread.sleep(1000);
                    }
                    System.exit(1);
                    return null;
                }
            };
            progressBar.progressProperty().bind(updateTask.progressProperty());
            new Thread(updateTask).start();
        }
    }
}
