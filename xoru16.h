#include <stdio.h>
#include <stdint.h>

#define MAX 0x38
#define MIN 0x00

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


uint8_t final_random_16() {
    uint8_t range = MAX - MIN;
    uint8_t result = random_u16() % range;
    
    if ( result > 0x27 && result < 0x2D ) {
        result += 0x06;
    }
    return result;
}

void print_final_range_u16() {
    for( int i = 0; i < 15; ++i ) {
        printf("%d | ", i);
        for( int j = 0; j < 11; ++j ) {
            printf("%x : ", final_random_16());
        }
        printf("%x\n", final_random_16());
    }
}

void loop_change_seed_u16() {
    
    for(int i = 0; i < 6; ++i) {
        random_state_16 = (random_state_16 * i) + random_state_16;
        print_range_u16();
    }
    
}
