import com.sun.security.jgss.GSSUtil;

import java.io.IOException;
import java.util.Vector;


public class Main {

    public static Vector<String> pathSignals =  new Vector<>();
    public static String redSignal = ColorText.getColor(ColorText.FORGROUND_RED);
    public static String yellowSignal = ColorText.getColor(ColorText.FORGROUND_ORANGE);
    public static String greenSignal = ColorText.getColor(ColorText.FORGROUND_GREEN);

    public static void main(String[] args) {

    pathSignals.add(0,redSignal);
    pathSignals.add(1,redSignal);
    pathSignals.add(2,redSignal);

    int signal_number = 1;

    while(true){
        Countdown countdown_time = new Countdown(5);

        switch (signal_number){

            case 1:
                // for 1st path.
                handleSignal(1,countdown_time);
                break;

            case 2:
                // for 2nd path
                handleSignal(2,countdown_time);
                break;

            case 3:
                // for 3rd path
                handleSignal(3,countdown_time);
                break;
            default:
                System.out.println("System has been failed");
        }
        if(signal_number >= 3) signal_number = 1;
        else signal_number++;
        countdown_time.start();
        clearScreen();
    }

    }

    public static void handleSignal(int signal_number, Countdown countdown){

        for(int i=1; i<=pathSignals.size(); i++){
            if(i==signal_number) System.out.print(greenSignal + "\t");
            else System.out.print(redSignal + "\t");
        }
        System.out.println("\n");
    }

    public static void clearScreen(){
        try{
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        }
        catch (IOException | InterruptedException e){
            System.out.println("Error: "+ e.getMessage());
        }
    }
}
