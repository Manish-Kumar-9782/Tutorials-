# Handle Null or Missing Values

### Identification and Checking

1. **`isna()` or `isnull()`**: Detect missing values.

   ```python
   df.isna()
   df.isnull()
   ```
2. **`notna()` or `notnull()`**: Detect existing (non-missing) values.

   ```python
   df.notna()
   df.notnull()
   ```

### Handling and Filling

3. **`fillna()`**: Fill missing values with a specified value or method.

   ```python
   df.fillna(value=0)
   df.fillna(method='ffill')
   ```
4. **`ffill()` or `pad()`**: Forward fill missing values.

   ```python
   df.ffill()
   df.pad()
   ```
5. **`bfill()` or `backfill()`**: Backward fill missing values.

   ```python
   df.bfill()
   df.backfill()
   ```
6. **`interpolate()`**: Fill missing values using interpolation.

   ```python
   df.interpolate()
   ```

### Dropping

7. **`dropna()`**: Remove missing values.
   ```python
   df.dropna()
   ```

### Replacing

8. **`replace()`**: Replace specific values.
   ```python
   df.replace(to_replace=np.nan, value=0)
   ```

### Counting and Summarizing

9. **`isna().sum()`**: Count missing values in each column.
   ```python
   df.isna().sum()
   ```

### Other Useful Methods

10. **`dropna(axis=1)`**: Remove columns with missing values.

    ```python
    df.dropna(axis=1)
    ```
11. **`dropna(how='all')`**: Drop rows or columns where all elements are missing.

    ```python
    df.dropna(how='all')
    ```
12. **`dropna(thresh=n)`**: Drop rows or columns with less than `n` non-null values.

    ```python
    df.dropna(thresh=2)
    ```

---

---

### `DataFrame.isna()`

**Purpose and Usage:**
The `isna()` method in pandas is used to detect missing values in a DataFrame. Missing values are typically represented as `NaN` (Not a Number) in pandas. This method returns a DataFrame of the same shape with boolean values: `True` where the data is missing and `False` where it is not. It's useful for identifying where data might be missing so you can decide how to handle it (e.g., filling in missing values, removing rows/columns with missing data).

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [4, 5, None]})
missing_values = df.isna()
print(missing_values)
```

**Real-life Example:**
Imagine you are analyzing student grades, and you have a DataFrame where some grades are missing.

**Explanation:**
Using `isna()`, you can quickly identify which students have missing grades.

```python
grades = pd.DataFrame({'Math': [85, None, 78], 'Science': [92, 88, None]})
missing_grades = grades.isna()
print(missing_grades)
```

In this example, the `missing_grades` DataFrame shows `True` where the grades are missing.

### `DataFrame.isnull()`

**Purpose and Usage:**
The `isnull()` method functions exactly the same way as `isna()`. It detects missing values in a DataFrame and returns a DataFrame of the same shape with boolean values indicating the presence of missing data. In pandas, `isnull()` and `isna()` are interchangeable.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [4, 5, None]})
missing_values = df.isnull()
print(missing_values)
```

**Real-life Example:**
Continuing with the student grades scenario, you can also use `isnull()` to find missing grades.

**Explanation:**
Using `isnull()`, you get the same result as with `isna()`, identifying which students have missing grades.

```python
grades = pd.DataFrame({'Math': [85, None, 78], 'Science': [92, 88, None]})
missing_grades = grades.isnull()
print(missing_grades)
```

In this example, the `missing_grades` DataFrame, just like with `isna()`, shows `True` where the grades are missing.

### When to Use Each Method

You can use either `isna()` or `isnull()` to check for missing data in your DataFrame since they are functionally the same. The choice between them often comes down to personal or team preference.

### Summary:

- **`isna()`**: Use this method to detect missing values (`NaN`) in your DataFrame.
- **`isnull()`**: This method is identical to `isna()` and can also be used to find missing values in your DataFrame.

---

### `DataFrame.notna()`

