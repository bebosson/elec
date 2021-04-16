EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
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
S 9000 1750 950  500 
U 60991DCA
F0 "connecteur_isp" 50
F1 "Connector_ISP.sch" 50
F2 "MISO" I L 9000 1850 50 
F3 "SCK" I L 9000 2050 50 
F4 "MOSI" I L 9000 1950 50 
F5 "RST" I L 9000 2150 50 
$EndSheet
NoConn ~ 3300 3450
NoConn ~ 3300 3350
NoConn ~ 3300 3250
Wire Wire Line
	3900 4450 3900 4250
$Comp
L power:GND #PWR0101
U 1 1 60972291
P 3900 4450
F 0 "#PWR0101" H 3900 4200 50  0001 C CNN
F 1 "GND" H 3905 4277 50  0000 C CNN
F 2 "" H 3900 4450 50  0001 C CNN
F 3 "" H 3900 4450 50  0001 C CNN
	1    3900 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1050 3900 1250
$Comp
L Device:R_Small R2
U 1 1 6075A379
P 8450 3050
F 0 "R2" V 8250 3000 50  0000 L CNN
F 1 "10K" V 8350 3000 50  0000 L CNN
F 2 "" H 8450 3050 50  0001 C CNN
F 3 "~" H 8450 3050 50  0001 C CNN
	1    8450 3050
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0102
U 1 1 607552E3
P 10550 3750
F 0 "#PWR0102" H 10550 3600 50  0001 C CNN
F 1 "+3.3V" V 10565 3878 50  0000 L CNN
F 2 "" H 10550 3750 50  0001 C CNN
F 3 "" H 10550 3750 50  0001 C CNN
	1    10550 3750
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 60754CA5
P 9100 3650
F 0 "#PWR0103" H 9100 3500 50  0001 C CNN
F 1 "+3.3V" V 9115 3778 50  0000 L CNN
F 2 "" H 9100 3650 50  0001 C CNN
F 3 "" H 9100 3650 50  0001 C CNN
	1    9100 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	9800 3750 10150 3750
Connection ~ 9800 3750
$Comp
L power:GND #PWR0104
U 1 1 6073EFC8
P 9800 3450
F 0 "#PWR0104" H 9800 3200 50  0001 C CNN
F 1 "GND" H 9805 3277 50  0000 C CNN
F 2 "" H 9800 3450 50  0001 C CNN
F 3 "" H 9800 3450 50  0001 C CNN
	1    9800 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	9800 3650 9800 3750
$Comp
L Device:R_Small R5
U 1 1 6073EFBD
P 9800 3550
F 0 "R5" H 9859 3596 50  0000 L CNN
F 1 "10K" H 9859 3505 50  0000 L CNN
F 2 "" H 9800 3550 50  0001 C CNN
F 3 "~" H 9800 3550 50  0001 C CNN
	1    9800 3550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 6073EFB3
P 10350 3750
F 0 "SW5" H 10350 4035 50  0000 C CNN
F 1 "SW_Push" H 10350 3944 50  0000 C CNN
F 2 "" H 10350 3950 50  0001 C CNN
F 3 "~" H 10350 3950 50  0001 C CNN
	1    10350 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 3650 8700 3650
Connection ~ 8350 3650
$Comp
L power:GND #PWR0105
U 1 1 60738C31
P 8350 3350
F 0 "#PWR0105" H 8350 3100 50  0001 C CNN
F 1 "GND" H 8355 3177 50  0000 C CNN
F 2 "" H 8350 3350 50  0001 C CNN
F 3 "" H 8350 3350 50  0001 C CNN
	1    8350 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	8350 3550 8350 3650
$Comp
L Device:R_Small R4
U 1 1 60738C26
P 8350 3450
F 0 "R4" H 8409 3496 50  0000 L CNN
F 1 "10K" H 8409 3405 50  0000 L CNN
F 2 "" H 8350 3450 50  0001 C CNN
F 3 "~" H 8350 3450 50  0001 C CNN
	1    8350 3450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 60738C1C
P 8900 3650
F 0 "SW4" H 8900 3935 50  0000 C CNN
F 1 "SW_Push" H 8900 3844 50  0000 C CNN
F 2 "" H 8900 3850 50  0001 C CNN
F 3 "~" H 8900 3850 50  0001 C CNN
	1    8900 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 607371A0
