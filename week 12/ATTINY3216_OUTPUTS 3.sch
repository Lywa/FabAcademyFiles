EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 3050 1100 0    50   Input ~ 0
5V
Text GLabel 3350 1100 2    50   Input ~ 0
GND
$Comp
L fab:CAP-UNPOLARIZEDFAB C1
U 1 1 60820D9F
P 3250 1100
F 0 "C1" H 3200 1314 45  0000 C CNN
F 1 "1 uF" H 3200 1230 45  0000 C CNN
F 2 "fab:fab-C1206FAB" H 3280 1250 20  0001 C CNN
F 3 "" H 3250 1100 50  0001 C CNN
	1    3250 1100
	1    0    0    -1  
$EndComp
Connection ~ 5705 2650
Wire Wire Line
	5705 2650 5705 2900
Wire Wire Line
	6655 2900 6655 2650
Wire Wire Line
	5705 2900 6655 2900
Wire Wire Line
	6555 2450 6705 2450
Connection ~ 6555 2450
Wire Wire Line
	6555 2650 6555 2450
Wire Wire Line
	6455 2650 6555 2650
Wire Wire Line
	5655 2450 6555 2450
Wire Wire Line
	6105 2650 6155 2650
Wire Wire Line
	5655 2650 5705 2650
$Comp
L fab:RES-US1206FAB R1
U 1 1 60830C6F
P 5905 2650
F 0 "R1" H 5905 2844 45  0000 C CNN
F 1 "220Ω" H 5905 2760 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 5935 2800 20  0001 C CNN
F 3 "" H 5905 2650 50  0001 C CNN
	1    5905 2650
	1    0    0    -1  
$EndComp
$Comp
L fab:FTDI-SMD-HEADER M4
U 1 1 6081E2F7
P 5655 2150
F 0 "M4" H 5655 2150 45  0001 C CNN
F 1 "FTDI-SMD-HEADER" H 5655 2150 45  0001 C CNN
F 2 "fab:fab-1X06SMD" H 5685 2300 20  0001 C CNN
F 3 "" H 5655 2150 50  0001 C CNN
	1    5655 2150
	-1   0    0    1   
$EndComp
Text GLabel 5655 2250 2    50   Input ~ 0
TXD
Text GLabel 5655 2350 2    50   Input ~ 0
RXD
Text GLabel 6655 2650 2    50   Input ~ 0
GND
NoConn ~ 5655 2150
NoConn ~ 5655 2550
$Comp
L fab:LEDFAB1206 L1
U 1 1 6082AEB3
P 6355 2650
F 0 "L1" V 6559 2700 45  0000 C CNN
F 1 "LED_GREEN" V 6475 2700 45  0000 C CNN
F 2 "fab:fab-LED1206FAB" H 6385 2800 20  0001 C CNN
F 3 "" H 6355 2650 50  0001 C CNN
	1    6355 2650
	0    -1   -1   0   
$EndComp
$Comp
L fab:PINHD-1x03-SMD-HEADER M1
U 1 1 60840A0B
P 1100 2700
F 0 "M1" H 1100 2700 45  0001 C CNN
F 1 "PINHD-1x03-SMD-HEADER" H 1100 2700 45  0001 C CNN
F 2 "fab:fab-1X03SMD" H 1130 2850 20  0001 C CNN
F 3 "" H 1100 2700 50  0001 C CNN
	1    1100 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 2800 950  2800
Wire Wire Line
	1400 2800 1350 2800
$Comp
L fab:RES-US1206FAB R2
U 1 1 608447E5
P 1600 2800
F 0 "R2" H 1600 2994 45  0000 C CNN
F 1 "220Ω" H 1600 2910 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 1630 2950 20  0001 C CNN
F 3 "" H 1600 2800 50  0001 C CNN
	1    1600 2800
	-1   0    0    1   
$EndComp
Text GLabel 1100 2200 0    50   Input ~ 0
GND
Text GLabel 1100 2400 0    50   Input ~ 0
PWM1
Text GLabel 1800 2800 2    50   Input ~ 0
GND
$Comp
L fab:PINHD-1x03-SMD-HEADER M2
U 1 1 6084B449
P 1150 4200
F 0 "M2" H 1150 4200 45  0001 C CNN
F 1 "PINHD-1x03-SMD-HEADER" H 1150 4200 45  0001 C CNN
F 2 "fab:fab-1X03SMD" H 1180 4350 20  0001 C CNN
F 3 "" H 1150 4200 50  0001 C CNN
	1    1150 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 4300 1000 4300
