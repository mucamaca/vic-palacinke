package edu.vic.pancake.piSide.netwerking;

import java.io.*;

public class ArduinoDebugFilter extends Thread{
    public static boolean shutDown = false;

    static {
        new ArduinoDebugFilter().start();
        System.out.println("Starting arduino debug filter.");
    }

    @Override
    public void run() {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        while (!shutDown){
            try {
                if (ArduinoCommunication.inUnfiltered.available() > 0){
                    byte b = (byte)ArduinoCommunication.inUnfiltered.read();
                    if (b == 127){
                        char c;
                        boolean exit = false;
                        StringBuilder builder = new StringBuilder();
                        InputStreamReader inRead = new InputStreamReader(ArduinoCommunication.inUnfiltered);
                        while (!exit){
                            if (ArduinoCommunication.inUnfiltered.available() > 0) {
                                c = (char) inRead.read();
                                if (c == '\n')
                                    exit = true;
                                else
                                    builder.append(c);
                            }
                        }
                        System.out.println("[Arduino Debug]" + builder.toString());
                        logToFile(builder.toString());
                    }else {
                        ArduinoCommunication.in.add(b);
                    }
                }
            } catch (IOException e) {
                System.err.println("Debug filter encountered an error: ");
                e.printStackTrace();
            }
        }
    }

    private void logToFile(String message){
        File file = new File("Arduino.log");
        try (FileWriter fOut = new FileWriter(file, true);
                PrintWriter out = new PrintWriter(fOut)){
            out.println(message);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
