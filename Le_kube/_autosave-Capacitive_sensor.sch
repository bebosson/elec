EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
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
L Kube_library:ICM7555xB U3
U 1 1 608AC307
P 5750 4000
F 0 "U3" H 5750 4581 50  0000 C CNN
F 1 "TLC555CDR" H 5750 4490 50  0000 C CNN
F 2 "Le_kube:TLC555(SOIC-8_L5.0-W4.0-P1.27-LS6.0-BL)" H 6600 3600 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/icm7/icm7555-56.pdf" H 6600 3600 50  0001 C CNN
	1    5750 4000
	1    0    0    -1  
$EndComp
$Comp
L Kube_library:R R13
U 1 1 608B0911
P 7650 2750
F 0 "R13" V 7604 2838 50  0000 L CNN
F 1 "10K" V 7695 2838 50  0000 L CNN
F 2 "Le_kube:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" H 7650 2750 50  0001 C CNN
F 3 "" H 7650 2750 50  0001 C CNN
	1    7650 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 4050 7650 2950
$Comp
L Kube_library:D D1
U 1 1 608B1E06
P 7200 2550
F 0 "D1" H 7200 2767 50  0000 C CNN
F 1 "D" H 7200 2676 50  0000 C CNN
F 2 "Le_kube:SOD-323_L1.8-W1.3-LS2.5-RD" H 7200 2550 50  0001 C CNN
F 3 "~" H 7200 2550 50  0001 C CNN
	1    7200 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 2550 7450 2550
$Comp
L Kube_library:R R12
U 1 1 608B3772
P 5900 2350
F 0 "R12" V 5854 2438 50  0000 L CNN
F 1 "1M" V 5945 2438 50  0000 L CNN
F 2 "Le_kube:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" H 5900 2350 50  0001 C CNN
F 3 "" H 5900 2350 50  0001 C CNN
	1    5900 2350
	0    1    1    0   
$EndComp
$Comp
L Le_kube-rescue:C-Kube_library C17
U 1 1 608B4227
P 5550 2350
AR Path="/608B4227" Ref="C17"  Part="1" 
AR Path="/608A4ECC/608B4227" Ref="C17"  Part="1" 
F 0 "C17" V 5504 2465 50  0000 L CNN
F 1 "1µF" V 5595 2465 50  0000 L CNN
F 2 "Le_kube:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" V 5700 2388 50  0001 C CNN
F 3 "~" H 5550 2350 50  0001 C CNN
	1    5550 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 2550 5900 2550
Wire Wire Line
	5550 2500 5550 2550
Wire Wire Line
	5550 2550 5900 2550
Connection ~ 5900 2550
Wire Wire Line
	5900 2150 5550 2150
Wire Wire Line
	5550 2150 5550 2200
Connection ~ 5550 2150
$Comp
L power:GND #PWR0137
U 1 1 608CACB1
P 3400 4100
F 0 "#PWR0137" H 3400 3850 50  0001 C CNN
F 1 "GND" H 3405 3927 50  0000 C CNN
F 2 "" H 3400 4100 50  0001 C CNN
F 3 "" H 3400 4100 50  0001 C CNN
	1    3400 4100
	1    0    0    -1  
$EndComp
$Comp
L Le_kube-rescue:C-Kube_library C15
U 1 1 608CBCCA
P 3850 4050
AR Path="/608CBCCA" Ref="C15"  Part="1" 
AR Path="/608A4ECC/608CBCCA" Ref="C15"  Part="1" 
F 0 "C15" H 3850 4302 50  0000 C CNN
F 1 "470pF" H 3850 4211 50  0000 C CNN
F 2 "Le_kube:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" V 4000 4088 50  0001 C CNN
F 3 "~" H 3850 4050 50  0001 C CNN
	1    3850 4050
	1    0    0    -1  
$EndComp
$Comp
L Le_kube-rescue:C-Kube_library C14
U 1 1 608CE6B8
P 3850 3200
AR Path="/608CE6B8" Ref="C14"  Part="1" 
AR Path="/608A4ECC/608CE6B8" Ref="C14"  Part="1" 
F 0 "C14" H 3850 3452 50  0000 C CNN
F 1 "100nF" H 3850 3361 50  0000 C CNN
F 2 "Le_kube:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" V 4000 3238 50  0001 C CNN
F 3 "~" H 3850 3200 50  0001 C CNN
	1    3850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4100 3400 4050
Wire Wire Line
	3400 4050 3700 4050
$Comp
L Kube_library:R R11
U 1 1 608D1C5F
P 4350 4050
F 0 "R11" H 4350 4275 50  0000 C CNN
F 1 "1.6K" H 4350 4184 50  0000 C CNN
F 2 "Le_kube:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" H 4350 4050 50  0001 C CNN
F 3 "" H 4350 4050 50  0001 C CNN
	1    4350 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3600 4650 4050
