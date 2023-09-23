import numpy as np
import cv2 as cv 

img =  cv.imread("/home/panirpal/workspace/Learning/Courses/computer-vision/cpp/data/frm.png")
assert img is not None," no file"

px = img[100,100]

img[100,100] = [255,255,255]

print(img.shape, img.dtype)

# access blue channel only
print(img[:,:,0]) 

# red pixel value at (10,10)
red = img.item(10,10,2)
print(red)