Wire Wire Line
	1450 4300 1400 4300
$Comp
L fab:RES-US1206FAB R3
U 1 1 6084B451
P 1650 4300
F 0 "R3" H 1650 4494 45  0000 C CNN
F 1 "220Ω" H 1650 4410 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 1680 4450 20  0001 C CNN
F 3 "" H 1650 4300 50  0001 C CNN
	1    1650 4300
	-1   0    0    1   
$EndComp
$Comp
L fab:LEDFAB1206 L3
U 1 1 6084B457
P 1200 4300
F 0 "L3" V 1404 4350 45  0000 C CNN
F 1 "LED_GREEN" V 1320 4350 45  0000 C CNN
F 2 "fab:fab-LED1206FAB" H 1230 4450 20  0001 C CNN
F 3 "" H 1200 4300 50  0001 C CNN
	1    1200 4300
	0    1    1    0   
$EndComp
Text GLabel 1150 3700 0    50   Input ~ 0
GND
Text GLabel 1150 3900 0    50   Input ~ 0
PWM3
Text GLabel 1850 4300 2    50   Input ~ 0
GND
Text GLabel 1000 4300 0    50   Input ~ 0
PWM4
Wire Notes Line
	4955 4050 4955 1700
Wire Notes Line
	4955 1700 7305 1700
Wire Notes Line
	7305 1700 7305 4050
Wire Notes Line
	7305 4050 4955 4050
Text Notes 5655 3950 2    50   ~ 0
Programming\n
Text Notes 5755 1850 2    50   ~ 0
Serial Connexion\n
Wire Notes Line
	2600 650  2600 1450
Wire Notes Line
	2600 1450 3800 1450
Wire Notes Line
	3800 1450 3800 650 
Wire Notes Line
	3800 650  2600 650 
Text Notes 3400 750  2    50   ~ 0
Power estabilization\n
Text Notes 1100 1850 2    50   ~ 0
Servo 1\n
Text Notes 1000 3450 2    50   ~ 0
Servo 2\n
Wire Notes Line
	2150 1650 600  1650
Wire Notes Line
	600  1650 600  3150
Wire Notes Line
	600  3150 2150 3150
Wire Notes Line
	2150 1650 2150 3150
Wire Notes Line
	600  3250 2150 3250
Wire Notes Line
	2150 3250 2150 4550
Wire Notes Line
	2150 4550 600  4550
Wire Notes Line
	600  4550 600  3250
$Comp
L fab:LEDFAB1206 L2
U 1 1 608447EB
P 1150 2800
F 0 "L2" V 1354 2850 45  0000 C CNN
F 1 "LED_GREEN" V 1270 2850 45  0000 C CNN
F 2 "fab:fab-LED1206FAB" H 1180 2950 20  0001 C CNN
F 3 "" H 1150 2800 50  0001 C CNN
	1    1150 2800
	0    1    1    0   
$EndComp
$Comp
L fab:PINHD-1x03-SMD-HEADER M3
U 1 1 60852F3D
P 1250 5650
F 0 "M3" H 1250 5650 45  0001 C CNN
F 1 "PINHD-1x03-SMD-HEADER" H 1250 5650 45  0001 C CNN
F 2 "fab:fab-1X03SMD" H 1280 5800 20  0001 C CNN
F 3 "" H 1250 5650 50  0001 C CNN
	1    1250 5650
	1    0    0    -1  
$EndComp
Text GLabel 1250 5250 0    50   Input ~ 0
DATA12
Text GLabel 1250 5150 0    50   Input ~ 0
GND
Wire Notes Line
	600  4800 2150 4800
Wire Notes Line
	2150 4800 2150 5700
Wire Notes Line
	2150 5700 600  5700
Wire Notes Line
	600  5700 600  4800
