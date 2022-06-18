# In this section we will see how to blur an image and reduce some noise from the image

# first import the opencv module
import cv2 as cv

# load the image
img = cv.imread("images/image1.jpg")

# in this section we will only use the Gaussian blur, we will see more blur technique in future sections.
cv.imshow("Original Image", img)

blur_img = cv.GaussianBlur(img, ksize=(3, 3), sigmaX=cv.BORDER_DEFAULT)
# To increase the Blur effect increase the ksize values.
cv.imshow("Gaussian Blured Image", blur_img)

cv.waitKey(0)

# Gaussian Blur full Documentation:
# https://docs.opencv.org/4.6.0/d4/d86/group__imgproc__filter.html#gaabe8c836e97159a9193fb0b11ac52cf1
# From this link you will get Image filter functions also
