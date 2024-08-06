
## Python Conditional Statements

Conditional statements are the cornerstone of decision-making in Python programming. They provide the ability to execute different code blocks based on whether specific conditions are met or not. This flexibility is instrumental in creating dynamic and responsive applications.

### Understanding Conditional Statements

Conditional statements in Python revolve around the `if` keyword. They offer various structures to control the program's flow based on logical expressions. The outcome of these expressions, either `True` or `False`, determines which code block is executed.

### The `if` Statement

The most basic conditional statement is the `if` statement. It executes a block of code if the specified condition is true.

**Syntax:**

```python
if condition:
    # code to be executed if condition is true
```

**Example:**

```python
age = 18
if age >= 18:
    print("You are an adult.")
```

In this example, the condition `age >= 18` is evaluated. Since it's true, the code within the `if` block is executed, printing "You are an adult."

### The `if-else` Statement

The `if-else` statement provides two possible execution paths based on a condition. If the condition is true, the code within the `if` block runs; otherwise, the code within the `else` block executes.

**Syntax:**

```python
if condition:
    # code to be executed if condition is true
else:
    # code to be executed if condition is false
```

**Example:**

```python
age = 15
if age >= 18:
    print("You are an adult.")
else:
    print("You are a minor.")
```

Here, the condition `age >= 18` is false, so the code within the `else` block is executed, printing "You are a minor."

### The `if-elif-else` Statement

The `if-elif-else` statement allows for multiple conditions to be checked sequentially. The first condition that evaluates to `True` will have its corresponding code block executed. If none of the conditions are true, the optional `else` block is executed.

**Syntax:**

```python
if condition1:
    # code to be executed if condition1 is true
elif condition2:
    # code to be executed if condition2 is true
elif condition3:
    # code to be executed if condition3 is true
else:
    # code to be executed if none of the conditions are true
```

**Example:**

```python
number = 0
if number > 0:
    print("Number is positive")
elif number < 0:
    print("Number is negative")
else:
    print("Number is zero")
```

In this example, none of the conditions are true, so the `else` block is executed, printing "Number is zero."

### Key Considerations

* Indentation is crucial in Python to define code blocks within conditional statements. Consistent indentation enhances code readability.
* Conditions are evaluated from top to bottom, and the first true condition determines the executed code block.
* The `else` block is optional and provides a default action if no conditions are met.
* Nested `if` statements can be used for more complex decision-making, but they should be used judiciously to avoid overly complex code.
* Conditional statements can be combined with logical operators (and, or, not) to create more intricate conditions.

## Python If-Else Practice Problems

### Problem 1: Even or Odd

**Task:** Write a Python program to check if a given number is even or odd.

```python
number = int(input("Enter a number: "))

if number % 2 == 0:
    print(number, "is even")
else:
    print(number, "is odd")
```

### Problem 2: Largest of Three Numbers

**Task:** Write a Python program to find the largest among three given numbers.

```python
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))
num3 = float(input("Enter third number: "))

if (num1 >= num2) and (num1 >= num3):
   largest = num1
elif (num2 >= num1) and (num2 >= num3):
   largest = num2
else:
   largest = num3

print("The largest number is", largest)
```

### Problem 3: Check if a number is positive, negative, or zero

**Task:** Write a Python program to check if a given number is positive, negative, or zero.

```python
number = float(input("Enter a number: "))

if number > 0:
   print("The number is positive")
elif number < 0:
   print("The number is negative")
else:
   print("The number is zero")
```

### Problem 4: Check if a year is leap year

**Task:** Write a Python program to check if a given year is a leap year.

```python
year = int(input("Enter a year: "))

if (year % 400 == 0) or ((year % 4 == 0) and (year % 100 != 0)):
   print(year, "is a leap year")
else:
   print(year, "is not a leap year")
```

### Problem 5: Check if a character is vowel or consonant

**Task:** Write a Python program to check if a given character is a vowel or consonant.

```python
char = input("Enter a character: ")

if char in ('a', 'e', 'i', 'o', 'u'):
    print(char, "is a vowel")
else:
    print(char, "is a consonant")
```

### Problem 6: Calculate the grade of a student based on marks

**Task:** Write a Python program to calculate the grade of a student based on their marks.

```python
marks = float(input("Enter the marks obtained: "))

if marks >= 90:
    grade = 'A'
elif marks >= 80:
    grade = 'B'
elif marks >= 70:
    grade = 'C'
elif marks >= 60:
    grade = 'D'
else:
    grade = 'F'

print("Grade:", grade)
```

### Problem 7: Check if a number is divisible by 5 and 7

**Task:** Write a Python program to check if a given number is divisible by both 5 and 7.

```python
number = int(input("Enter a number: "))

if number % 5 == 0 and number % 7 == 0:
    print(number, "is divisible by both 5 and 7")
else:
    print(number, "is not divisible by both 5 and 7")
```

### Problem 8: Find the largest number among three without using if-else

**Task:** Write a Python program to find the largest number among three without using if-else statements.

```python
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))
num3 = float(input("Enter third number: "))

largest = max(num1, num2, num3)
print("The largest number is", largest)
```

### Problem 9: Check if a triangle is equilateral, isosceles, or scalene

**Task:** Write a Python program to check if a triangle is equilateral, isosceles, or scalene based on the lengths of its sides.

```python
side1 = float(input("Enter the length of the first side: "))
side2 = float(input("Enter the length of the second side: "))
side3 = float(input("Enter the length of the third side: "))

if side1 == side2 == side3:
    print("The triangle is equilateral")
elif side1 == side2 or side1 == side3 or side2 == side3:
    print("The triangle is isosceles")
else:
    print("The triangle is scalene")
```

### Problem 10: Check if a year is a century year

**Task:** Write a Python program to check if a given year is a century year.

```python
year = int(input("Enter a year: "))

if year % 100 == 0:
    print(year, "is a century year")
else:
    print(year, "is not a century year")
```
