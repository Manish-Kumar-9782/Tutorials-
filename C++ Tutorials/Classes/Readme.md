# Classes In C++

### Inheritance 

Inheritance: The capability of a "class" to derive properties and characteristcs from another class is called inheritance. 

Inheritance is a feature or a process in which new classes are created from 
the existing classes. The new class created is called "derived class" or 
"Child class" and the existing class is known as the "base class" or 
"parent class". The derived class now is said to be inherited from the base 
class.

`Explanation:` when we say derived class inherits the base class, it means the derived class inherits all the properties of the base class, without changing the properties of base class and may add new features to tis own.

These new features in the derived class will not affect the base class. The derived class is the extended version of the base class.

`Sub Class:` The class that inherits properties from another class is called _subclass_ or _derived class_.

`Super Class:` The class whose properties are inherited by a subclass is called _BaseClass_ or _SuperClass_.

#### What is the need of inheritance and where should we use it.

Suppose that we want to create classes for different kind of vehicle like, Bus, Car, Truck, Bike etc. For all of these classes ther are some methods which will be common to each classes like applyBreak(), headLightOn(), headLightOff(), start(), move() etc. 

In this kind of situation we have to redefine the same functionality for each class which will be a time consuming task, To avoid this kind of situation we use the inheritance concept in which we make a class which will 
have those common functionality for the _sub-class_ or _derived-class_.

By Defining a common class for each type of vehical who share the common functionality, they will inherit those functionality from that super class.

