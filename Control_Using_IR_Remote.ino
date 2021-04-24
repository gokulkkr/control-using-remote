#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");

}

void loop() {
  if(irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    Serial.println(digitalRead(13));
	if (digitalRead(13)==0)
    {
    	if(results.value==0xFD00FF)
    	{
      		digitalWrite(13,HIGH);
    	}
    }
    else
    {
    	if (results.value==0xFD00FF)
    	{
      		digitalWrite(13,LOW);
    	}
    }
  }
}