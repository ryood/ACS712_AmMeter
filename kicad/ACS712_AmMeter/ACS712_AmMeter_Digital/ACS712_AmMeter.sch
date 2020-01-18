EESchema Schematic File Version 4
LIBS:ACS712_AmMeter-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ACS712_AmMeter_Digital_Board"
Date "2020-01-11"
Rev "Ver. 0.9"
Comp "PNPN Manufactory"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5150 4100 5350 4100
Wire Wire Line
	5150 4000 5350 4000
NoConn ~ 5250 3200
NoConn ~ 5150 3200
NoConn ~ 5050 3200
NoConn ~ 4950 3200
NoConn ~ 4850 3200
NoConn ~ 4750 3200
NoConn ~ 4150 3700
NoConn ~ 4150 3800
NoConn ~ 4150 3900
NoConn ~ 4150 4000
NoConn ~ 4150 4100
NoConn ~ 4150 4200
NoConn ~ 4150 4300
NoConn ~ 4150 4400
NoConn ~ 4150 4500
NoConn ~ 4150 4600
NoConn ~ 4150 4800
NoConn ~ 5850 4700
NoConn ~ 5850 4600
NoConn ~ 5850 4500
NoConn ~ 5850 4100
NoConn ~ 5850 3900
NoConn ~ 5850 3700
NoConn ~ 5150 4300
NoConn ~ 5150 4400
$Comp
L power:VCC #PWR04
U 1 1 5E19D6B2
P 5050 2700
F 0 "#PWR04" H 5050 2550 50  0001 C CNN
F 1 "VCC" H 5068 2873 50  0000 C CNN
F 2 "" H 5050 2700 50  0001 C CNN
F 3 "" H 5050 2700 50  0001 C CNN
	1    5050 2700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5E19DF1F
P 5450 2700
F 0 "#PWR05" H 5450 2450 50  0001 C CNN
F 1 "GND" H 5455 2527 50  0000 C CNN
F 2 "" H 5450 2700 50  0001 C CNN
F 3 "" H 5450 2700 50  0001 C CNN
	1    5450 2700
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5E19E51D
P 5050 2600
F 0 "#FLG01" H 5050 2675 50  0001 C CNN
F 1 "PWR_FLAG" H 5050 2773 50  0000 C CNN
F 2 "" H 5050 2600 50  0001 C CNN
F 3 "~" H 5050 2600 50  0001 C CNN
	1    5050 2600
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5E19EADF
P 5450 2600
F 0 "#FLG02" H 5450 2675 50  0001 C CNN
F 1 "PWR_FLAG" H 5450 2773 50  0000 C CNN
F 2 "" H 5450 2600 50  0001 C CNN
F 3 "~" H 5450 2600 50  0001 C CNN
	1    5450 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2700 5450 2600
$Comp
L power:VCC #PWR09
U 1 1 5E1A00CC
P 8450 3350
F 0 "#PWR09" H 8450 3200 50  0001 C CNN
F 1 "VCC" H 8467 3523 50  0000 C CNN
F 2 "" H 8450 3350 50  0001 C CNN
F 3 "" H 8450 3350 50  0001 C CNN
	1    8450 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5E1A05D3
P 8450 4400
F 0 "#PWR010" H 8450 4150 50  0001 C CNN
F 1 "GND" H 8455 4227 50  0000 C CNN
F 2 "" H 8450 4400 50  0001 C CNN
F 3 "" H 8450 4400 50  0001 C CNN
	1    8450 4400
	1    0    0    -1  
$EndComp
$Comp
L ACS712_AmMeter-rescue:Arduino_PRO-MINI-2-ArduinoProMini-eagle-import A1
U 1 1 5E1A783C
P 5050 4200
F 0 "A1" H 4400 5050 50  0001 C CNN
F 1 "Arduino_PRO-MINI-2" H 4750 3350 50  0001 C CNN
F 2 "ArduinoProMini:PRO-MINI-2" H 5050 4200 50  0001 C CNN
F 3 "" H 5050 4200 50  0001 C CNN
	1    5050 4200
	1    0    0    -1  
