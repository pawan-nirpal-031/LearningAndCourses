import numpy as np
import cv2 as cv 

img =  cv.imread("/home/panirpal/workspace/Learning/Courses/computer-vision/cpp/data/frm.png")
assert img is not None," no file"

# addition of imgs 

x = np.uint8([250])
y = np.uint8([10])

print(cv.add(x,y)) # since pixel value cannot exceed 255, it will be capped to 255, more like min(255,x+y) in mathematical sense 

print(x+y) # since x + y = 260 but the underlying data type is 8 bit only, hence unable to hold 260, it will use the lower 8 bits only, say 260 in binary is 000100000100 -> it will use lower 8 bits only, ie 00000100 -> which is 4 and discard remaining bits 

