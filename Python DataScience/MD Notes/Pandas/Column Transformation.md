# Column Transformation

### 1. Using the `apply()` Function

The `apply()` method in pandas is incredibly versatile and allows you to apply a function along an axis of the DataFrame. This can be very useful for performing complex data transformations. Here's a real-life example to illustrate its use:

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3, 4, 5]})

# Function to transform values
def transform(x):
    return x * 10

# Applying the function to column 'A'
df['A'] = df['A'].apply(transform)
print(df)
```

##### Example: Calculating BMI from Height and Weight

Imagine you have a DataFrame with height and weight information for a group of people, and you want to calculate their Body Mass Index (BMI).

```python
import pandas as pd

# Sample DataFrame
data = {
    'Name': ['John', 'Jane', 'Tom', 'Lucy'],
    'Height_cm': [175, 160, 180, 155],
    'Weight_kg': [70, 60, 80, 50]
}
df = pd.DataFrame(data)

# Function to calculate BMI
def calculate_bmi(row):
    height_m = row['Height_cm'] / 100
    weight_kg = row['Weight_kg']
    bmi = weight_kg / (height_m ** 2)
    return bmi

# Applying the function to each row
df['BMI'] = df.apply(calculate_bmi, axis=1)

print(df)
```

##### Output

```
    Name  Height_cm  Weight_kg        BMI
0   John        175         70  22.857143
1   Jane        160         60  23.437500
2    Tom        180         80  24.691358
3   Lucy        155         50  20.811655
```

##### Explanation

- **Creating the DataFrame:** A DataFrame is created with columns for names, height in centimeters, and weight in kilograms.
- **Defining the Function:** A function `calculate_bmi` is defined to compute BMI based on the height and weight.
- **Using `apply()`**: The `apply()` method is used to apply the `calculate_bmi` function to each row of the DataFrame (`axis=1` specifies row-wise operation).

<br>

### 2. Using the `map()` Function

The `map()` method in pandas is used to transform each element in a column using a function or a dictionary. It's simple and useful for tasks like converting values, replacing data, or mapping one set of values to another.

```python
# Applying a lambda function to transform values
df['A'] = df['A'].map(lambda x: x * 10)
print(df)
```

##### Example: Convert Grades to Pass/Fail

Imagine you have a list of student grades, and you want to convert these grades into 'Pass' or 'Fail'. Let's see how to do this using `map()`.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Name': ['Rahul', 'Sneha', 'Arjun', 'Ritika'],
    'Grade': ['A', 'B', 'C', 'D']
}
df = pd.DataFrame(data)

# Dictionary to map grades to Pass/Fail
grade_map = {
    'A': 'Pass',
    'B': 'Pass',
    'C': 'Pass',
    'D': 'Fail',
    'E': 'Fail'
}

# Using .map() to transform the 'Grade' column
df['Result'] = df['Grade'].map(grade_map)

print(df)
```

##### Output

```
     Name Grade Result
0   Rahul     A   Pass
1   Sneha     B   Pass
2   Arjun     C   Pass
3  Ritika     D   Fail
```

##### Explanation

1. **Creating the DataFrame:** We start with a DataFrame of student names and their grades.
2. **Creating the Dictionary:** We create a dictionary (`grade_map`) that maps each grade to either 'Pass' or 'Fail'.
3. **Using `map()`:** We use the `map()` method to apply this dictionary to the 'Grade' column, creating a new column called 'Result'.

<br>

### 3. Using Vectorized Operations

Vectorized operations in pandas allow you to perform operations on entire columns at once, rather than row by row. This makes your code faster and easier to read.

```python
# Performing a vectorized operation
df['A'] = df['A'] * 10
print(df)
```

##### Example: Increasing Prices

Imagine you have a list of product prices, and you want to increase all prices by 10%. Here's how to do it using vectorized operations:

```python
import pandas as pd

# Sample DataFrame
data = {
    'Product': ['Pen', 'Notebook', 'Eraser', 'Sharpener'],
    'Price': [10, 20, 5, 7]
}
df = pd.DataFrame(data)

# Increase prices by 10%
df['Price'] = df['Price'] * 1.10

print(df)
```

##### Output

```
     Product  Price
0        Pen   11.0
1   Notebook   22.0
2     Eraser    5.5
3  Sharpener    7.7
```

##### Explanation

1. **Creating the DataFrame:** We start with a DataFrame of products and their prices.
2. **Vectorized Operation:** By multiplying the 'Price' column by 1.10, we increase all prices by 10% in one go.

<br>

### 4. Using `replace()`

The `replace()` method in pandas is used to change specific values in a DataFrame. It's helpful when you want to switch certain values for others, such as fixing errors or converting data.

```python
# Replacing specific values
df['A'] = df['A'].replace({10: 100, 20: 200})
print(df)
```

##### Example: Cleaning Up Survey Data

Imagine you have a DataFrame with survey responses, and some of the answers are in a format that you want to change. For example, 'Yes' should be 1 and 'No' should be 0. Let's see how to do this:

