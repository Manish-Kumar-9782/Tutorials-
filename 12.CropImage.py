# In this section we will see how to crop an image
# cropping an image is a technique to select a particular region from an image and make a new image.

# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")

# now to crop the image we need to slice the image because img is an ndarray object so we just need to slice it
cropped = img[300:500, 300:500]

# display the image by using the cv.imshow() function.
cv.imshow("Image", img)

# displaying the cropped image
cv.imshow("Cropped", cropped)
# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
