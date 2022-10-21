import json
import time
from multiprocessing import connection
import serial
from Ports import *

#-----------------------------------------------------------------------------------
selectedPort = "COM" + str(ChoosePort())
connection = serial.Serial(baudrate = 9600, port = selectedPort)

try:
    connection.open()
    print("Opening connection with port " + selectedPort)
except:
    print("Connection with port " + selectedPort + " already opened, proceeding\n")
#-----------------------------------------------------------------------------------

ask_user_input = False
user_step = 0

step = {"STEP_STALL": 0,
        "STEP_BLUE":  1,
        "STEP_GREEN": 2,
        "STEP_RED":   3,
        "STEP_WHITE": 4}

while True:

    if (ask_user_input):
        print("im here")
        user_step = int(input("Choose a step number: "))
        ask_user_input = False

        # SEND MESSAGE
        dict_json = {
            "msg_step": user_step,
            }
        y = json.dumps(dict_json)
        connection.write(y.encode('utf-8'))

    # READ MESSAGE
    while not ask_user_input:
    
        data = connection.readline().decode("utf-8")
        try:
            dict_json = json.loads(data)
            print(dict_json)
            ask_user_input = bool(dict_json["ask_user_input"])
        except json.JSONDecodeError as error:
            print("JSON:", error)
