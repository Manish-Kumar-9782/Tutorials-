# In this section we will see how to perform the bitwise operation on an image.
# Bitwise operation are very usefull in masking operation or analysing an image by using masks.

# first import the module
import cv2 as cv
import numpy as np

# load the image by using the cv.imread() function
# img = cv.imread("images/image1.jpg")

# To see the clear effect of the bitwise operation we will make an operation by using the numpy
rect = np.zeros([600, 600], 'uint8')
rect = cv.rectangle(rect, (80, 80), (530, 530), (255, 255, 255), thickness=-1)
cv.imshow("Rectangle", rect)

circle = np.zeros([600, 600], 'uint8')
circle = cv.circle(circle, (300, 300), 250, (255, 255, 255), thickness=-1)
cv.imshow("Circle", circle)

# Note: The size of the circle should be greater than the rectangle to
# see the effect of the bitwise and and or operations

# Now we have two image one with white rectangle and another is white circle filled with white color.

# from here we will perform the the bitwise operation on the image.

# 1. Bitwise_and operation  // bitwise and operation gives the intersection region as result
bitwise_and = cv.bitwise_and(rect, circle)
cv.imshow("Bitwise and operation", bitwise_and)

# 2. Bitwise_or operation // bitwise or operation gives the both region non-intersecting and intersecting region
bitwise_or = cv.bitwise_or(rect, circle)
cv.imshow("Bitwise Or operation", bitwise_or)

# 3. Bitwise_xor operation // bitwise xor operation gives the non-intersection region
bitwise_xor = cv.bitwise_xor(rect, circle)
cv.imshow("Bitwise xor operation", bitwise_xor)

# 4. Bitwise_Not operation // bitwise not operation invert the given image result
bitwise_not = cv.bitwise_not(circle)
cv.imshow("Bitwise not operation", bitwise_not)

# Note that here in bitwise operation function we didn't provide the mask since we are not applying the mask
# in those operations, in next section we will apply the mask on the images.

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
