
# In this section we will see how to make masks and apply them on images

# first import the module
import cv2 as cv
import numpy as np
# load the image by using the cv.imread() function
img = cv.imread("images/image3.jpg")
height, width = img.shape[:2]
# first we will make a new mask image, for simplicity we will make a circular shaped mask

circle = np.zeros([height, width], 'uint8')
circle = cv.circle(circle, (width//2, height//2), 200, (255, 255, 255), thickness=-1)
cv.imshow("Circle", circle)

# Now we have two images, one is mask image (white circle) and another is the image
# Now we will apply the mask on the real image

# to apply the mask on the real image first we need to superimpose a copy of img on the img
# and use the circle as mask

cv.imshow("Bitwise and ",
          cv.bitwise_and(img, img, mask=circle))

# Now from the result we can see the result of the masking we have a circular portion of the image
# display the image by using the cv.imshow() function.
cv.imshow("Image", img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
