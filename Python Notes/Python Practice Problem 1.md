1. **Check Even or Odd**: Write a Python program that determines whether a given number (accepted from the user) is even or odd, and prints an appropriate message to the user.

```python
def check_even_odd(num):
  """Checks if a number is even or odd.

  Args:
    num: The number to check.

  Returns:
    A string indicating whether the number is even or odd.
  """

  if num % 2 == 0:
    return "Even"
  else:
    return "Odd"

# Get user input
number = int(input("Enter a number: "))

# Check and print the result
result = check_even_odd(number)
print(f"The number {number} is {result}.")
```

2. **Count Occurrences**: Write a Python program to count the number 4 in a given list.

```python
def count_occurrences(numbers, target):
  """Counts the occurrences of a target number in a list.

  Args:
    numbers: The list of numbers.
    target: The number to count.

  Returns:
    The count of the target number in the list.
  """

  count = 0
  for num in numbers:
    if num == target:
      count += 1
  return count

# Example usage
my_list = [1, 4, 2, 4, 3, 4]
target_number = 4
result = count_occurrences(my_list, target_number)
print(f"The number {target_number} appears {result} times in the list.")
```

3. **Vowel Check**: Write a Python program to test whether a passed letter is a vowel or not.

```python
def is_vowel(char):
  """Checks if a character is a vowel.

  Args:
    char: The character to check.

  Returns:
    True if the character is a vowel, False otherwise.
  """

  vowels = "aeiouAEIOU"
  return char in vowels

# Example usage
char = input("Enter a character: ")
if is_vowel(char):
  print(f"{char} is a vowel.")
else:
  print(f"{char} is not a vowel.")
```

4. **Value in Group**: Write a Python program that checks whether a specified value is contained within a group of values.

```python
def value_in_group(value, group):
  """Checks if a value is present in a group.

  Args:
    value: The value to check.
    group: The group of values.

  Returns:
    True if the value is in the group, False otherwise.
  """

  return value in group

# Example usage
my_group = [1, 2, 3, 4, 5]
value_to_check = 3
if value_in_group(value_to_check, my_group):
  print(f"{value_to_check} is in the group.")
else:
  print(f"{value_to_check} is not in the group.")
```

5. **Histogram**: Write a Python program to create a histogram from a given list of integers.

```python
def create_histogram(numbers):
  """Creates a histogram from a list of integers.

  Args:
    numbers: The list of integers.
  """

  for num in numbers:
    print("*" * num)

# Example usage
my_list = [3, 5, 2, 4]
create_histogram(my_list)
```

6. **Concatenate List Elements**: Write a Python program that concatenates all elements in a list into a string and returns it.

```python
def concatenate_list(list_elements):
  """Concatenates all elements in a list into a string.

  Args:
    list_elements: The list of elements.

  Returns:
    The concatenated string.
  """

  return "".join(list_elements)

# Example usage
my_list = ["hello", " ", "world"]
result = concatenate_list(my_list)
print(result)
```

7. **Even Numbers**: Write a Python program to print all even numbers from a given list of numbers in the same order and stop printing any after 237 in the sequence.

```python
def print_even_numbers(numbers):
  """Prints even numbers from a list up to 237.

  Args:
    numbers: The list of numbers.
  """

  for num in numbers:
    if num % 2 == 0 and num <= 237:
      print(num)

# Example usage
my_list = [2, 3, 4, 5, 6, 238, 237, 236]
print_even_numbers(my_list)
```

8. **Colors Not in List**: Write a Python program that prints out all colors from color_list_1 that are not present in color_list_2.

```python
def colors_not_in_list(color_list_1, color_list_2):
  """Prints colors from list 1 that are not in list 2.

  Args:
    color_list_1: The first list of colors.
    color_list_2: The second list of colors.
  """

  for color in color_list_1:
    if color not in color_list_2:
      print(color)

# Example usage
color_list_1 = ["red", "green", "blue", "yellow"]
color_list_2 = ["green", "blue"]
colors_not_in_list(color_list_1, color_list_2)
```

9. **Sum of Three Integers**: Write a Python program to sum three given integers. However, if two values are equal, the sum will be zero.

```python
def sum_of_three(num1, num2, num3):
  """Calculates the sum of three numbers, with special condition.

  Args:
    num1: The first number.
    num2: The second number.
    num3: The third number.

  Returns:
    The sum of the numbers, or 0 if two numbers are equal.
  """

  if num1 == num2 or num1 == num3 or num2 == num3:
    return 0
  else:
    return num1 + num2 + num3

# Example usage
result = sum_of_three(2, 3, 4)
print(result)
```

10. **Sum of Two Integers**: Write a Python program to sum two given integers. However, if the sum is between 15 and 20 it will return 20.

```python
def sum_of_two(num1, num2):
  """Calculates the sum of two numbers with a special condition.

  Args:
    num1: The first number.
    num2: The second number.

  Returns:
    The sum of the numbers, or 20 if the sum is between 15 and 20.
  """

  sum_value = num1 + num2
  if 15 < sum_value <= 20:
    return 20
  else:
    return sum_value

# Example usage
result = sum_of_two(5, 12)
print(result)
```

11. **Equal or Sum/Difference is 5**: Write a Python program that returns true if the two given integer values are equal or their sum or difference is 5.

