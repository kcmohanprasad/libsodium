#include "crypto_shorthash_siphash24.h"

size_t
crypto_shorthash_siphash24_bytes(void) {
    return crypto_shorthash_siphash24_BYTES;
}

size_t
crypto_shorthash_siphash24_keybytes(void) {
    return crypto_shorthash_siphash24_KEYBYTES;
}

const char *
crypto_shorthash_siphash24_primitive(void) {
    return "siphash24";
}
