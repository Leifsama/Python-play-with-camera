import cv2
import numpy as np
KERNEL = np.ones((4, 4), np.uint8)
#video = cv2.VideoCapture('bear.flv')
video = cv2.VideoCapture(0)
print("ss")
while(True):

#    if video.isOpened():
#       print("success")
#    else:

#      print("fail")
#      print("video.error()")

    ret, frame = video.read()
    #for frame in frames:
    cv2.imshow('Original', frame)
    cv2.waitKey(1)

    b,g,r = cv2.split(frame)
    b = b.astype(float)
    g = g.astype(float)
    r = r.astype(float)
    mat = b + g + r
    mat[mat == 0] = 1.0  # avoid division by 0
    r[r < 60] = 0        # ignore 'dark red'
    reddish = r/mat*255  # 'normalize' red, i.e. red compared to other color planes
    reddish = reddish.astype(np.uint8)

    cv2.imshow('Original2', reddish)
    cv2.waitKey(1)

    __, binaryImg = cv2.threshold(reddish, 110, 255, cv2.THRESH_BINARY)
    binaryImg = cv2.morphologyEx(binaryImg, cv2.MORPH_OPEN, KERNEL)
    binaryImg = cv2.morphologyEx(binaryImg, cv2.MORPH_CLOSE, KERNEL)

    cv2.imshow('Original2', binaryImg)
    cv2.waitKey(1)

    __, contours, hierarchy= cv2.findContours(binaryImg, mode=cv2.RETR_EXTERNAL, method=cv2.CHAIN_APPROX_NONE)


#+moment teziste, hledani teziste, 


