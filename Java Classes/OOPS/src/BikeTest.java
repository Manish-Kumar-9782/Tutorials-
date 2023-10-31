class Bike{
    void run(){System.out.println("Bike running");}
}

// extending the Bike by Splender class
class Splendor extends Bike{
    @Override
    void run(){System.out.println("Splender Bike running safely with 60km");}

    public static void main(String args[]){
        Bike b1 = new Bike();
        Bike b2 = new Splendor();//upcasting

        b1.run();
        b2.run();

        boolean a =  b2 instanceof Bike;
    }
}