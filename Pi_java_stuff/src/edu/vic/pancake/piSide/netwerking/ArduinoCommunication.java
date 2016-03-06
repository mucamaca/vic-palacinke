package edu.vic.pancake.piSide.netwerking;

import gnu.io.*;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.TooManyListenersException;

/**
 * Class ki skrbi za komunikacijo z Arduinom.
 * Komunikacija poteka prek streamov in in out.
 * @author Luka
 */

public class ArduinoCommunication {
    public static OutputStream out;
    public static InputStream in;

    private static final String PORT = "";
    private static final int BAUD_RATE = 9600;
    private static SerialPort serialPort;

    static {
        //Poišči port
        CommPortIdentifier portId = null;
        Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();
        while (portEnum.hasMoreElements()){
            CommPortIdentifier currentPortId = (CommPortIdentifier) portEnum.nextElement();
            if (currentPortId.getName().equals(PORT)){
                portId = currentPortId;
            }
        }
        //Preveri če smo dejansko našli port
        if (portId != null){
            System.err.println("Port " + PORT + " ni najden.");
            System.exit(-1);
        }
        //Imamo port identifier, odprimo in in out
        try {
            serialPort = (SerialPort) portId.open(ArduinoCommunication.class.getName(), 2000);
            serialPort.setSerialPortParams(BAUD_RATE,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);

            serialPort.notifyOnDataAvailable(true);
            //Tukaj dodaj še ostale notify zadeve po potrebi.

            out = serialPort.getOutputStream();
            in = serialPort.getInputStream();
        } catch (PortInUseException e) {
            e.printStackTrace();
            System.exit(-1);
        } catch (UnsupportedCommOperationException e) {
            e.printStackTrace();
            System.exit(-1);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
        //Port odprt. Dodamo hook za zapiranje porta ob exitanju
        Runtime.getRuntime().addShutdownHook(new Thread(new Runnable() {
            @Override
            public void run() {
                if (serialPort != null) {
                    serialPort.removeEventListener();
                    serialPort.close();
                    try {
                        in.close();
                        out.close();
                    } catch (IOException e) {
                    }
                }
            }
        }));
    }

    public static boolean addSerialPortListener(SerialPortEventListener listener){
        try {
            serialPort.addEventListener(listener);
        } catch (TooManyListenersException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
