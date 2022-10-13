import serial.tools.list_ports

BAUDRATE = 9600

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portsList = []

print("\n********** Port list **********")
for port in ports:
    portsList.append(str(port))
    print(str(port))
print("********** Port list **********\n")

noPortSelected = True
while noPortSelected:
    portSelected = input("Select Port: COM")

    for i in range(0, len(portsList)):
        if portsList[i].startswith("COM" + str(portSelected)):
            print("Port COM" + portSelected + " was successfully selected!\n")
            noPortSelected = False
    if noPortSelected:
        print("Port COM" + portSelected + " was not found, please try again\n")

serialInst.baudrate = BAUDRATE
serialInst.port = "COM" + str(portSelected)
serialInst.open()

while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()
        print(packet.decode('utf').strip('\n'))
    command = input("Arduino Command (ON/OFF) or EXIT: ")
    serialInst.write(command.encode('utf-8'))
    if command == "EXIT":
        exit()

"""
while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()
        print(packet.decode('utf').strip('\n'))
"""

"""
while True:
    command = input("Arduino Command (ON/OFF) or EXIT: ")
    serialInst.write(command.encode('utf-8'))
    if command == "EXIT":
        exit()
"""
