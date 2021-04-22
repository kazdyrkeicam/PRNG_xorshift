#include <stdio.h>
#include <stdint.h>

uint32_t random_state_32 = 1234;

uint32_t random_u32() {
    uint32_t result = random_state_32;
    result ^= result << 13;
    result ^= result >> 17;
    result ^= result << 5;
    random_state_32 = result;
    return result;
}

uint32_t random_int_range_32(uint8_t min, uint8_t max) {
    uint8_t range = max - min;
    uint8_t result = random_u32() % range;
    result += min;
    return result;
}

void print_range_u32() {
    printf("%u : ", random_int_range_32(0, 10));
    printf("%u : ", random_int_range_32(0, 10));
    printf("%u : ", random_int_range_32(0, 10));
    printf("%u : ", random_int_range_32(0, 10));
    printf("%u\n", random_int_range_32(0, 10));
}
