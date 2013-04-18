#ifndef crypto_onetimeauth_poly1305_H
#define crypto_onetimeauth_poly1305_H

#define crypto_onetimeauth_poly1305_BYTES 16
#define crypto_onetimeauth_poly1305_KEYBYTES 32
#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <stdint.h>
#include <stdio.h>

typedef struct crypto_onetimeauth_poly1305_implementation {
    const char *(*implementation_name)(void);
    int         (*onetimeauth)(unsigned char *out,
                               const unsigned char *in,
                               unsigned long long inlen,
                               const unsigned char *k);
    int         (*onetimeauth_verify)(const unsigned char *h,
                                      const unsigned char *in,
                                      unsigned long long inlen,
                                      const unsigned char *k);
} crypto_onetimeauth_poly1305_implementation;

const char *crypto_onetimeauth_poly1305_ref_implementation_name(void);
    
int crypto_onetimeauth_poly1305_set_implementation(crypto_onetimeauth_poly1305_implementation *impl);

int crypto_onetimeauth_poly1305(unsigned char *out,
                                const unsigned char *in,
                                unsigned long long inlen,
                                const unsigned char *k);

int crypto_onetimeauth_poly1305_verify(const unsigned char *h,
                                       const unsigned char *in,
                                       unsigned long long inlen,
                                       const unsigned char *k);

#ifdef __cplusplus
}
#endif

#endif
