# ESE218 MEMS Pressure Sensor - Adafruit IO
Author: Kim Luong

## Parts Required
- 1 x NodeMCU 8266
- 1 x [BMP388](https://www.adafruit.com/product/3966)

## Connections
I2C used to read in data.
|BMMP288 | NodeMCU|
|:------:|:------:|
|  Vin   |  3.3V  |
|  GND   |  GND   |
|  SCK   |  D1    |
|  SDI   |  D2    |
 
## Setup Instructions
1. Download or clone the github repo to your computer. 
2. Follow [these instructions](https://docs.google.com/document/d/17QhpRgrozE3ZZsFBizJNyipnE-AXzO-qaewx7TUlNto/edit#heading=h.c6uv5nikp79h) setup your NodeMCU.
3. In the Arduino IDE, install the following libraries:
    - Adafruit BMP3XX Library 
    - Click on "Install All" to install all the dependencies
    ![image](https://user-images.githubusercontent.com/13370293/141351346-d3e8db05-a1d7-424b-ae94-4cfede99bd67.png)
    - Adafruit IO Arduino
    ![image](https://user-images.githubusercontent.com/13370293/141794987-151290ae-77a6-4a9b-80d6-f9b93450d9e4.png)
4. Flash the code in this repo onto the NodeMCU. You can do this by opening up ese_lab7_adafruit.ino in the ese218_lab7_adafruit folder.
5. Create an account at [io.adafruit](https://io.adafruit.com/).
6. Click **My Key**
  ![image](https://user-images.githubusercontent.com/13370293/141810450-eb952459-161e-4549-b77d-d8c24b09f5e5.png)
7. Going back to the Arduino IDE, modify config.h so it has the appropriate username and key.
  ![image](https://user-images.githubusercontent.com/13370293/141795754-0cc49a75-e0c7-4a65-9f48-768a1c3b0d46.png)
8. Back to the io.adafruit.com website, click on Dashboard > Welcome Dashboard (or a new one that you made). Under the gear icon on the right hand side, select **Create New Block** > **Line Chart**.  
![image](https://user-images.githubusercontent.com/13370293/141811275-90756bc9-85ad-4972-82bd-63e98c0e584f.png)
10. Create a new feed called "pressure" (all lowercase). Select it and click "Next step >"
  ![image](https://user-images.githubusercontent.com/13370293/141811812-5db2c837-b124-4565-9dda-83dfd46a2b3f.png)
  ![image](https://user-images.githubusercontent.com/13370293/141811950-999e0190-509a-4aea-986a-9888aeeb8e93.png)
  ![image](https://user-images.githubusercontent.com/13370293/141812072-2863d796-67db-4a51-a9eb-1262d794d96b.png)
10. Create another Gauge block for the pressure feed.
11. Repeat steps 8-10 for a feed called "altitude".
12.  Your final dashboard should look similar to the following:
  ![image](https://user-images.githubusercontent.com/13370293/141846123-4b303bd9-4e7a-4fc4-8324-ae0164006b79.png)
13. In order to export data as a csv, follow [these instructions](https://io.adafruit.com/blog/tips/2016/09/12/exporting-data/).
