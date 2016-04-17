package edu.vic.pancake.piSide.GUI;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.HashMap;
import java.util.Map;

public class GuiMain extends Application{
    public static final int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 450;

    Stage stage;
    Scene splashScene, insertMoneyScene;
    public static GuiMain guiMain;
    public static Map<String, ScreenListener> controllers = new HashMap<>();

    public GuiMain() {
        guiMain = this;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent splashFxml = FXMLLoader.load(getClass().getResource("res/splash_screen.fxml"));
        Parent insertMoneyFxml = FXMLLoader.load(getClass().getResource("res/insert_money_screen.fxml"));

        splashScene = new Scene(splashFxml, SCREEN_WIDTH, SCREEN_HEIGHT);
        insertMoneyScene = new Scene(insertMoneyFxml, SCREEN_WIDTH, SCREEN_HEIGHT);

        stage = primaryStage;
        stage.setTitle("PfankuchenMacher9000 GUI");
        stage.setScene(splashScene);
        stage.show();
    }

    public void switchScreen(Screens screen){
        System.out.println("Switch screen called.");
        switch (screen){
            case INSERT_MONEY:
                stage.setScene(insertMoneyScene);
                break;
        }
    }
}
