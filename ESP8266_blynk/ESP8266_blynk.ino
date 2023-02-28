
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPLnMd5ltJe"
#define BLYNK_TEMPLATE_NAME "SolenoidControl"
#define BLYNK_AUTH_TOKEN "OaztkgKIkhZHxIE5Zbaa08A939UEO1Ty"

#define CH1 D0
#define CH2 D5
#define CH3 D6
#define CH4 D7

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "G6PD_2.4G";
char pass[] = "570610193";

BLYNK_CONNECTED()
{
  Blynk.syncAll();
}

BLYNK_WRITE(V0)
{
  if (param.asInt() == 1)
  {
    digitalWrite(CH1, LOW);
  }
  else
  {
    digitalWrite(CH1, HIGH);
  }
}
BLYNK_WRITE(V1)
{
  if (param.asInt() == 1)
  {
    digitalWrite(CH2, LOW);
  }
  else
  {
    digitalWrite(CH2, HIGH);
  }
}
BLYNK_WRITE(V2)
{
  if (param.asInt() == 1)
  {
    digitalWrite(CH3, LOW);
  }
  else
  {
    digitalWrite(CH3, HIGH );
  }
}
BLYNK_WRITE(V3)
{
  if (param.asInt() == 1)
  {
    digitalWrite(CH4, LOW);
  }
  else
  {
    digitalWrite(CH4, HIGH);
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  digitalWrite(CH1, HIGH);
  digitalWrite(CH2, HIGH);
  digitalWrite(CH3, HIGH);
  digitalWrite(CH4, HIGH);
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  pinMode(CH3, OUTPUT);
  pinMode(CH4, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
