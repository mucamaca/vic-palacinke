package edu.vic.pancake.piSide.netwerking;

public class ArduinoListener{
    public static ArduinoListener instance;
    
    static {
        instance = new AruinoListener();
    }
    
    private ArduinoListener(){
        //Thread thread =  TODO
    }
}
