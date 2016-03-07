package edu.vic.pancake.piSide.gui;

import edu.vic.pancake.piSide.Main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class InsertMoneyPanel extends JPanel{
    private PancakeGuiFrame frame;
    private JLabel messageLabel, insertedMoneyLabel;

    private float insertedMoney = 0.0F;

    public InsertMoneyPanel(final PancakeGuiFrame frame) {
        this.frame = frame;
        setLayout(new FlowLayout(FlowLayout.CENTER));

        if (Main.runningOnPi){
            System.out.println("Money inserter: Running on Pi, proceed by inserting money.");
        }else {
            System.out.println("Money inserter: Not running on Pi, proceed on click.");
        }

        messageLabel = new JLabel("Vstavi 1.00€.");
        insertedMoneyLabel = new JLabel("Še 1.00€");

        add(messageLabel);
        add(insertedMoneyLabel);
        repaint();

        /*addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (!Main.runningOnPi){
                    frame.changeScreen(PancakeGuiFrame.Screens.NUTELLA_SELECTOR);
                }
            }
        });*/
        addComponentListener(new ComponentAdapter() {
            @Override
            public void componentShown(ComponentEvent e) {
                System.out.println("n");
            }
        });
    }
}
