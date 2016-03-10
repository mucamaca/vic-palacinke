package edu.vic.pancake.piSide;

import com.pi4j.system.SystemInfo;
import edu.vic.pancake.piSide.gui.PancakeGuiFrame;
import edu.vic.pancake.piSide.netwerking.ArduinoCommunication;
import edu.vic.pancake.piSide.netwerking.ArduinoDebugFilter;

public class Main implements Runnable{
    public static boolean runningOnPi = true;
    public PancakeGuiFrame frame;

    public static void main(String[] args) {
        ArduinoCommunication.isOpen();
        ArduinoDebugFilter.shutDown = false;
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
        frame = new PancakeGuiFrame(this);
        frame.repaint();
    }

    private void setUpPiStuff() throws NotRunningOnPiException{
        try{
            SystemInfo.getHardware();
        } catch (Exception e) {
            throw new NotRunningOnPiException(e);
        }
        //Če smo kle, pol laufamo na piju
    }
}