package edu.vic.pancake.piSide.gui;

import javax.swing.*;
import java.awt.*;

/**
 * Ta class sestavi okno za izbiro palačink
 */
public class PancakeGuiFrame extends JFrame{
    private static enum Screens {
        SPLASH, INSERT_MONEY, NUTELLA_SELECTOR;
    }

    public PancakeGuiFrame() throws HeadlessException {
        super("PancakeMaker 9000 GUI");
        setLocation(0, 0);
        setSize(800, 600);
    }
}
