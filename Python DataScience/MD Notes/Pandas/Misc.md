### `df.items` and `df.keys` Methods in Pandas

#### 1. `df.items` Method

The `df.items` method in pandas is used to iterate over (column name, Series) pairs. This means it allows you to loop through each column in the DataFrame and access both the column name and the data in that column as a Series. This can be particularly useful when you need to perform operations on each column individually.

**Possible Situations to Use `df.items`:**

- **Data Cleaning:** When you need to apply a cleaning function to each column.
- **Data Transformation:** When you want to transform data in each column differently.
- **Column-wise Analysis:** When you need to analyze or summarize data column by column.

**Example:**

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6]})

# Using df.items to iterate over columns
for column_name, series in df.items():
    print(f"Column: {column_name}")
    print(series)
```

#### 2. `df.keys` Method

The `df.keys` method in pandas is used to get the column labels of the DataFrame. It returns an Index object containing the column names. This is useful when you need to know the names of the columns in your DataFrame, especially when working with large datasets.

**Possible Situations to Use `df.keys`:**

- **Column Selection:** When you need to select or filter columns based on their names.
- **Dynamic Column Operations:** When you want to perform operations on columns dynamically based on their names.
- **Metadata Extraction:** When you need to extract metadata about the DataFrame, such as column names.

**Example:**

```python
import pandas as pd

# Sample DataFrame
df = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6]})

# Using df.keys to get column names
column_names = df.keys()
print(column_names)
```

### Real-Life Example: Data Cleaning and Transformation

Imagine you have a DataFrame with survey data, and you want to clean and transform each column differently. You can use `df.items` to iterate over each column and apply specific cleaning functions.

```python
import pandas as pd

# Sample DataFrame
data = {
    'Age': [25, 30, None, 22],
    'Score': [85, 90, 88, None]
}
df = pd.DataFrame(data)

# Using df.items to clean and transform data
for column_name, series in df.items():
    if series.isnull().any():
        df[column_name] = series.fillna(series.mean())  # Fill missing values with mean

print(df)
```

### Explanation of the Example

1. **Creating the DataFrame:** We start with a DataFrame that contains survey data with some missing values.
2. **Using `df.items`:** We use the `df.items` method to iterate over each column in the DataFrame.
3. **Cleaning and Transforming Data:** For each column, we check if there are any missing values. If there are, we fill the missing values with the mean of that column.
4. **Result:** The resulting DataFrame has the missing values filled with the mean, making the data cleaner and ready for analysis.
