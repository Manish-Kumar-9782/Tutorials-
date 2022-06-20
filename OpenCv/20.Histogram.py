
# In this section we will see how to make the histogram of an images
# histogram are very useful to analysis the density and intensity of pixle on some certain region.

# first import the module
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt  # to draw the histogram by using the matplotlib

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")

# 1. first we will see the intensity of grayscale image
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# now we will calculate the hist values
# calcHist(images, channels, mask, histSize, ranges[, hist[, accumulate]]) -> hist
gray_hist = cv.calcHist([gray], [0], None, [256], [0, 256])

# now to plot the histogram we will use the matplotlib

plt.plot(gray_hist, color='gray')
plt.title("GrayScale Histogram")
plt.show()

# From result we can see the histogram plot which show that there is high intensity pixels density is more greater
# than the low intensity pixels.

# 2. Now we will make a mask to calculate the histogram result on the selected result

mask = np.zeros(img.shape[:2], 'uint8')
width, height = mask.shape[:2]
circle = cv.circle(mask, (height//2-200, width//2), 300, (255, 255, 255), -1)
mask = cv.bitwise_and(gray, gray, mask=circle)
cv.imshow("mask", mask)

# Now we will apply this mask on the calcHist function

hist2 = cv.calcHist([gray], [0], mask, [256], (0, 256))
plt.plot(gray_hist, color='gray')
plt.title("GrayScale Masked Histogram")
plt.show()

# as you see the both plots have slightly different curve
# display the image by using the cv.imshow() function.
# cv.imshow("Image", img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
