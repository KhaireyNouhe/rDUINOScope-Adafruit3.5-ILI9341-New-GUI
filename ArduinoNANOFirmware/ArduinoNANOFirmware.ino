// This file is part of Arduino ST4.
//
// Arduino ST4 is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Arduino ST4 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Arduino ST4.  If not, see <http://www.gnu.org/licenses/>.
//
// Copyright Kevin Ferrare 2014

/*
   Led indicates whether the software requested connection, it is shut off when the software disconnects
*/
const int pinLED = 13;
const int GuidingSensePin = 7; 
const int Sender_Pulse_LED = 8; 
const int rDUINOScope_Pulse_LED = 9; 
/**
   An axis has a pin per direction.
   Both pins cannot be up at the same time.
*/
class Axis {
  private:
    int plusPin;
    int minusPin;
  public:
    Axis(int plusPin, int minusPin) :
      plusPin(plusPin), minusPin(minusPin) {
    }
    void setupPins() {
      pinMode(this->plusPin, OUTPUT);
      pinMode(this->minusPin, OUTPUT);
    }
    void plus() {
      digitalWrite(this->minusPin, LOW);
      digitalWrite(this->plusPin, HIGH);
    }
    void minus() {
      digitalWrite(this->plusPin, LOW);
      digitalWrite(this->minusPin, HIGH);
    }
    void reset() {
      digitalWrite(this->minusPin, LOW);
      digitalWrite(this->plusPin, LOW);
    }
};

class Axis rightAscension(
    4, //RA+ pin
    5); //RA- pin
class Axis declination(
    6,//DEC+ pin
    3);//DEC- pin

void setup()
{
  rightAscension.setupPins();
  declination.setupPins();
  pinMode(pinLED, OUTPUT);
  pinMode(GuidingSensePin, OUTPUT);
  pinMode(Sender_Pulse_LED, OUTPUT);
  pinMode(rDUINOScope_Pulse_LED, OUTPUT);
  //57.6k, 8 data bits, no parity, one stop bit.
  Serial.begin(57600, SERIAL_8N1);
  //Wait for serial port to connect. Needed for Leonardo only
  while (!Serial);
  Serial.println("INITIALIZED#");
}

void resetPins() {
  rightAscension.reset();
  declination.reset();
}

void loop()
{
  if (Serial.available() > 0) {
    //Received something
    String GuideCode = Serial.readStringUntil('#');
    boolean validGuideCode = true;
    //Parse GuideCode
    if (GuideCode == "CONNECT") {
      digitalWrite(pinLED, HIGH);
      digitalWrite(GuidingSensePin, HIGH);
       digitalWrite(Sender_Pulse_LED, HIGH);
      digitalWrite(rDUINOScope_Pulse_LED, HIGH); 
      resetPins();
    }
    else if (GuideCode == "DISCONNECT") {
      digitalWrite(pinLED, LOW);
      digitalWrite(GuidingSensePin, LOW);
      digitalWrite(Sender_Pulse_LED, LOW);
      digitalWrite(rDUINOScope_Pulse_LED, LOW); 
      resetPins();
    }
    else if (GuideCode == "RA0") {
      rightAscension.reset();
      digitalWrite(Sender_Pulse_LED, LOW);
      digitalWrite(rDUINOScope_Pulse_LED, LOW); 
    }
    else if (GuideCode == "RA+") {
      rightAscension.plus();
     digitalWrite(Sender_Pulse_LED, HIGH);
     digitalWrite(rDUINOScope_Pulse_LED, HIGH); 
    }
    else if (GuideCode == "RA-") {
      rightAscension.minus();
      digitalWrite(Sender_Pulse_LED, HIGH);
      digitalWrite(rDUINOScope_Pulse_LED, HIGH); 
    }
    else if (GuideCode == "DEC0") {
      declination.reset();
      digitalWrite(Sender_Pulse_LED, LOW);
      digitalWrite(rDUINOScope_Pulse_LED, LOW); 
    }
    else if (GuideCode == "DEC+") {
      declination.plus();
      digitalWrite(Sender_Pulse_LED, HIGH);
      digitalWrite(rDUINOScope_Pulse_LED, HIGH); 
    }
    else if (GuideCode == "DEC-") {
      declination.minus();
      digitalWrite(Sender_Pulse_LED, HIGH);
      digitalWrite(rDUINOScope_Pulse_LED, HIGH); 
    }
    else {
      validGuideCode = false;
      digitalWrite(Sender_Pulse_LED, LOW);
      digitalWrite(rDUINOScope_Pulse_LED, LOW); 
    }
    if (validGuideCode) {
      //Acknowledge valid command
      Serial.println("OK#");
    }
  }
}
