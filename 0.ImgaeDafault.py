
# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")


# display the image by using the cv.imshow() function.
cv.imshow("Image", img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
