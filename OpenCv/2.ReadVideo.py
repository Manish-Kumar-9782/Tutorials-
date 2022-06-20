# Now in this sectio we will try to read a video stroed on the local disk.

# first import the opencv module
import cv2 as cv

# Now to read the video we need to use VideoCapture() function from opencv
# VideoCapture can take the integer or the address of the file
# for now we will we will read the video locally stored
capture = cv.VideoCapture("videos/video2.mp4")

# Now to read the vidow we need to read the vido frame by frame for that we need to use a loop
# in this condition we don't know the how many frame a vidow would have so we will use the infinite loop
# and we will break this on last frame.
# Note the capture is a VideoCapture object

while True:

    # now we will get the video frames by using the capture.read() function
    # this will give us the boolean value and a frame if it has any

    isTrue, frame = capture.read()

    if cv.waitKey(20) & 0xFF == ord('q'):
        # if this key 'q' is press then we will break the while loop or close the displaying window
        break

    if not isTrue:
        # by using this condition we will close the video display without getting an error
        break
    # Now again we need to use the cv.imshow() function to display the frame
    cv.imshow("video2", frame)

    # Now after showing a frames we need to come out from the while by using a condition
    # for that we will make a condition.

# after comming out from the while loop we need to close video file or capturing device.
# now after releasing the all video memory we need to close the display window.
capture.release()

# after closing the capture device or display we need to close all the window.
cv.destroyAllWindows()


cv.waitKey(0)