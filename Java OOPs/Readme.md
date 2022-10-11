# Java OOPs Programming

In this section, we will learn about the basic of OPPs Object-Oriented Programming is paradigm that provides many concepts, such as inheritance, data binding, polymorphism, etc.

## Section Contains

* Advantage of OOPs
* Naming Convention
* Object and class
* Method overloading
* Constructor
* static keyword
* this keyword with six usage
* Inheritance
* Aggregation
* Method Overriding
* Covariant Return Type
* super keyword
* Instance Initializer block
* final keyword
* Abstract class
* Interface
* Runtime Polymorphism
* Static and Dynamic Binding
* Downcasting with instanceof operator
* Package
* Access Modifiers
* Encapsulation
* Object Cloning


**Simula** is considered the first object-oriented programming language. The programming paradigm where everything is represented as an object is known as a truly object-oriented programming language.

**Smalltak** is considered the first truly object-oriented programming language.

The popular object-oriented languages are Java, C#, PHP, Python, C++, etc.

The main aim of object-oriented programming is to implement real-world entities, for example, object, classes, abstraction, inheritance, polymorphism, etc.


## OPPs (Object-Oriented Programming System)

**Object** means a real-world entity such as a pen, chair, table, computer, watch, etc.** Object-Oriented Programming** is a methodology or paradigm to design a program using classes and objects. It simplifies software development and maintenance by providing some concepts:

* Object
* Class
* Inheritance
* Polymorphism
* Abstraction
* Encapsulation

Other terms in OPPs design:

* Coupling
* Cohesion
* Association
* Aggregation
* Composition

* **Object:** Any entity that has state and behavior is known as an object. For example, a chair, pen, table, keyboard, bike, etc. It can be physical or logical.

* **class:** An Object can be defined as an instance of a class. An object contains an address and takes up some space in memory. Objects can communicate without knowing the details of each other's data or code. The only necessary thing is the type of message accepted and the type of response returned by the objects.

### Class

Collection of objects is called class. it is a logical entity. A class can be also be defined as a blueprint form which we can create an individual object. Class doesn't consume any space.

### Inheritance

When one object acquires all the properties and behaviors of a parent object, it is known as inheritance. It provides code reusability. It is used to achieve runtime polymorphism.

### Polymorphism

If one task is performed in different ways, it is known as polymorphism. For example: to convince the customer differently, to draw something, for example, shape, triangle, rectangle, etc.

In Java, we use method overloading and method overriding to achieve polymorphism.

### Abstraction

Hiding internal details and showing functionality is known as abstraction. For example phone call, we don't know the internal processing.

In Java, we use abstract class and interface to achieve abstraction.

### Encapsulation

Binding (or wrapping) code and data together into a single unit are known as encapsulation. For example, a capsule, it is wrapped with different medicines.

A java class is the example of encapsulation. Java bean is the fully encapsulated class because all the data members are private here.

### Coupling

Coupling refers to the knowledge or information or dependency of another class. It arises when classes are aware of each other. If a class has the details information of another class, there is strong coupling. In Java, we use private, protected, and public modifiers to display the visibility level of a class, method, and field. we can use interfaces for the weaker coupling because there is no concrete implementation.

### Cohesion

Cohesion refers to the level of a component which performs a single well-defined task. A single well-defined task is done by a highly cohesive method. The weakly cohesive method will split the task into separate parts. The java.io package is a highly cohesive package because it has I/O related classes and interface. However, the java.util package is a weakly cohesive package because it has unrelated classes and interfaces.

### Association

Association represents the relationship between the objects. Here, one object can be associated with one object or many objects. There can be four types of association between the objects:

* One to One
* One to Many
* Many to One
* Many to Many

Note: Association can be unidirectional or bidirectional.

### Aggregation

Aggregation is a way to achieve Association. Aggregation represents the relationship where one object contains other objects as a part of its state. It represents the weak relationship between objects. It is also termed as a has-a relationship in Java. Like, inheritance represents the is-a relationship. It is another way to reuse objects.

### Composition

The composition is also a way to achieve Association. The composition represents the relationship where one object contains other objects as a part of its state. There is a strong relationship between the containing object and the dependent object. It is the state where containing objects do not have an independent existence. If you delete the parent object, all the child objects will be deleted automatically.

________

<br>
<br>

# Java Naming Convention

Java naming convention isa rule to follow as we decide what to name our identifiers as class, package, variable, constant, method, etc. But, it is not forced to follow. So, it is known as convention not rule. These convention are suggested by several Java Communities such as Sun Microsystems and Netscape.

All the classes, interfaces, packages, methods and fields of Java programming language are given according to the Java naming convention. If we fail to follow these conventions, it may generate confusion or erroneous code.

By using standard Java naming conventions, we make our code easier to read for ourself and other programmers. Readability of Java program is very important. It indicates that less time is spent to figure out what the code does.

### Naming conventions of the Different Identifiers

<table>
        <thead>
            <tr>
                <th>Identifiers Type</th>
                <th>Naming Rules</th>
                <th>Example</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Class</td>
                <td>It should start with the uppercase letter. it should be noun sucah as Color, Button, System. Thread.
                    etc use appropriate words, instead of acronyms.</td>
                <td>
                    <span><pre>public class Employee{}</pre></span>
                </td>
            </tr>
            <tr>
                <td>Interface</td>
                <td>It should start with the uppercase letter. It should be an adjective such as Runnable, Remote, ActionListener. Use appropriate words, instead of acronyms.</td>
                <td><span><pre>interface Printable{}</pre></span></td>
            </tr> 
            <tr>
                <td>Method</td>
                <td>It should start with lowercase letter. it should be verb such as main(), print(), println(). if the name contains multiple words, start it with a lowercase letter followed by an uppercase letter such as actionPerformed().</td>
                <td><span>
                <pre>class Test{
    void testing(){}
    }
                </pre>
                </span></td>
            </tr>
            <tr>
                <td>Variable</td>
                <td>it should start with a lowercase letter such as id, name, it should not start with the special characters like & (ampersand), $(dollar), _ (underscore). if the name contains multiple words, start it with the lowercase letter followed by an uppercase letter such as firstName, lastName. Avoid using one-character variable such as x,y,z.</td>
                <td><span>
                <pre>class Employee{
    int empId;
    }
                </pre>
                </span></td>
            </tr>
            <tr>
                <td>Package</td>
                <td>it should be a lowercase such as java, lang. if the name contains multiple words, it should be separated by dots(.) such as java.util, java.lang.</td>
                <td><span>
                <pre>com.test;
class Employee{
    int empId;
    }
                </pre>
                </span></td>
            </tr>
            <tr>
                <td>Constant</td>
                <td>it should be in uppercase letters such as RED, YELLOW. if the name contains multiple words, it should be separated by an underscore(_) such as MAX_PRIORITY. it may contain digits but not as the first letter.</td>
                <td><span>
                <pre>class Employee{
    int empId;
    static final int MIN_AGE = 18;
    }
                </pre>
                </span></td>
            </tr>
        </tbody>
    </table>

### CamelCase in java naming conventions

Java follows camel-case syntax for naming the class, interface, method, and variable. if the name is combined with two words, the second word will start with uppercase letter always such as actionPerformed(), firstName(), ActionEvent(), ActionListener, etc.

   
