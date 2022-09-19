# Advance C++

## Pointers in C++

The pointer in C++ language is a variable, it is also known as locater or indicator that points to an address of a value.

**Advantage of pointer**

1. Pointer reduces the code and improves the performance, it is used to retrieving strings, trees etc. and used with arrays, structurs and functions.

2. we can return multiple values from function using pointers.

3. it makes us able to access any memory location in the computer's memory.

**Usage of pointers.**

There are many usage of pointers in C++ language.

`Dynamic memory allocation:` In C/C++ language, we can dynamically allocate memory using malloc() and calloc() functions where pointers is used.

`Arrays, functions and structures: ` Pointers in C/C++ language are widely used in arrays, functions and sturectures. it reduces the code and improves the performance.

| Symbol            | Name                 | Description                         |
| ----------------- | -------------------- | ----------------------------------- |
| &(ampersand)      | Address operator     | Determine the address of a vaiable. |
| * (asterisk sign) | indirection operator | Access the value of an address.     |

**Declaring a pointer**

The pointer in C/C++ language can be declared by using *(asterisk symbol).

```C++
int *a;// pointer to int.
char *ch; // pointer to a char 
Type *t; // pointer to a custom type.
```
<b style="color:orange;">Note:</b> char* pointer works differently than the other pointer.

**sizeof() operator**

The sizeof() operator is an operator that evalutes the size of dat type,
constants, variable. it is a compile-time operator as it returns the size
of any varaible or a constant at the compliation time.

the size, which is calculated by the sizeof() operator, is  the amount of RAM
occupied in the computer.

Syntax: sizeof(data_type);

Here "data_type" can be the dat type of the data, varaibles, constants,
unions, stuructures, or any other user-defined data type.

sizeof() operator can be applied to the following operand:

    -> when an operand is of data type.
    -> when an operand is of class type.
    -> when an operand is of array type.
    -> when an operand is of pointer type.
    -> when an operand is an expression.
----

**Void Pointer in C++**

A void pointer is a general-purpose pointer that can hold the address of any data type, but it is not associated with any data type.

Void Pointer: A void pointer is a general-purpose pointer that can
hold the address of any data type, but it is not associated with
any data type.

Syntax: 
```C++ 
void *ptr;
```

In C++, we cannot assign the address of a variable to the variable of a different
data type.for example if we want to assign a float variable address to
an pointer to int then it will throw an error.

```C++
int *ptr;
float a = 34235.45345;
ptr = &a; //  error
```
**Difference b/w void pointer in C and C++**

In C, we can assign the void pointer to any other pointer type without any typecasting, whereas in C++, we need to typecast when we assign the void pointer type to any other pointer type.

----
## Template in C++

In this section we will  learn about the template, whate are the
template and how to use them.

It allows us to define the generic classes and generic functions
hence it provide the support for the generic programming.

`Generic Programming:` it is a technique where generic types are
used as parameters in algorightms so that they can work for
varity of data types.

Template can be represent in two types:

    1. Function templates.
    2. Class templates.


`Function Template: `if a template is defined for function then it
is called function template, it allow us to specify the single datatype
for each parameter, we don't need to specify the specific data type in
that function it will take any kind of parameter.

`Class Template:` if a template is defined for a class then it is 
called as a class template, which allow us the different kind 
of type in our class without specifing them in our class.

### Function template

1. function template are defined by spcefiying the `template<typename type>` just befor the return type.
2. here `type` is just a place holder which will be replaced with the actual data type later during the compilation.
3. `typename` is a keyword to tell the compiler that the next word will be type-placeholder not a variable or indentfier.
4. function template are called generic functions which can define a set of operation that can be applied to the various types of data.

```C++
template <typename Type>
void function_template(Type a)
{
    cout << "You have entered: " << a << endl;
}
```
**A template function with two argument**
```C++
template <typename type1, typename type2>
void function_template_multiple_types(type1 t1, type2 t2)
{
    cout << "this is a mutliple type template fucntions." << endl;
}
```

<b style="color:blue;">Note:</b> we can have any number of argument in a template which give us a huge advange over the overloading the function with the same number of argument but different types.

### Function template overloading

A function template can be overloaded by if a function template defined with the same name but with different number of parameter then it is called the overloading the function template.

**An Exmpale of overloaded function template**

```C++
template <typename type1>
void fun(type1 t1)
{
    cout << "firs parameter: " << t1 << endl;
}

template <typename type1, typename type2>
void fun(type1 t1, type2 t2)
{
    cout << "firs parameter: " << t1 << endl;
    cout << "second parameter: " << t2 << endl;
}

```

In the above example we have a `fun()` with two differnt function template with differnt number of parameters. in this case our function template `fun()` has been overloaded.


#### Restriction of Generic Functions

Generic functions perform the same operations for all the versions of a functions except teh data type differs.But we cannot use a generic function two defination of a __function__ is differernt to each other and both contain the same number of parameters.

for example:

```C++
void fun(float a)
{
    cout << "value of a is " << a << endl;
}

void fun(int a)
{

    if (a % 2 == 0)
        cout << "Number is even" << endl;
    else
        cout << "Number is odd" << endl;
}
```
If we have the situation such above, then we can't have a generic function for function `fun()`.


## Class Template

Class Template: class templates are defined in same way as function
template defined. when a class uses the template then the class is
know as the generic class.

`Syntax:`
```C++
template <class Type>
class class_name{
    // body of the class.
}
```

`class:` here class keyword show that the next word is a type not an identifier.
    we can use the typname instead of the class we mis-understand the term.

`Type:` it is a placeholder for the data type which will be used in our class.

**class template with multiple parameter**

class template can have multiple parameter like function template do,
each parameter is separated by comma.

```C++
template <class T1, class T2, ... , class Tn>
class class_name{
    // body of class
}
```

`instance -->`
```C++
class_name<type1, type2,..., typen> obj;
```
Here type1, type2, ... , typen can by any type. For example...

```C++
class_name<int, float,..., double> obj;
```
### Nontype template arguments

The template can contain multiple arguments, and we can also use the
non-type arguments in addtion to the type T argument, we can also use
other types of arguments such as string, function names, constant expression
and built-in types.

`Syntax:`
```C++
template <class type, int a>
class Student{
    T arr[a]// here a is the size of array.
    // T is the type of array items.
}
```

**Points to Remember**

* C++ supports a powerful feature known as a template to implement the concept of generic programmin.

* A template allows us to create a family of classes or family of functions to handle different data types.

* Template classes and functions eliminate the code duplication of different data types and thus makes the development easier and faster.

* Multiple parameters can be used in both class and functions template.

* Template functions can also be overloaded.

* We can also use nontype arguments such as built-in or derieved data types as template arguments.