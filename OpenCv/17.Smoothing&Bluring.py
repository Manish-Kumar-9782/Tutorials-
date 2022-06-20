# In this section we will see that how to smooth an image


# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
img = cv.imread("images/image3.jpg")

# Now we will see different kind of blur technique

# 1. Average blur
avg_blur = cv.blur(img, (3, 3))
cv.imshow("avrage blur", avg_blur)

# 2. Gaussian Blur 
gaussian_blur = cv.GaussianBlur(img, (3,3), 0)
cv.imshow("Gaussian Blur", gaussian_blur)

# 3. Median Blur
median_blur = cv.medianBlur(img, 3)
cv.imshow("Median blur", median_blur)

# 4. Bilateral
bilateral = cv.bilateralFilter(img, 15, 50, 50)
cv.imshow("Bilateral Blur", bilateral)
# display the image by using the cv.imshow() function.
cv.imshow("Image", img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
