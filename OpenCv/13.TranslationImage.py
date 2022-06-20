# In this section we will see how to translate an image by using the wrapAffine() feature

# first import the module
import cv2 as cv
import numpy as np

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")
img = cv.resize(img, (int(img.shape[1] * .5), int(img.shape[0] * .5)), interpolation=cv.INTER_AREA)


# in this we reduced the size half of the original size of image

def translate(img, x, y):
    # Now we will make an matrix to which will help us to translate the image
    transMat = np.float32([(1, 0, x), (0, 1, y)])
    dim = (img.shape[1], img.shape[0])
    return cv.warpAffine(img, transMat, dim)

# -x --> left shift
# -y --> up right shift
#  x --> right shift
#  y --> down shift


# Translate an image/ since we will use Affine

translated = translate(img, 100, 100)

# display the image by using the cv.imshow() function.
cv.imshow("Image", img)
cv.imshow("Translated", translated)
# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)

# warpAffine full documentation:
# https://docs.opencv.org/4.6.0/d6/d91/group__gapi__transform.html#gaa6d70833c5eb6f6885a1b5ceb7b83957


