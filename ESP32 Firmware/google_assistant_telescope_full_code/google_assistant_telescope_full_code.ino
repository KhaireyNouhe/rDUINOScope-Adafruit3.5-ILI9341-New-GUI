#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "defines.h"
/************************* Pin Definition *********************************/
#define buzzer 26  //buzzer to know the status of MQTT connections and can be used for any other purpose according to your project need.
#define LED_BUILTIN 2
#define RXD1 16 // GPIO 16 Pin to communicate with Arduino
#define TXD1 17  // GPIO 17 Pin to communicate with Arduino
String NGC_message;
String Messier_message;
String Solar_message;
String Control_message;
/************************* WiFi Access Point *********************************/
#define WLAN_SSID       "ATLASBAY"
#define WLAN_PASS       "admin1230"
/************************* Adafruit.io Setup *********************************/
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "khaireynouhe"
#define AIO_KEY         "aio_ePln04WJqMegOttlDUZ7ytvjqfKB"
/************ Global State (you don't need to change this!) ******************/
// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
/****************************** Feeds ***************************************/
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
//Adafruit_MQTT_Publish Light = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/light");
Adafruit_MQTT_Subscribe Telescope_NGC_Message = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Telescope-NGC");
Adafruit_MQTT_Subscribe Telescope_Messier_Message = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Telescope-Messier");
Adafruit_MQTT_Subscribe Telescope_Solar_Message = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Telescope-Solar");
Adafruit_MQTT_Subscribe Telescope_Control_Message = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Telescope-Commands");
/*************************** Sketch Code ************************************/
// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  Serial.begin(9600);
  //Serial1.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, RXD1, TXD1); // Starts communication with Arduino
  delay(10);
  pinMode(buzzer, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);    // if you get connected turn on the Built in LED
  Serial.println(F("Adafruit MQTT demo"));
  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH);    // if you get connected turn on the Built in LED
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, LOW);    // if you get connected turn on the Built in LED
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  mqtt.subscribe(&Telescope_NGC_Message);
  mqtt.subscribe(&Telescope_Messier_Message);
  mqtt.subscribe(&Telescope_Solar_Message);
  mqtt.subscribe(&Telescope_Control_Message);
  digitalWrite(LED_BUILTIN, HIGH);    // if you get connected turn on the Built in LED
}


