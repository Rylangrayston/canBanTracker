import serial
ser = serial.Serial('/dev/ttyACM5', 9600)
import time

logCount = 0
import time





while True:
    mesage = ser.read()
    print "Recived this on serial: ", mesage

    # update button mappings
    buttonMappings = open('buttonMappings.csv', 'r')
    mappingColums = buttonMappings.readline() 
    #print mappingColums

    buttonA_Mapping = buttonMappings.readline().strip() + time.strftime("%Y:%m:%d:%H:%M:%S") + "\n"
    buttonB_Mapping = buttonMappings.readline().strip() + time.strftime("%Y:%m:%d:%H:%M:%S") + "\n"
    buttonC_Mapping = buttonMappings.readline().strip() + time.strftime("%Y:%m:%d:%H:%M:%S") + "\n" 
    buttonD_Mapping = buttonMappings.readline().strip() + time.strftime("%Y:%m:%d:%H:%M:%S") + "\n" 
    buttonE_Mapping = buttonMappings.readline().strip() + time.strftime("%Y:%m:%d:%H:%M:%S") + "\n" 
    buttonF_Mapping = buttonMappings.readline().strip() + time.strftime("%Y:%m:%d:%H:%M:%S") + "\n" 
    buttonG_Mapping = buttonMappings.readline().strip() + time.strftime("%Y:%m:%d:%H:%M:%S") + "\n" 
    buttonH_Mapping = buttonMappings.readline().strip() + time.strftime("$%Y:%m:%d:%H:%M:%S") + "\n" 

    buttonMappings.close()




    
    if mesage == 'A':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonA_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonA_Mapping
        ser.write('A')
        logFile.close()

    
    if mesage == 'B':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonB_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonB_Mapping
        ser.write('B')
        logFile.close()

    
    if mesage == 'C':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonC_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonC_Mapping
        ser.write('C')
        logFile.close()

    
    if mesage == 'D':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonD_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonD_Mapping
        ser.write('D')
        logFile.close()

    
    if mesage == 'E':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonE_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonE_Mapping
        ser.write('E')
        logFile.close()

    
    if mesage == 'F':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonF_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonF_Mapping
        ser.write('F')
        logFile.close()

    
    if mesage == 'G':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonG_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonG_Mapping
        ser.write('G')
        logFile.close()

    
    if mesage == 'H':
        logFile = open('logFile.csv', 'a')
        logFile.write(buttonH_Mapping)
        logCount += 1
        print "log count: ", logCount
        print "logged: ", buttonH_Mapping
        ser.write('H')
        logFile.close()

    







