#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL2KQzLATYj"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "5FOC0NO9dDp1zl6IKGAb-1yp9MU1T3UA"

#include <BlynkSimpleEsp32.h>

// Create Relay Modules 
const int relay1 = 0;
const int relay2 = 4;
const int relay3 = 16;
const int relay4 = 17;

const int led0 = 22;
const int led4 = 5;
const int led3 = 18;
const int led2 = 19;
const int led1 = 21;

int v6 = 0;
int v7 = 0;
int v8 = 0;
int v9 = 0;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "Wokwi-GUEST", "");

  // Initialize Relay Modules 
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Blynk.virtualWrite(V0, 0);
  Blynk.virtualWrite(V1, 0);
  Blynk.virtualWrite(V2, 0);
  Blynk.virtualWrite(V3, 0);
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V6, 0);
  Blynk.virtualWrite(V7, 0);
  Blynk.virtualWrite(V8, 0);
  Blynk.virtualWrite(V9, 0);
  Blynk.virtualWrite(V10, 0);

  Blynk.virtualWrite(V0, 1);
  digitalWrite(led0, HIGH);

  Serial.println("Setup completed.");
}

BLYNK_WRITE(V1)
{
  int buttonState = param.asInt();
  if (buttonState == 1 && v6 == 1) {
    digitalWrite(relay1, HIGH);
    delay(1000);
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V6, 0);
    digitalWrite(relay1, LOW);
    digitalWrite(led1, LOW);
    v6 = 0;
  } else {
    Blynk.virtualWrite(V1, 0);
    digitalWrite(relay1, LOW);
  }
}

BLYNK_WRITE(V2)
{
  int buttonState = param.asInt();
  if (buttonState == 1 && v7 == 1) {
    digitalWrite(relay2, HIGH);
    delay(1000);
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V7, 0);
    digitalWrite(relay2, LOW);
    digitalWrite(led2, LOW);
    v7 = 0;
  } else {
    Blynk.virtualWrite(V2, 0);
    digitalWrite(relay2, LOW);
  }
}

BLYNK_WRITE(V3)
{
  int buttonState = param.asInt();
  if (buttonState == 1 && v8 == 1) {
    digitalWrite(relay3, HIGH);
    delay(1000);
    Blynk.virtualWrite(V3, 0);
    Blynk.virtualWrite(V8, 0);
    digitalWrite(relay3, LOW);
    digitalWrite(led3, LOW);
    v8 = 0;
  } else {
    Blynk.virtualWrite(V3, 0);
    digitalWrite(relay3, LOW);
  }
}

BLYNK_WRITE(V4)
{
  int buttonState = param.asInt();
  if (buttonState == 1 && v9 == 1) {
    digitalWrite(relay4, HIGH);
    delay(1000);
    Blynk.virtualWrite(V4, 0);
    Blynk.virtualWrite(V9, 0);
    digitalWrite(relay4, LOW);
    digitalWrite(led4, LOW);
    v9 = 0;
  } else {
    Blynk.virtualWrite(V4, 0);
    digitalWrite(relay4, LOW);
    digitalWrite(led4, LOW);
  }
}

BLYNK_WRITE(V5)
{
  int menuOption = param.asInt();
  
  switch(menuOption) {
    case 0:
      Blynk.virtualWrite(V11, "Activated All"); 
      Blynk.virtualWrite(V6, 1);
      Blynk.virtualWrite(V7, 1);
      Blynk.virtualWrite(V8, 1);
      Blynk.virtualWrite(V9, 1);
      v6 = 1;
      v7 = 1;
      v8 = 1;
      v9 = 1;
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      break;
    case 1:
      Blynk.virtualWrite(V11, "Activated Port 1"); 
      Blynk.virtualWrite(V6, 1);
      v6 = 1;
      digitalWrite(led1, HIGH);
      break;
    case 2:
      Blynk.virtualWrite(V11, "Activated Port 2"); 
      Blynk.virtualWrite(V7, 1);
      v7 = 1;
      digitalWrite(led2, HIGH);
      break;
    case 3:
      Blynk.virtualWrite(V11, "Activated Port 3 "); 
      Blynk.virtualWrite(V8, 1);
      v8 = 1;
      digitalWrite(led3, HIGH);
      break;
    case 4:
      Blynk.virtualWrite(V11, "Activated Port 4"); 
      Blynk.virtualWrite(V9, 1);
      v9 = 1;
      digitalWrite(led4, HIGH);
      break;
  }
}

BLYNK_WRITE(V10)
{
  int buttonState = param.asInt();
  if (buttonState == 1 && v6 == 1 && v7 == 1 && v8 == 1 && v9 == 1) {
      Blynk.virtualWrite(V1, 1);
      digitalWrite(relay1, HIGH);
      Blynk.virtualWrite(V2, 1);
      digitalWrite(relay2, HIGH);
      Blynk.virtualWrite(V3, 1);
      digitalWrite(relay3, HIGH);
      Blynk.virtualWrite(V4, 1);
      digitalWrite(relay4, HIGH);
    delay(1000);
      Blynk.virtualWrite(V1, 0);
      Blynk.virtualWrite(V6, 0);
      digitalWrite(relay1, LOW);
      Blynk.virtualWrite(V2, 0);
      Blynk.virtualWrite(V7, 0);
      digitalWrite(relay2, LOW);
      Blynk.virtualWrite(V3, 0);
      Blynk.virtualWrite(V8, 0);
      digitalWrite(relay3, LOW);
      Blynk.virtualWrite(V4, 0);
      Blynk.virtualWrite(V9, 0);
      digitalWrite(relay4, LOW);
      v6 = 0;
      v7 = 0;
      v8 = 0;
      v9 = 0;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    Blynk.virtualWrite(V10, 0);
  } else {
    Blynk.virtualWrite(V10, 0);
  }
}

void loop()
{
  Blynk.run();
}