#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <ESP8266WiFi.h>
#include "endianUtil.hpp"

// A message, as defined in this file, can be read from a byte stream direktly.
// For dokumentation on the message types look at the protocoll spezification
// For each Message there is also a function implemented wich creaetes one from falues.

struct connectionMsg{
    uint8_t version[2];     /**< 2 bytes for the version */
    uint8_t magicNumber[2]; /**< 2 bytes for the magic Number */
} __attribute__((packed));  //this line is to prevent the compiler form inserting pedding
connectionMsg createConnectionMsg(uint16_t version,uint16_t magicNumber);


struct connectionResponse{
  uint8_t version[2];   /**< 2 bytes for the version */
  uint8_t sessionId[2]; /**< 2 bytes for the session ID*/
} __attribute__((packed));
connectionResponse createConnectionResponse(uint16_t version,uint16_t sessionId);

struct messageHeader{
  uint8_t sessionId[2]; /**< 2 bytes for the session ID */
  uint8_t paketNR[3];   /**< 3 bytes paket number */
  uint8_t dataCount;    /**< 1 byte data count */
} __attribute__((packed));
messageHeader createMessageHeader(uint16_t sessionId,uint32_t paketNR,uint8_t dataCount);

struct deviceCommand{
  uint8_t device[2];    /**< 2 bytes for device */
  uint8_t data[2];      /**< 2 bytes for device data */
} __attribute__((packed));
deviceCommand createDeviceCommand(uint16_t device,uint16_t data);

#endif