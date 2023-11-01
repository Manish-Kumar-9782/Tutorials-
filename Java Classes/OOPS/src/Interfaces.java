
// creating a new interface.
interface Mobile{
    // by default all methods in interface are public and abstract.
    void call();
    void endCall();

    private void establish_connection(){
        System.out.println("establishing the connection...");
    }

    default void wifi_call(){
        this.establish_connection();
        System.out.println("making a wifi_call");
    }
}


// now implementing the interface.

class Iphone implements Mobile{

    public void call(){
        System.out.println("Calling Iphone");
    }

    public void endCall(){
        System.out.println("End Calling Iphone..");
    }
}


class Samsung implements Mobile{

    public void call(){
        System.out.println("Calling Samsung");
    }

    public void endCall(){
        System.out.println("End Calling Samsung..");
    }
}

class SmartPerson extends Person{


    SmartPerson(String name, int age, double height) {
        super(name, age, height);
    }

    public void makeCall(Mobile m){
        System.out.println(this.name + " making a call..");
        m.call();
        m.endCall();
    }

    public void make_wifiCall(Mobile m){
        System.out.println(this.name + " making a wifi call..");
        m.wifi_call();
    }
}