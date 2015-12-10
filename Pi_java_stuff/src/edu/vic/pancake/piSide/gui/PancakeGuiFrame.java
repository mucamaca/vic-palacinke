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

    //GUI elements
    private SplashPanel splashPanel;
    private InsertMoneyPanel insertMoneyPanel;

    public PancakeGuiFrame(Main main) throws HeadlessException {
        super("PancakeMaker 9000 GUI");
        this.main = main;
        setLocation(0, 0);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        addStuff();
        setVisible(true);
    }

    public void changeScreen(Screens screen){
        if (screen != currentScreen){
            removeAll();
            System.out.println("Changing screen to " + screen + ".");
            switch (screen){
                case SPLASH:
                    add(splashPanel);
                    System.out.println("switched to splash");
                    break;
                case INSERT_MONEY:
                    add(insertMoneyPanel);
                    System.out.println("switched to insert");
                    break;
                case NUTELLA_SELECTOR:
                    break;
            }
            repaint();
        }
    }

    private void addStuff(){
        //Init em all
        splashPanel = new SplashPanel(this);
        insertMoneyPanel = new InsertMoneyPanel(this);

        add(splashPanel);
    }
}
