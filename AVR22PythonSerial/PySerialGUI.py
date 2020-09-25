import PySimpleGUI as sg
import serial

ser = serial.Serial('COM4', 9600, timeout=0, parity=serial.PARITY_NONE, stopbits = serial.STOPBITS_ONE , bytesize = serial.EIGHTBITS, rtscts=0)

sg.theme('DarkBlue')   

layout = [  [sg.Text('Python AVR Kontrol')],
            [sg.Button('LED1 YAK', key=1), sg.Button('LED1 SONDUR', key=2), sg.Button('LED2 YAK', key=3), sg.Button('LED2 SONDUR', key=4) ] ]

window = sg.Window('AVR Kontrol', layout)
while True:
    a = window.read()
    okunan = a[0]
    okunan = str(okunan)
    print(okunan)
    ser.write(okunan.encode('Ascii'))
window.close()