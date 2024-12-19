# Filter Dataframe

## Query Method

The `.query()` method in pandas is used to filter data from a DataFrame using a query string. This method allows you to select rows that meet specific conditions, making it easier to filter and manipulate your data. It is especially useful because you can write the conditions in a simple and readable string format, similar to SQL queries.

### 2. Simple Use of `query()` Method

Here's a quick example to show how `query()` works:

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3, 4], 'B': [5, 6, 7, 8]})

# Filter rows where column A is greater than 2
filtered_df = df.query('A > 2')
print(filtered_df)
```

### 3. Real-Life Example: Filtering Students' Scores

Imagine you have a DataFrame with students' names and their scores, and you want to select only the students who scored more than 40.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Name': ['Akash', 'Meera', 'Raj', 'Anita'],
    'Score': [45, 30, 50, 20]
}
df = pd.DataFrame(data)

# Using .query() to filter students who scored more than 40
filtered_df = df.query('Score > 40')

print(filtered_df)
```

### Output

```
    Name  Score
0  Akash     45
2    Raj     50
```

### 4. Explanation of the Example

1. **Creating the DataFrame:** We start with a DataFrame that contains the names of students and their exam scores.
2. **Using `query()` Method:** We use the `query()` method to filter the DataFrame and select only the rows where the 'Score' is greater than 40.
3. **Result:** After applying the `query()` method, the resulting DataFrame contains only the students who scored more than 40, making it easier to focus on the high scorers.

<br>

## Boolean Indexing

Boolean indexing in pandas is a powerful way to filter data in a DataFrame based on specific conditions. It's called "boolean" indexing because it uses boolean values (True or False) to determine which rows to keep. When you create a condition, it returns a Series of True/False values, and you can use this to select rows that meet the condition. This method is very useful for quickly finding and working with specific subsets of your data.

### 2. Simple Use of Boolean Indexing

Here's a quick example of how boolean indexing works:

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3, 4], 'B': [5, 6, 7, 8]})

# Boolean Indexing
filtered_df = df[df['A'] > 2]
print(filtered_df)
```

### 3. Real-Life Example: Filtering Students' Scores

Imagine you have a DataFrame with students' names and their scores, and you want to select only the students who scored more than 40.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Name': ['Akash', 'Meera', 'Raj', 'Anita'],
    'Score': [45, 30, 50, 20]
}
df = pd.DataFrame(data)

# Using boolean indexing to filter students who scored more than 40
filtered_df = df[df['Score'] > 40]

print(filtered_df)
```

### 4. Explanation of the Example

1. **Creating the DataFrame:** We start with a DataFrame that contains the names of students and their exam scores.
2. **Using Boolean Indexing:** We create a condition (`df['Score'] > 40`) that checks if the score is greater than 40. This condition returns a Series of True/False values.
3. **Filtering the DataFrame:** We use this condition to filter the DataFrame, keeping only the rows where the condition is True.
4. **Result:** The resulting DataFrame contains only the students who scored more than 40, making it easier to identify the high scorers.

<br>

## `.loc` Property

The `.loc` property in pandas is used for accessing a group of rows and columns by labels or a boolean array. It is very powerful because it allows you to filter data based on conditions that you specify. You can use `.loc` to filter rows in a DataFrame by giving a condition that each row must meet. This is useful when you need to work with specific parts of your data.

### 2. Simple Use of `.loc` Property

Here's a quick example to show how `.loc` works:

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3, 4], 'B': [5, 6, 7, 8]})

# Using .loc to filter rows where column 'A' is greater than 2
filtered_df = df.loc[df['A'] > 2]
print(filtered_df)
```

### 3. Real-Life Example: Filtering Students' Scores

Imagine you have a DataFrame with students' names and their scores, and you want to select only the students who scored more than 40.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Name': ['Akash', 'Meera', 'Raj', 'Anita'],
    'Score': [45, 30, 50, 20]
}
df = pd.DataFrame(data)

# Using .loc to filter students who scored more than 40
filtered_df = df.loc[df['Score'] > 40]

print(filtered_df)
```

### 4. Explanation of the Example

1. **Creating the DataFrame:** We start with a DataFrame that contains the names of students and their exam scores.
2. **Using `.loc` Property:** We use the `.loc` property with a condition (`df['Score'] > 40`) to filter the DataFrame. This condition checks if the score is greater than 40 and returns a boolean array.
3. **Filtering the DataFrame:** The `.loc` property uses this boolean array to keep only the rows where the condition is True.
4. **Result:** The resulting DataFrame contains only the students who scored more than 40, making it easier to focus on the high scorers.

The `.loc` property is a straightforward and efficient way to filter data based on conditions, allowing you to work with specific subsets of your DataFrame.

<br>

## `.isin` Method

The `.isin()` method in pandas is used to filter rows in a DataFrame based on whether the values in a column belong to a specific list of values. This method is useful when you want to select rows where a column's values match any of the values in the list. It's a simple and efficient way to filter data based on multiple conditions.

### 2. Simple Use of `.isin()` Method

Here's a quick example to show how `.isin()` works:

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3, 4], 'B': [5, 6, 7, 8]})

