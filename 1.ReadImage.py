import cv2 as cv

# to read a file we need to use the imread function it will returns an ndarray object
img = cv.imread("images/image1.jpg")
print(f"imread reaturs: {type(img)}")

# now we can display the image on the screen by using the imshow function.
cv.imshow('image', img)

# to hold the image window on the screen we need to use waitKey() function.
cv.waitKey(0)