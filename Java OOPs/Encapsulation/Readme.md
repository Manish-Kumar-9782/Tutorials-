# Encapsulation in Java

Encapsulation in java is a process of wrapping code and data together into a single unit, for example capsule which is mixed of several medicines, a automobile engine which is assembled with different small components.

We can create a fully encapsulated class in java by making all the data members of the class private. To access and modify the we can use setter and getter methods to set and get the data.

### Advantage of Encapsulation in java

* we can make a class read-only or write-only, by using the getter or setter method.

* we can get more control over the data. (e.g. we can make some restriction on the data like assigning valid value and accessed from valid user.)

* it is a way to achieve data hiding in java because other class will not be able to access the data through the private data members.

* The encapsulate class is easy to test. So, it is better fro unit testing.

example of encapsulated class:

```java
class Student{

    private String name; // private data member

    // getter function for name data member 
    public String getName(){
        return this.name;
    }   

    // setter function for name data member
    public void setName(String name){
        this.name = name;
    }
}
```

**Read-Only Class**
A class which has only getter methods.
```java
class Student{
    private String name; // private data member

    // getter function for name data member 
    public String getName(){
        return this.name;
    }   
}
```

**Write-only class**
A class which has only setter methods.
```java

class Student{
    private String name; // private data member 

    // setter function for name data member
    public void setName(String name){
        this.name = name;
    }
}
```
____
<br><br>

# Java Package

A java-package is group of similar types of classes, interfaces and sub-packages. Package in java can be categorized in two form, built-in package and user-defined package.

`Built-in Package:` java, lang, awt, javax, swing, net, io, util, sql etc.

### Advantage of Java Package

1. Java package is used to categorize the classes and interfaces so that they can be easily maintained.

2. Java package provides access protection.

3. Java package removes naming collision.

**compile java package**
```
javac -d directory javafilename
```
here: -d switch specifies the destination were to put the generated class file. 

**run package**
```
java packagename.classname
```
Note: here we need to use the fully qualified name to run the desired class.

### Accessing the Other packages

There are three ways to access the package from outside the current working package.

**`1. import package.`** 

* if we use `package.*` then all the classes and interfaces of this package will be accessible but not subpackages.

* The `import` keyword is used to amke the classes and interface of another package accessible to current package.

```java
package pack;   
public class A{  
  public void msg(){System.out.println("Hello");}  
}    
```

```java
package mypack;  
import pack.*;  // importing all classes
  
class B{  
  public static void main(String args[]){  
   A obj = new A();  
   obj.msg();  
  }  
}    
```


**`2. package.class`**

* if we import `package.classname` then only declared class of this package will be accessible.

```java
package pack;  
public class A{  
  public void msg(){System.out.println("Hello");}  
}   
```

```java
package mypack;  
import pack.A;  // importing a specified class
  
class B{  
  public static void main(String args[]){  
   A obj = new A();  
   obj.msg();  
  }  
}   
```


**`3. Using fully qualified name`**

* if we use fully qualified name then only declared class of this package will be accessible. Here we don't need to use the `import` keyword but we need to use fully qualified name every time when we are accessing the class or interface. 

```java
package pack;  
public class A{  
  public void msg(){System.out.println("Hello");}  
}  
```

```java
package mypack;  
class B{  
  public static void main(String args[]){  
   pack.A obj = new pack.A();//using fully qualified name  
   obj.msg();  
  }  
}  
```
<div class='note'>
<p> <b>Note:</b> If we import a package, all the classes and interface of that package will be imported excluding the classes and interfaces of the subpackages. There for , we need to import the subpackage as well.</p>
</div>

## Subpackage in java

Package inside the package is called the subpackage. it should be created to categorize the package further.

**Subpackage example**

```java
package com.vrist.edu;  
class Education{  
  public static void main(String args[]){  
   System.out.println("This is Education sub package");  
  }  
}  
```

compile:
```
javac -d directory filename.java
```

run:
```
java com.vrist.edu.Education
```

# Access Modifiers Visibility 

<table>
        <tr>
            <th>Access Modifiers</th>
            <th>Within class</th>
            <th>Within packages</th>
            <th>Outside package by subclass only</th>
            <th>Outside package</th>
        </tr>
        <tr>
            <td>Private</td>
            <td>Y</td>
            <td>N</td>
            <td>N</td>
            <td>N</td>
        </tr>
        <tr>
            <td>Default</td>
            <td>Y</td>
            <td>Y</td>
            <td>N</td>
            <td>N</td>
        </tr>
        <tr>
            <td>Protected</td>
            <td>Y</td>
            <td>Y</td>
            <td>Y</td>
            <td>N</td>
        </tr>
        <tr>
            <td>Public</td>
            <td>Y</td>
            <td>Y</td>
            <td>Y</td>
            <td>Y</td>
        </tr>
    </table>