Wire Wire Line
	4650 4050 4550 4050
Wire Wire Line
	4650 4050 5250 4050
Connection ~ 4650 4050
Wire Wire Line
	4150 4050 4100 4050
Wire Wire Line
	4100 4050 4100 5100
Wire Wire Line
	4100 5100 4650 5100
Wire Wire Line
	6850 5100 6850 4250
Wire Wire Line
	6850 4250 6250 4250
Connection ~ 4100 4050
Wire Wire Line
	4100 4050 4000 4050
Wire Wire Line
	3700 3200 3400 3200
Wire Wire Line
	3400 3200 3400 4050
Connection ~ 3400 4050
$Comp
L Le_kube-rescue:C-Kube_library C16
U 1 1 608D6035
P 5750 4900
AR Path="/608D6035" Ref="C16"  Part="1" 
AR Path="/608A4ECC/608D6035" Ref="C16"  Part="1" 
F 0 "C16" H 5750 5152 50  0000 C CNN
F 1 "10nF" H 5750 5061 50  0000 C CNN
F 2 "Le_kube:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" V 5900 4938 50  0001 C CNN
F 3 "~" H 5750 4900 50  0001 C CNN
	1    5750 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4900 6250 4900
Wire Wire Line
	6250 4900 6250 4600
Wire Wire Line
	5600 4900 5250 4900
Wire Wire Line
	5250 4900 5250 4450
$Comp
L power:GND #PWR0138
U 1 1 608D8B90
P 6250 4600
F 0 "#PWR0138" H 6250 4350 50  0001 C CNN
F 1 "GND" V 6255 4472 50  0000 R CNN
F 2 "" H 6250 4600 50  0001 C CNN
F 3 "" H 6250 4600 50  0001 C CNN
	1    6250 4600
	0    -1   -1   0   
$EndComp
Connection ~ 6250 4600
Wire Wire Line
	6250 4600 6250 4450
Wire Wire Line
	5250 4250 4650 4250
Wire Wire Line
	4650 4250 4650 5100
Connection ~ 4650 5100
Wire Wire Line
	4650 5100 6850 5100
Wire Wire Line
	5250 3800 5000 3800
Wire Wire Line
	5000 3800 5000 3200
$Comp
L power:+3.3V #PWR0139
U 1 1 608DB0AC
P 5000 3200
F 0 "#PWR0139" H 5000 3050 50  0001 C CNN
F 1 "+3.3V" H 5015 3373 50  0000 C CNN
F 2 "" H 5000 3200 50  0001 C CNN
F 3 "" H 5000 3200 50  0001 C CNN
	1    5000 3200
	1    0    0    -1  
$EndComp
Connection ~ 5000 3200
Wire Wire Line
	6250 3800 6250 3200
Wire Wire Line
	6250 3200 5000 3200
Wire Wire Line
	6250 4050 7650 4050
$Comp
L power:GND #PWR0140
U 1 1 608E415B
P 4850 2150
F 0 "#PWR0140" H 4850 1900 50  0001 C CNN
F 1 "GND" V 4855 2022 50  0000 R CNN
F 2 "" H 4850 2150 50  0001 C CNN
F 3 "" H 4850 2150 50  0001 C CNN
	1    4850 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 2150 5550 2150
Text HLabel 4850 2550 0    50   Input ~ 0
AOUT
Wire Wire Line
	5550 2550 4850 2550
Connection ~ 5550 2550
Wire Wire Line
	7450 2550 7450 2150
Connection ~ 7450 2550
Wire Wire Line
	7450 2550 7350 2550
Wire Wire Line
	7200 2150 7450 2150
Wire Wire Line
	6900 2150 5900 2150
Connection ~ 5900 2150
$Comp
L Kube_library:PROBE C19
U 1 1 60DFB560
P 7050 2150
F 0 "C19" H 7050 2465 50  0001 C CNN
F 1 "PROBE" H 7050 2374 50  0001 C CNN
F 2 "Le_kube:PROBE" V 7200 2188 50  0001 C CNN
F 3 "~" H 7050 2150 50  0001 C CNN
	1    7050 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3200 4650 3200
Wire Wire Line
	5000 3200 4650 3200
Connection ~ 4650 3200
$Comp
L Kube_library:R R14
U 1 1 608D3458
P 4650 3400
F 0 "R14" V 4696 3322 50  0000 R CNN
F 1 "330R" V 4605 3322 50  0000 R CNN
F 2 "Le_kube:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" H 4650 3400 50  0001 C CNN
F 3 "" H 4650 3400 50  0001 C CNN
	1    4650 3400
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
