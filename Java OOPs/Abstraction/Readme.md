# Abstract class in java

A class which is declared with the abstract keyword is known s an abstract class in java. it can have abstract and non-abstract method (method with the body.)

## Abstraction

Abstraction is a process of hiding the implementation details and showing only functionality to the user.

Another way, it shows only essential things to the user and hides the internal details, for example, sending SMS where you type the text and send the message. You don't know the internal processing about the message delivery.

There are two way to achieve abstraction in java:

1. Abstract class (0 - 100%)
2. interface (100%)

## Abstract class in java

A class is declared as abstract is known as an abstract class. it can have abstract and non-abstract methods. it needs to be extended and its method implemented. it cannot be instantiated.

**`Pointes to Note:`**

* An abstract class must be declared with an abstract keyword.
* it can have abstract and non-abstract methods.
* it cannot be instantiated.
* it can have constructors and static methods also.
* it can have final methods which will force the subclass not to change the body of the method.

```java
abstract class className{
    // statement;
}
```
### Abstract method in java

A method which is declared as abstract and does not have implementation is known as an abstract method.

```java
abstract void someFunc(); // method declaration.
```

**Example of the abstract class:**

```java
abstract class Automobile{
    abstract void run(); // only declaration 
}

// now inheriting the Bike class
class Car{
    void run(){
        System.out.println("Car is running on road!..");
    }
}
```

Note: if there is an abstract method in a class, that class must be abstract method.

Note: if we are extending an abstract class that ahs an abstract method, we must either provide the implementation of the method or make this class abstract.

Note: The abstract class can also be used to provide some implementation of the interface. In such case, the end user many not be forced to override al the methods of the interface.

----
----

# Interface in Java

An interface in Java is a blueprint of a class. It has static constants and abstract methods.

The interface in Java is a mechanism to achieve abstraction. There can be only abstract methods in the Java interface, not method body. It is used to achieve abstraction and multiple inheritance in Java.

In another words, interface can have abstract methods and fields. it cannot have a method body.

Java Interface also represent the IS-A relationship. it cannot be instantiated just like the abstract class. we can have default, static and private methods in an interface.

## Use of Interface

* It is used to achieve abstraction.
* By interface, we can support the functionality of multiple inheritance.
* It can be used to achieve loose coupling.

### Declaration of the Interface

An interface is declared by using the interface keyword. it provides total abstraction; means all the methods in an interface are declared with the empty body, and all the fields are public, static and final by default. A class that implements an interface must implement all the methods declared in the interface.

```java
interface interface_name{
    // declare public static final fields.
    // declare all the abstract methods.
}
```

Note: Since java 8 interface improvement: The java compiler adds public and abstract keywords before the interface method. it adds public, static and final keyword before data members.

### Relation b/w the classes and interfaces.

* a class  `extends` another class.
* a class `implements` an interface.
* an interface `extends` another interface. 

### Multiple inheritance in java By Interface

if a class implements multiple interfaces, or an interfaces extends multiple interfaces, it is known as multiple inheritance.

For example:

```java
interface Printable{
    void print();
}

interface Showable{
    void show();
}

// Now a class will implement these two interfaces.
class A implements Printable, Showable{

    void print(){
        System.out.println("Printing the message");
    }

    void show(){
        System.out.println("Showing the message");
    }
}
```

Note: multiple inheritance is not supported in java by classes but it is possible by an interface. because there is no ambiguity.it is because its implementation is provided by the implementation class.

For example:

```java
interface Printable{
    void print();
}

interface Showable{
    void print();
}

// Now a class will implement these two interfaces.
class A implements Printable, Showable{

    void print(){
        System.out.println("Printing the message");
    }
}
```

## Interface Inheritance

A class implements an interface, but an interface extends another interface.

```java
interface Printable{
    void print();
}

interface Showable extends Printable{
    void show();
}

// Now a class will implement these two interfaces.
class A implements Showable{

    void print(){
        System.out.println("Printing the message");
    }
    void show(){
        System.out.println("Showing the message");
    }
}
```

### Default Method in Interfaces

Since java 8, we can have method body in interface. But we need to make it default method.

```java
interface Printable{
    default void print(){
        System.out.println("Printing the message by default method.");
    }
}

// Now a class will implement these two interfaces.
class A implements Printable{

    void show(){
        System.out.println("Showing the message");
    }
}
```

### Static Method in Interface

Since Java 8, we can have static method in interface. 

```java
interface Printable{
    static void print(){
        System.out.println("Printing the message by default method.");
    }

    void show();
}

// Now a class will implement these two interfaces.
class A implements Printable{

    void show(){
        System.out.println("Showing the message");
    }
}
```

### Marker or Tagged Interface

An interface which has no member is known as a marker or tagged interface, for example, Serializable, Cloneable, Remote etc. They are used to provide some essential information to the JVM so that JVM may perform some useful operation.

## Difference b/w abstract class and interface

<table>
        <tr>
            <th>Abstract Class</th>
            <th>Interface</th>
        </tr>
        <tr>
            <td>Abstract class can have abstract and non-abstract methods.</td>
            <td>Interface can have only abstract methods. Since java 8, it can have default and static methods alos</td>
        </tr>
        <tr>
            <td>Abstract class doesn't support multiple inheritance</td>
            <td>interface supports multiple inheritance.</td>
        </tr>
        <tr>
            <td>Abstract class can have final, non-final static and non-static variable.</td>
            <td>Interface has only static and final variable.</td>
        </tr>
        <tr>
            <td>Abstract class can provide the implementation of interface.</td>
            <td>Interface can't provide the implementation of abstract class.</td>
        </tr>
        <tr>
            <td>The abstract keyword is used to declare abstract class.</td>
            <td>the interface keyword is used to declare interface.</td>
        </tr>
        <tr>
            <td>An abstract class can implement multiple java interfaces</td>
            <td>An interface can extend another java interface only.</td>
        </tr>
        <tr>
            <td>An abstract class can be extended using the keyword "extends".</td>
            <td>An interface can be implemented using keyword "implements".</td>
        </tr>
        <tr>
            <td>A java abstract class can have class members like private, protected, public, default.</td>
            <td>Members of a java interface are public by default.</td>
        </tr>
    </table>
