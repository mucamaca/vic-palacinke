package edu.vic.pancake.piSide;

import com.pi4j.system.SystemInfo;
import edu.vic.pancake.piSide.netwerking.ArduinoCommunication;

import java.io.IOException;

public class Main implements Runnable{
    public static boolean runningOnPi = true;
    public ArduinoCommunication communication;

    public static void main(String[] args) {
        new Main().run();
    }

    @Override
    public void run() {
        try {
            setUpPiStuff();
        }catch (NotRunningOnPiException e) {
            e.printStackTrace();
            runningOnPi = false;
        }

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