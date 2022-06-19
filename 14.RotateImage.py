# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")


# Now we will make a function to rotate the image.

def Rotate(img, angle, rectPoint=None):
    """
    :param img: img is the source image.
    :param angle: angle to rotate the image
    :param rectPoint: point of the rotation, if not given then we will set it to the center position.
    :return:img,  rotated img.
    """
    # Now first we need to get the height and width of the matrix
    height, width = img.shape[:2]

    # Now we need to set the rotating point for the image.
    if rectPoint is None:
        rectPoint = (width // 2, height // 2)

    # Now we need a rotated matrix 
    rotated_Mat = cv.getRotationMatrix2D(rectPoint, angle, 1.0)

    # now we need to apply the warpAffine on the rotated_Mat
    return cv.warpAffine(img, rotated_Mat, (width, height))


rotated_img = Rotate(img, 90)

# display the image by using the cv.imshow() function.
cv.imshow("Image", img)
cv.imshow("Rotated Image", rotated_img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)

# warpAffine full documentation:
# https://docs.opencv.org/4.6.0/d6/d91/group__gapi__transform.html#gaa6d70833c5eb6f6885a1b5ceb7b83957

# getRotationImageMatrix2D full documentation:
# https://docs.opencv.org/4.6.0/da/d54/group__imgproc__transform.html#gaef89d8cc92350c452b5422c8c6c5f58c
