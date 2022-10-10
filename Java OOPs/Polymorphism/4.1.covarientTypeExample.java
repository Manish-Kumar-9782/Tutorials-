
/*
 * In this section we will see the problem without using the covariant type method 
 * overriding.
 */

class A1 {
    A1 getSelf() {
        return this;
    }
}

class A2 extends A1 {
    @Override
    A1 getSelf() {
        return this;
    }
}

class A3 extends A2 {
    @Override
    A1 getSelf() {
        return this;
    }
}

class Main {

    public static void main(String[] args) {

        A1 a1 = new A1();
        A2 a2 = new A2();
        A3 a3 = new A3();
        System.out.println(a1);
        System.out.println(a2);
        System.out.println(a3);
    }
}

/*
 * Explanation of above code:
 * 
 * -> In above example A1 is the parent class for A2 and A3;
 * 
 * -> A2 is the parent class for A3.
 * 
 * -> return type for getSelf() method in all classes is same.
 * 
 * -> in this we don't know the exact type of object the method is actually
 * returning.
 * 
 * -> we can only deduce that returned object will be of type A1, which is the
 * most generic class.
 * 
 * -> we cannot say for sure that returned object will be of A2 and A3. it is
 * where we need to do the type casting to find out the specific type of object
 * returned from the method.
 * 
 * -> it also requires precision from the programmer to ensure that typecasting
 * is
 * done property; we may get the ClassCastException.
 * 
 * -> if make we 10 to 15 level of hierarchal inheritance then this will be a
 * huge problem for both reader and writer to solve this issue we use the
 * Covariant Type
 * 
 */