```python
import pandas as pd

# Sample DataFrame
data = {
    'Name': ['Ananya', 'Rohan', 'Priya', 'Aman'],
    'Response': ['Yes', 'No', 'Yes', 'No']
}
df = pd.DataFrame(data)

# Using .replace() to transform 'Yes' to 1 and 'No' to 0
df['Response'] = df['Response'].replace({'Yes': 1, 'No': 0})

print(df)
```

##### Output

```
     Name  Response
0  Ananya         1
1   Rohan         0
2   Priya         1
3     Aman         0
```

##### Explanation

1. **Creating the DataFrame:** We start with a DataFrame of names and their survey responses ('Yes' or 'No').
2. **Using `replace()`:** We use the `replace()` method to change 'Yes' to 1 and 'No' to 0.

<br>

### 5. Using `.loc[]`

The `.loc[]` property in pandas is used for accessing a group of rows and columns by labels or a boolean array. It's also quite handy for updating or replacing values in your DataFrame.

```python
# Update values conditionally
df.loc[df['A'] > 20, 'A'] = 999
print(df)
```

##### Example: Updating Prices Based on Condition

Imagine you have a list of product prices, and you want to update the prices of certain products based on a condition. For instance, increase the price of all products that are currently priced below 15 units by 20%.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Product': ['Pen', 'Notebook', 'Eraser', 'Sharpener'],
    'Price': [10, 20, 5, 25]
}
df = pd.DataFrame(data)

# Using .loc to update prices based on a condition
df.loc[df['Price'] < 15, 'Price'] = df.loc[df['Price'] < 15, 'Price'] * 1.20

print(df)
```

##### Output

```
     Product  Price
0        Pen   12.0
1   Notebook   20.0
2     Eraser    6.0
3  Sharpener   25.0
```

##### Explanation

1. **Creating the DataFrame:** We start with a DataFrame of products and their prices.
2. **Using `df.loc` to specify condition:** We select the rows where the price is less than 15.
3. **Updating the `Price` column:** We multiply the prices of the selected rows by 1.20 to increase them by 20%.

<br>

### 6. Using `.where()` method

The pandas DataFrame `.where()` method is used to replace values where a specified condition is not met. It's particularly useful for filtering and conditional replacement. Here’s how you can use it with a real-life example:

##### Real-Life Example: Analyzing Sales Data

Imagine you have a DataFrame with sales data for different products. You want to keep only the rows where the sales are above a certain threshold, and replace all other values with `NaN`.

```python
import pandas as pd
import numpy as np

# Sample DataFrame
data = {
    'Product': ['A', 'B', 'C', 'D'],
    'Sales': [250, 120, 340, 90]
}
df = pd.DataFrame(data)

# Define the threshold
threshold = 150

# Use the .where() method to keep values above the threshold, replace others with NaN
df_filtered = df.where(df['Sales'] > threshold)

print(df_filtered)
```

##### Output

```
  Product  Sales
0       A  250.0
1     NaN    NaN
2       C  340.0
3     NaN    NaN
```

##### Explanation

- The `.where()` method keeps the values where the condition (`df['Sales'] > threshold`) is `True`.
- For rows where the condition is not met, it replaces the values with `NaN`.

You can also specify a value to replace the non-matching rows, instead of `NaN`, using the `other` parameter.

```python
# Use the .where() method to keep values above the threshold, replace others with a specific value
df_filtered = df.where(df['Sales'] > threshold, other=0)

print(df_filtered)
```

##### Output

```
  Product  Sales
0       A    250
1       B      0
2       C    340
3       D      0
```

In this example, we replaced the non-matching sales values with `0` instead of `NaN`. The `.where()` method is highly versatile and can be tailored to various scenarios where conditional replacement or filtering is needed.

<br>

### 7. Using `.mask()` Method

The `mask()` method in pandas is used to replace specific values in a DataFrame based on a condition. When the condition is `True`, the value is replaced with another specified value; if the condition is `False`, the original value remains. This method is very useful for cleaning and transforming data.

```python
# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, -3, 4], 'B': [5, -6, 7, -8]})

# Replace negative values with NaN
df = df.mask(df < 0, np.nan)
print(df)
```

##### Example: Cleaning Exam Scores

Imagine you have a list of students' exam scores, and you want to replace any scores below 35 with `NaN` (not a number), indicating that those scores need review.

```python
import pandas as pd
import numpy np

# Sample DataFrame
data = {
    'Name': ['Akash', 'Meera', 'Raj', 'Anita'],
    'Score': [45, 30, 50, 20]
}
df = pd.DataFrame(data)

# Using .mask() to replace scores below 35 with NaN
df['Score'] = df['Score'].mask(df['Score'] < 35, np.nan)

print(df)
```

### Output

```
     Name  Score
0   Akash   45.0
1   Meera    NaN
2     Raj   50.0
3   Anita    NaN
```

##### Explanation

1. **Creating the DataFrame:** We start with a DataFrame that contains the names of students and their exam scores.
2. **Using `mask()` Method:** We use the `mask()` method to check if the score is less than 35. If it is, the score is replaced with `NaN`. This makes it clear which scores need further attention.
3. **Result:** After applying the `mask()` method, the scores below 35 are replaced with `NaN`, helping to identify which students need help.
