# Inheritance

Inheritance is the one of the Pillar of the OPPs programming, In this section we will learn about the inheritance concept, what is inheritance and how to use it.

Inheritance in Java is a mechanism in which one object acquires all the properties and behaviors of a parent object. It is an important part of OOPs (Object Oriented programming system).

In java we can create other classes by using the some predefined classes (existing classes). When we inherit from an existing class, we can reuse methods and fields of the parent class. In addition we can add new methods and fields in our current class also by which we can extends our functionality.

Inheritance represent the `IS-A relationship` which is also known as a parent-child relationship.

### Why to use inheritance

* Code reusability
* To achieve Runtime Polymorphism
* To extend the existing the classes

### Terms used in inheritance

* `class:` A class is a group of objects which have common properties. it is a template or blueprint form which object are created.

* `Sub Class/Child Class:` Subclass is a class which inherits the other class. it is also called a derived class, extended class, or child class.

* `Super Class/Parent Class:` Superclass is the class from where a subclass inherits the features. it is also called a base class or a parent class.

* `Reusability:` Reusability is a mechanism which facilitates us to reuse the fields and methods of the existing class when we create a new class. we can use the same fields and methods already defined in the previous class.

**Inheritance Syntax**

```java
class SubClass extends SuperClass{
    // SubClass fields declaration & definition.
    // SubClass Constructor
    // SubClass methods.

}
```
Here **extends** keyword indicates that we are making a new class that derives from an existing class. The meaning of "extends" is to increase the functionality.

Note: A class which is inherited is called a parent or superclass and the new class is called child or subclass.

Here is a simple example of the inheritance.

```java
class Student{

    String name;
    int age;
    double height;

    void display() {

        System.out.println("PrimaryKey:\t\t");
        System.out.println("Name:\t\t" + this.name);
        System.out.println("Age:\t\t" + this.age);
        System.out.println("Height:\t\t" + this.height);
    }
}

// Inheriting Student class by Employee class

class Employee{

    int empid;
    double salary;

    void display(){
        super.display();
        System.out.println("EmpId:\t\t" + this.empid);
        System.out.println("Salary:\t\t" + this.salary);
    }
}
```
## Types of inheritance in java

In java we have three types of inheritance.

* Single Inheritance
* Multilevel Inheritance
* Hierarchical Inheritance

In java, multiple and hybrid inheritance is supported through interface only.

![typesofinheritance](typesofinheritance.jpg)

Note: Multiple inheritance is not supported in java through class.

**Multiple Inheritance is not supported in java?**

* To avoid the Ambiguity (same name collision in b/w two classes)
* To reduce the complexity and simplify the language


# Aggregation in Java

if a class have an entity reference, it is known as Aggregation. Aggregation represents HAS-A relationship.

Consider a situation where an instance is created of another class which contain its own fields and method, in such case our class will have an entity reference of that object, in this case relation is class HAS-A object.

**Use of Aggregation**

use of aggregation gives use some benefits like:

* Code reuse when there is no need of is-a relationship.
* Inheritance should be used only if the relationship IS-A is maintained throughout the lifetime of the object involved; otherwise, aggregation is the best choice.

A Basic Example of the Aggregation for student class.

```java

class Address{
    int plot_no, pincode;
    String street, town, city, state,country;

    public Address(int pn, String street, String town, String city, String state, String country){
        this.plot_no =pn; 
        this.city = city;
        this.street = street;
        this.town= town;
        this.state =state;
        this.country = country;
    }

}

class Student{

    String name;
    int age;
    double height;
    Address address; // HAS-A relationship

    void display() {

        System.out.println("PrimaryKey:\t\t");
        System.out.println("Name:\t\t" + this.name);
        System.out.println("Age:\t\t" + this.age);
        System.out.println("Height:\t\t" + this.height);
    }
}
```
Here in the above example we have a class `Address` which contains it's own fields and method and we use this `Address` as the filed of the Student which refers to the reference of the instance of the `Address` hence this is a HAS-A relationship.
