#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL2KQzLATYj"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "5FOC0NO9dDp1zl6IKGAb-1yp9MU1T3UA"

#include <BlynkSimpleEsp32.h>

const int relay1 = 0;
const int relay2 = 4;
const int relay3 = 16;
const int relay4 = 17;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "Wokwi-GUEST", "");

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  Serial.println("Setup completed.");
}

BLYNK_WRITE(V1)
{
  int buttonState = param.asInt();
  Serial.print("Button state: ");
  Serial.println(buttonState);
  if (buttonState == 1) {
    digitalWrite(relay1, HIGH);
    Serial.println("Relay ON");
  } else {
    digitalWrite(relay1, LOW);
    Serial.println("Relay OFF");
  }
}

BLYNK_WRITE(V2)
{
  int buttonState = param.asInt();
  Serial.print("Button state: ");
  Serial.println(buttonState);
  if (buttonState == 1) {
    digitalWrite(relay2, HIGH);
    Serial.println("Relay ON");
  } else {
    digitalWrite(relay2, LOW);
    Serial.println("Relay OFF");
  }
}

BLYNK_WRITE(V3)
{
  int buttonState = param.asInt();
  Serial.print("Button state: ");
  Serial.println(buttonState);
  if (buttonState == 1) {
    digitalWrite(relay3, HIGH);
    Serial.println("Relay ON");
  } else {
    digitalWrite(relay3, LOW);
    Serial.println("Relay OFF");
  }
}

BLYNK_WRITE(V4)
{
  int buttonState = param.asInt();
  Serial.print("Button state: ");
  Serial.println(buttonState);
  if (buttonState == 1) {
    digitalWrite(relay4, HIGH);
    Serial.println("Relay ON");
  } else {
    digitalWrite(relay4, LOW);
    Serial.println("Relay OFF");
  }
}

void loop()
{
  Blynk.run();
}