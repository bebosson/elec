EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5600 1700 5200 1700
$Comp
L power:GND #PWR?
U 1 1 606D7059
P 5200 1700
F 0 "#PWR?" H 5200 1450 50  0001 C CNN
F 1 "GND" V 5205 1572 50  0000 R CNN
F 2 "" H 5200 1700 50  0001 C CNN
F 3 "" H 5200 1700 50  0001 C CNN
	1    5200 1700
	0    1    1    0   
$EndComp
$Comp
L Kube_library:R R5
U 1 1 606D72A6
P 5050 2050
F 0 "R5" H 5200 2150 50  0000 C CNN
F 1 "910K" H 4900 2150 50  0000 C CNN
F 2 "" H 5050 2050 50  0001 C CNN
F 3 "" H 5050 2050 50  0001 C CNN
	1    5050 2050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 2050 5600 2050
Wire Wire Line
	4400 2050 4850 2050
$Comp
L power:GND #PWR?
U 1 1 606D94A8
P 4400 2050
F 0 "#PWR?" H 4400 1800 50  0001 C CNN
F 1 "GND" V 4405 1922 50  0000 R CNN
F 2 "" H 4400 2050 50  0001 C CNN
F 3 "" H 4400 2050 50  0001 C CNN
	1    4400 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	8250 1600 8250 1800
NoConn ~ 8100 1700
$Comp
L power:GND #PWR?
U 1 1 606DA2EF
P 8250 2500
F 0 "#PWR?" H 8250 2250 50  0001 C CNN
F 1 "GND" H 8400 2400 50  0000 C CNN
F 2 "" H 8250 2500 50  0001 C CNN
F 3 "" H 8250 2500 50  0001 C CNN
	1    8250 2500
	1    0    0    -1  
$EndComp
Connection ~ 8250 1800
Wire Wire Line
	8250 1800 8250 1900
Connection ~ 8250 1900
Wire Wire Line
	8250 1900 8250 2000
Connection ~ 8250 2000
Wire Wire Line
	8250 2000 8250 2100
Connection ~ 8250 2100
Wire Wire Line
	8250 2100 8250 2200
Connection ~ 8250 2200
Wire Wire Line
	8250 2200 8250 2300
Connection ~ 8250 2300
Wire Wire Line
	8250 2300 8250 2400
Connection ~ 8250 2400
Wire Wire Line
	8250 2400 8250 2500
$Comp
L Kube_library:C C3
U 1 1 606B34DF
P 6150 3550
F 0 "C3" H 6150 3802 50  0000 C CNN
F 1 "1µF" H 6150 3711 50  0000 C CNN
F 2 "" V 6300 3588 50  0001 C CNN
F 3 "~" H 6150 3550 50  0001 C CNN
	1    6150 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3200 6000 3550
Wire Wire Line
	6300 3550 6300 3200
$Comp
L Kube_library:C C4
U 1 1 606BB097
P 6650 3550
F 0 "C4" H 6650 3802 50  0000 C CNN
F 1 "1µF" H 6650 3711 50  0000 C CNN
F 2 "" V 6800 3588 50  0001 C CNN
F 3 "~" H 6650 3550 50  0001 C CNN
	1    6650 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3200 6500 3550
Wire Wire Line
	6800 3550 6800 3200
$Comp
L Kube_library:C C5
U 1 1 606BD997
P 7050 3450
F 0 "C5" V 7150 3600 50  0000 R CNN
F 1 "4.7µF" V 6950 3650 50  0000 R CNN
F 2 "" V 7200 3488 50  0001 C CNN
F 3 "~" H 7050 3450 50  0001 C CNN
	1    7050 3450
	0    -1   -1   0   
$EndComp
$Comp
L Kube_library:C C6
U 1 1 606C0222
P 7250 3450
F 0 "C6" V 7350 3600 50  0000 R CNN
F 1 "2.2µF" V 7150 3400 50  0000 R CNN
F 2 "" V 7400 3488 50  0001 C CNN
F 3 "~" H 7250 3450 50  0001 C CNN
	1    7250 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7050 3200 7050 3300
Wire Wire Line
	7050 3600 7050 3750
