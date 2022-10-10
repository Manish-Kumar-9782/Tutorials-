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

3. Covariant return type helps in preventing the run-time `ClassCastExceptions` on returns.

```java
class A1{
    A1 getSelf(){return this;}
}
class A2{
    A2 getSelf(){return this;}
}
class A3{
    A3 getSelf(){return this;}
}
```
**How is Covariant return types implemented?**

Java doesn't allow the return type-based overloading, but JVM always allows return type-based overloading. JVM uses the full signature of a method for lookup/resolution. Full signature means it includes return type in addition to argument types. that is, a class can have two or more methods differing only by return type. java compiler uses this fact to implement covariant return types.


# Super Keyword

The `super` keyword in java is a reference variable which is used to refer immediate parent class object. Whenever we create the instance of subclass, an instance of parent class is created implicitly which is referred by super reference variable. 

**Usage of java super keyword**

1. super can be used to refer immediate parent class instance variable.
2. super can be used to invoke immediate parent class.
3. super() can be used to invoke immediate parent class constructor.

Note: super() is added in each class constructor automatically by compiler in there is no super() or this(). we know that default constructor is provided by compiler automatically if there is no constructor, it also adds super() as the first statement.

<br>

# Instance initializer block

Instance Initializer block is used to initialize the instance dat member. it run each time when object of the class is created. The initialization of the instance variable can be done directly but there can be performed extra operations while initializing the instance variable in the instance initializer block.

Note: The java compiler copies the code of instance initializer block in every constructor as the first statement, that's why an initializer block will always execute before the constructor statements.

```java
class A{
    int var1;

    A(){
        System.out.println("constructor is invoked");
    }

    {System.out.println("initializer block is invoked");}
}

```

### Rules of instance initializer block:

1. The instance initializer block is created when instance of the class is created.
2. The instance initializer block is invoked after the parent class constructor is invoked.(i.e after super() constructor call).
3. The instance initializer block comes in the order in which they appear.


<br>

# final keyword 

The `final keyword` in java is used to restrict the user. The java final keyword can be used in many context.

1. variable  (stop value change)
2. method (stop method overriding)
3. class (stop inheritance)

The final keyword can be applied with variables, a final variable that have no value is called blank final variable or uninitialized final variable. it can be initialized in constructor only.

The blank final variable can be static also which will be initialized in the static block only.

### Blank or uninitialized final variable

A final variable that is not initialized at the time of declaration is known as blank final variable. it can be initialized only in constructor.

**staic blank final variable:**

A static final variable that is not initialized at the time of declaration is known as static blank final variable. it can be initialized only in static block.

if we declare any parameter as final, we cannot change the value of it.


# Runtime Polymorphism 

Polymorphism in Java is a concept by which we can perform a single action in different ways. Polymorphism is derived from 2 Greek words: `poly` and `morphs`. The word "poly" means many and "morphs" means forms. So polymorphism means many forms.

There are two types of polymorphism in Java: compile-time polymorphism and runtime polymorphism. We can perform polymorphism in java by method overloading and method overriding.

**Runtime Polymorphism in java:**

Runtime polymorphism or Dynamic Method Dispatch is a process in which a call to an overridden method is resolved at runtime rather than compile-time.

In this process, an overridden method is called through the reference variable of a superclass. The determination of the method to be called is based on the object being referred to by the reference variable.

**Upcasting::** if the reference variable of parent class refers to the object of child class, it is known as upcasting.

```java
class A{}
class B extends A{}
```

```java
A a  = new B(); // upcasting.
```
For upcasting, we can use the reference variable of class type or interface type.

Example of runtime polymorphism:

```java
class Automobile{

    void run(){
        System.out.println("running");
    }
}

class Car{
    @Override // runtime polymorphism.
    void run(){
        System.out.println("Car is running");
    }
}
```
Note: method invocation is determined by the JVM not compiler, hence it is known as runtime polymorphism.

Note: Runtime polymorphism can't be achieved by data members.

<br>

# Static & Dynamic Binding

Connecting a method call to the method body is known as binding. There are two type of binding.

1. Static Binding (also known as Early Binding) : When type of the object is determined at compiled time, it is known as static binding. if there is any private, final or static method in a class, there is static binding.

2. Dynamic Binding (also known as Late Binding): When type of the object is determined at run-time, it is known as dynamic binding.

**Example of static binding:**

```java

class A{
    static void func(){}
}
```
```java
A.func(); // static binding.
```

**Example of Dynamic binding:**

```java
class A{
    void func()
}

class B extends A{
    @Override
    void func(){
        // override statements.
    }
}
```
```java
A b = new B();
a.func(); // dynamic binding.
```

<br>

# instanceof Operator

The `instanceof` operator is used to test whether the object is an instance of the specified type (class or subclass or interface). 

The instanceof in java is also known as type comparison operator because it compares the instance with type. it returns either true or false. if we apply the instanceof operator with any variable that has null, value it returns false.

**Example of instanceof operator:**

```java
class A{
    void greet("hello world");
}

class Main{
    public static void main(String[] args){
        A a = new A();

        System.out.println(a instanceof A);
    }
}
```
```java
Output: true
```

An object of subclass type is also a type of parent class. for example, if `Dog` extends `Animal` then object of `Dog` can be referred by either `Dog` or `Animal` class.

Note: if we apply instanceof operator with a variable that have null value, it returns false.

**`DownCasting:`** When subclass type refers to the object of parent class, it is known as downcasting. if we perform it directly compiler gives compilation error. if we perform it by typecasting `ClassCastException` is thrown at runtime. but if we use the `instanceof` operator, downcasting is possible.