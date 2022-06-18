# In this section we will learn how to convert our image into a grayscale image.

# import modules

import cv2 as cv

# read an image
img = cv.imread("images/image1.jpg")
# To convert the image into grayscale or any other channels we need to use color code
# to check which color code is used for what purpose we need to check the full documentation
to_gray = cv.COLOR_BGR2GRAY  # our color code to convert our image into a grayscale color

gray_img = cv.cvtColor(img, to_gray)

cv.imshow("Image", img)
cv.imshow("GrayImage", gray_img)

# In result we can see that our colored image is converted into a gray scale

# to hold the image displaying  window
cv.waitKey(0)

# Convert An Image color code space https://docs.opencv.org/4.6.0/d8/d01/group__imgproc__color__conversions.html
