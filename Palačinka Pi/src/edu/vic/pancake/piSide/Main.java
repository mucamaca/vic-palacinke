package edu.vic.pancake.piSide;

import com.pi4j.system.SystemInfo;

import java.io.IOException;

public class Main implements Runnable{
    public static boolean runningOnPi = true;

    public static void main(String[] args) {
        new Main().run();
    }

    @Override
    public void run() {
        try {
            SystemInfo.getHardware();
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
            runningOnPi = false;
        }
    }
}