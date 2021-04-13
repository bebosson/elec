EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Sensor_Temperature:LM75C U?
U 1 1 606BAF16
P 5400 3550
F 0 "U?" H 5250 4050 50  0000 C CNN
F 1 "LM75A" H 5600 4050 50  0000 C CNN
F 2 "" H 5400 3550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm75b.pdf" H 5400 3550 50  0001 C CNN
	1    5400 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3450 5900 3450
Wire Wire Line
	5900 3450 5900 3550
Wire Wire Line
	5800 3550 5900 3550
Connection ~ 5900 3550
Wire Wire Line
	5900 3550 5900 3650
Wire Wire Line
	5800 3650 5900 3650
$Comp
L power:GND #PWR?
U 1 1 606BC5F4
P 5900 3650
F 0 "#PWR?" H 5900 3400 50  0001 C CNN
F 1 "GND" H 5905 3477 50  0000 C CNN
F 2 "" H 5900 3650 50  0001 C CNN
F 3 "" H 5900 3650 50  0001 C CNN
	1    5900 3650
	1    0    0    -1  
$EndComp
Connection ~ 5900 3650
$Comp
L power:GND #PWR?
U 1 1 606C179D
P 5400 4050
F 0 "#PWR?" H 5400 3800 50  0001 C CNN
F 1 "GND" H 5405 3877 50  0000 C CNN
F 2 "" H 5400 4050 50  0001 C CNN
F 3 "" H 5400 4050 50  0001 C CNN
	1    5400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2900 5400 3050
Wire Wire Line
	5400 2900 5650 2900
$Comp
L Device:C_Small C7
U 1 1 606C3724
P 5750 2900
F 0 "C7" V 5521 2900 50  0000 C CNN
F 1 "100nF" V 5612 2900 50  0000 C CNN
F 2 "" H 5750 2900 50  0001 C CNN
F 3 "~" H 5750 2900 50  0001 C CNN
	1    5750 2900
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 2900 5900 2900
Wire Wire Line
	5900 2900 5900 3000
$Comp
L power:GND #PWR?
U 1 1 606C5255
P 5900 3000
F 0 "#PWR?" H 5900 2750 50  0001 C CNN
F 1 "GND" H 5905 2827 50  0000 C CNN
F 2 "" H 5900 3000 50  0001 C CNN
F 3 "" H 5900 3000 50  0001 C CNN
	1    5900 3000
	1    0    0    -1  
$EndComp
NoConn ~ 5000 3650
Text HLabel 4500 3450 0    50   Input ~ 0
SDA
Wire Wire Line
	5000 3450 4700 3450
Wire Wire Line
	5000 3550 4700 3550
Text HLabel 4500 3550 0    50   Input ~ 0
SCL
$Comp
L power:+3.3V #PWR?
U 1 1 606CC412
P 5400 2750
F 0 "#PWR?" H 5400 2600 50  0001 C CNN
F 1 "+3.3V" H 5415 2923 50  0000 C CNN
F 2 "" H 5400 2750 50  0001 C CNN
F 3 "" H 5400 2750 50  0001 C CNN
	1    5400 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3050 4700 3150
$Comp
L Device:R_Small R6
U 1 1 606D09E7
P 4700 3250
F 0 "R6" H 4759 3296 50  0000 L CNN
F 1 "10K" H 4759 3205 50  0000 L CNN
F 2 "" H 4700 3250 50  0001 C CNN
F 3 "~" H 4700 3250 50  0001 C CNN
	1    4700 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3350 4700 3450
Connection ~ 4700 3450
Wire Wire Line
	4700 3450 4500 3450
Wire Wire Line
	4700 3550 4700 3650
Connection ~ 4700 3550
Wire Wire Line
	4700 3550 4500 3550
$Comp
L Device:R_Small R7
U 1 1 606D1923
P 4700 3750
F 0 "R7" H 4759 3796 50  0000 L CNN
F 1 "10K" H 4759 3705 50  0000 L CNN
F 2 "" H 4700 3750 50  0001 C CNN
F 3 "~" H 4700 3750 50  0001 C CNN
	1    4700 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3850 4700 4000
$Comp
L power:+3.3V #PWR?
U 1 1 606D255B
P 4700 4000
F 0 "#PWR?" H 4700 3850 50  0001 C CNN
F 1 "+3.3V" H 4715 4173 50  0000 C CNN
F 2 "" H 4700 4000 50  0001 C CNN
F 3 "" H 4700 4000 50  0001 C CNN
	1    4700 4000
	1    0    0    1   
$EndComp
Wire Wire Line
	5400 2900 5400 2750
Connection ~ 5400 2900
$Comp
L power:+3.3V #PWR?
U 1 1 606D3BE0
P 4700 3050
F 0 "#PWR?" H 4700 2900 50  0001 C CNN
F 1 "+3.3V" H 4715 3223 50  0000 C CNN
F 2 "" H 4700 3050 50  0001 C CNN
F 3 "" H 4700 3050 50  0001 C CNN
	1    4700 3050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
