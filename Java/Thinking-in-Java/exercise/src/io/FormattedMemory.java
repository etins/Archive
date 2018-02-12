package io;

import java.io.*;

public class FormattedMemory {
    public static void main(String[] args) throws IOException {
        try {
            DataInputStream in = new DataInputStream(
                new ByteArrayInputStream(
                        BufferedInputFile.read(
                                "FormattedmemoryInput.java"
                        ).getBytes()
                )
            );
            while(true)
                System.out.println((char)in.readByte());
        } catch (EOFException E) {
            System.err.println("End of stream");
        }
    }
}
