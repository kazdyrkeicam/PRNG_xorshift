#include <stdio.h>
#include <stdint.h>

uint16_t random_state_16 = 1;

uint16_t random_u16() {
    uint16_t result = random_state_16;
    result ^= result << 7;
    result ^= result >> 9;
    result ^= result << 8;
    random_state_16 = result;
    return result;
}

uint8_t random_int_range_16(uint8_t min, uint8_t max) {
    uint8_t range = max - min;
    uint8_t result = random_u16() % range;
    result += min;
    return result;
}

void print_range_u16() {
    for( int i = 0; i < 15; ++i ) {
        printf("%d | ", i);
        for( int j = 0; j < 11; ++j ) {
            printf("%u : ", random_int_range_16(0, 10));
        }
        printf("%u\n", random_int_range_16(0, 10));
    }
}

void loop_change_seed_u16() {
    
    for(int i = 0; i < 6; ++i) {
        random_state_16 = (random_state_16 * i) + random_state_16;
        print_range_u16();
    }
    
}
