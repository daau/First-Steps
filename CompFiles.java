/*
Project 10-1

Compare two files

To use this program, specify the names
of the files to be compared
on the command line.

java CompFile FIRST.TXT SECOND.TXT
 */

import java.io.*;

class CompFiles{
    public static void main(String args[])throws IOException{
        int i=0, j=0;
        FileInputStream f1;
        FileInputStream f2;

        try{
            // open first file
            try{
                f1 = new FileInputStream(args[0]);
            }
            catch(FileNotFoundException exc){
                System.out.println(args[0] + " File Not Found");
                return;
            }

            // open second file
            try{
                f2 = new FileInputStream(args[1]);
            }
            catch(FileNotFoundException exc){
                System.out.println(args[1] + " File Not Found");
                return;
            }

        }
        catch(ArrayIndexOutOfBoundsException exc){
            System.out.println("Usage: CompFile f1 f2");
            return;
        }

        // Compare files
        try{
            do{
                i = f1.read();
                j = f2.read();
                if(i != j) break;
            }
            while( (i != -1) && (j != -1));
        }
        catch(IOException exc){
            System.out.println("File error");
        }
        if(i!=j)
            System.out.println("Files differ.");
        else
            System.out.println("Files are the same.");
        f1.close();
        f2.close();
    }
}
