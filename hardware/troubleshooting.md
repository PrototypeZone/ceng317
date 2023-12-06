# Troubleshooting your Hardware Project
1. Do the labs of CENG 153 work?
2. [Inspect your PCB](https://github.com/PrototypeZone/ceng317/blob/main/hardware/pcb/inspection.md)https://github.com/PrototypeZone/ceng317/blob/main/hardware/pcb/inspection.md
3. Power down your pi properly ```sudo shudown -h now``` and wait for green activity LED to show disk activity, for the red power LED to turn off and then back on, then for the green LED to blink 10 times before removing power.
4. Connect your sensor to your circuit board with a cable.
5. Power up your Raspberry Pi
6. ```i2cdetect -y 1```
7. If address not shown, Power down your pi properly
8. remove your circuit board
9. Connect your sense hat
10. Power up your Raspberry Pi
11. ```i2cdetect -y 1```
12. Should be showing the sense hat 6a 5f etc
13. Power down your pi properly
14. Connect your sensor directly [Raspberry pi pinout](https://pinout.xyz/) [QWIIC colour scheme](https://www.sparkfun.com/qwiic#faqs)
15. ```i2cdetect -y 1```
16. 
