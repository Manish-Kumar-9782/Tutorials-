package LibManage;

import java.util.Scanner;

public class Address {
    int plno, pincode;
    String street, landmark, town, city, district, state, country;

    Address(){}; // default constructor.
    Address(int plno, String street, String landmark, String town, String city,
            String district, String state, String country, int pincode){
        this.plno = plno;
        this.state = state;
        this.street = street;
        this.landmark = landmark;
        this.town = town;
        this.city = city;
        this.district = district;
        this.country = country;
        this.pincode = pincode;
    }

    void scanAddress(){
        Scanner scan = new Scanner(System.in);
        Display.printSep(100);
        System.out.println("Address Information: \n");
        System.out.print("Enter Plot No.");
        this.plno = scan.nextInt();
        scan.nextLine();
        System.out.print("Enter street.");
        this.street = scan.nextLine();
        System.out.print("Enter landmark.");
        this.landmark = scan.nextLine();
        System.out.print("Enter town.");
        this.town = scan.nextLine();
        System.out.print("Enter city.");
        this.city = scan.nextLine();
        System.out.print("Enter district.");
        this.district = scan.nextLine();
        System.out.print("Enter state.");
        this.state = scan.nextLine();
        System.out.print("Enter country.");
        this.country = scan.nextLine();
        System.out.print("Enter pincode.");
        this.pincode = scan.nextInt();
    }
    void display(){
        System.out.println(String.format("%20s %20s", "Plot No:", this.plno));
        System.out.println(String.format("%20s %20s", "Street:", this.street));
        System.out.println(String.format("%20s %20s", "Landmark:", this.landmark));
        System.out.println(String.format("%20s %20s", "Town:", this.town));
        System.out.println(String.format("%20s %20s", "City:", this.city));
        System.out.println(String.format("%20s %20s", "District:", this.district));
        System.out.println(String.format("%20s %20s", "State:", this.state));
        System.out.println(String.format("%20s %20s", "Country:", this.country));
        System.out.println(String.format("%20s %20s", "Pincode:", this.pincode));
    }
}
