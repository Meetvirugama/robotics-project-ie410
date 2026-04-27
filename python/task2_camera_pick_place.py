import cv2
import numpy as np
import serial
import time

# CHANGE THIS PORT
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(2)

def send_angles(b, s, e, w, r, g):
    cmd = f"{b},{s},{e},{w},{r},{g}\n"
    ser.write(cmd.encode())
    time.sleep(1.5)

def detect_object(frame):
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower = np.array([100,150,50])
    upper = np.array([140,255,255])

    mask = cv2.inRange(hsv, lower, upper)
    contours,_ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if len(contours)==0:
        return None

    c = max(contours, key=cv2.contourArea)
    x,y,w,h = cv2.boundingRect(c)
    return x+w//2, y+h//2

def map_to_robot(x,y):
    base = int(180*x/640)
    shoulder = int(80 + (y/480)*40)
    return base, shoulder

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        continue

    pos = detect_object(frame)

    if pos:
        x,y = pos
        base, shoulder = map_to_robot(x,y)

        # Hover
        send_angles(base,90,90,90,90,10)

        # Lower
        send_angles(base,shoulder,60,90,90,10)

        # Grab
        send_angles(base,shoulder,60,90,90,70)

        # Lift
        send_angles(base,90,90,90,90,70)

        # Move to B
        send_angles(45,90,90,90,90,70)

        # Release
        send_angles(45,90,90,90,90,10)

        break

    cv2.imshow("frame", frame)
    if cv2.waitKey(1)==27:
        break

cap.release()
cv2.destroyAllWindows()
ser.close()