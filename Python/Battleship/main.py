import json
import time
from multiprocessing import connection
import serial
from Ports import *

selectedPort = "COM" + str(ChoosePort())
connection = serial.Serial(baudrate = 9600, port = selectedPort)

try:
    connection.open()
    print("Opening connection with port " + selectedPort)
except:
    print("Connection with port " + selectedPort + " already opened, proceeding\n")

while True:

    # SEND MESSAGE
    dict_json = {
        "yolo": 2.3,
        "bruh": 5,
        }
    y = json.dumps(dict_json)
    connection.write(y.encode('utf-8'))

    # READ MESSAGE
    data = connection.readline().decode("utf-8")
    try:
        dict_json = json.loads(data)
        print(dict_json)
    except json.JSONDecodeError as error:
        print("JSON:", error)
