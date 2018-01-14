package exceptions;

import java.util.logging.*;
import java.io.*;

class LoggingException extends Exception{
    private static Logger logger =
            Logger.getLogger("LogginException");
    public LoggingException() {
        StringWriter trace = new StringWriter();
        printStackTrace(new PrintWriter(trace));
        logger.severe(trace.toString());
    }
}

public class LoggingExceptions {
    public static void main(String[] args) {
        try {
            throw new LoggingException();
        } catch (LoggingException e) {
            System.err.print("Caught " + e );
        }
        try {
            throw new LoggingException();
        } catch (LoggingException e) {
            System.out.println("Caught " + e);
        }
    }
}