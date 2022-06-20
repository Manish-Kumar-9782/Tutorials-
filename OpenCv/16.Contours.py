
# In this section we will see the Contours feature of transformation.
# Contours: Contours can be explained simply as a curve joining all the continuous points (along the boundary),
# having same color or intensity.

# Contours detection can be effected by using different kind of filters like blur, thresholds by changing the color
# code etc

# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
import numpy as np

img = cv.imread("images/object1.jpg")

# before finding the contours we need to change the color mode of the image
# changing the color mode RGB to Gray
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow("gray", gray)


# Now we will also detect edges in the image.
edges = cv.Canny(gray, 125, 170)
cv.imshow("Edges", edges)


# 1. detecting the contour on the original image
# 	cv.findContours(image, mode, method[, contours[, hierarchy[, offset]]]	) ->	contours, hierarchy
orignal_contours, hierarchy = cv.findContours(edges, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f"{len(orignal_contours)} Contours found!")
# Now to visualise the contours we need to draw them on an image
# To clear vision we will draw them on a black image
# first make a blake image by using the numpy array with zeros
black_img = np.zeros(gray.shape, 'uint8')
# cv.imshow("black", black_img)

# Now in this black we need to draw the contours to display them
drawn_contours = cv.drawContours(black_img, orignal_contours, -1, (255, 255, 255), 1)

# display the image by using the cv.imshow() function.
cv.imshow("Image", img)
cv.imshow("Contours", drawn_contours)


# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)


# find Contours:
# https://docs.opencv.org/4.6.0/d3/dc0/group__imgproc__shape.html#gadf1ad6a0b82947fa1fe3c3d497f260e0

# draw Contours:
# https://docs.opencv.org/4.6.0/d6/d6e/group__imgproc__draw.html#ga746c0625f1781f1ffc9056259103edbc