$EndComp
$Comp
L mylib:OLED_SSD1306_I2C U1
U 1 1 5E19927E
P 8350 4050
F 0 "U1" H 8580 4096 50  0000 L CNN
F 1 "OLED_SSD1306_I2C" H 8580 4005 50  0000 L CNN
F 2 "myfootprint:OLED_SSD1306_I2C" H 8350 3650 50  0001 C CNN
F 3 "" H 8350 4050 50  0001 C CNN
	1    8350 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 4400 8450 4350
Wire Wire Line
	8050 3950 8000 3950
Wire Wire Line
	8050 4150 7700 4150
Text Label 7450 3950 0    50   ~ 0
SCL
Text Label 7450 4150 0    50   ~ 0
SDA
Text Label 5350 4000 2    50   ~ 0
SCL
Text Label 5350 4100 2    50   ~ 0
SDA
Wire Wire Line
	5850 3800 5950 3800
$Comp
L power:GND #PWR06
U 1 1 5E1AB713
P 5950 5150
F 0 "#PWR06" H 5950 4900 50  0001 C CNN
F 1 "GND" H 5955 4977 50  0000 C CNN
F 2 "" H 5950 5150 50  0001 C CNN
F 3 "" H 5950 5150 50  0001 C CNN
	1    5950 5150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR07
U 1 1 5E1AC33E
P 6050 3400
F 0 "#PWR07" H 6050 3250 50  0001 C CNN
F 1 "VCC" H 6067 3573 50  0000 C CNN
F 2 "" H 6050 3400 50  0001 C CNN
F 3 "" H 6050 3400 50  0001 C CNN
	1    6050 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 4000 6050 4000
Wire Wire Line
	6050 4000 6050 3400
Connection ~ 5950 4500
Wire Wire Line
	5950 4500 5950 5000
Wire Wire Line
	5050 2600 5050 2700
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5E1BB4EA
P 3450 2650
F 0 "J1" H 3368 2867 50  0000 C CNN
F 1 "PWR_IN" H 3368 2776 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 3450 2650 50  0001 C CNN
F 3 "~" H 3450 2650 50  0001 C CNN
	1    3450 2650
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5E1BC69D
P 3900 3150
F 0 "#PWR02" H 3900 2900 50  0001 C CNN
F 1 "GND" H 3905 2977 50  0000 C CNN
F 2 "" H 3900 3150 50  0001 C CNN
F 3 "" H 3900 3150 50  0001 C CNN
	1    3900 3150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR01
U 1 1 5E1BD0DA
P 3900 2550
F 0 "#PWR01" H 3900 2400 50  0001 C CNN
F 1 "VCC" H 3917 2723 50  0000 C CNN
F 2 "" H 3900 2550 50  0001 C CNN
F 3 "" H 3900 2550 50  0001 C CNN
	1    3900 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 2550 3900 2650
$Comp
L Device:CP C1
U 1 1 5E1BDA94
P 3900 2850
F 0 "C1" H 4018 2896 50  0000 L CNN
F 1 "100u" H 4018 2805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 3938 2700 50  0001 C CNN
F 3 "~" H 3900 2850 50  0001 C CNN
	1    3900 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2650 3900 2650
Wire Wire Line
	3900 3150 3900 3050
Wire Wire Line
	3900 2700 3900 2650
Connection ~ 3900 2650
Wire Wire Line
	3900 3050 3700 3050
Wire Wire Line
	3700 3050 3700 2750
Wire Wire Line
	3700 2750 3650 2750
Connection ~ 3900 3050
Wire Wire Line
	3900 3050 3900 3000
Wire Wire Line
	5950 3800 5950 4500
Text Label 6300 4400 2    50   ~ 0
V_NEG
Text Label 6300 4300 2    50   ~ 0
V_POS
Text Label 6300 4200 2    50   ~ 0
V_PWR
Wire Wire Line
	6350 4400 5850 4400
Wire Wire Line
	6350 4300 5850 4300
Wire Wire Line
	6350 4200 5850 4200
Wire Wire Line
	6350 4500 5950 4500
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 5E1B1927
P 6550 4400
F 0 "J3" H 6630 4392 50  0000 L CNN
F 1 "ADC_IN" H 6630 4301 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 6550 4400 50  0001 C CNN
F 3 "~" H 6550 4400 50  0001 C CNN
	1    6550 4400
	1    0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5E1C7BC0
