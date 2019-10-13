/*
 *  crc.h
 *
 *  copyright (c) 2019 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache2.0
 *
 *  https://github.com/shixiongfei/crc
 */

#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CRC16_SEED 0x1021                 /* CRC16-CCITT */
#define CRC32_SEED 0xEDB88320UL           /* CRC32-IEEE-802.3 */
#define CRC64_SEED 0x42F0E1EBA9EA3693ULL  /* CRC64-ECMA-182 */
#define CRC_TABLESIZE 256

void crc16_table(unsigned short *crc_table, unsigned short seed);
void crc32_table(unsigned int *crc_table, unsigned int seed);
void crc64_table(uint64_t *crc_table, uint64_t seed);

unsigned short crc16(unsigned short crc, const unsigned short *crc_table,
                     const void *buffer, int len);
unsigned int crc32(unsigned int crc, const unsigned int *crc_table,
                   const void *buffer, int len);
uint64_t crc64(uint64_t crc, const uint64_t *crc_table, 
               const void *buffer, int len);

#ifdef __cplusplus
};
#endif

#endif /* __CRC_H__ */