```python
def check_condition(num1, num2):
  """Checks if two numbers are equal or their sum/difference is 5.

  Args:
    num1: The first number.
    num2: The second number.

  Returns:
    True if the condition is met, False otherwise.
  """

  return num1 == num2 or abs(num1 - num2) == 5 or num1 + num2 == 5

# Example usage
result = check_condition(3, 8)
print(result)
```

12. **Sum of Digits**: Write a Python program to calculate the sum of digits of a number.

```python
def sum_of_digits(number):
  """Calculates the sum of digits of a number.

  Args:
    number: The number to calculate the sum of digits for.

  Returns:
    The sum of the digits.
  """

  sum_of_digits = 0
  while number > 0:
    digit = number % 10
    sum_of_digits += digit
    number //= 10
  return sum_of_digits

# Example usage
num = 12345
result = sum_of_digits(num)
print(result)
```

13. **Sort Three Integers**: Write a Python program to sort three integers without using conditional statements and loops.

```python
def sort_three_numbers(x, y, z):
  """Sorts three integers without using conditionals or loops.

  Args:
    x, y, z: The three integers to sort.

  Returns:
    A tuple of the sorted numbers.
  """

  # Using the max and min functions to find the largest and smallest numbers
  largest = max(x, y, z)
  smallest = min(x, y, z)

  # The remaining number is the middle one
  middle = (x + y + z) - largest - smallest

  return smallest, middle, largest

# Example usage
x = 3
y = 1
z = 2
sorted_numbers = sort_three_numbers(x, y, z)
print(sorted_numbers)
```

14. **Sum of Container Items**: Write a Python program to calculate the sum of all items of a container (tuple, list, set, dictionary).

```python
def sum_container_items(container):
  """Calculates the sum of all items in a container.

  Args:
    container: The container (tuple, list, set, or dictionary).

  Returns:
    The sum of the items.
  """

  if isinstance(container, dict):
    # For dictionaries, sum the values
    return sum(container.values())
  else:
    # For other containers, sum the elements
    return sum(container)

# Example usage
my_list = [1, 2, 3, 4]
my_tuple = (5, 6, 7)
my_set = {8, 9, 10}
my_dict = {'a': 11, 'b': 12}

print(sum_container_items(my_list))
print(sum_container_items(my_tuple))
print(sum_container_items(my_set))
print(sum_container_items(my_dict))
```

15. **Greater Than a Number**: Write a Python program to test whether all numbers in a list are greater than a certain number.

```python
def all_greater_than(numbers, threshold):
  """Checks if all numbers in a list are greater than a threshold.

  Args:
    numbers: The list of numbers.
    threshold: The threshold value.

  Returns:
    True if all numbers are greater than the threshold, False otherwise.
  """

  return all(num > threshold for num in numbers)

# Example usage
my_list = [5, 7, 9, 11]
threshold_value = 4
result = all_greater_than(my_list, threshold_value)
print(result)
```

16. **Count Character Occurrences**: Write a Python program to count the number of occurrences of a specific character in a string.

```python
def count_character_occurrences(string, char):
  """Counts the occurrences of a character in a string.

  Args:
    string: The input string.
    char: The character to count.

  Returns:
    The count of the character in the string.
  """

  return string.count(char)

# Example usage
my_string = "hello world"
char_to_count = "l"
count = count_character_occurrences(my_string, char_to_count)
print(count)
```

17. **Sum of Cubes**: Write a Python function that takes a positive integer and returns the sum of the cube of all positive integers smaller than the specified number.

```python
def sum_of_cubes(n):
  """Calculates the sum of cubes of positive integers smaller than n.

  Args:
    n: The upper limit.

  Returns:
    The sum of cubes.
  """

  if n <= 0:
    raise ValueError("n must be a positive integer")

  # Using the formula for the sum of cubes: n^2 * (n+1)^2 / 4
  return n * (n + 1) // 2 * (n * (n + 1) // 2)

# Example usage
number = 5
result = sum_of_cubes(number)
print(result)
```

18. **Odd Product Pair**: Write a Python function to check whether a distinct pair of numbers whose product is odd is present in a sequence of integer values.

```python
def has_odd_product_pair(numbers):
  """Checks if there's a distinct pair with an odd product in a list.

  Args:
    numbers: The list of numbers.

  Returns:
    True if an odd product pair exists, False otherwise.
  """

  odd_count = 0
  for num in numbers:
    if num % 2 != 0:
      odd_count += 1
      if odd_count >= 2:
        return True
  return False

# Example usage
number_list = [2, 4, 6, 7, 9]
result = has_odd_product_pair(number_list)
print(result)
```

19. **Divisible by Another Number**: Write a Python function to check whether a number is divisible by another number. Accept two integer values from the user.

```python
def is_divisible(dividend, divisor):
  """Checks if one number is divisible by another.

  Args:
    dividend: The number to be divided.
    divisor: The divisor.

  Returns:
    True if the dividend is divisible by the divisor, False otherwise.
  """

  return dividend % divisor == 0

# Get input from the user
dividend = int(input("Enter the dividend: "))
divisor = int(input("Enter the divisor: "))

if is_divisible(dividend, divisor):
  print(f"{dividend} is divisible by {divisor}")
else:
  print(f"{dividend} is not divisible by {divisor}")
```


