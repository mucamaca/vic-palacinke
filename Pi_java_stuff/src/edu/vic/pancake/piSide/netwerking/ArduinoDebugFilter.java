package edu.vic.pancake.piSide.netwerking;

import java.io.IOException;

public class ArduinoDebugFilter extends Thread{
    static {
        new ArduinoDebugFilter().run();
    }

    @Override
    public void run() {
        //FIXME add a graceful shutdown
        while (true){
            try {
                if (ArduinoCommunication.inUnfiltered.available() > 0){
                    byte b = (byte)ArduinoCommunication.inUnfiltered.read();
                    if (b == 127){
                        //TODO print all next stuff
                    }else {
                        ArduinoCommunication.in.add(b);
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
