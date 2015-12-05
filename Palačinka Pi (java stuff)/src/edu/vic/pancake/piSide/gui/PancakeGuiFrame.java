package edu.vic.pancake.piSide.gui;

import edu.vic.pancake.piSide.Main;

import javax.swing.*;
import java.awt.*;

/**
 * Ta class sestavi okno za izbiro palačink
 */
public class PancakeGuiFrame extends JFrame{
    private static enum Screens {
        SPLASH, INSERT_MONEY, NUTELLA_SELECTOR;
    }
    private Screens currentScreen = Screens.SPLASH;
    private Main main;

    private JLabel splashText;

    public PancakeGuiFrame(Main main) throws HeadlessException {
        super("PancakeMaker 9000 GUI");
        this.main = main;
        setLocation(0, 0);
        setSize(800, 600);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        addStuff();
        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        //TODO update screen if necessary
        super.paint(g);
    }

    private void addStuff(){
        splashText = new JLabel("PalačinkaMaker 9000");
        //Check if there is impact font
        String [] fonts = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
        String fontName = "Arial";
        for (String s:fonts){
            if (s.equals("Impact"))
                fontName = s;
        }
        Font splashFont =  new Font(fontName, Font.BOLD, 30);
        splashText.setFont(splashFont);
        add(splashText);
    }
}