$Comp
L power:GND #PWR?
U 1 1 606C45C5
P 7050 3800
F 0 "#PWR?" H 7050 3550 50  0001 C CNN
F 1 "GND" H 7055 3627 50  0000 C CNN
F 2 "" H 7050 3800 50  0001 C CNN
F 3 "" H 7050 3800 50  0001 C CNN
	1    7050 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3750 7250 3750
Connection ~ 7050 3750
Wire Wire Line
	7050 3750 7050 3800
Wire Wire Line
	7250 3200 7250 3300
Wire Wire Line
	7250 3600 7250 3750
Wire Wire Line
	5600 2200 3400 2200
Wire Wire Line
	3400 2200 3400 3250
Wire Wire Line
	3400 3250 2950 3250
Wire Wire Line
	2950 3350 3550 3350
Wire Wire Line
	3550 3350 3550 2300
Wire Wire Line
	3550 2300 5600 2300
Wire Wire Line
	2950 3450 3750 3450
Wire Wire Line
	3750 3450 3750 2400
Wire Wire Line
	3750 2400 5600 2400
Wire Wire Line
	5600 2500 4700 2500
Wire Wire Line
	3850 2500 3850 3550
Wire Wire Line
	3850 3550 2950 3550
Wire Wire Line
	2950 3650 4050 3650
Wire Wire Line
	4050 3650 4050 2600
Wire Wire Line
	5600 2700 5300 2700
$Comp
L Kube_library:R R9
U 1 1 60712FDF
P 5100 2700
F 0 "R9" H 5054 2788 50  0000 L CNN
F 1 "0" H 5000 2850 50  0000 L CNN
F 2 "" H 5100 2700 50  0001 C CNN
F 3 "" H 5100 2700 50  0001 C CNN
	1    5100 2700
	-1   0    0    1   
$EndComp
Wire Wire Line
	4900 2700 4700 2700
Wire Wire Line
	4700 2700 4700 2500
Connection ~ 4700 2500
Wire Wire Line
	2400 1900 5600 1900
Wire Wire Line
	7900 2650 8500 2650
Wire Wire Line
	7900 2750 8500 2750
Wire Wire Line
	8500 2750 8500 2650
Connection ~ 8500 2650
Wire Wire Line
	7900 2950 8500 2950
Wire Wire Line
	7900 2850 8500 2850
Wire Wire Line
	8500 2850 8500 2950
Connection ~ 8500 2950
Wire Wire Line
	8500 2950 8500 3050
$Comp
L power:GND #PWR?
U 1 1 6075A80C
P 8500 3050
F 0 "#PWR?" H 8500 2800 50  0001 C CNN
F 1 "GND" H 8505 2877 50  0000 C CNN
F 2 "" H 8500 3050 50  0001 C CNN
F 3 "" H 8500 3050 50  0001 C CNN
	1    8500 3050
	1    0    0    -1  
$EndComp
$Comp
L Kube_library:C C1
U 1 1 6076456A
P 8900 2800
F 0 "C1" V 8854 2915 50  0000 L CNN
F 1 "1µF" V 8945 2915 50  0000 L CNN
F 2 "" V 9050 2838 50  0001 C CNN
F 3 "~" H 8900 2800 50  0001 C CNN
	1    8900 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 2950 8900 2950
Wire Wire Line
	8500 2650 8900 2650
$Comp
L Kube_library:C C2
U 1 1 6076CFA7
P 9300 2800
F 0 "C2" V 9254 2915 50  0000 L CNN
F 1 "1µF" V 9345 2915 50  0000 L CNN
F 2 "" V 9450 2838 50  0001 C CNN
F 3 "~" H 9300 2800 50  0001 C CNN
	1    9300 2800
	0    1    1    0   
$EndComp
Connection ~ 8900 2650
Connection ~ 8900 2950
Wire Wire Line
	8900 2950 9300 2950
Wire Wire Line
	8900 2650 9300 2650
Text Label 3050 3250 0    50   ~ 0
CS
Text Label 3050 3350 0    50   ~ 0
DC
Text Label 3050 3450 0    50   ~ 0
RES
Text Label 3050 3550 0    50   ~ 0
D1
Text Label 3050 3650 0    50   ~ 0
D0
Wire Wire Line
	7900 1600 8250 1600
Wire Wire Line
	7900 1700 8100 1700
Wire Wire Line
	7900 2000 8250 2000
