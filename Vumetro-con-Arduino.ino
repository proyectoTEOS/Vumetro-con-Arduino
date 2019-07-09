/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  Web https://www.proyecto-teos.com
*/

#include <Adafruit_NeoPixel.h> //https://github.com/adafruit/Adafruit_NeoPixel

/*Declaration of the connection pins, number of neopyxels that the bar has, 
pin of the microphone module, temporary window used for the measurement intervals.*/
const uint8_t pinPixelTA = 2, pinPixelTB = 3, numPixelsT = 8, soundPinT = A0, sampleWindowT = 35;

/*Instances of neopixels.*/
Adafruit_NeoPixel vuMeterAT(numPixelsT, pinPixelTA, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel vuMeterBT(numPixelsT, pinPixelTB, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  /*The neopixels are started and a 100% brightness is established.*/
  vuMeterAT.begin();
  vuMeterBT.begin();
  vuMeterAT.setBrightness(100);
  vuMeterBT.setBrightness(100);
}

void loop() {
  /*In the for cycle, the iteration of the neopixels is performed, in the second 
  parameter it receives the return value given by soundLevel(), which contains 
  the number of neopixels that must be illuminated.*/
  for (uint8_t iT = 0; iT <= soundLevelT(); iT++) {
    /*All if statements evaluate the number of pixels to determine what color 
    they should assign. Send the instruction of the neopíxel that should be 
    illuminated and with what color (green, yellow and red respectively).*/
    if (iT <= 2) {
      vuMeterAT.setPixelColor(iT, vuMeterAT.Color(0, 255, 0));
      vuMeterBT.setPixelColor(iT, vuMeterBT.Color(0, 255, 0));
    }
    else if (iT <= 5) {
      vuMeterAT.setPixelColor(iT, vuMeterAT.Color(255, 255, 0));
      vuMeterBT.setPixelColor(iT, vuMeterBT.Color(255, 255, 0));
    }
    else if (iT <= 7) {
      vuMeterAT.setPixelColor(iT, vuMeterAT.Color(255, 0, 0));
      vuMeterBT.setPixelColor(iT, vuMeterBT.Color(255, 0, 0));
    }
    /*Shows the neopixel.*/
    vuMeterAT.show();
    vuMeterBT.show();
  }
  /*Clean the bar.*/
  vuMeterAT.clear();
  vuMeterBT.clear();
}

/*Variable that returns a number based on the voltage conversion detected by the 
 microphone to a value that can be interpreted by the bar of neopixels.*/
uint8_t soundLevelT() {
  /*Declaration of variables. Stores the conversion value. Minimum and maximum signal 
  for comparison of collected values. Analog port assignment and pin resolution bits*/
  String resultSerialT;
  unsigned long startMillisT = millis();
  uint16_t voltsToNeoPixelT, peakToPeakT, signalMaxT, signalMinT = 1023, incomingSoundT, bitsResolutionT = 1023;
  double voltsT;
  /*Cycle that allows to take samples and compare with the minimum and maximum readings, 
  this to reduce the noise of the signal.*/
  while (millis() - startMillisT < sampleWindowT) {
    incomingSoundT = analogRead(soundPinT);
    if (incomingSoundT < bitsResolutionT) {
      if (incomingSoundT > signalMaxT)
        signalMaxT = incomingSoundT;
      else if (incomingSoundT < signalMinT)
        signalMinT = incomingSoundT;
    }
  }
  /*Amplitude of sound.*/
  peakToPeakT = signalMaxT - signalMinT;
  /*Conversion to tension.*/
  voltsT = (peakToPeakT * 5.0) / bitsResolutionT;
  /*Multiply by a factor of 10 to have better value control.*/
  voltsToNeoPixelT = voltsT * 10;
  /*The constrain function ensures that the delivered value is within the range of 0 to 7.*/
  voltsToNeoPixelT = constrain(voltsToNeoPixelT, 0, 7);
  /*The value is printed and returned.*/
  resultSerialT = String(voltsToNeoPixelT);
  Serial.println(resultSerialT);
  return voltsToNeoPixelT;
}