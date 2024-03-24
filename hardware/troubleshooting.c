/*  C code to read whoami registers from say the
 *  Raspberry Pi Sense HAT add-on board (HTS221 sensor)
 *  Inspired by https://github.com/davebm1/c-sense-hat/blob/main/humidity.c
 *  sudo raspi-config --> interfacing options --> enable i2c
 *  sudo apt install libi2c-dev
 *  Build with:  gcc -Wall -O2 troubleshooting.c -o troubleshooting -li2c
 *               or just 'make'
 */

#include <fcntl.h>
#include <i2c/smbus.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define DEV_PATH "/dev/i2c-1"
/**For the HTS221*/   
//#define I2C_ADDR 0x5F
#define HTS221_DEV_ID 0xBC
/**For the LPS25H*/
//#define I2C_ADDR 0x5c
#define LPS25H_DEV_ID 0xBD
/**For the relay*/
//#define I2C_ADDR 0x18
/**For the VL53Lseries*/
#define I2C_ADDR 0x29

#define WHO_AM_I 0x0F

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21

void delay(int);

int main(void) {
    int fd = 0;
    uint8_t status = 0;

    fprintf(stdout,"Use i2cdetect -y 1 to determine what addresses have peripherals, then enter an i2c address\t\n");
    fprintf(stdout,"Examples:\n 
        mprls\t0x18\n
        cap1203\t0x28\n
        vl53l1x\t0x29\tvl53l4cd\t0x29\n
        nau7802\t0x2a\n
        ism330\t0x30\n
        tmp117\t0x48\n
        sgp40\t0x59\n
        drv8835\t0x5d\n
        hts221\t0x5f\n
        i2cdB\t0x64\n
        icm20948\t0x69\n
        lsm6dso\t0x6b\n
        bme280\t0x77\tgroveh2olevel\t0x77\tens160\t0x77\n");
    hex i2caddr; //?
    fscanf("%x",i2caddr);
    
    /* open i2c comms */
    if ((fd = open(DEV_PATH, O_RDWR)) < 0) {
        perror("Unable to open i2c device");
        exit(1);
    }

    /* configure i2c slave */
    if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Unable to configure i2c slave device");
        close(fd);
        exit(1);
    }

    printf("\nThe device at %#x identifies as %#x\n",I2C_ADDR,i2c_smbus_read_byte_data(fd, WHO_AM_I));

    //For the HTS221 Should provide
    //The device at 0x5f identifies as 0xbc
 
    //For the LPS25H Should provide
    //The device at 0x5c identifies as 0xbd

    //For the relay Should provide
    //The device at 0x5c identifies as 0x0?

    //For the VL53Lseries Should provide
    //The device at 0x5c identifies as 0x?

    /* check we are who we should be */
    if (i2c_smbus_read_byte_data(fd, WHO_AM_I) != HTS221_DEV_ID) {
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
