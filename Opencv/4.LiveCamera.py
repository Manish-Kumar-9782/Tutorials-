# Now in this section we will capture the video from the camera.

# first import the cv module
import cv2 as cv


# now we will make a function to capture video from a live camera

def CameraVideo():
    cam = cv.VideoCapture(0)
    # 0 for selecting the camera which is connected two the computer and it is set for default camera
    # Now we need to display the each frame by using the while loop

    while True:

        isTrue, frame = cam.read()  # start to read the frame from camera.

        if not isTrue:
            break

        if cv.waitKey(20) & 0xFF == ord("q"):
            break

        cv.imshow('Camera', frame)

    cam.release()  # stopping the camera to capture the frames.
    cv.destroyAllWindows()  # destroyig the all  windows.

# CameraVideo()
# uncomment above code for defalut result.
# ===================================================================================== #

# now we can rescale the captured frame by using the set properties of the capture object
# check this for more information https://docs.opencv.org/4.6.0/d4/d15/group__videoio__flags__base.html
# In this page you can found the all the constant to set the properties.
# in our case we just need to resize the height and width

Height = cv.CAP_PROP_FRAME_HEIGHT
Width = cv.CAP_PROP_FRAME_WIDTH

# after defining the properties we need to resize or rescale the frame resolution by defining another function.

def FrameResolution(capture, size):

    capture.set(Width, size[0])
    capture.set(Height, size[1])


# Now we will make another CameraVideo function which will rescale the capturing video.
def CameraVideo2():
    cam = cv.VideoCapture(0)
    # 0 for selecting the camera which is connected two the computer and it is set for default camera
    # Now we need to display the each frame by using the while loop
    FrameResolution(cam, size=(1920, 1080))

    while True:

        isTrue, frame = cam.read()  # start to read the frame from camera.

        if not isTrue:
            break

        if cv.waitKey(20) & 0xFF == ord("q"):
            break

        cv.imshow('Camera', frame)

    cam.release()  # stopping the camera to capture the frames.
    cv.destroyAllWindows()  # destroyig the all  windows.


CameraVideo2()

# here you can see the difference in result
# Note that capture.set() only work in the live capturing of video we can't use this properties in saved videos.
# fot that we need to manually resize all the frames.
cv.waitKey(0)



