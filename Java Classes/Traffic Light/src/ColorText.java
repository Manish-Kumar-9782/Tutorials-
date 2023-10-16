public class ColorText {

    public static final String FORGROUND_RED = "\u001B[31m";
    public static final String FORGROUND_ORANGE = "\u001B[33m";
    public static final String FORGROUND_GREEN = "\u001B[32m";
    public static final String FORGROUND_RESET = "\u001B[0m";
    public static final String BLOCK = "\u2587";

    public static String getColor(String color){
        return color + BLOCK + BLOCK + FORGROUND_RESET;
    }
    
}
