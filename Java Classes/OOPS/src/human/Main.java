package human;
import mobile.*;
public class Main {

    public static void main(String[] args) {

        Iphone ip = new Iphone();
        Samsung sm = new Samsung();

        SmartPerson pr = new SmartPerson("khurshid", 21, 5.7);

        pr.makeCall(ip);

    }
}