P 6850 3250
F 0 "#PWR0106" H 6850 3000 50  0001 C CNN
F 1 "GND" H 7000 3150 50  0000 C CNN
F 2 "" H 6850 3250 50  0001 C CNN
F 3 "" H 6850 3250 50  0001 C CNN
	1    6850 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 3550 7200 3550
Connection ~ 6850 3550
Wire Wire Line
	6850 3450 6850 3550
$Comp
L Device:R_Small R3
U 1 1 60734D6E
P 6850 3350
F 0 "R3" H 6909 3396 50  0000 L CNN
F 1 "10K" H 6909 3305 50  0000 L CNN
F 2 "" H 6850 3350 50  0001 C CNN
F 3 "~" H 6850 3350 50  0001 C CNN
	1    6850 3350
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0107
U 1 1 60733B39
P 7600 3550
F 0 "#PWR0107" H 7600 3400 50  0001 C CNN
F 1 "+3.3V" V 7600 3700 50  0000 L CNN
F 2 "" H 7600 3550 50  0001 C CNN
F 3 "" H 7600 3550 50  0001 C CNN
	1    7600 3550
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 607269BE
P 7400 3550
F 0 "SW3" H 7400 3835 50  0000 C CNN
F 1 "SW_Push" H 7400 3744 50  0000 C CNN
F 2 "" H 7400 3750 50  0001 C CNN
F 3 "~" H 7400 3750 50  0001 C CNN
	1    7400 3550
	1    0    0    -1  
$EndComp
Connection ~ 7150 2750
Wire Wire Line
	7150 2750 7350 2750
$Comp
L power:GND #PWR0108
U 1 1 606F85F7
P 7150 2450
F 0 "#PWR0108" H 7150 2200 50  0001 C CNN
F 1 "GND" H 7155 2277 50  0000 C CNN
F 2 "" H 7150 2450 50  0001 C CNN
F 3 "" H 7150 2450 50  0001 C CNN
	1    7150 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R1
U 1 1 606F7EE5
P 7150 2550
F 0 "R1" H 7209 2596 50  0000 L CNN
F 1 "10K" H 7209 2505 50  0000 L CNN
F 2 "" H 7150 2550 50  0001 C CNN
F 3 "~" H 7150 2550 50  0001 C CNN
	1    7150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 2750 7150 2650
$Comp
L power:+3.3V #PWR0109
U 1 1 606F53C0
P 7750 2750
F 0 "#PWR0109" H 7750 2600 50  0001 C CNN
F 1 "+3.3V" V 7765 2878 50  0000 L CNN
F 2 "" H 7750 2750 50  0001 C CNN
F 3 "" H 7750 2750 50  0001 C CNN
	1    7750 2750
	0    1    1    0   
$EndComp
$Comp
L Kube_library:LDR LDR1
U 1 1 606F17C2
P 7550 2750
F 0 "LDR1" H 7567 3165 50  0000 C CNN
F 1 "LDR" H 7567 3074 50  0000 C CNN
F 2 "" H 7550 2750 50  0001 C CNN
F 3 "" H 7550 2750 50  0001 C CNN
	1    7550 2750
	1    0    0    -1  
$EndComp
$Sheet
S 6650 4800 950  600 
U 60669017
F0 "Ecran" 50
F1 "ssd1306_128_64.sch" 50
F2 "CS" I L 6650 5300 50 
F3 "DC" I L 6650 5200 50 
F4 "RES" I L 6650 4900 50 
F5 "SDA_D1" I L 6650 5000 50 
F6 "SCK_D0" I L 6650 5100 50 
$EndSheet
$Sheet
S 6650 4100 950  300 
U 606BA942
F0 "Thermometre" 50
F1 "LM75A_Temp_Sensor.sch" 50
F2 "SDA" I L 6650 4200 50 
F3 "SCL" I L 6650 4300 50 
$EndSheet
NoConn ~ 8700 5400
$Comp
L power:+3.3V #PWR0110
U 1 1 606F01BC
P 8700 5500
F 0 "#PWR0110" H 8700 5350 50  0001 C CNN
F 1 "+3.3V" V 8715 5628 50  0000 L CNN
F 2 "" H 8700 5500 50  0001 C CNN
F 3 "" H 8700 5500 50  0001 C CNN
	1    8700 5500
	0    -1   -1   0   
