package edu.vic.pancake.piSide.netwerking;

/**
 * Class ki skrbi za komunikacijo z Arduinom.
 * @author Matevž
 * @author Luka
 */

public class ArduinoCommunication {
    public static ArduinoCommunication instance;
    private boolean shouldExit = false;
    private ListenerThread listenerThread;

    public static void init() { instance = new ArduinoCommunication(); }


    private ArduinoCommunication() {
        listenerThread = new ListenerThread();
    }

    public void sendToArduino(MessageTypes type){
        //TODO pošlji sporočilo
    }

    public void shutDown(){
        shouldExit = true;
    }

    private class ListenerThread extends Thread{
        public ListenerThread() {
            this.start();
        }

        @Override
        public void run() {
            while (!shouldExit){
                //TODO detekta sporočila z arduina in jih dostavi listenerjem
            }
        }
    }
}
