# In this section we will see how to resize an image

# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")

# to resize the image use cv.resize() function
# cv.resize(src, dsize[, dst[, fx[, fy[, interpolation]]]]	) -> dst

resized = cv.resize(img, (int(img.shape[1]*.5), int(img.shape[0]*.5)), interpolation=cv.INTER_AREA)
# in this we reduced the size half of the original size of image

# display the image by using the cv.imshow() function.
cv.imshow("Image", img)
cv.imshow("Resized", resized)
# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)

# resize full documentation:
# https://docs.opencv.org/4.6.0/da/d54/group__imgproc__transform.html#ga47a974309e9102f5f08231edc7e7529d