#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// Configurações WiFi
#define WLAN_SSID       "SEU_SSID"
#define WLAN_PASS       "SUA_SENHA"

// Configurações Adafruit IO
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883 // MQTT porta
#define AIO_USERNAME    "SEU_USERNAME_IO"
#define AIO_KEY         "SUA_AIO_KEY"

WiFiClient client;

// Config. MQTT
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Feed (substitua USERNAME e FEED)
Adafruit_MQTT_Publish wifi_signal_db = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/wifi-signal-db");

void setup() {
  Serial.begin(115200);
  delay(10);

  // Conectando ao WiFi
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");

  // Conectar ao servidor MQTT
  connect_MQTT();
}

void connect_MQTT() {
  int8_t ret;
  while ((ret = mqtt.connect()) != 0) {
    Serial.print(".");
    delay(2000);
  }
  Serial.println("Conectado ao MQTT!");
}

void loop() {
  // Garante conexão MQTT
  if (!mqtt.connected()) {
    connect_MQTT();
  }
  mqtt.processPackets(10000);
  mqtt.ping();

  // Medida RSSI (dBm)
  int32_t rssi = WiFi.RSSI();
  Serial.print("dBm atual: ");
  Serial.println(rssi);

  // Publica via MQTT
  if (!wifi_signal_db.publish(rssi)) {
    Serial.println("Falha ao publicar!");
  }

  delay(5000); // Aguarda 5 segundos para medir novamente
}
