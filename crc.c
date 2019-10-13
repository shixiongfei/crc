/*
 *  crc.c
 *
 *  copyright (c) 2019 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache2.0
 *
 *  https://github.com/shixiongfei/crc
 */

#include "crc.h"

void crc16_table(unsigned short *crc_table, unsigned short seed) {
  unsigned short i, j, r;

  for (i = 0; i < CRC_TABLESIZE; ++i) {
    r = i << 8;
    for (j = 0; j < 8; ++j)
      r = (r << 1) ^ ((r & 0x8000) ? seed : 0);
    crc_table[i] = r;
  }
}

void crc32_table(unsigned int *crc_table, unsigned int seed) {
  unsigned int i, j, r;

  for (i = 0; i < CRC_TABLESIZE; ++i) {
    r = i;
    for (j = 0; j < 8; ++j)
      r = (r >> 1) ^ ((r & 1) ? seed : 0);
    crc_table[i] = r;
  }
}

#if 0
static uint64_t crc_reflect(uint64_t data, int data_len) {
  uint64_t retval = data & 0x01;
  int i;

  for (i = 1; i < data_len; ++i) {
    data >>= 1;
    retval = (retval << 1) | (data & 0x01);
  }
  return retval;
}
#endif

void crc64_table(uint64_t *crc_table, uint64_t seed) {
  uint64_t i, j, r;

  for (i = 0; i < CRC_TABLESIZE; ++i) {
    r = i << 56;
    for (j = 0; j < 8; ++j)
      r = (r << 1) ^ ((r & 0x8000000000000000ULL) ? seed : 0);
    crc_table[i] = r;
  }
}

unsigned short crc16(unsigned short crc, const unsigned short *crc_table,
                     const void *buffer, int len) {
  const unsigned char *b = (const unsigned char *)buffer;

  if (!buffer || (len <= 0))
    return 0;

  while (0 != len--)
    crc = (crc << 8) ^ crc_table[((crc >> 8) ^ *b++) & 0xFF];

  return crc;
}

unsigned int crc32(unsigned int crc, const unsigned int *crc_table,
                   const void *buffer, int len) {
  const unsigned char *b = (const unsigned char *)buffer;

  if (!buffer || (len <= 0))
    return 0;

  crc = ~crc;

  while (0 != len--)
    crc = (crc >> 8) ^ crc_table[*b++ ^ (crc & 0xFF)];

  return ~crc;
}

uint64_t crc64(uint64_t crc, const uint64_t *crc_table, 
               const void *buffer, int len) {
  const unsigned char *b = (const unsigned char *)buffer;

  if (!buffer || (len <= 0))
    return 0;

  while (0 != len--)
    crc = (crc << 8) ^ crc_table[((crc >> 56) ^ *b++) & 0xFF];

  return crc;
}
