
/*
 * public: class will be public it means we can access this class outside the package.
 * 
 * public method: if a function of a class defined as public then this function can be accessed 
 * from outside the package.
 * 
 * static: 
 * 
 *  -> allocate at time of class loading. (compile time allocation)
 * -> do not bound to class instance, only bounded by class.
 * -> to use we don't need to make instance of that class.
 * 
 * 
 */

public class JavaIntro {

    public static void main(String[] args) {
        // statements

        // args: it is an array of string values, they are passed by the CLI interface.
        for (int i = 0; i < args.length; i++) {
            System.out.println(args[i]);
        }
    }

}
