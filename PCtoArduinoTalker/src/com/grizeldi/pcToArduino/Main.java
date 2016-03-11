package com.grizeldi.pcToArduino;

import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.io.*;
import java.util.Enumeration;

/**
 * Class for sending stuff to Arduino.
 * Written for Windows and Linux. @grizeldi found it not working on Windows.
 * Goes along with the code in arduino testing folder.
 * Needs java RXTX library.
 */
public class Main implements Runnable, SerialPortEventListener{
    private SerialPort serialPort;
    public String PORT_NAME;
    public static final int BAUD_RATE = 9600;

    private BufferedReader input;
    private OutputStream output;

    public static void main(String[] args) {
        if (args.length > 0){
            switch (args [0].toLowerCase()){
                case "linux":
                    new Main(OS.LINUX);
                    break;
                case "windows":
                    new Main(OS.WINDOWS);
                    break;
                default:
                    jamalify();
            }
        }else {
            jamalify();
        }
    }

    /**
     * Used to tell the user that he/she is a Jamal.
     * Nice joke.
     */
    private static void jamalify(){
        System.out.println("Jamal, you is stupid.");
        System.out.println("You need to pass a windows/linux parameter!");
    }

    /**
     * Init happens here.
     * @param os OS you are running on.
     */
    private Main(OS os) {
        switch (os){
            case WINDOWS:
                PORT_NAME = "USB1";
                break;
            case LINUX:
                PORT_NAME = "/dev/ttyUSB0";
                break;
            default:
                return;
        }

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

    /**
     * Reads from the console and sends to Arduino.
     */
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

    /**
     * Listener for serial events.
     * When it receives a data available event, it reads the data and prints it.
     * @param serialPortEvent We are only interested in data available events.
     */
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
