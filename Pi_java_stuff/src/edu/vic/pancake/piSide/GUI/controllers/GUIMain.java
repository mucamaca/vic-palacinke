package edu.vic.pancake.piSide.GUI.controllers;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class GUIMain extends Application {
    public static GUIMain guiMain;

    Stage stage;
    Scene splashScene;

    public GUIMain() {
        guiMain = this;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent fxml = FXMLLoader.load(getClass().getResource("res/splash_screen.fxml"));

        splashScene = new Scene(fxml, 800, 450);

        stage = primaryStage;
        stage.setTitle("PfankuchenMacher9000 GUI");
        stage.setScene(splashScene);
        stage.show();
    }

    public void switchScreen(){
        System.out.println("Switch screen called.");
    }
}
