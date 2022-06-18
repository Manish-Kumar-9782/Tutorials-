# In this section we will see that how to detect edges in the image

# import opencv
import cv2 as cv

# load an image
img = cv.imread("images/image1.jpg")

# Now we will use cv.Canny() function to detect the edges in an image\
# 	cv.Canny(	image, threshold1, threshold2[, edges[, apertureSize[, L2gradient]]]	) ->	edges
edges = cv.Canny(img, 120, 175)

# we can manipulate the Canny Edges result by changing the threshold range and also applying some filter operation.
# in this section we will apply the Gaussian blur to change the Canny edge result.
blur_img = cv.GaussianBlur(img, ksize=(3, 3), sigmaX=cv.BORDER_DEFAULT)
blured_edges = cv.Canny(blur_img, 120, 175)

cv.imshow("Image", img)
cv.imshow("Blured Edges", blured_edges)
cv.imshow("Canny Edges", edges)

cv.waitKey(0)

# Canny edge full documentation:
# https://docs.opencv.org/4.6.0/dd/d1a/group__imgproc__feature.html#ga04723e007ed888ddf11d9ba04e2232de
# In this article we will found the Feature Detection documention also

