package mobile;

// creating a new interface.
public interface Mobile{
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
