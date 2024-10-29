// void setup() {
//   Serial.begin(9600);
//   pinMode(6, INPUT);
//   pinMode(7, OUTPUT);
// }

// void loop() {
//   if (digitalRead(6) == 1) {
//     digitalWrite(7, LOW);
//   } else if (digitalRead(6) == 0) {
//     digitalWrite(7, HIGH);
//   }
// }

/*
  Simple Audio Player for Arduino Zero

 Demonstrates the use of the Audio library for the Arduino Zero

 Hardware required :
 * Arduino shield with a SD card on CS4
 * A sound file named "test.wav" in the root directory of the SD card
 * An audio amplifier to connect to the DAC0 and ground
 * A speaker to connect to the audio amplifier


 Arturo Guadalupi <a.guadalupi@arduino.cc>
 Angelo Scialabba <a.scialabba@arduino.cc>
 Claudio Indellicati <c.indellicati@arduino.cc>

 This example code is in the public domain

 http://arduino.cc/en/Tutorial/SimpleAudioPlayerZero

*/

#include <SD.h>
#include <SPI.h>
#include <AudioZero.h>

void setup() {
  // debug output at 9600 baud
  Serial.begin(9600);
  
  // hall effect
    pinMode(6, INPUT);
    pinMode(7, OUTPUT);

  // setup SD-card
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDCARD_SS_PIN)) {
    Serial.println(" failed!");
    while(true);
  }
  Serial.println(" done.");
  // 44100kHz stereo => 88200 sample rate
  AudioZero player1 = AudioZero.begin(88200);
}

void loop() {
  // hall effect
  if (digitalRead(6) == 1) {
    digitalWrite(7, LOW);
  } else if (digitalRead(6) == 0) {
    digitalWrite(7, HIGH);
  }

  int count = 0;
  // open wave file from sdcard
  File myFile = SD.open("mmsh1.wav");
  if (!myFile) {
    // if the file didn't open, print an error and stop
    Serial.println("error opening test.wav");
    while (true);
  }

  Serial.print("Playing");
  // until the file is not finished
  AudioZero.play(myFile);
  Serial.println("End of file. Thank you for listening!");
  while (true);
}


// /*
//   SD card test
//   This example shows how use the utility libraries on which the'
//   SD library is based in order to get info about your SD card.
//   Very useful for testing a card when you're not sure whether its working or not.
//   Pin numbers reflect the default SPI pins for Uno and Nano models
//   The circuit:
//     SD card attached to SPI bus as follows:
//  ** SDO - pin 11 on Arduino Uno/Duemilanove/Diecimila
//  ** SDI - pin 12 on Arduino Uno/Duemilanove/Diecimila
//  ** CLK - pin 13 on Arduino Uno/Duemilanove/Diecimila
//  ** CS - depends on your SD card shield or module.
//         Pin 10 used here for consistency with other Arduino examples
//   created  28 Mar 2011
//   by Limor Fried
//   modified 24 July 2020
//   by Tom Igoe
// */

// // include the SD library:
// #include <SPI.h>
// #include <SD.h>

// // set up variables using the SD utility library functions:

// Sd2Card card;
// SdVolume volume;
// SdFile root;

// // change this to match your SD shield or module;
// // Default SPI on Uno and Nano: pin 10
// // Arduino Ethernet shield: pin 4
// // Adafruit SD shields and modules: pin 10
// // Sparkfun SD shield: pin 8
// // MKRZero SD: SDCARD_SS_PIN

// const int chipSelect = SDCARD_SS_PIN;

// void setup() {
//   // Open serial communications and wait for port to open:
//   Serial.begin(9600);

//   // bug fix
//   pinMode(10, OUTPUT);
//   digitalWrite(10, HIGH);

//   while (!Serial) {
//     ; // wait for serial port to connect. Needed for native USB port only
//   }

//   Serial.print("\nInitializing SD card...");
//   // we'll use the initialization code from the utility libraries
//   // since we're just testing if the card is working!

//   if (!card.init(SPI_HALF_SPEED, chipSelect)) {
//     Serial.println("initialization failed. Things to check:");
//     Serial.println("* is a card inserted?");
//     Serial.println("* is your wiring correct?");
//     Serial.println("* did you change the chipSelect pin to match your shield or module?");
//     while (1);
//   } else {
//     Serial.println("Wiring is correct and a card is present.");
//   }

//   // print the type of card
//   Serial.println();
//   Serial.print("Card type:         ");
//   switch (card.type()) {
//     case SD_CARD_TYPE_SD1:
//       Serial.println("SD1");
//       break;
//     case SD_CARD_TYPE_SD2:
//       Serial.println("SD2");
//       break;
//     case SD_CARD_TYPE_SDHC:
//       Serial.println("SDHC");
//       break;
//     default:
//       Serial.println("Unknown");
//   }

//   // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
//   if (!volume.init(card)) {
//     Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
//     while (1);
//   }

//   Serial.print("Clusters:          ");
//   Serial.println(volume.clusterCount());
//   Serial.print("Blocks x Cluster:  ");
//   Serial.println(volume.blocksPerCluster());
//   Serial.print("Total Blocks:      ");
//   Serial.println(volume.blocksPerCluster() * volume.clusterCount());
//   Serial.println();

//   // print the type and size of the first FAT-type volume
//   uint32_t volumesize;
//   Serial.print("Volume type is:    FAT");
//   Serial.println(volume.fatType(), DEC);
//   volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
//   volumesize *= volume.clusterCount();       // we'll have a lot of clusters
//   volumesize /= 2;                           // SD card blocks are always 512 bytes (2 blocks are 1KB)
//   Serial.print("Volume size (Kb):  ");
//   Serial.println(volumesize);
//   Serial.print("Volume size (Mb):  ");
//   volumesize /= 1024;
//   Serial.println(volumesize);
//   Serial.print("Volume size (Gb):  ");
//   Serial.println((float)volumesize / 1024.0);
//   Serial.println("\nFiles found on the card (name, date and size in bytes): ");
//   root.openRoot(volume);

//   // list all files in the card with date and size
//   root.ls(LS_R | LS_DATE | LS_SIZE);
//   root.close();
// }

// void loop(void) {
// }
