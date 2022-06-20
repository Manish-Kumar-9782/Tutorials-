# in this section we will learn to detect the face by using the CasecadeClassifier


# first import the module
import cv2 as cv

# load the image by using the cv.imread() function
img = cv.imread("images/image1.jpg")
# now we need to change the color image into the gray color
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# Now we need to make a haar casecade classifier object
haar_casecade = cv.CascadeClassifier("Haar_Casecade.xml")
face_rect = haar_casecade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=3)

for x,y,w,g in face_rect:
    
    cv.rectangle(img, (x,y) , (x+w, y+g), (0, 255, 0), thickness=2)


# display the image by using the cv.imshow() function.
cv.imshow("Image", img)

# to hold the display window we need to use waitKey(0) function.
cv.waitKey(0)
