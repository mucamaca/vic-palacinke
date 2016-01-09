package com.grizeldi.pcToArduino;

import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.io.*;
import java.util.Enumeration;

/**
 * Class for sending stuff to Arduino.
 * Written for Windows.
 * Goes along with the code in arduino testing folder.
 */
public class Main implements Runnable, SerialPortEventListener{
    private SerialPort serialPort;
    public static final String PORT_NAME = "COM1";
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
            System.out.println("Port name: " + currentPortId.getName());
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
        Runtime.getRuntime().addShutdownHook(new Thread(new Runnable() {
            @Override
            public void run() {
                close();
            }
        }));
    }

    public synchronized void close(){
        if (serialPort != null){
            serialPort.removeEventListener();
            serialPort.close();
        }
    }

    @Override
    public void run() {
        BufferedReader console = new BufferedReader(new InputStreamReader(System.in));
        while (true){
            try {
                byte in = Byte.parseByte(console.readLine());
                output.write(in);
                output.flush();
            } catch (IOException e) {
                e.printStackTrace();
                return;
            }
        }
    }

    @Override
    public synchronized void serialEvent(SerialPortEvent serialPortEvent) {
        System.out.println("Serial event received: " + serialPortEvent);
        if (serialPortEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE){
            try {
                String in = input.readLine();
                System.out.println("Got message from Arduino: " + in);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
