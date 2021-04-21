/* Try the XORShift on different size integers */


#include <stdio.h>
#include <stdint.h>

uint16_t random_state_16 = 1234;
uint32_t random_state_32 = 1234;

uint16_t random_u16() {
    uint16_t result = random_state_16;
    result ^= result << 7;
    result ^= result >> 9;
    result ^= result << 8;
    random_state_16 = result;
    return result;
}

uint32_t random_u32() {
    uint32_t result = random_state_32;
    result ^= result << 13;
    result ^= result >> 17;
    result ^= result << 5;
    random_state_32 = result;
    return result;
}


uint16_t random_int_range_16(int min, int max) {
    int range = max - min;
    int result = random_u16() % range;
    result += min;
    return result;
}

void print_u16() {
    printf("%u\n", random_u16());
    printf("%u\n", random_u16());
    printf("%u\n", random_u16());
    printf("%u\n", random_u16());
    printf("%u\n", random_u16());
}

void print_u32() {
    printf("%u\n", random_u32());
    printf("%u\n", random_u32());
    printf("%u\n", random_u32());
    printf("%u\n", random_u32());
    printf("%u\n", random_u32());
}

void print_range_u16() {
    printf("%u : ", random_int_range_16(0, 10));
    printf("%u : ", random_int_range_16(0, 10));
    printf("%u : ", random_int_range_16(0, 10));
    printf("%u : ", random_int_range_16(0, 10));
    printf("%u\n", random_int_range_16(0, 10));
}

void loop_change_seed() {
    
    for(int i = 0; i < 6; ++i) {
        random_state_16 = i;
        print_range_u16();
    }
    
}

int main() {
    //print_u16();
    //printf("========\n");
    //print_u32();
    //printf("========\n");
    //print_range_u16();
    loop_change_seed();
    return 0;
}