Text Notes 1050 4950 2    50   ~ 0
Led Strip\n
Text GLabel 2935 2120 0    50   Input ~ 0
5V
Text GLabel 4135 2120 2    50   Input ~ 0
GND
Text GLabel 4135 2720 2    50   Input ~ 0
UPDI
Text GLabel 6705 2450 2    50   Input ~ 0
5V
Text GLabel 1100 2300 0    50   Input ~ 0
5V
Text GLabel 1250 5350 0    50   Input ~ 0
5V
Text GLabel 1150 3800 0    50   Input ~ 0
5V
$Comp
L fab:TERM-1X02-FABLAB J1
U 1 1 608220DB
P 4505 1090
F 0 "J1" H 4733 1140 45  0000 L CNN
F 1 "TERM-1X02-FABLAB" H 4505 1090 45  0001 L BNN
F 2 "fab:fab-ED555DS-2DS" H 4535 1240 20  0001 C CNN
F 3 "" H 4505 1090 50  0001 C CNN
	1    4505 1090
	1    0    0    -1  
$EndComp
Text GLabel 5340 3570 0    50   Input ~ 0
GND
Text GLabel 5330 3670 0    50   Input ~ 0
5V
Text GLabel 5365 3470 0    50   Input ~ 0
UPDI
Wire Wire Line
	5365 3470 5590 3470
Wire Wire Line
	5340 3570 5590 3570
Wire Wire Line
	5330 3670 5590 3670
Text GLabel 4305 985  0    50   Input ~ 0
5V
Wire Wire Line
	4330 1100 4495 1100
Wire Wire Line
	4495 1100 4495 1090
Wire Wire Line
	4495 1090 4505 1090
Wire Wire Line
	4305 985  4505 985 
Wire Wire Line
	4505 985  4505 990 
Text GLabel 2935 3170 0    50   Input ~ 0
TXD
Text GLabel 2935 3320 0    50   Input ~ 0
RXD
Text GLabel 950  2800 0    50   Input ~ 0
PWM2
Text GLabel 4135 3470 2    50   Input ~ 0
PWM1
Text GLabel 4135 3320 2    50   Input ~ 0
PWM3
Text GLabel 2935 3470 0    50   Input ~ 0
PWM2
Text GLabel 4135 3170 2    50   Input ~ 0
PWM4
Text GLabel 4330 1100 0    50   Input ~ 0
GND
$Comp
L fab:6MM_SWITCH6MM_SWITCH S1
U 1 1 60835727
P 3575 5135
F 0 "S1" H 3728 5177 45  0000 L CNN
F 1 "6MM_SWITCH" H 3728 5093 45  0000 L CNN
F 2 "fab:fab-6MM_SWITCH" H 3605 5285 20  0001 C CNN
F 3 "" H 3575 5135 50  0001 C CNN
	1    3575 5135
	1    0    0    -1  
$EndComp
Wire Wire Line
	3575 5335 3575 5455
Wire Wire Line
	3575 5590 3565 5590
Wire Wire Line
	3575 5455 3315 5455
Connection ~ 3575 5455
Wire Wire Line
	3575 5455 3575 5590
$Comp
L fab:RES-US1206FAB R4
U 1 1 6083CC84
P 3115 5455
F 0 "R4" H 3115 5649 45  0000 C CNN
F 1 "10kΩ" H 3115 5565 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 3145 5605 20  0001 C CNN
F 3 "" H 3115 5455 50  0001 C CNN
	1    3115 5455
	1    0    0    -1  
$EndComp
Text GLabel 2915 5455 0    50   Input ~ 0
5V
Wire Wire Line
	3675 5335 3575 5335
Connection ~ 3575 5335
Wire Wire Line
	3575 4935 3675 4935
Wire Wire Line
	3675 4710 3675 4935
Connection ~ 3675 4935
Text GLabel 3675 4710 1    50   Input ~ 0
GND
Wire Notes Line
	2550 5670 2550 4275
Wire Notes Line
	2550 4275 4340 4275
Wire Notes Line
	4340 4275 4340 5865
Wire Notes Line
	4340 5865 2550 5865
Wire Notes Line
	2550 5865 2550 5680
Wire Notes Line
	2550 5680 2540 5680
