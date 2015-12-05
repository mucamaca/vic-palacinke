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
    private boolean shouldExit = false;
    private AnimatorThread animatorThread;
    private boolean animatingBigger = true;

    private JLabel splashText;

    public PancakeGuiFrame(Main main) throws HeadlessException {
        super("PancakeMaker 9000 GUI");
        this.main = main;
        addStuff();
        animatorThread = new AnimatorThread();
        setLocation(0, 0);
        setSize(800, 600);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void changeScreen(Screens screen){
        if (screen != currentScreen){
            System.out.println("Changing screen to " + screen);
            removeAll();
            switch (screen){
                case SPLASH:
                    add(splashText);
                    break;
                case INSERT_MONEY:
                    break;
                case NUTELLA_SELECTOR:
                    break;
            }
        }
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
        splashText.setHorizontalAlignment(SwingConstants.CENTER);
        add(splashText);
    }

    private void update(){
        if (currentScreen == Screens.SPLASH){
            int fontSize = splashText.getFont().getSize();
            if (animatingBigger){
                splashText.setOpaque(false);
            }
            System.out.println("Current animatingBigger: " + animatingBigger);
        }
        repaint();
    }

    /**
     * Ker funkcija update() ne dela, jo bomo klicali sami.
     */
    private class AnimatorThread extends Thread{
        public AnimatorThread() {
            this.start();
        }

        @Override
        public void run() {
            while (!shouldExit){
                update();
                try {
                    sleep(20);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
