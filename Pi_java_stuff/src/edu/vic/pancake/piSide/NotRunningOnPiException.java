package edu.vic.pancake.piSide;

public class NotRunningOnPiException extends Exception{
    private Throwable cause;

    public NotRunningOnPiException(Throwable cause) {
        super(cause);
        this.cause = cause;
    }

    @Override
    public Throwable getCause() {
        return cause;
    }
}
