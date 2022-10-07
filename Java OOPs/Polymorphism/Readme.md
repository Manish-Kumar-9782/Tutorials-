# Polymorphism in Java

Polymorphism means "many forms", and it occurs when we have many classes that are related to each other by inheritance. This allow us to perform a single action in different ways.

In this section we will see that how to achieve the polymorphism in java programming with different approach.

## Method Overloading in Java

if a class has multiple methods having same name but different in parameter, it is known as Method Overloading. if we have to perform only one operation, having same name of the methods increases the readability of the program.

To understand the method overloading and its uses, let's consider an ***add*** function example: suppose that we want to add two integer, float, short, byte, long, double numeric number in this case we can define the add function for each kind operation with the same name but with the different number or datatype argument and also with the different return type.

for example:
```java
int add(int a, int b){
    return a+b;
}

float add(float a, float b){
    return a+b
}

short add(short a, short b){
    return a+b
}

double add(double a, double b){
    return a+b
}

long add(long a, long b){
    return a+b
}
```

In the above example add function is an overloaded function which can same operation with many data type or we can say that same operation in many ways. 

We can achieve the method overloading in two ways.

1. By changing number of arguments.
2. By changing the data type.

Note: in java we can overload a method by just changing the return type of the method only.

### Method Overloading: changing no. of arguments

```java
int add(int a,int b){
    return a+b;
    } 
// overloading the add function with      
int add(int a,int b,int c){
    return a+b+c;
    }
```

In the above examples we have two methods with the same name and same return type, but they both have different number of parameters.

### Method Overloading: changing data type of arguments

```java
int add(int a,int b){
    return a+b;
    } 
// overloading the add function with      
double add(double a,double b){
    return a+b+c;
    }
```
In the above example we have two methods with the same name but with different return type, one method return int and other return double. They also take different kind of data type as argument value.

Note: method overloading is not possible by changing the return type of the method only because of ambiguity. Consider below example

```java
int add(int a,int b){
    return a+b;
    } 
// overloading the add function with      
double add(int a,int b){
    return a+b+c;
    }
```
<output style='background-color: rgba(126, 127, 129, 0.10);
padding: 10px;
margin-top: 5px;
border-radius: 5px;
color: lightsteelblue;'>Compile Time Error: method add is already defined...</output> 

-----
-----

# Method Overriding in Java

if subclass (child class) has the same method as declared in the parent class, it is known as method overriding in java.

in other words, if a subclass provides the specific implementation of the method that has been declared by one of its parent class, it is known as method overriding. 

**Usage of java Method Overriding**

* Method overriding is used to provide the specific implementation of a method which is already provide by its superclass.

* Method overriding is used for runtime polymorphism.

**Rules for Java Method Overriding.**

* The method must have the same name as in the parent class.
* The method must have the same parent as in the parent class.
* There must be an IS-A relationship (inheritance).

**`Example of the method overriding`**

```java
class Animal{

    void walk(){
        System.out.println("Animal is walking..")
    }
}

class Dog extends Animal{

    void walk(){
        System.out.println("Dog is walking..")
    }
}
```
**`Points To note:`**

* A static method cannot be overridden. 
* Because it is bound with class whereas instance method is bound with an object. Static belongs to the class area, and an instance belongs to the heap area.

Method Overriding with Access Modifier:

Consider an example given below:

```java
class A {
    protected void func1() {
        System.out.println("hello func1");
    }
}

public class Test extends A {
    void func1() {
        System.out.println("hello func1");
    }
}
```
If we are overriding any method then overridden method must not be more restrictive. if we override method with more restrictive Access Specifier then it will raise a compiler time error.


### Difference b/w the Method Overloading & Method Overriding.

<table>
        <tr>
            <th>SN.</th>
            <th>Method Overloading</th>
            <th>Method Overriding</th>
        </tr>
        <tr>
            <td>1.</td>
            <td>Method overloading is used to increase the readability of the program.</td>
            <td>Method overriding is used to provide the specific implementation of the method that is already provided
                by its super class.</td>
        </tr>
        <tr>
            <td>2.</td>
            <td>Method overloading is performed within class.</td>
            <td>Method overriding occurs in two classes that have IS-A (inheritance) relationship</td>
        </tr>
        <tr>
            <td>3.</td>
            <td>Incase of method overloading, parameter must be different.</td>
            <td>In case of method overriding parameter must be same.</td>
        </tr>
        <tr>
            <td>4.</td>
            <td>Method overloading is the example of compile time polymorphism.</td>
            <td>Method overriding is the example of the run time polymorphism.</td>
        </tr>
        <tr>
            <td>5.</td>
            <td>In java, method overloading can't be performed byy changing return type of the method only. Return type can be ame or different in method overloading. But we must have to change the parameter.</td>
            <td>Return type must be same or covariant in method overriding.</td>
        </tr>
    </table>

----
----

<br>

# Covariant Return Type

The covariant return type specifies that the return type may vary in the same direction as the subclass.

it is possible to override method by changing the return type if subclass overrides any method whose return type is Non-Primitive but it changes its return type to subclass type.

consider this example:

```java
class A{
    A get(){
        return this;
    }
}

class B extends A{
    @Override // override annotation
    B get(){
        return this;
    }
}
```
As you can see in the above example, the return type of the `get()` method of _A_ class is _A_ but the return type of the `get()` method of _B_ class is _B_. Both methods have different return type but it is method overriding. This is known as covariant return type.

we are overriding the `get()` method by changing the class type _B_ which is not a primitive data type. 

## Advantage of Covariant Return Type

1. Covariant return type assists to stay away from the confusing type casts in the class hierarchy and makes the code more usable, readable, and maintainable.

2. In the method overriding, the covariant return type provides the liberty to have more to the point return types.

3. Covariant return type helps in preventing the run-time ClassCastExceptions on returns.