
# In this section we will see how to make a bgr colored image histogram
#
# for that first import the module, opencv, numpy, matplotlib
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")

# first we will make a matplot lib figure in which we will plot the histogram
plt.figure()
plt.title("RGB Histogram")
plt.xlabel("Bins")
plt.ylabel("Density of pixels")

for i, col in enumerate(("b", "g", "r")):
    hist = cv.calcHist([img], [i], None, [256], [0, 256])
    plt.plot(hist, color=col)
    plt.xlim([0, 256])

plt.show()

# display the image by using the cv.imshow() function.
cv.imshow("Image", img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