Text Notes 2875 4435 2    50   ~ 0
Switch\n
Text Notes 4555 740  2    50   ~ 0
Power Supply\n
Wire Notes Line
	3945 640  4900 640 
Wire Notes Line
	4900 640  4900 1445
Wire Notes Line
	4900 1445 3900 1445
Wire Notes Line
	3900 1445 3900 635 
Wire Notes Line
	3900 635  3955 635 
Text GLabel 3565 5590 2    50   Input ~ 0
ARDUINO4
$Comp
L fab:RES-US1206FAB R5
U 1 1 6081ED1D
P 5590 1150
F 0 "R5" H 5590 1344 45  0000 C CNN
F 1 "0Ω" H 5590 1260 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 5620 1300 20  0001 C CNN
F 3 "" H 5590 1150 50  0001 C CNN
	1    5590 1150
	1    0    0    -1  
$EndComp
Text GLabel 5390 1150 0    50   Input ~ 0
TXD
Text GLabel 5790 1150 2    50   Input ~ 0
TXD
$Comp
L fab:RES-US1206FAB R6
U 1 1 60825B22
P 6600 1060
F 0 "R6" H 6600 1254 45  0000 C CNN
F 1 "0Ω" H 6600 1170 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 6630 1210 20  0001 C CNN
F 3 "" H 6600 1060 50  0001 C CNN
	1    6600 1060
	1    0    0    -1  
$EndComp
Text GLabel 6400 1060 0    50   Input ~ 0
5V
Text GLabel 6800 1060 2    50   Input ~ 0
5V
$Comp
L fab:RES-US1206FAB R7
U 1 1 60827E43
P 7320 1425
F 0 "R7" H 7320 1619 45  0000 C CNN
F 1 "0Ω" H 7320 1535 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 7350 1575 20  0001 C CNN
F 3 "" H 7320 1425 50  0001 C CNN
	1    7320 1425
	1    0    0    -1  
$EndComp
Text GLabel 7120 1425 0    50   Input ~ 0
GND
Text GLabel 7520 1425 2    50   Input ~ 0
GND
$Comp
L fab:RES-US1206FAB R8
U 1 1 60828C64
P 7660 895
F 0 "R8" H 7660 1089 45  0000 C CNN
F 1 "0Ω" H 7660 1005 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 7690 1045 20  0001 C CNN
F 3 "" H 7660 895 50  0001 C CNN
	1    7660 895 
	1    0    0    -1  
$EndComp
Text GLabel 7460 895  0    50   Input ~ 0
GND
Text GLabel 7860 895  2    50   Input ~ 0
GND
Text GLabel 4135 3020 2    50   Input ~ 0
DATA12
Text GLabel 2935 2870 0    50   Input ~ 0
ARDUINO4
$Comp
L fab:ATtiny3216 U1
U 1 1 6081D19B
P 3535 2795
F 0 "U1" H 3535 3762 50  0000 C CNN
F 1 "ATtiny3216" H 3535 3671 50  0000 C CNN
F 2 "fab:fab-SOIC-20_7.5x12.8mm_P1.27mm" H 3535 2795 50  0001 C CIN
F 3 "" H 3535 2795 50  0001 C CNN
	1    3535 2795
	1    0    0    -1  
$EndComp
$Comp
L fab:RES-US1206FAB R9
U 1 1 608534B3
P 8480 1175
F 0 "R9" H 8480 1369 45  0000 C CNN
F 1 "0Ω" H 8480 1285 45  0000 C CNN
F 2 "fab:fab-R1206FAB" H 8510 1325 20  0001 C CNN
F 3 "" H 8480 1175 50  0001 C CNN
	1    8480 1175
	1    0    0    -1  
$EndComp
Text GLabel 8280 1175 0    50   Input ~ 0
PWM3
Text GLabel 8680 1175 2    50   Input ~ 0
PWM3
Text GLabel 4135 2420 2    50   Input ~ 0
SCL
Text GLabel 4135 2570 2    50   Input ~ 0
SDA
Text GLabel 5320 4445 0    50   Input ~ 0
SCL
Text GLabel 5320 4545 0    50   Input ~ 0
SDA
Wire Notes Line
	4950 4160 5820 4160
Wire Notes Line
	5820 4160 5820 4810
