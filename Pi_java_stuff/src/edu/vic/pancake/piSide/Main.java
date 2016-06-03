package edu.vic.pancake.piSide;

import com.pi4j.system.SystemInfo;
import edu.vic.pancake.piSide.GUI.GuiMain;
import javafx.application.Application;

import edu.vic.pancake.piSide.netwerking.ArduinoCommunication;

public class Main implements Runnable{
    public static boolean runningOnPi = false;

    public static void main(String[] args) {
        new Main().run();
    }

    @Override
    public void run() {
        try {
            setUpPiStuff();
        }catch (NotRunningOnPiException e) {
            System.out.println("You aren't running on PI:");
            e.getCause().printStackTrace();
            runningOnPi = false;
        }
        System.out.println("Opening GUI...");
        Application.launch(GuiMain.class);
    }

    private void setUpPiStuff() throws NotRunningOnPiException{
        try{
            SystemInfo.getHardware();
        } catch (Exception e) {
            return;
        }
        //Če smo kle, pol laufamo na piju
        runningOnPi = true;
        if (ArduinoCommunication.isOpen()){
            System.out.println("Arduino comm up and running!");
        }
    }
}