$EndComp
NoConn ~ 8700 6100
NoConn ~ 8700 6000
$Comp
L power:+3.3V #PWR0111
U 1 1 606E7603
P 10100 5400
F 0 "#PWR0111" H 10100 5250 50  0001 C CNN
F 1 "+3.3V" V 10115 5528 50  0000 L CNN
F 2 "" H 10100 5400 50  0001 C CNN
F 3 "" H 10100 5400 50  0001 C CNN
	1    10100 5400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 606E6C32
P 10100 6100
F 0 "#PWR0112" H 10100 5850 50  0001 C CNN
F 1 "GND" V 10105 5972 50  0000 R CNN
F 2 "" H 10100 6100 50  0001 C CNN
F 3 "" H 10100 6100 50  0001 C CNN
	1    10100 6100
	0    -1   -1   0   
$EndComp
$Comp
L Le_kube-rescue:ESP8266-01_ESP-01-ESP01S U4
U 1 1 606E17A6
P 9400 5800
F 0 "U4" H 9400 6467 50  0000 C CNN
F 1 "ESP8266-01_ESP-01" H 9400 6376 50  0000 C CNN
F 2 "XCVR_ESP8266-01/ESP-01" H 9400 5800 50  0001 L BNN
F 3 "" H 9400 5800 50  0001 L BNN
F 4 "AI-Thinkers vendor" H 9400 5800 50  0001 L BNN "MANUFACTURER"
	1    9400 5800
	1    0    0    -1  
$EndComp
$Comp
L Kube_library:R R16
U 1 1 6095BC8F
P 2700 5100
F 0 "R16" H 2700 5325 50  0000 C CNN
F 1 "10K" H 2700 5234 50  0000 C CNN
F 2 "" H 2700 5100 50  0001 C CNN
F 3 "" H 2700 5100 50  0001 C CNN
	1    2700 5100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 60945E81
P 2700 5300
F 0 "#PWR0113" H 2700 5050 50  0001 C CNN
F 1 "GND" H 2705 5127 50  0000 C CNN
F 2 "" H 2700 5300 50  0001 C CNN
F 3 "" H 2700 5300 50  0001 C CNN
	1    2700 5300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 6090CCB7
P 2300 1650
F 0 "#PWR0115" H 2300 1400 50  0001 C CNN
F 1 "GND" H 2305 1477 50  0000 C CNN
F 2 "" H 2300 1650 50  0001 C CNN
F 3 "" H 2300 1650 50  0001 C CNN
	1    2300 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1400 2700 1400
Connection ~ 2300 1400
Wire Wire Line
	2700 1100 2700 900 
$Comp
L Le_kube-rescue:C-Kube_library C2
U 1 1 60904FF9
P 2700 1250
F 0 "C2" V 2654 1365 50  0000 L CNN
F 1 "10µF" V 2745 1365 50  0000 L CNN
F 2 "" V 2850 1288 50  0001 C CNN
F 3 "~" H 2700 1250 50  0001 C CNN
	1    2700 1250
	0    1    1    0   
$EndComp
Connection ~ 2700 4900
Wire Wire Line
	2700 2350 2700 4900
Wire Wire Line
	2700 2350 2000 2350
$Comp
L Transistor_FET:IRLB8721PBF Q1
U 1 1 60931B90
P 1800 2350
F 0 "Q1" H 2005 2396 50  0000 L CNN
F 1 "IRLB8721PBF" H 2005 2305 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2050 2275 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 1800 2350 50  0001 L CNN
	1    1800 2350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1750 3700 1750 3950
NoConn ~ 1650 3700
NoConn ~ 2050 3400
NoConn ~ 2050 3300
$Comp
L power:GND #PWR0116
U 1 1 6093FE4F
P 1750 3950
F 0 "#PWR0116" H 1750 3700 50  0001 C CNN
F 1 "GND" H 1755 3777 50  0000 C CNN
F 2 "" H 1750 3950 50  0001 C CNN
F 3 "" H 1750 3950 50  0001 C CNN
	1    1750 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_A J2
U 1 1 60929EFF
P 1750 3300
F 0 "J2" H 1807 3767 50  0000 C CNN
F 1 "USB_A" H 1807 3676 50  0000 C CNN
F 2 "" H 1900 3250 50  0001 C CNN
F 3 " ~" H 1900 3250 50  0001 C CNN
	1    1750 3300
	1    0    0    -1  
$EndComp
Connection ~ 1700 900 
Wire Wire Line
	1700 900  1700 2150
