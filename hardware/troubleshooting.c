/*
 *  C code to whoami registers from say the
 *  Raspberry Pi Sense HAT add-on board (HTS221 sensor)
 *
 *  sudo raspi-config --> interfacing options --> enable i2c
 *
 *  sudo apt install libi2c-dev
 *
 *  Build with:  gcc -Wall -O2 troubleshooting.c -o troubleshooting -li2c
 *               or just 'make'
 *
 *  Tested with:  Sense HAT v1.0 / Raspberry Pi 3 B+ / Raspbian GNU/Linux 10 (buster)
 *
 */

#include <fcntl.h>
#include <i2c/smbus.h>
#include <linux/i2c-dev.h>
//#include <i2c/smbus.h> //new
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define DEV_PATH "/dev/i2c-1"
/**For the HTS221*/   
//#define DEV_ID 0x5F
/**For the LPS25H*/
//#define DEV_ID 0x5c
/**For the relay*/
//#define DEV_ID 0x18
/**For the VL53Lseries*/
#define DEV_ID 0x29

#define WHO_AM_I 0x0F

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21

void delay(int);

int main(void) {
    int fd = 0;
    uint8_t status = 0;

    /* open i2c comms */
    if ((fd = open(DEV_PATH, O_RDWR)) < 0) {
        perror("Unable to open i2c device");
        exit(1);
    }

    /* configure i2c slave */
    if (ioctl(fd, I2C_SLAVE, DEV_ID) < 0) {
        perror("Unable to configure i2c slave device");
        close(fd);
        exit(1);
    }

    printf("\nThe device at %#x identifies as %#x\n",DEV_ID,i2c_smbus_read_byte_data(fd, WHO_AM_I));

    //For the HTS221 Should provide
    //The device at 0x5f identifies as 0xbc
 
    //For the LPS25H Should provide
    //The device at 0x5c identifies as 0xbd

    //For the relay Should provide
    //The device at 0x5c identifies as 0x0?

    //For the VL53Lseries Should provide
    //The device at 0x5c identifies as 0x?

    /* check we are who we should be */
    if (i2c_smbus_read_byte_data(fd, WHO_AM_I) != 0xBC) {
        printf("%s\n", "who_am_i error");
        close(fd);
        exit(1);
    }

    /* Power down the device */
    i2c_smbus_write_byte_data(fd, CTRL_REG1, 0x00);
    close(fd);

    return (0);
}

void delay(int t) {
    usleep(t * 1000);
}
