/*  C code to read whoami registers from say the
 *  Raspberry Pi Sense HAT add-on board (HTS221 sensor)
 *  Inspired by: https://github.com/davebm1/c-sense-hat/blob/main/humidity.c
 *  Referenced: https://www.includehelp.com/c/working-with-hexadecimal-values-in-c-programming-language.aspx
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

#define CTRL_REG1 0x20

int main(void) {
    int fd = 0;
    uint8_t status = 0;

    /* open i2c bus */
    if ((fd = open(DEV_PATH, O_RDWR)) < 0) {
        perror("Unable to open i2c bus");
        exit(1);
    }

    fprintf(stdout,"Use i2cdetect -y 1 to determine what addresses have peripherals, then enter an i2c address\n");
    fprintf(stdout,"Examples:\n" 
        "relay\t\t0x18\n"
        "mprls\t\t0x18\n"
        "lsm9ds1_mg\t0x1C\n"
        "cap1203\t\t0x28\n"
        "vl53l1x\t\t0x29\tvl53l4cd\t0x29\n"
        "nau7802\t\t0x2A\n"
        "ism330\t\t0x30\n"
        "tcs3400\t\t0x39\n"
        "tmp117\t\t0x48\n"
        "sgp40\t\t0x59\n"
        "lps25h\t\t0x5C\n"
        "drv8835\t\t0x5D\n"
        "hts221\t\t0x5F\n"
        "i2cdB\t\t0x64\n"
        "icm20948\t0x69\n"
        "lsm9ds1_ag\t0x6A\n"
        "lsm6dso\t\t0x6B\n"
        "bme280\t\t0x77\tgroveh2olevel\t0x77\tens160\t0x77\n"
        "enter a hexidecimal i2c address (e.g. 5F): ");
    int i2caddr;
    scanf("%x",&i2caddr);
    
    /* configure i2c slave */
    if (ioctl(fd, I2C_SLAVE, i2caddr) < 0) {
        perror("Unable to configure i2c slave device");
        close(fd);
        exit(1);
    }

    fprintf(stdout,"Read the datasheet to determine what register contains the device id, then enter it\n");
    fprintf(stdout,"Examples:\n"
        "relay\t\t0x?\n"
        "mprls\t\t0x?\n"
        "lsm9ds1_mg\t0x0F\n"
        "cap1203\t\t0x?\n"
        "vl53l1x\t\t0x?\tvl53l4cd\t0x?\n"
        "nau7802\t\t0x?\n"
        "ism330\t\t0x?\n"
        "tcs3400\t\t0x92\n"
        "tmp117\t\t0x?\n"
        "sgp40\t\t0x?\n"
        "lps25h\t\t0x0F\n"
        "drv8835\t\t0x?\n"
        "hts221\t\t0x?\n"
        "i2cdB\t\t0x?\n"
        "icm20948\t0x?\n"
        "lsm9ds1_ag\t0x0F\n"
        "lsm6dso\t\t0x?\n"
        "bme280\t\t0x?\tgroveh2olevel\t0x?\tens160\t0x?\n"
        "enter a hexidecimal register (e.g. 0F): ");
    int whoami;
    scanf("%x",&whoami);
    
    printf("\nThe device at %#X, in register %#X, identifies as %#X\n",i2caddr,whoami,i2c_smbus_read_byte_data(fd, whoami));
 
    //This should provide for the
    //relay:       The device at 0x18, in register 0x0F, identifies as 0x0?
    //mprls:       The device at 0x18, in register 0x, identifies as 0x
    //lsm9ds1_mg:  The device at 0x1C, in register 0x0F, identifies as 0x3D
    //cap1203:     The device at 0x28, in register 0x, identifies as 0x
    //vl53lseries: The device at 0x29, in register 0x0F, identifies as 0x?
    //nau7802:     The device at 0x2A, in register 0x, identifies as 0x
    //ism330:      The device at 0x30, in register 0x, identifies as 0x
    //tcs3400:     The device at 0x39, in register 0x92, identifies as 0x90
    //tmp117:      The device at 0x48, in register 0x, identifies as 0x
    //sgp40:       The device at 0x59, in register 0x, identifies as 0x
    //lps25h:      The device at 0x5C, in register 0x0F, identifies as 0xBD
    //drv8835:     The device at 0x5D, in register 0x, identifies as 0x
    //hts221:      The device at 0x5F, in register 0x0F, identifies as 0xBC
    //i2cdB:       The device at 0x64, in register 0x, identifies as 0x
    //icm20948:    The device at 0x69, in register 0x, identifies as 0x
    //lsm9ds1_ag:  The device at 0x6A, in register 0x0F, identifies as 0x68
    //lsm6dso:     The device at 0x6B, in register 0x, identifies as 0x
    //bme280:      The device at 0x77, in register 0x, identifies as 0x

    /* Power down the device */
    i2c_smbus_write_byte_data(fd, CTRL_REG1, 0x00);
    close(fd);

    return (0);
}