$Comp
L Switch:SW_SPST SW1
U 1 1 60AA65EA
P 1250 900
F 0 "SW1" H 1250 1050 50  0000 C CNN
F 1 "I/O" H 1250 1150 50  0000 C CNN
F 2 "" H 1250 900 50  0001 C CNN
F 3 "~" H 1250 900 50  0001 C CNN
	1    1250 900 
	1    0    0    -1  
$EndComp
$Comp
L Kube_library:LD1117 VR1
U 1 1 60AB15B9
P 2300 900
F 0 "VR1" H 2300 1100 50  0000 C CNN
F 1 "LD1117" H 2300 1200 50  0000 C CNN
F 2 "" H 2200 950 50  0001 C CNN
F 3 "" H 2200 950 50  0001 C CNN
	1    2300 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 2150 8300 2150
$Comp
L Device:C_Small C6
U 1 1 60AB6BA8
P 8300 2550
F 0 "C6" H 8392 2596 50  0000 L CNN
F 1 "100nF" H 8392 2505 50  0000 L CNN
F 2 "" H 8300 2550 50  0001 C CNN
F 3 "~" H 8300 2550 50  0001 C CNN
	1    8300 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 2150 8300 2450
Wire Wire Line
	8300 2650 8300 3050
Wire Wire Line
	7150 2750 4500 2750
$Comp
L MCU_Microchip_ATmega:ATmega328PB-AU U0
U 1 1 6081701B
P 3900 2750
F 0 "U0" H 3850 2650 50  0000 C CNN
F 1 "ATmega328PB-AU" H 3850 2900 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 3900 2750 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001906C.pdf" H 3900 2750 50  0001 C CNN
	1    3900 2750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 6075C822
P 6500 2350
F 0 "SW2" H 6500 2550 50  0000 C CNN
F 1 "RST" H 6500 2650 50  0000 C CNN
F 2 "" H 6500 2550 50  0001 C CNN
F 3 "~" H 6500 2550 50  0001 C CNN
	1    6500 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 6075D1A8
P 6700 2350
F 0 "#PWR0117" H 6700 2100 50  0001 C CNN
F 1 "GND" V 6705 2222 50  0000 R CNN
F 2 "" H 6700 2350 50  0001 C CNN
F 3 "" H 6700 2350 50  0001 C CNN
	1    6700 2350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6300 2350 6300 3050
$Comp
L power:+3.3V #PWR0118
U 1 1 6075AB6D
P 8650 3050
F 0 "#PWR0118" H 8650 2900 50  0001 C CNN
F 1 "+3.3V" H 8665 3223 50  0000 C CNN
F 2 "" H 8650 3050 50  0001 C CNN
F 3 "" H 8650 3050 50  0001 C CNN
	1    8650 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 3050 8350 3050
Wire Wire Line
	8550 3050 8650 3050
Wire Wire Line
	6400 6050 6650 6050
Text Label 6400 6050 0    50   ~ 0
HUM
Wire Wire Line
	4500 2650 4650 2650
Text Label 4650 2650 0    50   ~ 0
HUM
Wire Wire Line
	9000 1850 8650 1850
Text Label 8650 1850 0    50   ~ 0
ISP_MISO
Wire Wire Line
	4500 1850 4700 1850
Text Label 4700 1850 0    50   ~ 0
ISP_MISO
Wire Wire Line
	9000 1950 8650 1950
Text Label 8650 1950 0    50   ~ 0
ISP_MOSI
Wire Wire Line
	4500 1950 4700 1950
Text Label 4700 1950 0    50   ~ 0
ISP_MOSI
Wire Wire Line
	9000 2050 8650 2050
Text Label 8650 2050 0    50   ~ 0
ISP_SCK
Wire Wire Line
	4500 2050 4700 2050
Text Label 4700 2050 0    50   ~ 0
ISP_SCK
Wire Wire Line
	4500 1550 4650 1550
Text Label 4650 1550 0    50   ~ 0
SCREEN_RST
Text Label 6100 4900 0    50   ~ 0
SCREEN_RST
Wire Wire Line
	6100 4900 6650 4900
Wire Wire Line
	3300 3550 2750 3550
Text Label 2750 3550 0    50   ~ 0
SCREEN_MISO
Wire Wire Line
	6650 5000 6100 5000
Text Label 6100 5000 0    50   ~ 0
SCREEN_MISO
Wire Wire Line
	4500 2550 4650 2550
