package edu.vic.pancake.piSide.gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class SplashPanel extends JPanel{
    private PancakeGuiFrame frame;
    private JLabel splashText;
    private AnimatorThread animatorThread;

    public SplashPanel(final PancakeGuiFrame frame) {
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
        Font splashFont =  new Font(fontName, Font.BOLD, 50);
        splashText.setFont(splashFont);
        splashText.setHorizontalAlignment(SwingConstants.CENTER);
        setLayout(new BorderLayout());
        add(splashText, BorderLayout.CENTER);

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                frame.changeScreen(PancakeGuiFrame.Screens.INSERT_MONEY);
            }
        });
    }

    private void update(){
        //TODO more work neeeded
        repaint();
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
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
