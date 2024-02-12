# Sensor (sense the environment) and Effector (cause an effect in the environment) Choices
When choosing a sensor/effector consider your interest, the cost (of it and additional components required), availability (in stock vs backordered), the I2C address, ease of development, and whether it duplicates something already available on the Sense Hat.   
The following IMUs, Accel/Magnet/Gyros duplicate SenseHat functionality:    
https://www.sparkfun.com/categories/tags/qwiic-movement   
Typical choices are I2C sensors/effectors, Dallas one wire and SPI sensors/effectors often require more hardware/software work, while simple On/Off digital sensors/effectors such as breakbeam, IR proximity, and capacitive touch are too simple unless multiples are considered. Examples:   
https://www.sparkfun.com/categories/tags/qwiic-imaging   
https://www.sparkfun.com/categories/tags/qwiic-distance   
https://www.sparkfun.com/categories/tags/qwiic-environmental   
https://www.sparkfun.com/categories/tags/qwiic-other   
However some Qwiic options are problematic for example:   
https://www.sparkfun.com/categories/tags/qwiic-gps   
The 0x10 XA1110 GPS Breakout it not a good choice since we don't have access to a solid GPS signal in the classroom.   
Note: Stemma QT uses the same 4 Pin JST SH 1.0mm pitch connectors as Qwiic (Black for GND, Red for V+, Blue for SDA, Yellow for SCL). Keep in mind the logic on the Raspberry Pi is 3.3V only.   
Note: Some Qwiic breakout boards require additional connections.   
Note: Purchasing from SparkFun directly with regular shipping is not reliable/fast enough given that we make our choices in the first couple of weeks of class and need them by reading week. Purchasing via DigiKey for SparkFun items they have in stock usually is fast enough.

