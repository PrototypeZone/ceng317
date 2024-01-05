# Project Introduction

## Weeks
See the [Critical Path](summer2024criticalpath.md)

## Background
Our focus has been on six areas of ongoing/continuing multi-year work. In these areas, we welcomed brief project charters from industry that proposed the scope, mandate, and contain the system specification (design approach and requirements).

1. Facilities: Bicycle Rental/Parking Lot/Vision System
2. Building Automation: Greenhouse/SolarPanel/Home
3. Consumer: Entertainment Protocol DMX/Baby Monitoring Project
4. Education: Robust Hackable Educational Project
5. Robotics: Control/Navigation/Dashboard
6. Health and Wellness: Wearable 

Currently getting up to speed with the state of the art has been a challenge let alone making a contribution. For example, a modern parking lot will contain vehicle sensors, license plate recognition, RFID/transponders, etc.

Regarding a more accessible project example, there was a time that one would go to a bicycle rental company's shack, provide something of value as a deposit and the person working at the shack would provide a bicycle on the understanding that you would return it along with payment for the amount of time that you used it in exchange for return of your deposit.
![Toronto Island](https://www.torontoisland.com/images/bike/IMG_1697.JPG)

Times have changed, now you use your smart phone to provide your credit card information to the bicycle rental company and then you are provided the code to unlock a bicycle and you are charged based on when you next lock it up.
![dropbike](https://humber.ca/staff/sites/default/files/sub-images/dropbike%20lake%20and%20north.jpg)

The Computer Engineering Technology capstone consists of creating project similar to this. In this example there is a lock mechanism, a set of buttons to enter a code, lights and sound to provide feedback.
![Bikeshare](media/bikeshare.jpg)

In CENG 317, students learn how to create the embedded modules. In CENG 322, students learn how to write the corresponding app. In CENG 355, the group would package everything up together as a functioning prototype.
![NetworkArchitectureFall2018separate](media/NetworkArchitectureFall2018separate.jpg)

- Overall project maximum dimensions of 12 13/16" x 6" x 2 7/8" (32.5cm x 15.25cm x 7.25cm) which represents the space below the tray in the parts kit.
- Project case to be designed for 3D printing/laser cutting.
- Keeping safety and Z462 in mind, the highest AC voltage that is to be used is 16Vrms from a wall adapter from which +/- 15V or as high as 45 VDC can be obtained. Maximum power consumption is to be 20 Watts.
- We work with prototypes and prototypes are not to be left powered unattended.

## Project Examples
- Automated plant watering system
- Parking lot
- Living environment monitoring system
- Pet food dispenser
- Aquarium monitor
- Wellness monitor
- Envirorover which measures temperature, humidity, and light as it moves
- Waste bin monitoring system
- Sailing race start signal system as per [page 41](https://www.nsyc.net/wp-content/uploads/RC_SEMINAR_NSYC.pdf)   
    - [Drawing](https://buckeyelakeyc.com/wp-content/uploads/2020/02/RC_Drawing.png), [Actual](http://www.sail.ie/speedtips/speedtips_images/favour18.jpg)
    - -6 *Attention Signal* 4 Horns
    - -5 *Warning Signal* Red Shape up, Horn 
    - -4 *Preparatory Signal* P Flag Up, Horn 
    - -1 *One to go warning* P Flag Down, Long Horn 
    - 0 *Start* Red Shape down, Horn
    - If there is a false start X flag up as per [page 50](https://www.nsyc.net/wp-content/uploads/RC_SEMINAR_NSYC.pdf)
- Autonomous Electric Skidsteer
- IoT Home Appliance
- Traffic light
- Traffic counter
- Vending Machine
- Book/Equipment Sign-out System
- Depending on how CENG 260 goes: https://github.com/alexa/avs-device-sdk, https://www.mashgin.com/product/mashgin-kiosk
- Air monitoring
- Next bus sign
- Touchfree washroom
- Solar battery charger
- Water bottle filling station
- [Elevator](https://hackaday.com/2021/02/04/reverse-engineering-an-elevator-control-panel-results-in-clicky-goodness/)
- [Prescription Kiosk](https://humber.ca/staff/announcement/spotrx-pharmacy-now-available-north-campus)
- Fire protection system
- Golf simulator
- Trainable robot arm   

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

## Your individual project in CENG 317
- Each student will choose at least one [additional sensor/effector](sensorseffectors.md)
- Each student creates a custom interface board to fit between their Sense Hat and their Broadcom Single board computer to connect their chosen additional sensor or effector to their Raspberry Pi. A case should be lasercut/3D printed to accomodate their boards, sensor, and computing device within the overall maximum project dimensions.
   ![pcbstacking](media/pcbstacking.png)
- Standoffs, screws to be specified on [Bill Of Materials](hardware/bom.md)   
- Although it is not always the situation, if all the students in a group formed in CENG 322 software project are also in the same section in CENG 317 hardware project, the students may combine their designs into one PCB design of which multiple are made. This is also an opportunity to ensure that code written can operate with multi threading.
- Ideally the PCB would comply with the [Raspberry Pi Hardware Attached on Top specifications](https://github.com/raspberrypi/hats) including an [EEPROM](https://www.digikey.ca/en/products/base-product/onsemi/488/CAT24C256/56536) but the Raspberry Pi only checks I2C address 0x50 for eeproms so currently it is not designed for stacking hats.
- It will include a [Stacking Header](https://www.digikey.com/en/products/detail/adafruit-industries-llc/1979/6238003).
- It will include a [Qwiic socket](https://www.digikey.ca/en/products/detail/sparkfun-electronics/PRT-14417/7652746) ([alternate equivalent part](https://www.digikey.ca/en/products/detail/jst-sales-america-inc/SM04B-SRSS-TB/926710))to make use of [Qwiic Cables](https://www.digikey.ca/en/products/detail/sparkfun-electronics/KIT-15081/9770723).
- Use [KiCad](https://github.com/PrototypeZone/ceng317/tree/main/hardware/pcb) for the design.
- We also add: a spare header, a 2N4124 NPN transistor with a 2.2 kOhm resistor between pin 11 -- GPIO17 and the base of the transistor, connect the emitter to the ground, and connect an LED with a series 220 Ohm resistor on the collector side to 3.3V.