**Purpose and Usage:**
The `notna()` method in pandas is used to detect non-missing values in a DataFrame. It returns a DataFrame of the same shape with boolean values: `True` where the data is not missing and `False` where it is missing. This method is handy when you want to identify which elements in your DataFrame are valid (i.e., not `NaN`).

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [4, 5, None]})
valid_values = df.notna()
print(valid_values)
```

**Real-life Example:**
Suppose you are managing a class attendance sheet, and some entries are missing (students who missed the class). You want to mark the days when students were present.

**Explanation:**
Using `notna()`, you can identify the days when students attended the class.

```python
attendance = pd.DataFrame({'Day1': [True, None, True], 'Day2': [True, True, None]})
present_days = attendance.notna()
print(present_days)
```

In this example, the `present_days` DataFrame shows `True` where students attended the class.

### `DataFrame.notnull()`

**Purpose and Usage:**
The `notnull()` method functions exactly the same way as `notna()`. It detects non-missing values in a DataFrame and returns a DataFrame of the same shape with boolean values indicating the presence of non-missing data. In pandas, `notnull()` and `notna()` are interchangeable.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [4, 5, None]})
valid_values = df.notnull()
print(valid_values)
```

**Real-life Example:**
Continuing with the attendance example, you can also use `notnull()` to find the days students were present.

**Explanation:**
Using `notnull()`, you get the same result as with `notna()`, showing the days when students attended class.

```python
attendance = pd.DataFrame({'Day1': [True, None, True], 'Day2': [True, True, None]})
present_days = attendance.notnull()
print(present_days)
```

In this example, the `present_days` DataFrame, just like with `notna()`, shows `True` where students attended the class.

### When to Use Each Method

You can use either `notna()` or `notnull()` to check for non-missing data in your DataFrame since they are functionally the same. The choice between them often comes down to personal or team preference.

### Summary:

- **`notna()`**: Use this method to detect non-missing values in your DataFrame.
- **`notnull()`**: This method is identical to `notna()` and can also be used to find non-missing values in your DataFrame.

---

### `DataFrame.fillna()`

**Purpose and Usage:**
The `fillna()` method in pandas is used to fill missing values (`NaN`) in a DataFrame. You can specify a constant value, use methods to fill values forward or backward, or even use the mean, median, or other aggregation results. This method is helpful when you have missing data and want to ensure your analysis or computations are not affected by those gaps. You can apply this function along either rows or columns.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [None, 5, 6]})
df_filled = df.fillna(0)
print(df_filled)
```

**Real-life Example:**
Suppose you're analyzing monthly sales data for a store, but some months' data is missing. You want to fill these gaps to perform accurate calculations.

**Explanation:**
By using `fillna()`, you can fill the missing sales data with the average sales value, ensuring your analysis isn't skewed by the missing data.

```python
sales_data = pd.DataFrame({'Month': ['Jan', 'Feb', 'Mar'], 'Sales': [200, None, 300]})
average_sales = sales_data['Sales'].mean()
filled_sales_data = sales_data.fillna(average_sales)
print(filled_sales_data)
```

In this example, `fillna()` fills the missing sales value in February with the average sales value of the other months.

### `DataFrame.dropna()`

**Purpose and Usage:**
The `dropna()` method in pandas is used to remove missing values from a DataFrame. You can choose to drop rows or columns that contain any `NaN` values or specify a threshold for the number of non-`NaN` values required to retain a row or column. This method is useful when you want to eliminate incomplete data to ensure your analysis is based on complete observations.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [4, None, 6]})
df_dropped = df.dropna()
print(df_dropped)
```

**Real-life Example:**
Imagine you're working with a dataset of customer reviews, where some reviews have missing ratings. You want to remove the reviews without ratings to ensure your analysis is based on complete data.

**Explanation:**
Using `dropna()`, you can remove rows where the rating is missing, ensuring only complete reviews are considered.

```python
reviews = pd.DataFrame({'Review': ['Good', 'Bad', 'Excellent'], 'Rating': [5, None, 4]})
complete_reviews = reviews.dropna()
print(complete_reviews)
```

In this example, `dropna()` removes the row where the rating is missing, leaving only the complete reviews.

### When to Use Each Method

- **`fillna()`**: Use this method when you want to retain all your data but fill in the missing values to avoid disruptions in your analysis.
- **`dropna()`**: Use this method when you prefer to work only with complete data and are willing to remove any rows or columns that contain missing values.

---

### `DataFrame.bfill()`