void loop() {
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();
  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(20000))) {
    if (subscription == &Telescope_NGC_Message) {
      NGC_message = ((char *)&Telescope_NGC_Message.lastread);
      Serial.print(F("NGC_message = "));
      Serial.println(NGC_message);
      if (NGC_message == "NGC189") // EX: Ok, Google... Go to NGC # /Ok, Google... go to NGC #/ Ok, Google... Move to NGC #
      {
        Serial1.print(NGC189);
      }
      else if (NGC_message == "NGC225")
      {
        Serial1.print(NGC281);
      } else if (NGC_message == "NGC281")
      {
        Serial1.print(NGC225);
      } else if (NGC_message == "NGC288")
      {
        Serial1.print(NGC288);
      } else if (NGC_message == "NGC404")
      {
        Serial1.print(NGC404);
      } else if (NGC_message == "NGC584")
      {
        Serial1.print(NGC584);
      } else if (NGC_message == "NGC659")
      {
        Serial1.print(NGC659);
      } else if (NGC_message == "NGC772")
      {
        Serial1.print(NGC772);
      } else if (NGC_message == "NGC908")
      {
        Serial1.print(NGC908);
      } else if (NGC_message == "NGC1023")
      {
        Serial1.print(NGC1023);
      } else if (NGC_message == "NGC1232")
      {
        Serial1.print(NGC1232);
      } else if (NGC_message == "NGC1291")
      {
        Serial1.print(NGC1291);
      } else if (NGC_message == "NGC1316")
      {
        Serial1.print(NGC1316);
      } else if (NGC_message == "Mel20")
      {
        Serial1.print(Mel20);
      } else if (NGC_message == "NGC1333")
      {
        Serial1.print(NGC1333);
      } else if (NGC_message == "NGC1360")
      {
        Serial1.print(NGC1360);
      } else if (NGC_message == "NGC1365")
      {
        Serial1.print(NGC1365);
      } else if (NGC_message == "NGC1399")
      {
        Serial1.print(NGC1399);
      } else if (NGC_message == "NGC1398")
      {
        Serial1.print(NGC1398);
      } else if (NGC_message == "NGC1404")
      {
        Serial1.print(NGC1404);
      } else if (NGC_message == "Kem1")
      {
        Serial1.print(Kem1);
      } else if (NGC_message == "NGC1501")
      {
        Serial1.print(NGC1501);
      } else if (NGC_message == "NGC1502")
      {
        Serial1.print(NGC1502);
      } else if (NGC_message == "NGC1535")
      {
        Serial1.print(NGC1535);
      } else if (NGC_message == "NGC1528")
      {
        Serial1.print(NGC1528);
      } else if (NGC_message == "NGC1545")
      {
        Serial1.print(NGC1545);
      } else if (NGC_message == "NGC1647")
      {
        Serial1.print(NGC1647);
      } else if (NGC_message == "IC418")
      {
        Serial1.print(IC418);
      } else if (NGC_message == "Cr69")
      {
        Serial1.print(Cr69);
      } else if (NGC_message == "NGC1981")
      {
        Serial1.print(NGC1981);
      } else if (NGC_message == "Cr72")
      {
        Serial1.print(Cr72);
      } else if (NGC_message == "NGC1977")
      {
        Serial1.print(NGC1977);
      } else if (NGC_message == "NGC1999")
      {
        Serial1.print(NGC1999);
      } else if (NGC_message == "NGC2024")
      {
        Serial1.print(NGC2024);
      } else if (NGC_message == "NGC2163")
      {
        Serial1.print(NGC2163);
      } else if (NGC_message == "NGC2169")
      {
        Serial1.print(NGC2169);
      } else if (NGC_message == "NGC2175")
      {
        Serial1.print(NGC2175);
      } else if (NGC_message == "NGC2264")
      {
        Serial1.print(NGC2264);
      } else if (NGC_message == "NGC2301")
      {
        Serial1.print(NGC2301);
      } else if (NGC_message == "NGC2353")
      {
        Serial1.print(NGC2353);
      } else if (NGC_message == "NGC2440")
      {
        Serial1.print(NGC2440);
      } else if (NGC_message == "NGC2451")
      {
        Serial1.print(NGC2451);
      } else if (NGC_message == "NGC2467")
      {
        Serial1.print(NGC2467);
      } else if (NGC_message == "NGC2547")
      {
        Serial1.print(NGC2547);
      } else if (NGC_message == "NGC2539")
      {
        Serial1.print(NGC2539);
      } else if (NGC_message == "NGC2546")
      {
        Serial1.print(NGC2546);
      } else if (NGC_message == "NGC2683")
      {
        Serial1.print(NGC2683);
      } else if (NGC_message == "NGC2655")
      {
        Serial1.print(NGC2655);
      } else if (NGC_message == "NGC2841")
      {
        Serial1.print(NGC2841);
      } else if (NGC_message == "IC2488")
      {
        Serial1.print(IC2488);
      } else if (NGC_message == "NGC2903")
      {
        Serial1.print(NGC2903);
      } else if (NGC_message == "NGC3184")
      {
        Serial1.print(NGC3184);
      } else if (NGC_message == "NGC3228")
      {
        Serial1.print(NGC3228);
      } else if (NGC_message == "NGC3293")
      {
        Serial1.print(NGC3293);
      } else if (NGC_message == "NGC3344")
      {
        Serial1.print(NGC3344);
      } else if (NGC_message == "NGC3521")
      {
        Serial1.print(NGC3521);
      } else if (NGC_message == "NGC3621")
      {
        Serial1.print(NGC3621);
      } else if (NGC_message == "NGC3628")
      {
        Serial1.print(NGC3628);
      } else if (NGC_message == "NGC4214")
      {
        Serial1.print(NGC4214);
      } else if (NGC_message == "NGC4216")
      {
        Serial1.print(NGC4216);
      } else if (NGC_message == "NGC4361")
      {
        Serial1.print(NGC4361);
      } else if (NGC_message == "Mel111")
      {
        Serial1.print(Mel111);
      } else if (NGC_message == "NGC4490")
      {
        Serial1.print(NGC4490);
      } else if (NGC_message == "IC3568")
      {
        Serial1.print(IC3568);
      } else if (NGC_message == "NGC4526")
      {
        Serial1.print(NGC4526);
      } else if (NGC_message == "NGC4605")
      {
        Serial1.print(NGC4605);
      } else if (NGC_message == "NGC4656")
      {
        Serial1.print(NGC4656);
      } else if (NGC_message == "NGC4699")
      {
        Serial1.print(NGC4699);
      } else if (NGC_message == "NGC4725")
      {
        Serial1.print(NGC4725);
      } else if (NGC_message == "NGC5102")
      {
        Serial1.print(NGC5102);
      } else if (NGC_message == "NGC5281")
      {
        Serial1.print(NGC5281);
      } else if (NGC_message == "NGC5363")
      {
        Serial1.print(NGC5363);
      } else if (NGC_message == "NGC5662")
      {
        Serial1.print(NGC5662);
      } else if (NGC_message == "NGC5746")
      {
        Serial1.print(NGC5746);
      } else if (NGC_message == "NGC5866")
      {
        Serial1.print(NGC5866);
      } else if (NGC_message == "NGC5897")
      {
        Serial1.print(NGC5897);
      } else if (NGC_message == "NGC5986")
      {
        Serial1.print(NGC5986);
      } else if (NGC_message == "NGC6210")
      {
        Serial1.print(NGC6210);
      } else if (NGC_message == "NGC6242")
      {
        Serial1.print(NGC6242);
      } else if (NGC_message == "NGC6281")
      {
        Serial1.print(NGC6281);
      } else if (NGC_message == "NGC6369")
      {
        Serial1.print(NGC6369);
      } else if (NGC_message == "NGC6400")
      {
        Serial1.print(NGC6400);
      } else if (NGC_message == "IC4665")
      {
        Serial1.print(IC4665);
      } else if (NGC_message == "NGC6445")
      {
        Serial1.print(NGC6445);
      } else if (NGC_message == "NGC6503")
      {
        Serial1.print(NGC6503);
      } else if (NGC_message == "NGC6441")
      {
        Serial1.print(NGC6441);
      } else if (NGC_message == "XXXX")
      {
        Serial1.print(XXXX);
      } else if (NGC_message == "NGC6520")
      {
        Serial1.print(NGC6520);
      } else if (NGC_message == "NGC6544")
      {
        Serial1.print(NGC6544);
      } else if (NGC_message == "NGC6572")
      {
        Serial1.print(NGC6572);
      } else if (NGC_message == "NGC6624")
      {
        Serial1.print(NGC6624);
      } else if (NGC_message == "NGC6633")
      {
        Serial1.print(NGC6633);
      } else if (NGC_message == "IC4756")
      {
        Serial1.print(IC4756);
      } else if (NGC_message == "NGC6709")
      {
        Serial1.print(NGC6709);
      } else if (NGC_message == "NGC6712")
      {
        Serial1.print(NGC6712);
      } else if (NGC_message == "NGC6723")
      {
        Serial1.print(NGC6723);
      } else if (NGC_message == "Cr399")
      {
        Serial1.print(Cr399);
      } else if (NGC_message == "NGC6819")
      {
        Serial1.print(NGC6819);
      } else if (NGC_message == "NGC6818")
      {
        Serial1.print(NGC6818);
      } else if (NGC_message == "NGC6866")
      {
        Serial1.print(NGC6866);
      } else if (NGC_message == "NGC6940")
      {
        Serial1.print(NGC6940);
      } else if (NGC_message == "XXXXX")
      {
        Serial1.print(XXXXX);
      } else if (NGC_message == "NGC7008")
      {
        Serial1.print(NGC7008);
      } else if (NGC_message == "NGC7027")
      {
        Serial1.print(NGC7027);
      } else if (NGC_message == "Tr37")
      {
        Serial1.print(Tr37);
      } else if (NGC_message == "NGC7380")
      {
        Serial1.print(NGC7380);
      } else if (NGC_message == "OMe1")
      {
        Serial1.print(OMe1);
      } else if (NGC_message == "NGC7789")
      {
        Serial1.print(NGC7789);
      } else if (NGC_message == "NGC7793")
      {
        Serial1.print(NGC7793);
      } else if (NGC_message == "NGC134")
      {
        Serial1.print(NGC134);
      } else if (NGC_message == "NGC1245")
      {
        Serial1.print(NGC1245);
      } else if (NGC_message == "NGC1300")
      {
        Serial1.print(NGC1300);
      } else if (NGC_message == "NGC1491")
      {
        Serial1.print(NGC1491);
      } else if (NGC_message == "NGC1514")
      {
        Serial1.print(NGC1514);
      } else if (NGC_message == "NGC2022")
      {
        Serial1.print(NGC2022);
      } else if (NGC_message == "NGC3114")
      {
        Serial1.print(NGC3114);
      } else if (NGC_message == "NGC3918")
      {
        Serial1.print(NGC3918);
      } else if (NGC_message == "IC4406")
      {
        Serial1.print(IC4406);
      } else if (NGC_message == "NGC5617")
      {
        Serial1.print(NGC5617);
      } else if (NGC_message == "NGC5846")
      {
        Serial1.print(NGC5846);
      } else if (NGC_message == "NGC5907")
      {
        Serial1.print(NGC5907);
      } else if (NGC_message == "NGC5927")
      {
        Serial1.print(NGC5927);
      } else if (NGC_message == "IC4603")
      {
        Serial1.print(IC4603);
      } else if (NGC_message == "NGC6356")
      {
        Serial1.print(NGC6356);
      } else if (NGC_message == "NGC6388")
      {
        Serial1.print(NGC6388);
      } else if (NGC_message == "NGC6664")
      {
        Serial1.print(NGC6664);
      } else if (NGC_message == "NGC6781")
      {
        Serial1.print(NGC6781);
      } else if (NGC_message == "NGC6905")
      {
        Serial1.print(NGC6905);
      } else if (NGC_message == "NGC6939")
      {
        Serial1.print(NGC6939);
      }

    } else if (subscription == &Telescope_Messier_Message) {
      Messier_message = ((char *)&Telescope_Messier_Message.lastread);
      Serial.print(F("Messier_message = "));
      Serial.println(Messier_message);

      if (Messier_message == "M1") // Ex: Ok, Google... go to m# / Ok, Google... go to messier # / Ok, Google... Move to m #
      {
        Serial1.print(M1);
      }
      else if (Messier_message == "M2")
      {
        Serial1.print(M2);
      } else if (Messier_message == "M3")
      {
        Serial1.print(M3);
      } else if (Messier_message == "M4")
      {
        Serial1.print(M4);
      } else if (Messier_message == "M5")
      {
        Serial1.print(M5);
      } else if (Messier_message == "M6")
      {
        Serial1.print(M6);
      } else if (Messier_message == "M7")
      {
        Serial1.print(M7);
      } else if (Messier_message == "M8")
      {
        Serial1.print(M8);
      } else if (Messier_message == "M9")
      {
        Serial1.print(M9);
      } else if (Messier_message == "M10")
      {
        Serial1.print(M10);
      } else if (Messier_message == "M11")
      {
        Serial1.print(M11);
      } else if (Messier_message == "M12")
      {
        Serial1.print(M12);
      } else if (Messier_message == "M13")
      {
        Serial1.print(M13);
      } else if (Messier_message == "M14")
      {
        Serial1.print(M14);
      } else if (Messier_message == "M15")
      {
        Serial1.print(M15);
      } else if (Messier_message == "M16")
      {
        Serial1.print(M16);
      } else if (Messier_message == "M17")
      {
        Serial1.print(M17);
      } else if (Messier_message == "M18")
      {
        Serial1.print(M18);
      } else if (Messier_message == "M19")
      {
        Serial1.print(M19);
      } else if (Messier_message == "M20")
      {
        Serial1.print(M20);
      } else if (Messier_message == "M21")
      {
        Serial1.print(M21);
      } else if (Messier_message == "M22")
      {
        Serial1.print(M22);
      } else if (Messier_message == "M23")
      {
        Serial1.print(M23);
      } else if (Messier_message == "M24")
      {
        Serial1.print(M24);
      } else if (Messier_message == "M25")
      {
        Serial1.print(M25);
      } else if (Messier_message == "M26")
      {
        Serial1.print(M26);
      } else if (Messier_message == "M27")
      {
        Serial1.print(M27);
      } else if (Messier_message == "M28")
      {
        Serial1.print(M28);
      } else if (Messier_message == "M29")
      {
        Serial1.print(M29);
      } else if (Messier_message == "M30")
      {
        Serial1.print(M30);
      } else if (Messier_message == "M31")
      {
        Serial1.print(M31);
      } else if (Messier_message == "M32")
      {
        Serial1.print(M32);
      } else if (Messier_message == "M33")
      {
        Serial1.print(M33);
      } else if (Messier_message == "M34")
      {
        Serial1.print(M34);
      } else if (Messier_message == "M35")
      {
        Serial1.print(M35);
      } else if (Messier_message == "M36")
      {
        Serial1.print(M36);
      } else if (Messier_message == "M37")
      {
        Serial1.print(M37);
      } else if (Messier_message == "M38")
      {
        Serial1.print(M38);
      } else if (Messier_message == "M39")
      {
        Serial1.print(M39);
      } else if (Messier_message == "M40")
      {
        Serial1.print(M40);
      } else if (Messier_message == "M41")
      {
        Serial1.print(M41);
      } else if (Messier_message == "M42")
      {
        Serial1.print(M42);
      } else if (Messier_message == "M43")
      {
        Serial1.print(M43);
      } else if (Messier_message == "M44")
      {
        Serial1.print(M44);
      } else if (Messier_message == "M45")
      {
        Serial1.print(M45);
      } else if (Messier_message == "M46")
      {
        Serial1.print(M46);
      } else if (Messier_message == "M47")
      {
        Serial1.print(M47);
      } else if (Messier_message == "M48")
      {
        Serial1.print(M48);
      } else if (Messier_message == "M49")
      {
        Serial1.print(M49);
      } else if (Messier_message == "M50")
      {
        Serial1.print(M50);
      } else if (Messier_message == "M51")
      {
        Serial1.print(M51);
      } else if (Messier_message == "M52")
      {
        Serial1.print(M52);
      } else if (Messier_message == "M53")
      {
        Serial1.print(M53);
      } else if (Messier_message == "M54")
      {
        Serial1.print(M54);
      } else if (Messier_message == "M55")
      {
        Serial1.print(M55);
      } else if (Messier_message == "M56")
      {
        Serial1.print(M56);
      } else if (Messier_message == "M57")
      {
        Serial1.print(M57);
      } else if (Messier_message == "M58")
      {
        Serial1.print(M58);
      } else if (Messier_message == "M59")
      {
        Serial1.print(M59);
      } else if (Messier_message == "M60")
      {
        Serial1.print(M60);
      } else if (Messier_message == "M61")
      {
        Serial1.print(M61);
      } else if (Messier_message == "M62")
      {
        Serial1.print(M62);
      } else if (Messier_message == "M63")
      {
        Serial1.print(M63);
      } else if (Messier_message == "M64")
      {
        Serial1.print(M64);
      } else if (Messier_message == "M65")
      {
        Serial1.print(M65);
      } else if (Messier_message == "M66")
      {
        Serial1.print(M66);
      } else if (Messier_message == "M67")
      {
        Serial1.print(M67);
      } else if (Messier_message == "M68")
      {
        Serial1.print(M68);
      } else if (Messier_message == "M69")
      {
        Serial1.print(M69);
      } else if (Messier_message == "M70")
      {
        Serial1.print(M70);
      } else if (Messier_message == "M71")
      {
        Serial1.print(M71);
      } else if (Messier_message == "M72")
      {
        Serial1.print(M72);
      } else if (Messier_message == "M73")
      {
        Serial1.print(M73);
      } else if (Messier_message == "M74")
      {
        Serial1.print(M74);
      } else if (Messier_message == "M75")
      {
        Serial1.print(M75);
      } else if (Messier_message == "M76")
      {
        Serial1.print(M76);
      } else if (Messier_message == "M77")
      {
        Serial1.print(M77);
      } else if (Messier_message == "M78")
      {
        Serial1.print(M78);
      } else if (Messier_message == "M79")
      {
        Serial1.print(M79);
      } else if (Messier_message == "M80")
      {
        Serial1.print(M80);
      } else if (Messier_message == "M81")
      {
        Serial1.print(M81);
      } else if (Messier_message == "M82")
      {
        Serial1.print(M82);
      } else if (Messier_message == "M83")
      {
        Serial1.print(M83);
      } else if (Messier_message == "M84")
      {
        Serial1.print(M84);
      } else if (Messier_message == "M85")
      {
        Serial1.print(M85);
      } else if (Messier_message == "M86")
      {
        Serial1.print(M86);
      } else if (Messier_message == "M87")
      {
        Serial1.print(M87);
      } else if (Messier_message == "M88")
      {
        Serial1.print(M88);
      } else if (Messier_message == "M89")
      {
        Serial1.print(M89);
      } else if (Messier_message == "M90")
      {
        Serial1.print(M90);
      } else if (Messier_message == "M91")
      {
        Serial1.print(M91);
      } else if (Messier_message == "M92")
      {
        Serial1.print(M92);
      } else if (Messier_message == "M93")
      {
        Serial1.print(M93);
      } else if (Messier_message == "M94")
      {
        Serial1.print(M94);
      } else if (Messier_message == "M95")
      {
        Serial1.print(M95);
      } else if (Messier_message == "M96")
      {
        Serial1.print(M96);
      } else if (Messier_message == "M97")
      {
        Serial1.print(M97);
      } else if (Messier_message == "M98")
      {
        Serial1.print(M98);
      } else if (Messier_message == "M99")
      {
        Serial1.print(M99);
      } else if (Messier_message == "M100")
      {
        Serial1.print(M100);
      } else if (Messier_message == "M101")
      {
        Serial1.print(M101);
      } else if (Messier_message == "M102")
      {
        Serial1.print(M102);
      } else if (Messier_message == "M103")
      {
        Serial1.print(M103);
      } else if (Messier_message == "M104")
      {
        Serial1.print(M104);
      } else if (Messier_message == "M105")
      {
        Serial1.print(M105);
      } else if (Messier_message == "M106")
      {
        Serial1.print(M106);
      } else if (Messier_message == "M107")
      {
        Serial1.print(M107);
      } else if (Messier_message == "M108")
      {
        Serial1.print(M108);
      } else if (Messier_message == "M109")
      {
        Serial1.print(M109);
      } else if (Messier_message == "M110")
      {
        Serial1.print(M110);
      } else if (Messier_message == "M111")
      {
        Serial1.print(M111);
      } else if (Messier_message == "M112")
      {
        Serial1.print(M112);
      }
    } else if (subscription == &Telescope_Solar_Message) {
      Solar_message = ((char *)&Telescope_Solar_Message.lastread);
      Serial.print(F("Solar_message = "));
      Serial.println(Solar_message);
      if (Solar_message == "the sun")   // Ex: Ok, Google... move telescope to the sun
      {
        Serial1.print("$GOToSolar;SUN;0#");
      }
      else if (Solar_message == "sun") // Ex: Ok, Google... move telescope to sun
      {
        Serial1.print("$GOToSolar;SUN;0#");
      }
      else if (Solar_message == "Sun")
      {
        Serial1.print("$GOToSolar;SUN;0#");
      }
      else if (Solar_message == "Mercury")// Ex: Ok, Google... Go to planet Mercury
      {
        Serial1.print("$GOToSolar;MERCURY;1#");
      }
      else if (Solar_message == "Venus")
      {
        Serial1.print("$GOToSolar;VENUS;2#");
      }
      else if (Solar_message == "Earth")
      {
        Serial1.print("$GOToSolar;EARTH;3#");
      }
      else if (Solar_message == "Mars")
      {
        Serial1.print("$GOToSolar;MARS;4#");
      }
      else if (Solar_message == "Jupiter")
      {
        Serial1.print("$GOToSolar;JUPITER;5#");
      }
      else if (Solar_message == "Saturn")
      {
        Serial1.print("$GOToSolar;SATURN;6#");
      }
      else if (Solar_message == "Uranus")
      {
        Serial1.print("$GOToSolar;URANUS;7#");
      }
      else if (Solar_message == "Neptune")
      {
        Serial1.print("$GOToSolar;NEPTUNE;8#");
      }
      else if (Solar_message == "Pluto")
      {
        Serial1.print("$GOToSolar;PLUTO;9#");
      }
      else if (Solar_message == "the moon") // Ex: Ok, Google... move telescope to the moon
      {
        Serial1.print("$GOToSolar;MOON;10#");
      }
      else if (Solar_message == "moon") // Ex: Ok, Google... move telescope to moon
      {
        Serial1.print("$GOToSolar;MOON;10#");
      }
      else if (Solar_message == "Moon")
      {
        Serial1.print("$GOToSolar;MOON;10#");
      }

    } else if (subscription == &Telescope_Control_Message) {
      Control_message = ((char *)&Telescope_Control_Message.lastread);
      Serial.print(F("Control_message = "));
      Serial.println(Control_message);
      if (Control_message == "start tracking") // Ok, Google... Send start tracking
      {
        Serial1.print(":AP#");
      } else if (Control_message == "stop tracking") // Ok, Google... Send stop tracking
      {
        Serial1.print(":AL#");
      } else if (Control_message == "go home") // Ok, Google... Send go home
      {
        Serial1.print(":gotoHome#");
      }
    }
  }
  // ping the server to keep the mqtt connection alive
  // NOT required if you are publishing once every KEEPALIVE seconds
  /*
    if(! mqtt.ping()) {
    mqtt.disconnect();
    }
  */
  NGC_message = "";
  Messier_message = "";
  Solar_message = "";
  Control_message = "";
  Serial1.flush();
}
// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    digitalWrite(LED_BUILTIN, HIGH);    // if you get connected turn on the Built in LED
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  digitalWrite(buzzer, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);    // if you get connected turn on the Built in LED
  delay(200);
  digitalWrite(buzzer, LOW);
  digitalWrite(LED_BUILTIN, LOW);    // if you get connected turn on the Built in LED
  delay(200);
  digitalWrite(buzzer, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);    // if you get connected turn on the Built in LED
  delay(200);
  digitalWrite(buzzer, LOW);
  digitalWrite(LED_BUILTIN, LOW);    // if you get connected turn on the Built in LED
  delay(200);

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    digitalWrite(LED_BUILTIN, HIGH);    // if you get connected turn on the Built in LED
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
  Serial.println("MQTT Connected!");
  digitalWrite(LED_BUILTIN, HIGH);    // if you get connected turn on the Built in LED
  digitalWrite(buzzer, HIGH);
  delay(2000);
  digitalWrite(buzzer, LOW);

}
