# Troubleshooting your Hardware Project
1. Do the labs of CENG 153 work?
2. The image for the SD card is available [here](https://humberital-my.sharepoint.com/:u:/g/personal/mdrk0011_humber_ca/EWYsb95bC2RHuaZOORUl8VwB-CXncsMfPb_dhYUNbys-Aw?e=jIsr3X).
3. [Inspect your PCB](https://github.com/PrototypeZone/ceng317/blob/main/hardware/pcb/inspection.md)https://github.com/PrototypeZone/ceng317/blob/main/hardware/pcb/inspection.md
4. Power down your pi properly ```sudo shudown -h now``` and wait for green activity LED to show disk activity, for the red power LED to turn off and then back on, then for the green LED to blink 10 times before removing power.
5. Connect your sensor to your circuit board with a cable.
6. Power up your Raspberry Pi
7. ```i2cdetect -y 1```
8. If address not shown, Power down your pi properly
9. remove your circuit board
10. Connect your sense hat
11. Power up your Raspberry Pi
12. ```i2cdetect -y 1```
13. Should be showing the sense hat 6a 5f etc
14. Power down your pi properly
15. Connect your sensor directly [Raspberry pi pinout](https://pinout.xyz/) [QWIIC colour scheme](https://www.sparkfun.com/qwiic#faqs)
16. ```i2cdetect -y 1```
17. Look at the code for the humidity sensor on the sense hat https://github.com/davebm1/c-sense-hat/blob/main/humidity.c it first checks i2c_smbus_read_byte_data(fd, WHO_AM_I) look into what your sensor reports back.
```c
/**For the HTS221*/   
#define DEV_PATH "/dev/i2c-1"   
#define DEV_ID 0x5F   
#define WHO_AM_I 0x0F   
fd = open(DEV_PATH, O_RDWR);
ioctl(fd, I2C_SLAVE, DEV_ID);
printf("\nThe device at %#x identifies as %#x\n",DEV_ID,i2c_smbus_read_byte_data(fd, WHO_AM_I));
//Should provide
//The device at 0x5f identifies as 0xbc
 
/**For the LPS25H*/
#define DEV_PATH "/dev/i2c-1"
#define DEV_ID 0x5c
#define WHO_AM_I 0x0F
fd = open(DEV_PATH, O_RDWR);
ioctl(fd, I2C_SLAVE, DEV_ID);
printf("\nThe device at %#x identifies as %#x\n",DEV_ID,i2c_smbus_read_byte_data(fd, WHO_AM_I));
//Should provide
//The device at 0x5c identifies as 0xbd
```
17. What does your device at DEV_ID 0x__ identify as?