**Purpose and Usage:**
The `bfill()` method in pandas is used to fill missing values in a DataFrame by propagating the next valid observation backward. This method is useful when you want to fill missing data points by using the value immediately following the missing data. It helps in maintaining the continuity of data when certain values are missing.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [None, 5, 6]})
df_bfilled = df.bfill()
print(df_bfilled)
```

**Real-life Example:**
Imagine you are tracking daily temperatures, but some days have missing data. You want to fill these gaps using the temperature from the following day.

**Explanation:**
Using `bfill()`, you fill the missing temperature data by using the value from the next day.

```python
temperatures = pd.DataFrame({'Day1': [20, None, 22], 'Day2': [None, 25, 26]})
filled_temperatures = temperatures.bfill()
print(filled_temperatures)
```

In this example, the `filled_temperatures` DataFrame uses the temperature of the next day to fill the missing values.

### `DataFrame.ffill()`

**Purpose and Usage:**
The `ffill()` method in pandas is used to fill missing values in a DataFrame by propagating the last valid observation forward. This method is particularly useful when you want to fill missing data points by using the value immediately preceding the missing data. It's helpful for keeping data continuity when previous observations are relevant for filling gaps.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [4, None, 6]})
df_ffilled = df.ffill()
print(df_ffilled)
```

**Real-life Example:**
Suppose you are maintaining a record of a patient's daily medication doses, but some days are missing. You want to fill these gaps using the dose from the previous day.

**Explanation:**
Using `ffill()`, you fill the missing medication doses by using the value from the previous day.

```python
medication = pd.DataFrame({'Day1': [10, None, 12], 'Day2': [None, 15, 16]})
filled_medication = medication.ffill()
print(filled_medication)
```

In this example, the `filled_medication` DataFrame uses the dose of the previous day to fill the missing values.

### When to Use Each Method

- **`bfill()`**: Use this method when you prefer to fill missing values by using data from the subsequent entry. It is particularly useful in scenarios where future data points are more relevant for filling the gaps.
- **`ffill()`**: Use this method when you want to fill missing values by using data from the preceding entry. This is helpful when past data points are more relevant or indicative for filling the gaps.

---

### `DataFrame.interpolate()`

**Purpose and Usage:**
The `interpolate()` method in pandas is used to fill missing values (`NaN`) in a DataFrame using various interpolation techniques. Interpolation is a method of estimating unknown values that fall between known values. This method can be very useful when you need to handle missing data in a time series or any dataset where the data points are ordered. You can apply different methods such as linear, polynomial, or spline interpolation.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [4, None, 6]})
df_interpolated = df.interpolate()
print(df_interpolated)
```

**Real-life Example:**
Imagine you are analyzing daily temperature readings, but some days' data is missing. You can use interpolation to estimate the missing temperatures based on the available data.

**Explanation:**
Using `interpolate()`, you can fill in the missing temperature data by estimating values between the known points.

```python
temperatures = pd.DataFrame({'Day': [1, 2, 3, 4], 'Temp': [20, None, 22, 23]})
filled_temperatures = temperatures.interpolate()
print(filled_temperatures)
```

In this example, `interpolate()` fills the missing temperature on Day 2 by estimating it based on the temperatures of Day 1 and Day 3.

### `DataFrame.replace()`

**Purpose and Usage:**
The `replace()` method in pandas is used to replace specified values in a DataFrame. You can use it to replace one or more values with other specified values. This method is flexible as it allows you to specify the value to be replaced, the value to replace it with, and even supports replacing values based on a condition or a regular expression.

**Code Snippet:**

```python
import pandas as pd

df = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6]})
df_replaced = df.replace(4, 40)
print(df_replaced)
```

**Real-life Example:**
Suppose you have a DataFrame with customer satisfaction ratings where `-1` represents missing responses. You want to replace all `-1` values with `None` to indicate truly missing data.

**Explanation:**
Using `replace()`, you can change all `-1` values to `None`, making your data easier to understand and analyze.

```python
ratings = pd.DataFrame({'CustomerID': [1, 2, 3], 'Satisfaction': [5, -1, 4]})
cleaned_ratings = ratings.replace(-1, None)
print(cleaned_ratings)
```

In this example, `replace()` changes the `-1` rating to `None`, indicating that the response was missing.

### When to Use Each Method

- **`interpolate()`**: Use this method when you want to estimate and fill missing values based on other data points in a continuous dataset. It's especially useful for time series data.
- **`replace()`**: Use this method when you need to replace specific values in your DataFrame, either to clean up the data or to standardize values for better analysis.
