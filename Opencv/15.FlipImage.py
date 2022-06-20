
# In this section we will see how to apply the flip transformation on the image.

# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")

# Now we just need to use the flip function on the image.
flip_img = cv.flip(img, 0)

# 0 --> flip vertically
# 1 --> flip horizontally
# -1 --> flip both vertically and horizontally

# display the image by using the cv.imshow() function.
cv.imshow("Image", img)
cv.imshow("Flipped Image", flip_img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)

# See the full documentation on the flip:
# https://docs.opencv.org/4.6.0/d2/de8/group__core__array.html#gaca7be533e3dac7feb70fc60635adf441
