# import serial
# ser = serial.Serial('/dev/cu.usbserial-1420', 115200)
# ser.flushInput()

# while True:
#     try:
        # ser_bytes = ser.readline()
        # decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        # print(decoded_bytes)
        # with open("test_data.csv","a") as f:
        #     writer = csv.writer(f,delimiter=",")
        #     writer.writerow([time.time(),decoded_bytes])
#     except:
#         print("Keyboard Interrupt")
#         break

import serial
import time
import csv

## Boolean variable that will represent 
## whether or not the arduino is connected
connected = False


ser = serial.Serial('/dev/cu.usbserial-1420', 115200)
locations=['/dev/cu.usbserial-1410','/dev/cu.usbserial-1420','/dev/ttyUSB2','/dev/ttyUSB3']

for device in locations:
    try:
        print("Trying...",device)
        ser = serial.Serial(device, 115200)
        break
    except:
        print("Failed to connect on",device)

## loop until the arduino tells us it is ready
while not connected:
    serin = ser.read()
    connected = True

## open text file to store the current 
##gps co-ordinates received from the rover    
text_file = open("position4.txt", 'w')
## read serial data from arduino and 
## write it to the text file 'position.txt'
while 1:
    if ser.inWaiting():
        x=ser.read()
        x_str = str(x, 'utf-8')
        print(x) 
        text_file.write(x_str)
        if x_str=="\n":
             text_file.seek(0)
             text_file.truncate()
        text_file.flush()

## close the serial connection and text file
text_file.close()
ser.close()

#Stuff that just prints
# while(1):
    # print(ser.readline())
    # time.sleep(0.1)