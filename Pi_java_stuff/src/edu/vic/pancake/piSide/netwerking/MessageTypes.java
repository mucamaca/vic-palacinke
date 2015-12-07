package edu.vic.pancake.piSide.netwerking;

/**
 * Vse vrste sporočil, ki si jih lahko izmenjujeta pi in arduino.
 * @see edu.vic.pancake.piSide.netwerking.ArduinoCommunication
 */
public enum MessageTypes {
    //TODO dodaj vse tipe pred podpičje
    WAKEUP;

    public boolean isSingleUse(){
        //TODO funkcija naj returna true, če se sporočilo lahko pošlje/prejme samo enkrat
        return false;
    }
}