Text Label 4650 2550 0    50   ~ 0
SCREEN_SCK
Wire Wire Line
	6650 5100 6100 5100
Text Label 6100 5100 0    50   ~ 0
SCREEN_SCK
Wire Wire Line
	4500 3850 4650 3850
Text Label 4650 3850 0    50   ~ 0
SCREEN_MOSI
Wire Wire Line
	6650 5200 6100 5200
Text Label 6100 5200 0    50   ~ 0
SCREEN_MOSI
Wire Wire Line
	4500 3950 4650 3950
Text Label 4650 3950 0    50   ~ 0
SCREEN_SS
Wire Wire Line
	6650 5300 6100 5300
Text Label 6100 5300 0    50   ~ 0
SCREEN_SS
Wire Wire Line
	4500 3250 4650 3250
Text Label 4650 3250 0    50   ~ 0
ESP_TX
Wire Wire Line
	10100 5800 10250 5800
Text Label 10250 5800 0    50   ~ 0
ESP_TX
Wire Wire Line
	4500 3350 4650 3350
Text Label 4650 3350 0    50   ~ 0
ESP_RX
Wire Wire Line
	8700 5800 8400 5800
Text Label 8400 5800 0    50   ~ 0
ESP_RX
$Sheet
S 6650 5950 1050 200 
U 608A4ECC
F0 "Capteur_humidite" 50
F1 "Capacitive_sensor.sch" 50
F2 "AOUT" I L 6650 6050 50 
$EndSheet
Wire Wire Line
	6650 4200 6400 4200
Text Label 6400 4200 0    50   ~ 0
SDA
Wire Wire Line
	4500 2850 4650 2850
Text Label 4650 2850 0    50   ~ 0
SDA
Wire Wire Line
	4500 2950 4650 2950
Text Label 4650 2950 0    50   ~ 0
SCL
Wire Wire Line
	6650 4300 6400 4300
Text Label 6400 4300 0    50   ~ 0
SCL
Connection ~ 8300 3050
Wire Wire Line
	4500 3550 6850 3550
Wire Wire Line
	4500 3650 8350 3650
Wire Wire Line
	4500 3750 9800 3750
Wire Wire Line
	5400 3450 5400 4900
Wire Wire Line
	4500 3450 5400 3450
Wire Wire Line
	2700 4900 5400 4900
$Comp
L Device:C_Small C4
U 1 1 60C210C0
P 5850 2000
F 0 "C4" V 5500 1950 50  0000 L CNN
F 1 "34pF" V 5650 1900 50  0000 L CNN
F 2 "" H 5850 2000 50  0001 C CNN
F 3 "~" H 5850 2000 50  0001 C CNN
	1    5850 2000
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C5
U 1 1 60C22DAD
P 5850 2300
F 0 "C5" V 5950 2300 50  0000 C CNN
F 1 "34pF" V 6050 2300 50  0000 C CNN
F 2 "" H 5850 2300 50  0001 C CNN
F 3 "~" H 5850 2300 50  0001 C CNN
	1    5850 2300
	0    1    1    0   
$EndComp
$Comp
L Kube_library:Crystal Y1
U 1 1 60C2C691
P 5350 2150
F 0 "Y1" V 5304 2235 50  0000 L CNN
F 1 "Crystal" V 5395 2235 50  0000 L CNN
F 2 "" H 5350 2150 50  0001 C CNN
F 3 "~" H 5350 2150 50  0001 C CNN
	1    5350 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 2150 5150 2150
Wire Wire Line
	5150 2150 5150 2000
Wire Wire Line
	5150 2000 5350 2000
Wire Wire Line
	4500 2250 5150 2250
Wire Wire Line
	5150 2250 5150 2300
Wire Wire Line
	5150 2300 5350 2300
Connection ~ 6300 3050
Wire Wire Line
	6300 3050 8300 3050
Wire Wire Line
	4500 3050 6300 3050
Wire Wire Line
	5350 2000 5750 2000
Connection ~ 5350 2000
Wire Wire Line
	5950 2000 6150 2000
Wire Wire Line
	6150 2000 6150 2150
Wire Wire Line
	6150 2300 5950 2300
Wire Wire Line
	5750 2300 5350 2300
Connection ~ 5350 2300
Wire Wire Line
	6150 2150 6300 2150
Wire Wire Line
	6300 2150 6300 1750
