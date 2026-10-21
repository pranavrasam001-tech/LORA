#include <Arduino.h>
#include <SPI.h>
#include <RadioLib.h>

#define LORA_NSS 21
#define LORA_DIO1 16
#define LORA_NRST 23
#define LORA_BUSY 22

#define LORA_SCK 18
#define LORA_MISO 20
#define LORA_MOSI 19

#define LORA_FREQUENCY 868.0
#define LORA_BANDWIDTH 125.0
#define LORA_SPREADING_FACTOR 9
#define LORA_CODING_RATE 7
#define LORA_TX_POWER 10

SX1262 radio = new Module(
    LORA_NSS,
    LORA_DIO1,
    LORA_NRST,
    LORA_BUSY
);

volatile bool packetReceived = false;
bool radioReady = false;

void setPacketReceived() {
    packetReceived = true;
}

void printHelp() {
    Serial.println();
    Serial.println("LoRa Puck Commands");
    Serial.println("------------------");
    Serial.println("t <message>  Transmit a message");
    Serial.println("r            Enter receive mode");
    Serial.println("s            Display radio status");
    Serial.println("h            Display this help");
    Serial.println();
}

void displayRadioStatus() {
    Serial.print("Radio initialized: ");
    Serial.println(radioReady ? "YES" : "NO");

    if (radioReady) {
        Serial.print("Frequency: ");
        Serial.print(LORA_FREQUENCY);
        Serial.println(" MHz");
    }
}

void startReceiveMode() {
    int state = radio.startReceive();

    if (state == RADIOLIB_ERR_NONE) {
        Serial.println("Listening for LoRa packets...");
    } else {
        Serial.print("Failed to enter receive mode. Error: ");
        Serial.println(state);
    }
}

void transmitMessage(String message) {
    if (!radioReady) {
        Serial.println("Radio is not initialized.");
        return;
    }

    Serial.print("Transmitting: ");
    Serial.println(message);

    int state = radio.transmit(message);

    if (state == RADIOLIB_ERR_NONE) {
        Serial.println("Transmission successful.");
    } else {
        Serial.print("Transmission failed. Error: ");
        Serial.println(state);
    }

    startReceiveMode();
}

void processReceivedPacket() {
    packetReceived = false;

    String message;

    int state = radio.readData(message);

    if (state == RADIOLIB_ERR_NONE) {
        Serial.println();
        Serial.println("Packet received!");
        Serial.print("Message: ");
        Serial.println(message);

        Serial.print("RSSI: ");
        Serial.print(radio.getRSSI());
        Serial.println(" dBm");

        Serial.print("SNR: ");
        Serial.print(radio.getSNR());
        Serial.println(" dB");

    } else {
        Serial.print("Receive error: ");
        Serial.println(state);
    }

    startReceiveMode();
}

void processSerialCommand() {
    if (!Serial.available()) {
        return;
    }

    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command.length() == 0) {
        return;
    }

    if (command.startsWith("t ")) {
        transmitMessage(command.substring(2));
    } else if (command == "r") {
        startReceiveMode();
    } else if (command == "s") {
        displayRadioStatus();
    } else if (command == "h") {
        printHelp();
    } else {
        Serial.println("Unknown command. Enter h for help.");
    }
}

void setup() {
    Serial.begin(115200);

    unsigned long startTime = millis();

    while (!Serial && millis() - startTime < 5000) {
        delay(10);
    }

    Serial.println();
    Serial.println("LoRa Puck Starting...");

    SPI.setSCK(LORA_SCK);
    SPI.setTX(LORA_MOSI);
    SPI.setRX(LORA_MISO);
    SPI.begin();

    Serial.println("Initializing SX1262...");

    int state = radio.begin(
        LORA_FREQUENCY,
        LORA_BANDWIDTH,
        LORA_SPREADING_FACTOR,
        LORA_CODING_RATE,
        RADIOLIB_SX126X_SYNC_WORD_PRIVATE,
        LORA_TX_POWER,
        8,
        1.6,
        false
    );

    if (state == RADIOLIB_ERR_NONE) {
        radioReady = true;

        Serial.println("SX1262 initialized successfully.");

        radio.setDio1Action(setPacketReceived);

        startReceiveMode();
        printHelp();

    } else {
        Serial.print("SX1262 initialization failed. Error: ");
        Serial.println(state);
        Serial.println("Check SPI pins, power, RESET, BUSY, and DIO1.");
    }
}

void loop() {
    processSerialCommand();

    if (radioReady && packetReceived) {
        processReceivedPacket();
    }

    delay(5);
}
