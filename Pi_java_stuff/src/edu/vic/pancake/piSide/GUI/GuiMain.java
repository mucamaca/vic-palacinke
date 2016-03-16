package edu.vic.pancake.piSide.GUI;

import javafx.application.Application;
import javafx.stage.Stage;


public class GuiMain extends Application{
    Stage stage;

    @Override
    public void start(Stage stage) throws Exception {
        this.stage = stage;
        stage.setTitle("Palačinke GUI");
        stage.show();
    }
}
