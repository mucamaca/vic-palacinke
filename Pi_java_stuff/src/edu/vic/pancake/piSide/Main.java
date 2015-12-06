package edu.vic.pancake.piSide;

import com.pi4j.system.SystemInfo;
import edu.vic.pancake.piSide.gui.PancakeGuiFrame;
import edu.vic.pancake.piSide.netwerking.ArduinoCommunication;

import java.io.IOException;

public class Main implements Runnable{
    public static boolean runningOnPi = true;
    public ArduinoCommunication communication;
    public PancakeGuiFrame frame;

    public static void main(String[] args) {
        new Main().run();
    }

    @Override
    public void run() {
        try {
            setUpPiStuff();
        }catch (NotRunningOnPiException e) {
            System.out.println("You aren't running on PI:");
            e.printStackTrace();
            runningOnPi = false;
        }
        System.out.println("Opening GUI...");
        frame = new PancakeGuiFrame(this);
        frame.repaint();
    }

    private void setUpPiStuff() throws NotRunningOnPiException{
        try{
            SystemInfo.getHardware();
        } catch (InterruptedException | IOException e) {
            throw new NotRunningOnPiException();
        }
        //Če smo kle, pol laufamo na piju
        ArduinoCommunication.init();
        communication = ArduinoCommunication.instance;
    }
}