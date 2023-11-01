package human;
import mobile.Mobile;
class SmartPerson extends Person {
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