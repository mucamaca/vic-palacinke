package edu.vic.pancake.piSide.netwerking;

/**
 * Class ki skrbi za komunikacijo za Arduinom.
 * @author Matevž
 * @author Luka
 */
public class ArduinoCommunication {
    public static ArduinoCommunication instance = new ArduinoCommunication();
    private boolean shouldExit = false;

    private ArduinoCommunication() {

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
