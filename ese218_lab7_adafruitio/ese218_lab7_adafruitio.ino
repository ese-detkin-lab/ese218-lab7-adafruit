/***************************************************************************
 * Created by: Kim Luong, 2021-11-10
  All instructions are on the github repo. https://github.com/ese-detkin-lab/ese218-lab7-blynk
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include "SimpleTimer.h"
 
/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Lab Starts Here *******************************/
#define SEALEVELPRESSURE_HPA (1013.25)

// Variables
float t;
float p;
float a;
Adafruit_BMP3XX bmp;

// this int will hold the current count for our sketch
int count = 0;

// Adafruit Feeds
AdafruitIO_Feed *pressure = io.feed("pressure");

void sendSensor()
{

  if (! bmp.performReading()) 
  {
  Serial.println("Failed to perform reading :(");
  return;
  }
  t = bmp.temperature;
  p = bmp.pressure / 100.0;  // in hPa
  a = bmp.readAltitude(SEALEVELPRESSURE_HPA);

  // Uncomment the following if you wish to print to serial monitor.
 /*  
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(p);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(a);
  Serial.println(" m");

  Serial.println();
 */ 
  
  pressure->save(p);
}


void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  Serial.println(" ");
  Serial.println("Adafruit BMP388 / BMP390 test");
  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
  //if (! bmp.begin_SPI(BMP_CS)) {  // hardware SPI mode  
  //if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) {  // software SPI mode
  Serial.println("Could not find a valid BMP3 sensor, check wiring!");
  while (1);
  }

  // Set up oversampling and filter initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  // Adafruit IO is rate limited for publishing, so a delay is required in
  // between feed->save events. 
  sendSensor();
  delay(5000);

}
