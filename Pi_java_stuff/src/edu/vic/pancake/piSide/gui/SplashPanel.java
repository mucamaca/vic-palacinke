package edu.vic.pancake.piSide.gui;

import javax.swing.*;
import java.awt.*;

public class SplashPanel extends JPanel{
    private PancakeGuiFrame frame;
    private JLabel splashText;
    private AnimatorThread animatorThread;

    public SplashPanel(PancakeGuiFrame frame) {
        this.frame = frame;
        splashText = new JLabel("PalačinkaMaker 9000");
        animatorThread = new AnimatorThread();

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
        //TODO more work neeeded
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
            while (!frame.shouldExit){
                update();
                try {
                    sleep(20);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("GUI animator thread exiting.");
        }
    }
}
