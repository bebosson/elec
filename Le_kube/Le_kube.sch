EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 7900 2350 900  850 
U 606B8EB7
F0 "Temp_Sensor" 50
F1 "Temp_Sensor.sch" 50
$EndSheet
$Sheet
S 6800 3150 950  850 
U 60669017
F0 "Sheet60669016" 50
F1 "ssd1306_128_64.sch" 50
F2 "CS" I L 6800 3250 50 
F3 "DC" I L 6800 3350 50 
F4 "RES" I L 6800 3450 50 
F5 "SDA_D1" I L 6800 3550 50 
F6 "SCK_D0" I L 6800 3650 50 
$EndSheet
Wire Wire Line
	3600 1650 6050 1650
Wire Wire Line
	6050 1650 6050 3450
Wire Wire Line
	6050 3450 6800 3450
Wire Wire Line
	3600 3950 6250 3950
Wire Wire Line
	6250 3950 6250 3250
Wire Wire Line
	6250 3250 6800 3250
Wire Wire Line
	3600 3850 6350 3850
Wire Wire Line
	6350 3850 6350 3350
Wire Wire Line
	6350 3350 6800 3350
Wire Wire Line
	5900 1850 5900 3550
Wire Wire Line
	5900 3550 6800 3550
Wire Wire Line
	3600 1850 5900 1850
Wire Wire Line
	3600 2050 5750 2050
Wire Wire Line
	5750 2050 5750 3650
Wire Wire Line
	5750 3650 6800 3650
$Comp
L MCU_Microchip_ATmega:ATmega328PB-AU U?
U 1 1 6081701B
P 3000 2850
F 0 "U?" H 3000 1261 50  0000 C CNN
F 1 "ATmega328PB-AU" H 3000 1170 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 3000 2850 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001906C.pdf" H 3000 2850 50  0001 C CNN
	1    3000 2850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
