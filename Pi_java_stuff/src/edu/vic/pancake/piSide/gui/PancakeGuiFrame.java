package edu.vic.pancake.piSide.gui;

import edu.vic.pancake.piSide.Main;

import javax.swing.*;
import java.awt.*;

/**
 * Ta class sestavi okno za izbiro palačink
 */
public class PancakeGuiFrame extends JFrame{
    public enum Screens {
        SPLASH, INSERT_MONEY, NUTELLA_SELECTOR;
    }
    public Screens currentScreen;
    private Main main;
    boolean shouldExit = false;
    private boolean animatingBigger = true;

    //GUI elements
    private SplashPanel splashPanel;

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
                    add(splashPanel);
                    break;
                case INSERT_MONEY:
                    break;
                case NUTELLA_SELECTOR:
                    break;
            }
        }
    }

    private void addStuff(){
        //Init em all
        splashPanel = new SplashPanel(this);

        add(splashPanel);
        pack();
    }
}
