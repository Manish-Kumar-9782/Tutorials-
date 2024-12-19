# Refactoring Column

You can refactor a column in a pandas DataFrame by renaming it, changing its data type, or performing transformations.

### Renaming a Column

To rename a column, you can use the `rename()` method.

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'old_name': [1, 2, 3, 4, 5]})

# Renaming the column
df.rename(columns={'old_name': 'new_name'}, inplace=True)
print(df)
```

### Changing Data Type

You can change the data type of a column using the `astype()` method.

```python
# Changing the data type of a column
df['new_name'] = df['new_name'].astype(float)
print(df)
```

### Performing Transformations

Here’s how to refactor a column by applying a function to its values.

```python
# Applying a function to the column
df['new_name'] = df['new_name'].apply(lambda x: x * 10)
print(df)
```

### Using `assign()` to Create New Columns

You can also use the `assign()` method to create new columns based on transformations.

```python
# Creating a new column with transformed values
df = df.assign(new_column=df['new_name'] * 2)
print(df)
```
