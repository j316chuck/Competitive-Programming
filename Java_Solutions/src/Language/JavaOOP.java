package Language;

public class JavaOOP{
    //I DONT HAVE TO DO THIS BECAUSE PROJECT 2
    /* Notes */

   static class parent {
        int var1 = 2;
        public parent() {

        }
        /*public parent (int v) {
            var1 = v;
        }*/
        @Override
        public String toString() {
            return ((Integer) var1).toString();
        }
    }

    static class child extends parent{
        int var1 = 1;
        /*public child(int v) {
            var1 = v;
        }*/
        @Override
        public String toString() {
            return ((Integer) var1).toString();
        }
    }

    public static void main(String[] args) {

        child c = new child();
        System.out.println(c);
        parent p = c;
        System.out.println(p);
        System.out.println(p.var1);
        //okay so parent.var1 is a different variable than child.var1... thus they can have two different values
        //thus c.var1 = 1; parent.var1 = 2;


    }
    /*Constructor Rules
    1.classes = constructor called
    2.always this or super called (unless explicitly stated)
    3.no overriding constructors
    4.interfaces do not have constructors
    5. abstract classes can have constructors...
    6. use this() to invoke another parameter of same class
    */

    /* Polymorphism Rules
    1. Method Overriding
        a. applies only to inherited methods
        b. overriding method can have different return types (only subtypes of the same refernce or same as primitive void = void)
        c. cannot have more restrictive access modifier
        d. abstract methods must be overriden
        e. static and final methods cannot be overriden!!!
        f. argument list of overriding method should be exactly the same
        g. can throw any unchecked exceptions but not any checked exceptoins that are new or broader than the ones declared by the overriden method
        
     2. Overloading
        a. constructor can be overloaded
        b. can take place in same class or in subclass
        c. known as compile type polymorphism
        d. method return type may or may not be different for overloading (what matters is paramter type and #)
     */
}
