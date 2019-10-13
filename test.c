/*
 *  test.c
 *
 *  copyright (c) 2019 Xiongfei Shi
 *
 *  author: Xiongfei Shi <jenson.shixf(a)gmail.com>
 *  license: Apache2.0
 *
 *  https://github.com/shixiongfei/crc
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "crc.h"

int main(int argc, char *argv[]) {
  const char text[] = { "Hello World!" };

  unsigned short tbl_crc16[CRC_TABLESIZE] = { 0 };
  unsigned int tbl_crc32[CRC_TABLESIZE] = { 0 };
  uint64_t tbl_crc64[CRC_TABLESIZE] = { 0 };

  unsigned short c16;
  unsigned int c32;
  uint64_t c64;

  crc16_table(tbl_crc16, CRC16_SEED);
  crc32_table(tbl_crc32, CRC32_SEED);
  crc64_table(tbl_crc64, CRC64_SEED);

  c16 = crc16(0, tbl_crc16, NULL, -1);
  c32 = crc32(0, tbl_crc32, NULL, -1);
  c64 = crc64(0, tbl_crc64, NULL, -1);
  
  printf("CRC16: %x\n", crc16(c16, tbl_crc16, text, (int)strlen(text)));
  printf("CRC32: %x\n", crc32(c32, tbl_crc32, text, (int)strlen(text)));
  printf("CRC64: %"PRIx64"\n", crc64(c64, tbl_crc64, text, (int)strlen(text)));
  
  return 0;
}
