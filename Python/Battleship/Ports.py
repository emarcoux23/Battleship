import serial.tools.list_ports

def ChoosePort():

    ports = serial.tools.list_ports.comports()
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
                print("Port COM" + portSelected + " was successfully selected!")
                noPortSelected = False
        if noPortSelected:
            print("Port COM" + portSelected + " was not found, please try again\n")

    return portSelected