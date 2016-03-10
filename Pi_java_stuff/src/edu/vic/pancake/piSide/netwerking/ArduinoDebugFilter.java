package edu.vic.pancake.piSide.netwerking;

import java.io.IOException;
import java.io.InputStreamReader;

public class ArduinoDebugFilter extends Thread{
    public static boolean shutDown = false;

    static {
        new ArduinoDebugFilter().run();
    }

    @Override
    public void run() {
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
                        System.out.println(builder.toString());
                        //TODO log to file
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
}
