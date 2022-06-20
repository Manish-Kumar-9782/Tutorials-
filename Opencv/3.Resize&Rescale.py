# Now in this section we will show how to resize or rescale an image.

import cv2 as cv

# firt of all we will read an by using the imread() function image.
img = cv.imread("images/image1.jpg")

# to resize an image or video we need we need to reduce their ndarray shape for that we will make  a funciton.

def ResizeFrame(frame, scale=0.75):
    # by default we will resize our image or a frame by 75 percent.
    # Now we need to resize the frame by the frame's width or height
    height = int(frame.shape[0] * scale)
    width = int(frame.shape[1] * scale)
    dimension = (width, height)
    # Note since frame is an object of ndarrary so it will have a shape of 2d which contains the height and width
    # Now we will return the new dimension of the new resized frame.
    return cv.resize(frame, dimension, interpolation=cv.INTER_AREA)

# after this we need to use imshow function with new dimension
resized_img = ResizeFrame(img)

# Now we will make two imshow instance two show the difference result
cv.imshow("Original image", img)
cv.imshow("Resized Image", resized_img)


# to rescale the video same method need to apply on every before using the imshow function.
# to show this we will make a function to show the resized videos.

def ShowVideo(file, scale=0.70):
    # in this we just need to pass the file address and the scale percentage.
    # first capture the video
    capture = cv.VideoCapture(file)
    # after capturing the video we need to resize the every frame before dispalying them.
    while True:

        isTrue, frame = capture.read() # read every frame form the ndarray

        if not isTrue:
            break

        if cv.waitKey(20) & 0xFF == ord('q'):
            # wait for the key
            break

        # Now before displaying the each frame we need to resize them
        nframe = ResizeFrame(frame, scale)
        cv.imshow("Original Video", frame)
        cv.imshow("Resized Video", nframe)
    capture.release()  # closing the device which is reading the video
    cv.destroyAllWindows() # destroying all the window.


# now we need to call the above funciton.
ShowVideo("videos/video1.mp4")
# to hold the display window we need to use waitKey(0)
cv.waitKey(0)