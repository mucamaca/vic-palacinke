package edu.vic.pancake.piSide.gui;

import edu.vic.pancake.piSide.Main;

import javax.swing.*;
import java.awt.*;

/**
 * Ta class sestavi okno za izbiro palačink
 */
public class PancakeGuiFrame extends JFrame{
    public static enum Screens {
        SPLASH, INSERT_MONEY, NUTELLA_SELECTOR;
    }
    public Screens currentScreen = Screens.SPLASH;
    private Main main;
    boolean shouldExit = false;
    private boolean animatingBigger = true;

    //GUI elements
    private JLabel selectorScreenTitle, insertMoneyText, moneyCounter;
    private JButton nutellaKnof, brezVsegaKnof, marmeladaKnof;
    private JButton okKnof, cancelKnof;

    //Layout managers
    private FlowLayout flowLayout = new FlowLayout();
    private BorderLayout borderLayout = new BorderLayout();

    public PancakeGuiFrame(Main main) throws HeadlessException {
        super("PancakeMaker 9000 GUI");
        this.main = main;
        addStuff();
        setLocation(0, 0);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void changeScreen(Screens screen){
        if (screen != currentScreen){
            System.out.println("Changing screen to " + screen);
            removeAll();
            switch (screen){
                case SPLASH:
                    setLayout(flowLayout);
                    //add(splashText);
                    break;
                case INSERT_MONEY:
                    break;
                case NUTELLA_SELECTOR:
                    setLayout(borderLayout);
                    add(selectorScreenTitle, BorderLayout.NORTH);
                    break;
            }
        }
    }

    private void addStuff(){
        //Init em all
        selectorScreenTitle = new JLabel("Izberi namaz");
        
        moneyCounter = new JLabel("0.00 €");
	    insertMoneyText = new JLabel("Vstavi denar");

        okKnof = new JButton("OK");
        cancelKnof = new JButton("Cancel");
        
        nutellaKnof = new JButton("Nutella");
        brezVsegaKnof = new JButton("Brez");
        marmeladaKnof = new JButton("Marmelada");
    }
}
