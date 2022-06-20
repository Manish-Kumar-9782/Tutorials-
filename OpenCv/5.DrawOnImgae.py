# in this section we will show that how can we draw somting on the image

# first import the opencv as cv
# see all the function link at the end of the file.

import cv2 as cv
import numpy as np  # to manipulate the ndarray given by the cv image instance

# we can draw many thing on on an image like various kind of shape, text etc.

# in this section we will see how to draw a rectangle, circle, text triangle, ellipse etc.

# first of all we need to get read an image
image = cv.imread("images/image1.jpg")

# now after reading we get an ndarray object which will have
image_shape = image.shape
image_width = image_shape[0]
image_height = image_shape[1]

# we will need them in on some task so its good to have their height and width
print("Image size: ", image_shape)  # if image is colored then it will have 3 channels for each colour.

# Now we want to draw different things on the center of the image so we need the center of the image.
image_center = (image_height // 2, image_width // 2)  # currently loaded image center.

# 1. to draw a circle on an image we need to call cv.circle(image, center, radius, color, thickness)
circled_image = cv.circle(image, image_center, 300, color=[0, 0, 255], thickness=10)

# 2. draw a rectangle
rect_image = cv.rectangle(image, (image_center[0] - 100, image_center[1] - 100),
                          (image_center[0] + 100, image_center[1] + 100),
                          color=[0, 255, 0], thickness=10)

# 3. draw a Marker
cv.drawMarker(image, image_center, [255, 0, 0], thickness=20, markerSize=500)

# 4. Now finally we will add a text on the image.
cv.putText(image, text="Hello this is manish", org=(10, 50), color=[255, 0, 0],
           fontFace=cv.FONT_HERSHEY_TRIPLEX, fontScale=1)

# Now we will show the new circled image.
cv.imshow("Circled Image", circled_image)
# cv.imshow("Rect Image", rect_image)

# to hold the image display window we need to used the waitKey(0)
cv.waitKey(0)

# Note: To see the full documentation on the opencv drawing function see click on below link
# OpenCv Drawing Functions: https://docs.opencv.org/4.6.0/d6/d6e/group__imgproc__draw.html