Wire Wire Line
	7900 2100 8250 2100
Wire Wire Line
	7900 2200 8250 2200
Wire Wire Line
	7900 2300 8250 2300
Wire Wire Line
	7900 2400 8250 2400
Wire Wire Line
	7900 1800 8250 1800
Wire Wire Line
	7900 1900 8250 1900
$Comp
L Kube_library:128x64_OLED U
U 1 1 606CAE59
P 6750 2500
F 0 "U" H 6500 2500 50  0000 C CNN
F 1 "128x64_OLED" H 6500 2600 50  0000 C CNN
F 2 "" H 6750 2500 50  0001 C CNN
F 3 "~" H 6750 2500 50  0001 C CNN
	1    6750 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2500 8250 2500
Connection ~ 8250 2500
Wire Wire Line
	6000 3200 6050 3200
Wire Wire Line
	6200 3200 6300 3200
Wire Wire Line
	6700 3200 6800 3200
Text HLabel 2950 3250 0    50   Input ~ 0
CS
Text HLabel 2950 3350 0    50   Input ~ 0
DC
Text HLabel 2950 3450 0    50   Input ~ 0
RES
Text HLabel 2950 3550 0    50   Input ~ 0
SDA_D1
Text HLabel 2950 3650 0    50   Input ~ 0
SCK_D0
$Comp
L power:+3.3V #PWR?
U 1 1 607F2FDD
P 9300 2650
F 0 "#PWR?" H 9300 2500 50  0001 C CNN
F 1 "+3.3V" V 9315 2778 50  0000 L CNN
F 2 "" H 9300 2650 50  0001 C CNN
F 3 "" H 9300 2650 50  0001 C CNN
	1    9300 2650
	0    1    1    0   
$EndComp
Connection ~ 9300 2650
Connection ~ 4300 2500
Wire Wire Line
	4300 2500 3850 2500
Wire Wire Line
	4700 2500 4300 2500
Connection ~ 4600 2600
Wire Wire Line
	4600 2600 5600 2600
Wire Wire Line
	4050 2600 4600 2600
Wire Wire Line
	4300 2500 4300 3600
Wire Wire Line
	4300 4000 4450 4000
Wire Wire Line
	4600 3600 4600 2600
$Comp
L Kube_library:R R7
U 1 1 606DE359
P 4600 3800
F 0 "R7" V 4554 3888 50  0000 L CNN
F 1 "4.7K" V 4645 3888 50  0000 L CNN
F 2 "" H 4600 3800 50  0001 C CNN
F 3 "" H 4600 3800 50  0001 C CNN
	1    4600 3800
	0    1    1    0   
$EndComp
$Comp
L Kube_library:R R6
U 1 1 606DDDC0
P 4300 3800
F 0 "R6" V 4254 3888 50  0000 L CNN
F 1 "4.7K" V 4345 3888 50  0000 L CNN
F 2 "" H 4300 3800 50  0001 C CNN
F 3 "" H 4300 3800 50  0001 C CNN
	1    4300 3800
	0    1    1    0   
$EndComp
Connection ~ 4450 4000
Wire Wire Line
	4450 4000 4600 4000
$Comp
L power:+3.3V #PWR?
U 1 1 6080D5DA
P 4450 5200
F 0 "#PWR?" H 4450 5050 50  0001 C CNN
F 1 "+3.3V" H 4465 5373 50  0000 C CNN
F 2 "" H 4450 5200 50  0001 C CNN
F 3 "" H 4450 5200 50  0001 C CNN
	1    4450 5200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 4000 4450 5200
Wire Wire Line
	2400 1800 2400 1850
Wire Wire Line
	2400 1800 5600 1800
Wire Wire Line
	2400 1850 2200 1850
Connection ~ 2400 1850
Wire Wire Line
	2400 1850 2400 1900
$Comp
L power:GND #PWR?
U 1 1 606D33F3
P 2200 1850
F 0 "#PWR?" H 2200 1600 50  0001 C CNN
F 1 "GND" V 2205 1722 50  0000 R CNN
F 2 "" H 2200 1850 50  0001 C CNN
F 3 "" H 2200 1850 50  0001 C CNN
	1    2200 1850
	0    1    1    0   
$EndComp
$EndSCHEMATC
