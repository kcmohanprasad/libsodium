#ifndef crypto_hash_sha256_H
#define crypto_hash_sha256_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "export.h"

#define crypto_hash_sha256_BYTES 32U
#define crypto_hash_sha256_BLOCKBYTES 64U

#ifdef __cplusplus
# if __GNUC__
#  pragma GCC diagnostic ignored "-Wlong-long"
# endif
extern "C" {
#endif

typedef struct crypto_hash_sha256_state {
    uint32_t      state[8];
    uint32_t      count[2];
    unsigned char buf[64];
} crypto_hash_sha256_state;

SODIUM_EXPORT
size_t crypto_hash_sha256_bytes(void);

SODIUM_EXPORT
const char * crypto_hash_sha256_primitive(void);

SODIUM_EXPORT
int crypto_hash_sha256(unsigned char *,const unsigned char *,unsigned long long);

SODIUM_EXPORT
int crypto_hash_sha256_init(crypto_hash_sha256_state *state);

SODIUM_EXPORT
int crypto_hash_sha256_update(crypto_hash_sha256_state *state,
                              const unsigned char *in,
                              unsigned long long inlen);

SODIUM_EXPORT
int crypto_hash_sha256_final(crypto_hash_sha256_state *state,
                             unsigned char *out);

#ifdef __cplusplus
}
#endif

#define crypto_hash_sha256_cp crypto_hash_sha256

#endif
