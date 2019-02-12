#pragma once

#include "common.h"
#include "crypto/base64.h"
#include "crypto/sha1.h"

namespace crypto {
    String base64Encode(String data) {
      return internals::base64_encode((const unsigned char *) data.c_str(), data.size());
    }
    String base64Encode(uint8_t* data, size_t len) {
      return internals::base64_encode((const unsigned char *) data, len);
    }
    
    String base64Decode(String data) {
      return internals::base64_decode(data);
    }

    String sha1(String data) {
        SHA1 checksum;
        checksum.update(data);
        return checksum.final();
    }

    String randomBytes(size_t len) {
      // TODO: fix dummy implementation (16 is the number of websockets key length for handshakes)
      if(len == 16) {
        return "1234567890123456";
      }
      return "";
    }
}