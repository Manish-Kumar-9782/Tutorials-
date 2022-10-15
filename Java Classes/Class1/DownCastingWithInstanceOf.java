
interface Get {
    public void display();
}

class A implements Get {
    @Override
    public void display() {
        System.out.println("This is class a object");
    }
}

class B implements Get {
    @Override

    public void display() {
        System.out.println("This is class b object");
    }
}

class GetClassObject {

    void get(Get g) {
        // first we will get the upCasting values.

        // if we need to check that what type of variable we are getting.

        if (g instanceof A) {
            // now we need define another typecasting where g will be converted
            // to A.
            A a = (A) g;
            a.display();
        }

        if (g instanceof B) {
            // now here we need to define another typecasting
            // to B.
            B b = (B) g;
            b.display();
        }
    }

}

public class DownCastingWithInstanceOf {

    public static void main(String[] args) {
        GetClassObject get = new GetClassObject();

        Get g = new B(); // upCasting

        // Now we need to perform the downCasting.
        get.get(g);
    }

}
