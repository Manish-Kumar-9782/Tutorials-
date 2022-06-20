
# in this section we will see that Erode feature which is a filter
# Note: Erode filter can reverse the dilate effect if we pass the right parameter values that
# are given during dilate filtering.

# first import the modules
import cv2 as cv

# load the images
img = cv.imread("images/image1.jpg")
# now we need to use the cv.dilate(	src, kernel[, dst[, anchor[, iterations[, borderType[, borderValue]]]]]	) -> dst
# dilated = cv.dilate(img, (3,3), iterations=3)

# dilate featrue on the edges.
edges = cv.Canny(img, 120, 175)
edge_dilate = cv.dilate(edges, (3, 3), iterations=4)

# Now we will reverse the effect of dilate process we will use the same ksize and iterations.
erode = cv.erode(edge_dilate, (3, 3), iterations=4)
cv.imshow("Image", edges)
# cv.imshow("Dilated", dilated)
cv.imshow("edge dilate", edge_dilate)
cv.imshow("eroded", erode)
cv.waitKey(0)


# Dilate documentation
# https://docs.opencv.org/4.6.0/d4/d86/group__imgproc__filter.html#ga4ff0f3318642c4f469d0e11f242f3b6c

