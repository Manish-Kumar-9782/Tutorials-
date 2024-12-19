Logistic regression is a supervised machine learning algorithm mainly used for classification tasks where the goal is to predict the probability that an instance belongs to a given class or not. It is a kind of statistical algorithm, which analyze the relationship between a set of independent variables and the dependent binary variables. It is a powerful tool for decision-making. For example email spam or not.

## Logistic Regression

Logistic regression is a [supervised machine learning](https://www.geeksforgeeks.org/supervised-unsupervised-learning/) algorithm mainly used for binary [classification](https://www.geeksforgeeks.org/getting-started-with-classification/) where we use a logistic function, also known as a sigmoid function that takes input as independent variables and produces a probability value between 0 and 1. For example, we have two classes Class 0 and Class 1 if the value of the logistic function for an input is greater than 0.5 (threshold value) then it belongs to Class 1 it belongs to Class 0. It’s referred to as regression because it is the extension of linear regression but is mainly used for classification problems. The difference between [linear regression](https://www.geeksforgeeks.org/ml-linear-regression/) and logistic regression is that linear regression output is the continuous value that can be anything while logistic regression predicts the probability that an instance belongs to a given class or not.

### \***\*Understanding Logistic Regression\*\***

It is used for predicting the categorical dependent variable using a given set of independent variables.

- Logistic regression predicts the output of a categorical dependent variable. Therefore the outcome must be a categorical or discrete value.
- It can be either Yes or No, 0 or 1, true or False, etc. but instead of giving the exact value as 0 and 1, it gives the probabilistic values which lie between 0 and 1.
- Logistic Regression is much similar to the Linear Regression except that how they are used. Linear Regression is used for solving Regression problems, whereas Logistic regression is used for solving the classification problems.
- In Logistic regression, instead of fitting a regression line, we fit an “S” shaped logistic function, which predicts two maximum values (0 or 1).
- The curve from the logistic function indicates the likelihood of something such as whether the cells are cancerous or not, a mouse is obese or not based on its weight, etc.
- Logistic Regression is a significant machine learning algorithm because it has the ability to provide probabilities and classify new data using continuous and discrete datasets.
- Logistic Regression can be used to classify the observations using different types of data and can easily determine the most effective variables used for the classification.

#### \***\*Logistic Function (Sigmoid Function):\*\***

- The sigmoid function is a mathematical function used to map the predicted values to probabilities.
- It maps any real value into another value within a range of 0 and 1. The value of the logistic regression must be between 0 and 1, which cannot go beyond this limit, so it forms a curve like the “S” form.
- The S-form curve is called the Sigmoid function or the logistic function.
- In logistic regression, we use the concept of the threshold value, which defines the probability of either 0 or 1. Such as values above the threshold value tends to 1, and a value below the threshold values tends to 0.

### \***\*Differences b/w Linear and Logistic Regression\*\***

| Sr.No | Linear Regresssion | Logistic Regression |
| --- | --- | --- |
|  |  |  |
| 1 | Linear regression is used to predict the continuous dependent variable using a given set of independent variables. | Logistic regression is used to predict the categorical dependent variable using a given set of independent variables. |
| - | - | - |
| 2 | Linear regression is used for solving Regression problem. | It is used for solving classification problems. |
| 3 | In this we predict the value of continuous variables | In this we predict values of categorical varibles |
| 4 | In this we find best fit line. | In this we find S-Curve . |
| 5 | Least square estimation method is used for estimation of accuracy. | Maximum likelihood estimation method is used for Estimation of accuracy. |
| 6 | The output must be continuous value,such as price,age,etc. | Output is must be categorical value such as 0 or 1, Yes or no, etc. |
| 7 | It required linear relationship between dependent and independent variables. | It not required linear relationship. |
| 8 | There may be collinearity between the independent variables. | There should not be collinearity between independent varible. |

### \***\*Terminologies involved in Logistic Regression\*\***

Here are some common terms involved in logistic regression:

- \***\*Independent variables:\*\*** The input characteristics or predictor factors applied to the dependent variable’s predictions.
- \***\*Dependent variable:\*\*** The target variable in a logistic regression model, which we are trying to predict.
- \***\*Logistic function:\*\*** The formula used to represent how the independent and dependent variables relate to one another. The logistic function transforms the input variables into a probability value between 0 and 1, which represents the likelihood of the dependent variable being 1 or 0.
- **_Odds:_** It is the ratio of something occurring to something not occurring. it is different from probability as the probability is the ratio of something occurring to everything that could possibly occur.
- \***\*Log-odds:\*\*** The log-odds, also known as the logit function, is the natural logarithm of the odds. In logistic regression, the log odds of the dependent variable are modeled as a linear combination of the independent variables and the intercept.
- \***\*Coefficient:\*\*** The logistic regression model’s estimated parameters, show how the independent and dependent variables relate to one another.
- \***\*Intercept:\*\*** constant term in the logistic regression model, which represents the log odds when all independent variables are equal to zero.
- [\***\*Maximum likelihood estimation\*\***](https://www.geeksforgeeks.org/probability-density-estimation-maximum-likelihood-estimation/)\***\*:\*\*** The method used to estimate the coefficients of the logistic regression model, which maximizes the likelihood of observing the data given the model.

### How does Logistic Regression work?

The logistic regression model transforms the [linear regression](https://www.geeksforgeeks.org/ml-linear-regression/) function continuous value output into categorical value output using a sigmoid function, which maps any real-valued set of independent variables input into a value between 0 and 1. This function is known as the logistic function.

Let the independent input features be

![X = \begin{bmatrix} x_{11}  & ... & x_{1m}<span data-type=](https://quicklatex.com/cache3/71/ql_41cccaf8a7ab354031d548459747e571_l3.svg)\\ x*{21} & ... & x*{2m} \\ \vdots & \ddots & \vdots \\ x*{n1} & ... & x*{nm} \end{bmatrix} " title="Rendered by QuickLaTeX.com" />

and the dependent variable is Y having only binary value i.e. 0 or 1.

![Y = \begin{cases} 0 & \text{ if } Class<span data-type=](https://quicklatex.com/cache3/38/ql_48d942b46852599d337334e77e000338_l3.svg)\;1 \\ 1 & \text{ if } Class\;2 \end{cases} " title="Rendered by QuickLaTeX.com" />

then apply the multi-linear function to the input variables X

![z = \left(\sum_{i=1}^{n} w_{i}x_{i}\right) + b     ](https://quicklatex.com/cache3/cb/ql_999886a7b657ceb6b344f5227f888ccb_l3.svg "Rendered by QuickLaTeX.com")

Here ![x_i  ](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-e6ffd0848c6a699526574b307c58600a_l3.svg "Rendered by QuickLaTeX.com") is the ith observation of X, ![w_i = [w_1, w_2, w_3, \cdots,w_m]  ](https://quicklatex.com/cache3/6e/ql_cc8b2b9956c9f5add229804b56f24d6e_l3.svg "Rendered by QuickLaTeX.com") is the weights or Coefficient, and b is the bias term also known as intercept. simply this can be represented as the dot product of weight and bias.

![z = w\cdot X +b     ](https://quicklatex.com/cache3/23/ql_4f3afd86cc926735da3837081319a323_l3.svg "Rendered by QuickLaTeX.com")

whatever we discussed above is the [linear regression](https://www.geeksforgeeks.org/ml-linear-regression/).

#### Sigmoid Function

Now we use the [sigmoid function](https://www.geeksforgeeks.org/derivative-of-the-sigmoid-function/) where the input will be z and we find the probability between 0 and 1. i.e predicted y.

![\sigma(z) = \frac{1}{1-e^{-z}}     ](https://quicklatex.com/cache3/d0/ql_a8529c40057a70b9ad3bac404ef6c1d0_l3.svg "Rendered by QuickLaTeX.com")

![sigmoid function - Geeksforgeeks](https://media.geeksforgeeks.org/wp-content/uploads/20190522162153/sigmoid-function-300x138.png)Sigmoid function

As shown above, the figure sigmoid function converts the continuous variable data into the [probability](https://www.geeksforgeeks.org/probability-gq/) i.e. between 0 and 1.

- ![\sigma(z)        ](https://quicklatex.com/cache3/0c/ql_e0353c1c52b53da92c62631d22b4180c_l3.svg "Rendered by QuickLaTeX.com") tends towards 1 as ![z\rightarrow\infty     ](https://quicklatex.com/cache3/d2/ql_c7146b5390338e9cbcc819cb731a26d2_l3.svg "Rendered by QuickLaTeX.com")
- ![\sigma(z)        ](https://quicklatex.com/cache3/0c/ql_e0353c1c52b53da92c62631d22b4180c_l3.svg "Rendered by QuickLaTeX.com") tends towards 0 as ![z\rightarrow-\infty     ](https://quicklatex.com/cache3/32/ql_8bdebebf21db07e4d91f4a237acf3632_l3.svg "Rendered by QuickLaTeX.com")
- ![\sigma(z)        ](https://quicklatex.com/cache3/0c/ql_e0353c1c52b53da92c62631d22b4180c_l3.svg "Rendered by QuickLaTeX.com") is always bounded between 0 and 1

where the probability of being a class can be measured as:

![P(y=1) = \sigma(z) <span data-type=](https://quicklatex.com/cache3/c0/ql_7bccabf259089a1a3643c00c17c3b2c0_l3.svg)\\ P(y=0) = 1-\sigma(z) " title="Rendered by QuickLaTeX.com" />

### Logistic Regression Equation

The odd is the ratio of something occurring to something not occurring. it is different from probability as the probability is the ratio of something occurring to everything that could possibly occur. so odd will be

![\frac{p(x)}{1-p(x)}  = e^z     ](https://quicklatex.com/cache3/d0/ql_1da4fce941ebe37f0fa531c4a7e952d0_l3.svg "Rendered by QuickLaTeX.com")

Applying natural log on odd. then log odd will be

![\log \left[\frac{p(x)}{1-p(x)} \right] = z <span data-type=](https://quicklatex.com/cache3/4f/ql_b7567e457502c8e3714f77f5ceb49c4f_l3.svg)\\ \log \left[\frac{p(x)}{1-p(x)} \right] = w\cdot X +b " title="Rendered by QuickLaTeX.com" />

then the final logistic regression equation will be:

![p(X;b,w) = \frac{e^{w\cdot X +b}}{1+e^{w\cdot X +b}} = \frac{1}{1+e^{-w\cdot X +b}}     ](https://quicklatex.com/cache3/77/ql_a8401e7f2ea14a60021741e612627977_l3.svg "Rendered by QuickLaTeX.com")

### Likelihood function for Logistic Regression

The predicted probabilities will p(X;b,w) = p(x) for y=1 and for y = 0 predicted probabilities will 1-p(X;b,w) = 1-p(x)

![L(b,w) = \prod_{i=1}{n}p(x_i)^{y_i}(1-p(x_i))^{1-y_i}     ](https://quicklatex.com/cache3/31/ql_87261ea6bf72469973567efc0da74b31_l3.svg "Rendered by QuickLaTeX.com")

Taking natural logs on both sides

![\begin{aligned} l(b,w) =\log(L(b,w)) &= \sum_{i=1}^{n} y_i\log p(x_i)<span data-type=](https://quicklatex.com/cache3/59/ql_cd025cd816e8616487de1c55e8c35c59_l3.svg)\;+\; (1-y*i)\log(1-p(x_i)) \\ &=\sum*{i=1}^{n} y*i\log p(x_i)+\log(1-p(x_i))-y_i\log(1-p(x_i)) \\ &=\sum*{i=1}^{n} \log(1-p(x*i)) +\sum*{i=1}^{n}y*i\log \frac{p(x_i)}{1-p(x_i} \\ &=\sum*{i=1}^{n} -\log1-e^{-(w\cdot x*i+b)} +\sum*{i=1}^{n}y*i (w\cdot x_i +b) \\ &=\sum*{i=1}^{n} -\log1+e^{w\cdot x*i+b} +\sum*{i=1}^{n}y_i (w\cdot x_i +b) \end{aligned} " title="Rendered by QuickLaTeX.com" />

### Gradient of the log-likelihood function

To find the maximum likelihood estimates, we differentiate w.r.t w,

![\begin{aligned} \frac{\partial J(l(b,w)}{\partial w_j}&=-\sum_{i=n}^{n}\frac{1}{1+e^{w\cdot x_i+b}}e^{w\cdot x_i+b} x_{ij} +\sum_{i=1}^{n}y_{i}x_{ij} <span data-type=](https://quicklatex.com/cache3/27/ql_1d4532993340e36a8ff0f282366ca727_l3.svg)\\&=-\sum*{i=n}^{n}p(x_i;b,w)x*{ij}+\sum*{i=1}^{n}y*{i}x*{ij} \\&=\sum*{i=n}^{n}(y*i -p(x_i;b,w))x*{ij} \end{aligned} " title="Rendered by QuickLaTeX.com" />

### Assumptions for Logistic Regression

The assumptions for Logistic regression are as follows:

- \***\*Independent observations: \*\***Each observation is independent of the other. meaning there is no correlation between any input variables.
- \***\*Binary dependent variables: \*\***It takes the assumption that the dependent variable must be binary or dichotomous, meaning it can take only two values. For more than two categories softmax functions are used.
- \***\*Linearity relationship between independent variables and log odds:\*\*** The relationship between the independent variables and the log odds of the dependent variable should be linear.
- \***\*No outliers:\*\*** There should be no outliers in the dataset.
- \***\*Large sample size: \*\***The sample size is sufficiently large

### Types of Logistic Regression

On the basis of the categories, Logistic Regression can be classified into three types:

1. \***\*Binomial:\*\*** In binomial Logistic regression, there can be only two possible types of the dependent variables, such as 0 or 1, Pass or Fail, etc.
2. \***\*Multinomial:\*\*** In multinomial Logistic regression, there can be 3 or more possible unordered types of the dependent variable, such as “cat”, “dogs”, or “sheep”
3. \***\*Ordinal: \*\***In ordinal Logistic regression, there can be 3 or more possible ordered types of dependent variables, such as “low”, “Medium”, or “High”.

### Code Implementation for Logistic Regression

#### \***\*Binomial Logistic regression:\*\***

Target variable can have only 2 possible types: “0” or “1” which may represent “win” vs “loss”, “pass” vs “fail”, “dead” vs “alive”, etc., in this case, sigmoid functions are used, which is already discussed above.

Importing necessary libraries based on the requirement of model. This Python code shows how to use the breast cancer dataset to implement a Logistic Regression model for classification.

- Python3

| ` # import the necessary libraries``from ` ` sklearn.datasets ``import ` ` load_breast_cancer``from ` ` sklearn.linear_model ``import ` ` LogisticRegression``from ` ` sklearn.model_selection ``import ` ` train_test_split``from ` ` sklearn.metrics ``import ` ` accuracy_score``# load the breast cancer dataset``X, y ``= ` ` load_breast_cancer(return_X_y``=``True``)``# split the train and test dataset``X_train, X_test,\`` ``y_train, y_test ``= ` ` train_test_split(X, y,`` ``test_size``=``0.20``,`` ``random_state``=``23``)``# LogisticRegression``clf ``= ` ` LogisticRegression(random_state``=``0``)``clf.fit(X_train, y_train)``# Prediction``y_pred ``= ` `clf.predict(X_test)` ` acc ``= ` ` accuracy_score(y_test, y_pred)``print``(``"Logistic Regression model accuracy (in %):"``, acc``*``100``) ` |
| --- |

\***\*Output\*\*** :

```
Logistic Regression model accuracy (in %): 95.6140350877193

```

#### \***\*Multinomial Logistic Regression:\*\***

Target variable can have 3 or more possible types which are not ordered(i.e. types have no quantitative significance) like “disease A” vs “disease B” vs “disease C”.

In this case, the softmax function is used in place of the sigmoid function. [Softmax function ](https://www.geeksforgeeks.org/understanding-activation-functions-in-depth/)for K classes will be:

![\text{softmax}(z_i) =\frac{ e^{z_i}}{\sum_{j=1}^{K}e^{z_{j}}} ](https://quicklatex.com/cache3/5f/ql_197943822f70dc60acdc48aaa98c865f_l3.svg "Rendered by QuickLaTeX.com")

Here, **K** represents the number of elements in the vector z, and i, j iterates over all the elements in the vector.

Then the probability will be:

![Pr(Y=c|\overrightarrow{X}=x) =\frac{ e^{w\cdot x +b}}{\sum_{k=1}^{K}e^{w\cdot x+b}}     ](https://quicklatex.com/cache3/b2/ql_35e311413563c2585d19eed3b84479b2_l3.svg "Rendered by QuickLaTeX.com")

In Multinomial Logistic Regression, the output variable can have \***\*more than two possible discrete outputs\*\*** . Consider the Digit Dataset.

- Python3

| `from` ` sklearn.model_selection ``import ` ` train_test_split``from ` ` sklearn ``import ` `datasets, linear_model, metrics` ` # load the digit dataset``digits ``= ` `datasets.load_digits()` ` # defining feature matrix(X) and response vector(y)``X ``= ` ` digits.data``y ``= ` `digits.target` ` # splitting X and y into training and testing sets``X_train, X_test,\`` ``y_train, y_test ``= ` ` train_test_split(X, y,`` ``test_size``=``0.4``,`` ``random_state``=``1``) ` ` # create logistic regression object``reg ``= ` `linear_model.LogisticRegression()` ` # train the model using the training sets``reg.fit(X_train, y_train) ` ` # making predictions on the testing set``y_pred ``= ` `reg.predict(X_test)` ` # comparing actual response values (y_test)``# with predicted response values (y_pred)``print``(``"Logistic Regression model accuracy(in %):"``,`` ``metrics.accuracy_score(y_test, y_pred)``*``100``) ` |
| --- |

\***\*Output:\*\***

```
Logistic Regression model accuracy(in %): 96.52294853963839

```

#### \***\*Ordinal Logistic Regression:\*\***

It deals with target variables with ordered categories. For example, a test score can be categorized as: “very poor”, “poor”, “good”, or “very good”. Here, each category can be given a score like 0, 1, 2, or 3.

### Applying steps in logistic regression modeling

The following are the steps involved in logistic regression modeling:

- \***\*Define the problem:\*\*** Identify the dependent variable and independent variables and determine if the problem is a binary classification problem.
- \***\*Data preparation:\*\*** Clean and preprocess the data, and make sure the data is suitable for logistic regression modeling.
- [\***\*Exploratory Data Analysis (EDA)\*\***](https://www.geeksforgeeks.org/what-is-exploratory-data-analysis/)\***\*: \*\***Visualize the relationships between the dependent and independent variables, and identify any outliers or anomalies in the data.
- [\***\*Feature Selection\*\***](https://www.geeksforgeeks.org/feature-selection-techniques-in-machine-learning/)\***\*:\*\*** Choose the independent variables that have a significant relationship with the dependent variable, and remove any redundant or irrelevant features.
- [\***\*Model Building\*\***](https://www.geeksforgeeks.org/learning-model-building-scikit-learn-python-machine-learning-library/)\***\*: \*\***Train the logistic regression model on the selected independent variables and estimate the coefficients of the model.
- [\***\*Model Evaluation\*\***](https://www.geeksforgeeks.org/machine-learning-model-evaluation/)\***\*:\*\*** Evaluate the performance of the logistic regression model using appropriate metrics such as [accuracy](https://www.geeksforgeeks.org/techniques-to-evaluate-accuracy-of-classifier-in-data-mining/), [precision, recall, F1-score](https://www.geeksforgeeks.org/precision-recall-and-f1-score-using-r/), or [AUC-ROC](https://www.geeksforgeeks.org/auc-roc-curve/).
- \***\*Model improvement:\*\*** Based on the results of the evaluation, fine-tune the model by adjusting the independent variables, adding new features, or using regularization techniques to reduce overfitting.
- [\***\*Model Deployment\*\***](https://www.geeksforgeeks.org/python-model-deployment-using-tensorflow-serving/)\***\*:\*\*** Deploy the logistic regression model in a real-world scenario and make predictions on new data.

### Logistic Regression Model Thresholding

Logistic regression becomes a classification technique only when a decision threshold is brought into the picture. The setting of the threshold value is a very important aspect of Logistic regression and is dependent on the classification problem itself.

The decision for the value of the threshold value is majorly affected by the values of [precision and recall.](https://www.geeksforgeeks.org/confusion-matrix-machine-learning/) Ideally, we want both precision and recall to be 1, but this seldom is the case.

In the case of a Precision-Recall tradeoff, we use the following arguments to decide upon the threshold:

1. \***\*Low Precision/High Recall:\*\*** In applications where we want to reduce the number of false negatives without necessarily reducing the number of false positives, we choose a decision value that has a low value of Precision or a high value of Recall. For example, in a cancer diagnosis application, we do not want any affected patient to be classified as not affected without giving much heed to if the patient is being wrongfully diagnosed with cancer. This is because the absence of cancer can be detected by further medical diseases but the presence of the disease cannot be detected in an already rejected candidate.
2. \***\*High Precision/Low Recall:\*\*** In applications where we want to reduce the number of false positives without necessarily reducing the number of false negatives, we choose a decision value that has a high value of Precision or a low value of Recall. For example, if we are classifying customers whether they will react positively or negatively to a personalized advertisement, we want to be absolutely sure that the customer will react positively to the advertisement because otherwise, a negative reaction can cause a loss of potential sales from the customer.

### Frequently Asked Questions (FAQs)
