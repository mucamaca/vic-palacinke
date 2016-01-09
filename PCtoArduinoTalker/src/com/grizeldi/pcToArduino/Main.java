package com.grizeldi.pcToArduino;

import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.Enumeration;

/**
 * Class for sending stuff to Arduino.
 * Written for Windows.
 * Goes along with the code in arduino testing folder.
 */
public class Main implements Runnable, SerialPortEventListener{
    private SerialPort serialPort;
    public static final String PORT_NAME = "COM3";
    public static final int BAUD_RATE = 9600;

    private BufferedReader input;
    private OutputStream output;

    public static void main(String[] args) {
        new Main();
    }

    public Main() {
        CommPortIdentifier portId = null;
        Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();
        //Find the correct port.
        while (portEnum.hasMoreElements()){
            CommPortIdentifier currentPortId = (CommPortIdentifier) portEnum.nextElement();
            if (currentPortId.getName().equals(PORT_NAME)){
                portId = currentPortId;
            }
        }
        //Check if we found port.
        if (portId == null){
            System.out.println("Couldn't find COM3 port.");
            return;
        }
        //Open the port and add a listener.
        try {
            serialPort = (SerialPort) portId.open(Main.class.getName(), 2000);
            serialPort.setSerialPortParams(BAUD_RATE,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);

            output = serialPort.getOutputStream();
            input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));

            serialPort.addEventListener(this);
            serialPort.notifyOnDataAvailable(true);
        } catch (Exception e){
            System.err.println(e.toString());
            return;
        }
        new Thread(this).start();
    }

    @Override
    public void run() {

    }

    @Override
    public void serialEvent(SerialPortEvent serialPortEvent) {

    }
}