P 7700 3700
F 0 "R1" H 7770 3746 50  0000 L CNN
F 1 "4.7k" H 7770 3655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7630 3700 50  0001 C CNN
F 3 "~" H 7700 3700 50  0001 C CNN
	1    7700 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5E1C8531
P 8000 3700
F 0 "R2" H 8070 3746 50  0000 L CNN
F 1 "4.7k" H 8070 3655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7930 3700 50  0001 C CNN
F 3 "~" H 8000 3700 50  0001 C CNN
	1    8000 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 3550 7700 3450
Wire Wire Line
	7700 3450 8000 3450
Wire Wire Line
	8450 3350 8450 3450
Connection ~ 8450 3450
Wire Wire Line
	8450 3450 8450 3750
Wire Wire Line
	8000 3550 8000 3450
Connection ~ 8000 3450
Wire Wire Line
	8000 3450 8450 3450
Wire Wire Line
	7700 3850 7700 4150
Connection ~ 7700 4150
Wire Wire Line
	7700 4150 7450 4150
Wire Wire Line
	8000 3850 8000 3950
Connection ~ 8000 3950
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5E1F965B
P 6350 2650
F 0 "J2" H 6268 2867 50  0000 C CNN
F 1 "TP_GND" H 6268 2776 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6350 2650 50  0001 C CNN
F 3 "~" H 6350 2650 50  0001 C CNN
	1    6350 2650
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5E1F9B6B
P 6550 2950
F 0 "#PWR08" H 6550 2700 50  0001 C CNN
F 1 "GND" H 6555 2777 50  0000 C CNN
F 2 "" H 6550 2950 50  0001 C CNN
F 3 "" H 6550 2950 50  0001 C CNN
	1    6550 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2650 6550 2750
Wire Wire Line
	6550 2750 6550 2950
Connection ~ 6550 2750
$Comp
L Device:Buzzer BZ1
U 1 1 5E3F79F4
P 6500 4900
F 0 "BZ1" H 6505 5190 50  0000 C CNN
F 1 "Buzzer" H 6505 5099 50  0000 C CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 6475 5000 50  0001 C CNN
F 3 "~" V 6475 5000 50  0001 C CNN
	1    6500 4900
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5E40C003
P 7250 2500
F 0 "H1" H 7350 2546 50  0000 L CNN
F 1 "MountingHole" H 7350 2455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7250 2500 50  0001 C CNN
F 3 "~" H 7250 2500 50  0001 C CNN
	1    7250 2500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5E40C738
P 7250 2750
F 0 "H2" H 7350 2796 50  0000 L CNN
F 1 "MountingHole" H 7350 2705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 7250 2750 50  0001 C CNN
F 3 "~" H 7250 2750 50  0001 C CNN
	1    7250 2750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5E40CD16
P 8000 2500
F 0 "H3" H 8100 2546 50  0000 L CNN
F 1 "MountingHole" H 8100 2455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 8000 2500 50  0001 C CNN
F 3 "~" H 8000 2500 50  0001 C CNN
	1    8000 2500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5E40D241
P 8000 2750
F 0 "H4" H 8100 2796 50  0000 L CNN
F 1 "MountingHole" H 8100 2705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 8000 2750 50  0001 C CNN
F 3 "~" H 8000 2750 50  0001 C CNN
	1    8000 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5E415786
P 7150 3950
F 0 "J4" H 7068 4167 50  0000 C CNN
F 1 "I2C_PIN" H 7068 4076 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 7150 3950 50  0001 C CNN
F 3 "~" H 7150 3950 50  0001 C CNN
	1    7150 3950
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7350 3950 8000 3950
Wire Wire Line
	7350 4050 7450 4050
Wire Wire Line
	7450 4050 7450 4150
NoConn ~ 4150 4700
Wire Wire Line
	5850 4800 6400 4800
Wire Wire Line
	6400 5000 5950 5000
Connection ~ 5950 5000
Wire Wire Line
	5950 5000 5950 5150
$EndSCHEMATC