Wire Notes Line
	5820 4810 4950 4810
Wire Notes Line
	4950 4810 4950 4160
Text Notes 5025 4285 0    50   ~ 0
I2C\n
Text GLabel 5455 5055 0    50   Input ~ 0
ARDUINO0
Text GLabel 5455 5155 0    50   Input ~ 0
ARDUINO1
Text GLabel 5455 5465 0    50   Input ~ 0
ARDUINO2
Text GLabel 5455 5565 0    50   Input ~ 0
ARDUINO3
Text GLabel 2935 2270 0    50   Input ~ 0
ARDUINO0
Text GLabel 2935 2420 0    50   Input ~ 0
ARDUINO1
Text GLabel 4135 2870 2    50   Input ~ 0
ARDUINO3
Wire Notes Line
	5830 5015 5830 5870
Wire Notes Line
	4920 5015 4930 5015
Wire Notes Line
	4930 5015 4930 5010
Text Notes 5010 6200 0    50   ~ 0
Extra pins\n
Wire Notes Line
	4920 5870 4920 5015
$Comp
L fab:PINHD-1x02-SMD-HEADER M5
U 1 1 60872890
P 5320 4945
F 0 "M5" H 5320 4945 45  0001 C CNN
F 1 "PINHD-1x02-SMD-HEADER" H 5320 4945 45  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical_SMD_Pin1Left" H 5350 5095 20  0001 C CNN
F 3 "" H 5320 4945 50  0001 C CNN
	1    5320 4945
	1    0    0    -1  
$EndComp
Wire Notes Line
	5830 5010 5830 4860
Wire Notes Line
	5830 4860 4925 4860
Wire Notes Line
	4925 5020 4920 5020
Wire Notes Line
	4925 4860 4925 5020
Text GLabel 4135 2270 2    50   Input ~ 0
ARDUINO2
$Comp
L fab:PINHD-1x03-SMD-HEADER M8
U 1 1 608939C3
P 5590 3970
F 0 "M8" H 5590 3970 45  0001 C CNN
F 1 "PINHD-1x03-SMD-HEADER" H 5590 3970 45  0001 C CNN
F 2 "fab:fab-1X03SMD" H 5620 4120 20  0001 C CNN
F 3 "" H 5590 3970 50  0001 C CNN
	1    5590 3970
	1    0    0    -1  
$EndComp
$Comp
L fab:PINHD-1x02-SMD-HEADER M6
U 1 1 608A08B2
P 5455 5555
F 0 "M6" H 5455 5555 45  0001 C CNN
F 1 "PINHD-1x02-SMD-HEADER" H 5455 5555 45  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical_SMD_Pin1Left" H 5485 5705 20  0001 C CNN
F 3 "" H 5455 5555 50  0001 C CNN
	1    5455 5555
	1    0    0    -1  
$EndComp
$Comp
L fab:PINHD-1x02-SMD-HEADER M7
U 1 1 608A4A68
P 5455 5965
F 0 "M7" H 5455 5965 45  0001 C CNN
F 1 "PINHD-1x02-SMD-HEADER" H 5455 5965 45  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical_SMD_Pin1Left" H 5485 6115 20  0001 C CNN
F 3 "" H 5455 5965 50  0001 C CNN
	1    5455 5965
	1    0    0    -1  
$EndComp
Text GLabel 5460 5910 0    50   Input ~ 0
5V
Text GLabel 5460 6010 0    50   Input ~ 0
GND
$Comp
L fab:PINHD-1x02-SMD-HEADER M9
U 1 1 608A6D9F
P 5460 6410
F 0 "M9" H 5460 6410 45  0001 C CNN
F 1 "PINHD-1x02-SMD-HEADER" H 5460 6410 45  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical_SMD_Pin1Left" H 5490 6560 20  0001 C CNN
F 3 "" H 5460 6410 50  0001 C CNN
	1    5460 6410
	1    0    0    -1  
$EndComp
Wire Notes Line
	4915 5875 4915 6275
Wire Notes Line
	4915 6275 5840 6275
Wire Notes Line
	5835 6275 5835 5880
Wire Notes Line
	5835 5880 5820 5880
$EndSCHEMATC