# Using .isin() to filter rows where column 'A' has values 2 or 4
filtered_df = df[df['A'].isin([2, 4])]
print(filtered_df)
```

### 3. Real-Life Example: Selecting Specific Products

Imagine you have a DataFrame with a list of products and their prices, and you want to filter the DataFrame to show only the products 'Pen' and 'Notebook'.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Product': ['Pen', 'Notebook', 'Eraser', 'Sharpener'],
    'Price': [10, 20, 5, 7]
}
df = pd.DataFrame(data)

# Using .isin() to filter for specific products
filtered_df = df[df['Product'].isin(['Pen', 'Notebook'])]

print(filtered_df)
```

### Output

```
    Product  Price
0       Pen     10
1  Notebook     20
```

### 4. Explanation of the Example

1. **Creating the DataFrame:** We start with a DataFrame that contains a list of products and their prices.
2. **Using `.isin()` Method:** We use the `.isin()` method to filter the DataFrame. The condition `df['Product'].isin(['Pen', 'Notebook'])` checks if the 'Product' column contains the values 'Pen' or 'Notebook'.
3. **Filtering the DataFrame:** The `.isin()` method returns a boolean Series, which is used to filter the DataFrame, keeping only the rows where the condition is True.
4. **Result:** The resulting DataFrame contains only the products 'Pen' and 'Notebook', making it easy to focus on these specific items.

The `.isin()` method is a convenient way to filter data based on a list of values, helping you quickly and easily work with specific subsets of your DataFrame.

<br>

## `.between` Method

The `.between()` method in pandas is used to filter rows in a DataFrame based on whether the values in a column fall within a specified range. It is particularly useful for selecting data that lies between two values, making it easy to work with subsets of your data that meet specific criteria. The method is inclusive, meaning it includes both the start and end values in the range.

### 2. Simple Use of `.between()` Method

Here's a quick example to show how `.between()` works:

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3, 4, 5], 'B': [5, 6, 7, 8, 9]})

# Using .between() to filter rows where column 'A' is between 2 and 4
filtered_df = df[df['A'].between(2, 4)]
print(filtered_df)
```

### 3. Real-Life Example: Selecting Students within a Score Range

Imagine you have a DataFrame with students' names and their exam scores. You want to filter the DataFrame to show only the students who scored between 30 and 50.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Name': ['Akash', 'Meera', 'Raj', 'Anita'],
    'Score': [45, 30, 50, 20]
}
df = pd.DataFrame(data)

# Using .between() to filter students who scored between 30 and 50
filtered_df = df[df['Score'].between(30, 50)]

print(filtered_df)
```

### Output

```
    Name  Score
0  Akash     45
1  Meera     30
2    Raj     50
```

### 4. Explanation of the Example

1. **Creating the DataFrame:** We start with a DataFrame that contains the names of students and their exam scores.
2. **Using `.between()` Method:** We use the `.between()` method to filter the DataFrame. The condition `df['Score'].between(30, 50)` checks if the 'Score' column values are between 30 and 50, inclusive.
3. **Filtering the DataFrame:** The `.between()` method returns a boolean Series, which is used to filter the DataFrame, keeping only the rows where the condition is True.
4. **Result:** The resulting DataFrame contains only the students who scored between 30 and 50, making it easy to focus on students within this score range.

The `.between()` method is a convenient way to filter data based on a range of values, helping you quickly and efficiently work with specific subsets of your DataFrame.

<br>

## Multi-Condition Filtering

Multi-condition filtering in pandas allows you to filter rows in a DataFrame based on multiple conditions. You can combine these conditions using the `&` (and) operator and the `|` (or) operator. This is particularly useful when you need to apply more than one criterion to select the data you are interested in. Using multiple conditions helps you narrow down your data to only those rows that meet all or some of the specified conditions.

### 2. Simple Use of Multi-Condition Filtering

Here's a quick example to show how multi-condition filtering works:

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3, 4], 'B': [5, 6, 7, 8]})

# Multi-Condition Filtering
filtered_df = df[(df['A'] > 2) & (df['B'] < 8)]
print(filtered_df)
```

### 3. Real-Life Example: Selecting Specific Products Based on Price and Stock

Imagine you have a DataFrame with a list of products, their prices, and the number of items in stock. You want to filter the DataFrame to show only the products that are priced above 10 and have more than 5 items in stock.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Product': ['Pen', 'Notebook', 'Eraser', 'Sharpener'],
    'Price': [10, 20, 5, 7],
    'Stock': [15, 4, 10, 7]
}
df = pd.DataFrame(data)

# Using multi-condition filtering to select products priced above 10 and stock more than 5
filtered_df = df[(df['Price'] > 10) & (df['Stock'] > 5)]

print(filtered_df)
```

### 4. Explanation of the Example

1. **Creating the DataFrame:** We start with a DataFrame that contains a list of products, their prices, and the number of items in stock.
2. **Using Multi-Condition Filtering:** We create two conditions: `df['Price'] > 10` and `df['Stock'] > 5`. The `&` (and) operator is used to combine these conditions, so only rows that meet both conditions will be selected.
3. **Filtering the DataFrame:** The combined condition is used to filter the DataFrame, keeping only the rows where both conditions are True.
4. **Result:** The resulting DataFrame contains only the products that are priced above 10 and have more than 5 items in stock, making it easier to focus on these specific products.

Multi-condition filtering is a powerful tool for selecting data based on multiple criteria, helping you work with the most relevant subsets of your DataFrame.
