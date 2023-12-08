import pandas as pd
import matplotlib.pyplot as plt

def scatter(data, x, y, ax=None):
    
    if ax is None:
        ax = plt.gca();
        
    ax.scatter(data[x], data[y])
    ax.set_xlabel(x)
    ax.set_ylabel(y)
    
    return ax

def lm_scatter2(data, x, y, ax=None):
    
    if ax is None:
        ax = plt.gca();
        
    model = LinearRegression()
    
    # first remove all the nan values
    _data_ = data[[x,y]].dropna()
    
    train_x, test_x, train_y, test_y = train_test_split(_data_[x], _data_[y], test_size=0.3)
    
    train_x, test_x, train_y, test_y = series_reshape((-1,1), train_x, test_x, train_y, test_y)
    
    model.fit(train_x, train_y)
    
    
    ax.scatter(data[x], data[y])
    
    ax.plot(test_x, model.predict(test_x), color='red')
    ax.set_xlabel(x)
    ax.set_ylabel(y)
    
    return ax

def series_reshape(shape, *serieses):
    reshaped = []
    for series in serieses:
        assert isinstance(series, pd.Series), "series object must be instance of pandas.Series but given %s" % type(series)
        reshaped.append(series.to_numpy().reshape(*shape))
        
    return reshaped