Connection ~ 6150 2150
Wire Wire Line
	6150 2150 6150 2300
$Comp
L power:GND #PWR0119
U 1 1 60C440C0
P 6300 1750
F 0 "#PWR0119" H 6300 1500 50  0001 C CNN
F 1 "GND" H 6305 1577 50  0000 C CNN
F 2 "" H 6300 1750 50  0001 C CNN
F 3 "" H 6300 1750 50  0001 C CNN
	1    6300 1750
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 1250 4000 1050
Wire Wire Line
	4000 1050 3950 1050
$Comp
L Device:C_Small C3
U 1 1 60C4C0A6
P 3050 1850
F 0 "C3" H 3200 1900 50  0000 L CNN
F 1 "0.1µF" H 3150 1800 50  0000 L CNN
F 2 "" H 3050 1850 50  0001 C CNN
F 3 "~" H 3050 1850 50  0001 C CNN
	1    3050 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2200 3050 1950
Wire Wire Line
	3050 1750 3050 1550
Wire Wire Line
	3050 1550 3300 1550
$Comp
L power:GND #PWR0120
U 1 1 60C513FA
P 3050 2200
F 0 "#PWR0120" H 3050 1950 50  0001 C CNN
F 1 "GND" H 3055 2027 50  0000 C CNN
F 2 "" H 3050 2200 50  0001 C CNN
F 3 "" H 3050 2200 50  0001 C CNN
	1    3050 2200
	1    0    0    -1  
$EndComp
NoConn ~ 4500 1650
NoConn ~ 4500 1750
NoConn ~ 4500 2450
$Comp
L power:+3.3V #PWR0141
U 1 1 60CB0C5C
P 3050 900
F 0 "#PWR0141" H 3050 750 50  0001 C CNN
F 1 "+3.3V" V 3065 1028 50  0000 L CNN
F 2 "" H 3050 900 50  0001 C CNN
F 3 "" H 3050 900 50  0001 C CNN
	1    3050 900 
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 900  3050 900 
Connection ~ 2700 900 
Wire Wire Line
	3950 1050 3950 900 
Connection ~ 3950 1050
Wire Wire Line
	3950 1050 3900 1050
$Comp
L power:+3.3V #PWR0142
U 1 1 60CB7B26
P 3950 900
F 0 "#PWR0142" H 3950 750 50  0001 C CNN
F 1 "+3.3V" H 3965 1073 50  0000 C CNN
F 2 "" H 3950 900 50  0001 C CNN
F 3 "" H 3950 900 50  0001 C CNN
	1    3950 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 3100 2050 2550
Wire Wire Line
	2050 2550 1700 2550
$Comp
L power:+5V #PWR0143
U 1 1 60CD6CCF
P 1750 6400
F 0 "#PWR0143" H 1750 6250 50  0001 C CNN
F 1 "+5V" H 1765 6573 50  0000 C CNN
F 2 "" H 1750 6400 50  0001 C CNN
F 3 "" H 1750 6400 50  0001 C CNN
	1    1750 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 6550 1750 6400
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 60CD286D
P 1750 6550
F 0 "#FLG0101" H 1750 6625 50  0001 C CNN
F 1 "PWR_FLAG" H 1750 6723 50  0000 C CNN
F 2 "" H 1750 6550 50  0001 C CNN
F 3 "~" H 1750 6550 50  0001 C CNN
	1    1750 6550
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C18
U 1 1 60CF48BE
P 5450 1300
F 0 "C18" V 5300 1250 50  0000 L CNN
F 1 "100nF" V 5200 1200 50  0000 L CNN
F 2 "" H 5450 1300 50  0001 C CNN
F 3 "~" H 5450 1300 50  0001 C CNN
	1    5450 1300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 1300 5550 1300
Wire Wire Line
	5350 1300 5150 1300
Wire Wire Line
	5750 1000 5600 1000
Wire Wire Line
	5300 1000 5150 1000
Wire Wire Line
	5750 1300 5750 1150
Wire Wire Line
	5150 1300 5150 1150
$Comp
L power:+3.3V #PWR0144
U 1 1 60D0251C
P 5150 1150
F 0 "#PWR0144" H 5150 1000 50  0001 C CNN
F 1 "+3.3V" V 5165 1278 50  0000 L CNN
F 2 "" H 5150 1150 50  0001 C CNN
F 3 "" H 5150 1150 50  0001 C CNN
	1    5150 1150
	0    -1   -1   0   