## Your Existing Sense Hat
In addition to power and ground the sense hat uses:   
pin 3 -- GPIO2 or SDA   
pin 5 -- GPIO3 or SCL   
pin 16 -- GPIO23 (IMU Interrupt)   
pin 18 -- GPIO24 (IMU Interrupt)   
pin 22 -- GPIO25 (Atmel Prog Reset)   
pin 24 -- GPIO8 (Atmel Chip Reset)   
pin 27 -- GPIO0 (or maybe ID_SD or maybe EEPROM SDA or maybe HAT ID)   
pin 28 -- GPIO1 (or maybe ID_SC or maybe EEPROM SCL or maybe HAT ID)   
LED2472G and navigation pad connected via an Atmel ATTINY88 (0x46)   
LSM9DS1 IMU magnetometer 0x1c(0x1e) and accelerometer/gyroscope 0x6a(0x6b)   
[9DoF Stick IMU - LSM9DS1 SparkFun Retired Product equivalent to that on the sense hat](https://www.sparkfun.com/products/13944)   
LPS25H Pressure/Temperature sensor (0x5c)   
HTS221 Humidity/Temperature sensor (0x5f)   

## IC Part number with DigiKey purchasing link, Descriptive Name, DigiKey stock status, I2C address, DEV_ID, footprint, buyer beware

|Choice number|Part Number|Name|DigiKey stock status|I2C address|WHO_AM_I register|DEV_ID|footprint|Note|
|-------------|-----------|----|--------------------|-----------|-----------------|------|---------|----|
|-4| LED2472G|  ||0x46|0x|0x|Part of SenseHat||
|-3| LSM9DS1|  ||0x1c|0x|0x|Part of SenseHat||
|-2| LPS25H|  ||0x5c|0xf|0x5c|Part of SenseHat||
|-1| HTS221|  ||0x5f|0xf|0x5f|Part of SenseHat||
|0 |IC| In stock| 1/31/2024 out of stock| Retired Product|0x|0x| 0.8"|additional component/wiring required|
|1| SGP40| Air ||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|2| ENS160| Air quality (the replacement for the popular, but now-discontinued CCS811 https://www.adafruit.com/product/5606), also available as ENS160/BME280 Air quality, THP||0x53|0x|0x|Qwiic mounting holes 0.8" apart|
|4| BME680| Gas, Temp Humid Pressure||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|5| 4245 PSOC->DRV8835| DC Motor *requires motor, power, and mount*||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|6| 4245 PSOC->DRV8835| Stepper Motor *requires motor, power, and mount*||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|7| ADS1015|ADC for liquid level||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|8| |MicroPressure||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|9| MAX30101|Oximeter/Rate MAX30102? Oximeter and Heart Rate Sensor (0x57)||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|10|ID-12LA|RFID Reader||0x|0x|0x|Qwiic mounting holes 0.8" apart|Initial Configuration via Arduino|
|11|ST25DV64KC|RFID Tag||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|12|VEML6030|Light||0x48|0x|0x|Qwiic mounting holes 0.8" apart|
|13|VEML7700|Light||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|14|AS7262|Visible Spectrum||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|15|AS7263|NIR spectrum||0x49|0x|0x|Qwiic mounting holes 0.8" apart|
|16|VCNL4040|Proximity||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|17|PL-N823|PIR||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|18|TMF8821|ToF||0x|0x|0x|Qwiic mounting holes 0.8" apart|
|19|VL53L1X|ToF||0x18|0x0f|0x29|Qwiic mounting holes 0.8" apart|
|20|VL53L4CD|ToF||0x18|0x0f|0x29|Qwiic mounting holes 0.8" apart|
|21|VL53L5CX|ToF||0x18|0x0f|0x29|Qwiic mounting holes 0.8" apart|
|22|OPT4048DTSR|Color||0x|0x|0x|Qwiic mounting holes 0.8" apart|

### No mount 
23. MAX30101 & MAX32664 https://www.sparkfun.com/products/15219

### Mounting holes 1.2" wide, 1.6" height (30.48mm x 40.64mm)
24. zio oled https://www.sparkfun.com/products/15890

### Mounting holes .8" wide, 1.2" height (20.32mm x 30.48mm) 
25. NAU7802 scale https://www.sparkfun.com/products/15242 and load cell? *requires load cell and mount*

### Mounting holes 2.05" wide, .8" height (52.07mm x 20.32mm)
26. Relay https://www.sparkfun.com/products/15093 and solenoid?

### Mounting holes 44mm wide, 9mm height
27. SparkFun Qwiic OLED (0x3C for 128x32) https://www.sparkfun.com/products/17153

### Mounting holes 1.3" wide, .8" height
28. CAP1203 touch https://www.sparkfun.com/products/15344

### Mounting holes 1" wide, .7" height
29. HX711 Scale https://www.sparkfun.com/products/13879  *requires load cell, mount, pcb update*

### Mounting holes .7" wide
30. AK9753 Human https://www.sparkfun.com/products/14349

### Need to find the footprints, perhaps using KiCad to import Eagle files
1.  INA219 current https://www.adafruit.com/product/904
2.  RCWL-1601 Ultrasonic/qwiic HCSR04  https://www.adafruit.com/product/4742, https://www.sparkfun.com/products/17777
3.  BH1750 https://www.addicore.com/products/bh1750-light-intensity-sensor [BH1750 16-bit Ambient Light Sensor](https://learn.adafruit.com/adafruit-bh1750-ambient-light-sensor?view=all) Default I2C address 0x23 (alternate 0x5C)
4.  Micro LiDAR https://www.sparkfun.com/products/retired/14786
5.  Qwiic 4 character Alphanumeric
6.  TCA9534 GPIO 0x27
7.  12 Button keypad
8.  Qwiic joystick
9.  Qwiic Twist rgb rotary encoder
10. Qwiic 16x2 LCD
11. Total Dissolved Solids-ADC Converter (CQRSENTDS01 and ADS1115) (0x48, switchable to 0x49)
12. Grove i2c [water level](https://canada.newark.com/seeed-studio/101020635/water-level-sensor-board-arduino/dp/42AK5700)
13. TCS34725 Colour Sensor (0x29)

### Stemma QT
1.  LED Arcade Button 1x4 STEMMA QT
2.  NeoKey Four Mechanical Key Switches with NeoPixels STEMMA QT
3.  LTR-303 Light Sensor STEMMA QT
4.  AS7341 Color Sensor STEMMA QT
5.  TSL2591 Light Sensor STEMMA QT Digital Luminosity/Lux/Light Sensor (0x39-floating, 0x29-gnd, or 0x49-3.3V)
6.  ANO Rotary Navigation Wheel Stemma QT Adapter + ANO Encoder
7.  AD5693R 16-Bit DAC STEMMA QT
8.  EMC2101 PC Fan Controller STEMMA QT
9.  PCF8591 Quad 8-bit ADC + 8-bit DAC STEMMA QT
10. SGP30 Air Quality Sensor Breakout VOC and eCO2 STEMMA QT
11. Turing Complete Labs 10 Digit Monochrome LCD Display STEMMA QT
12. IS31FL3741 13x9 PWM RGB LED Matrix Driver STEMMA QT
13. TCA8418 Keypad Matrix and GPIO Expander STEMMA QT
14. NeoSlider Slide Potentiometer with 4 NeoPixels STEMMA QT

### Additional Components required
1. Qwiic Wii Nunchuck Adapter - if you have a nunchuck
2. PC Joystick STEMMA QT - if you have a joystick with subd 
3. LC709203F LiPoly / LiIon Fuel Gauge and Battery Monitor STEMMA QT
4. MAX17048 LiPoly / LiIon Fuel Gauge and Battery Monitor STEMMA QT
5. NeoDriver NeoPixel Driver Stemma QT
6. TSC2007 Resistive Touch Screen Controller STEMMA QT
7. [Conversion of cheap optical mouse to robot odometer](https://blog.jgc.org/2012/09/conversion-of-cheap-optical-mouse-to.html)   
[Further to the above](https://www.instructables.com/Interfacing-With-a-Mouse-Sensor-ADNS-3050/), [alternate](https://www.hackteria.org/wiki/Hacked_Optical_Mouse).   

### Using the [SparkFun Qwiic Adapter for non-qwiic sensors](https://www.sparkfun.com/products/14495)
   - Suplemental (to the SenseHat) choices:   
    [Particle Sensor - MAX30105](https://www.sparkfun.com/products/16474)   
    [Air Quality Sensor - CCS811 SparkFun Retired Product](https://www.sparkfun.com/products/retired/14181)   
    [ToF Range Finder - VL6180](https://www.sparkfun.com/products/12785)   
    [Haptic Motor Driver - DRV2605L](https://www.sparkfun.com/products/14538)   
    [Micro OLED Display](https://www.sparkfun.com/products/13003)   
    [RGB and Gesture Sensor - APDS-9960](https://www.sparkfun.com/products/12787)   
    [RGB Light Sensor - ISL29125](https://www.sparkfun.com/products/12829)   
    [LED Driver - LP55231](https://www.sparkfun.com/products/13884)   
    [DAC Breakout - MCP4725](https://www.sparkfun.com/products/12918)   
    [16 Output I/O Expander - SX1509](https://www.sparkfun.com/products/13601)   
    [Battery Babysitter - BQ24075](https://www.sparkfun.com/products/13777)   

### Austrailian options
[https://core-electronics.com.au/piicodev.html](https://core-electronics.com.au/piicodev.html)   
https://pcbartists.com/product/i2c-decibel-sound-level-meter-module/ with [qwiic adapter](https://www.digikey.ca/en/products/detail/sparkfun-electronics/DEV-14495/7942483) *requires pcb update*   

### Past sensor/effector address choices to prevent bus conflicts
- Suplemental (to the SenseHat) choices:   
ADC needed for analog sensors   
Relay or drivers required for higher current draw devices, freewheeling diodes for solenoids, consider buffers for servos   
Si4713 FM Transmitter with RDS (0x11)   
VCNL40x0 proximity sensor (0x13)   
Chirp! Water sensor (0x20)   
MCP23008 I2C GPIO expander (0x22)   
MCP23017 I2C GPIO expander (0x23)   
VL53L0x ToF distance (0x24 software selectable)   
TCS34725 color sensor (0x29)   
CAP1188 8-channel Capacitive Touch (0x2A)   
FT6x06 Capacitive Touch Driver (0x38)   
VEML6070 UV Index (0x39)   
SSD1305 monochrome OLED (0x3C)   
SSD1306 monochrome OLED (0x3D)   
STMPE610/STMPE811 Resistive Touch controller (0x41)   
ISL29125 Color Sensor (0x44)   
TMP006 IR Temperature sensor (0x46)   
TMP006 is a retired product https://www.sparkfun.com/products/retired/11859, it is also discontinued here https://www.adafruit.com/product/1296 and TMP007 here https://www.adafruit.com/product/2023, even Melexis Contact-less Infrared Sensor - MLX90614 3V - MLX90614ESF-BAA is out of stock https://www.adafruit.com/product/1747   
TMP007 IR Temperature sensor (0x47)   
YL-40 PCF8591 (0x48) https://www.adafruit.com/product/4648   
TSL2561 light sensor (0x49)   
ADS1115 4-channel 16-bit ADC (0x4B)   
INA219 High-Side DC Current/Voltage sensor (0x4C)   
MB85RC I2C FRAM (0x50)   
Nintendo Nunchuck controller (0x52)   
MAX3010x Pulse & Oximetry sensor (0x57)   
TPA2016 I2C-controlled Amplifier (0x58)   
DRV2605 Haptic Motor Driver (0x5A)   
CCS811 VOC sensor (0x5B)   
MPR121 12-point capacitive touch sensor (0x5D)   
TEA5767 Radio receiver (0x60)   
Si5351A Clock Generator (0x61)   
MCP4725A1 12-bit DAC (0x62)   
MCP4725A2 12-bit DAC (0x64)   
MCP4725A3 12-bit DAC (0x66)   
DS3231 RTC (0x68)   
AMG8833 IR Thermal Camera Breakout (0x69)   
TCA9548 1-to-8 I2C Multiplexer (0x70)   
HT16K33 LED Matrix Driver (0x72)   
IS31FL3731 144-LED CharliePlex driver (0x74)   
PCA9685 16-channel PWM driver (0x75)   
PN532 NFC/RFID reader (Use UART pins 8:TX and 10:RX)   

### Unclear purpose
1. ScoutMakes FM Radio Board STEMMA QT   
2. DS3502 Digital 10K Pot STEMMA QT   
3. DS1841 Digital 10K Pot STEMMA QT   
4. AW9523 GPIO Expander   
5. PCF8575 16 GPIO Expander STEMMA QT   

### Duplication of SenseHat
1.  SHTC3 Humidity
2.  DHT20 Temp Humid (non qwiic)
3.  BME280 Temp Humid Pressure
4.  TMP102 Temp
5.  TMP117 Temp
6.  STTS22H Temp
7.  MAX30205MTA Contact Body temp
8.  BMI270 IMU
9.  ICM-20948 IMU
10. ISM330DHCX, MMC5983MA IMU
11. BMA400 Accel
12. KX132 Accel
13. KX134 Accel
14. LSM6DSO Accel/Gyro
15. MLX90393 Magnet

### Using the [SparkFun Qwiic Adapter for non-qwiic sensors](https://www.sparkfun.com/products/14495)
   - Redudent (to the SenseHat) choices:   
    [9DoF IMU - MPU-9250](https://www.sparkfun.com/products/15335)   
    [6DoF IMU - LSM303C SparkFun Retired Product](https://www.sparkfun.com/products/retired/13303)   
    [6DoF IMU - LSM6DS3](https://www.sparkfun.com/products/18020)   
    [Triple Axis Accelerometer - LIS3DH](https://www.sparkfun.com/products/13963)   
    [Triple Axis Magnetometer - MAG3110 SparkFun Retired Product](https://www.sparkfun.com/products/retired/12670)   
    [Triple Axis Magnetometer - MLX90393 SparkFun Retired Product](https://www.sparkfun.com/products/retired/14160)   
    [Compass Module - HMC6343](https://www.sparkfun.com/products/12916)   
    [Atmospheric Sensor - BME280](https://www.sparkfun.com/products/13676)   
    [Barometric Pressure Sensor - MS5803-14BA](https://www.sparkfun.com/products/12909)   
    [Barometric Pressure Sensor - T5403 SparkFun Retired Product](https://www.sparkfun.com/products/retired/12039)   
    [Humidity and Temperature Sensor - Si7021](https://www.sparkfun.com/products/13763)   
    [Digital Temperature Sensor - TMP102](https://www.sparkfun.com/products/13314)

### Past sensor/effector address choices to prevent bus conflicts
- Redudent (to the SenseHat) choices:   
MAG3110 3-Axis Magnetometer (0x0E)   
LIS3DH 3-axis accelerometer (0x18)   
LSM303 Accelerometer & Magnetometer (0x19 for accelerometer and *0x1E for magnetometer)   
MCP9808 temp sensor (0x1A)   
MMA845x 3-axis Accelerometer (0x1C)   
LSM9DS0 9-axis IMU (0x1D for Accel/Mag, *0x6A for Gyro)   
*LSM303 Accelerometer & Magnetometer (0x19 for accelerometer and *0x1E for magnetometer)   
FXOS8700 Accelerometer/Magnetometer (0x1F)   
FXAS21002 Gyroscope (0x21)   
BNO055 IMU (0x28)   
HTU21D-F Humidity/Temp Sensor (0x40)   
HDC1008 Humidity/Temp sensor (0x42)   
SHT31 Humidity/Temp sensor (0x45)   
TMP102 Temperature sensor (0x4A)   
ADXL345 3-axis accelerometer (0x53)   
AM2315 Humidity/Temp sensor (0x5C)   
*LSM9DS0 9-axis IMU (0x1D for Accel/Mag, *0x6A for Gyro)   
L3GD20H gyroscope (0x6B)   
MS5607/MS5611 Barometric Pressure (0x76)   
BME280 Temp/Barometric/Humidity (0x77)   