$EndComp
Connection ~ 5150 1150
Wire Wire Line
	5150 1150 5150 1000
$Comp
L power:GND #PWR0145
U 1 1 60D042CC
P 5750 1150
F 0 "#PWR0145" H 5750 900 50  0001 C CNN
F 1 "GND" V 5755 1022 50  0000 R CNN
F 2 "" H 5750 1150 50  0001 C CNN
F 3 "" H 5750 1150 50  0001 C CNN
	1    5750 1150
	0    -1   -1   0   
$EndComp
Connection ~ 5750 1150
Wire Wire Line
	5750 1150 5750 1000
$Comp
L Device:CP CP0
U 1 1 60D13B58
P 5450 1000
F 0 "CP0" V 5700 1000 50  0000 C CNN
F 1 "10µF" V 5600 1000 50  0000 C CNN
F 2 "" H 5488 850 50  0001 C CNN
F 3 "~" H 5450 1000 50  0001 C CNN
	1    5450 1000
	0    -1   -1   0   
$EndComp
Connection ~ 1900 900 
Wire Wire Line
	1900 900  1900 1100
Wire Wire Line
	1900 1400 2300 1400
$Comp
L Le_kube-rescue:C-Kube_library C1
U 1 1 609039B3
P 1900 1250
F 0 "C1" V 1946 1135 50  0000 R CNN
F 1 "100nF" V 1855 1135 50  0000 R CNN
F 2 "" V 2050 1288 50  0001 C CNN
F 3 "~" H 1900 1250 50  0001 C CNN
	1    1900 1250
	0    -1   -1   0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 60D46E4E
P 1700 2550
F 0 "#FLG0103" H 1700 2625 50  0001 C CNN
F 1 "PWR_FLAG" H 1700 2723 50  0000 C CNN
F 2 "" H 1700 2550 50  0001 C CNN
F 3 "~" H 1700 2550 50  0001 C CNN
	1    1700 2550
	-1   0    0    1   
$EndComp
Connection ~ 1700 2550
$Comp
L power:GND #PWR0146
U 1 1 60D47E78
P 1250 6550
F 0 "#PWR0146" H 1250 6300 50  0001 C CNN
F 1 "GND" H 1255 6377 50  0000 C CNN
F 2 "" H 1250 6550 50  0001 C CNN
F 3 "" H 1250 6550 50  0001 C CNN
	1    1250 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 6550 1250 6400
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 60D4CB74
P 1250 6400
F 0 "#FLG0104" H 1250 6475 50  0001 C CNN
F 1 "PWR_FLAG" H 1250 6573 50  0000 C CNN
F 2 "" H 1250 6400 50  0001 C CNN
F 3 "~" H 1250 6400 50  0001 C CNN
	1    1250 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1200 2300 1400
Wire Wire Line
	2300 1400 2300 1650
Wire Wire Line
	1450 900  1700 900 
Connection ~ 1800 900 
Wire Wire Line
	1800 900  1700 900 
Wire Wire Line
	1900 900  1800 900 
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 60D46425
P 1800 900
F 0 "#FLG0102" H 1800 975 50  0001 C CNN
F 1 "PWR_FLAG" H 1800 1073 50  0000 C CNN
F 2 "" H 1800 900 50  0001 C CNN
F 3 "~" H 1800 900 50  0001 C CNN
	1    1800 900 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0114
U 1 1 60DDA66B
P 1200 1350
F 0 "#PWR0114" H 1200 1200 50  0001 C CNN
F 1 "+5V" H 1215 1523 50  0000 C CNN
F 2 "" H 1200 1350 50  0001 C CNN
F 3 "" H 1200 1350 50  0001 C CNN
	1    1200 1350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Jack-DC J?
U 1 1 607A5C33
P 750 1000
AR Path="/608A4ECC/607A5C33" Ref="J?"  Part="1" 
AR Path="/607A5C33" Ref="J3"  Part="1" 
F 0 "J3" H 521 958 50  0000 R CNN
F 1 "Jack-DC" H 521 1049 50  0000 R CNN
F 2 "" H 800 960 50  0001 C CNN
F 3 "~" H 800 960 50  0001 C CNN
	1    750  1000
	1    0    0    1   
$EndComp
Wire Wire Line
	1050 1100 1200 1100
Wire Wire Line
	1200 1100 1200 1350
$EndSCHEMATC
