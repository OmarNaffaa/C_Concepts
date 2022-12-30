#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
    Objective of code:
    --> Obtain 32 bit output from a 64 bit API. Only lower 32 bits will be retained
        since type is smaller
*/

void qurt_dummy_func(uint64_t* timeticks)
{
    printf("\nOutput before qurt_dummy_func (64-bit value): %" PRIx64 "\n", *timeticks);
    *timeticks = 0xFFFFFFFFAAAAAAAA;
    printf("Output after qurt_dummy_func (64-bit value): %" PRIx64 "\n\n", *timeticks);
}

void middle_func(uint32_t* ticks)
{
    uint64_t ticks_64bit = (uint64_t)(*ticks);

    printf("\nOutput of 32-bit value before middle_func: %" PRIx32 "\n", *ticks);
    printf("Output of 64-bit value before middle_func: %" PRIx64 "\n", ticks_64bit);

    qurt_dummy_func(&ticks_64bit);
    *ticks = (uint32_t)(ticks_64bit);

    printf("Output of 32-bit value after middle_func: %" PRIx32 "\n", *ticks);
    printf("Output of 64-bit value after middle_func: %" PRIx64 "\n\n", ticks_64bit);
}

int main() {
    uint32_t timeticks = 0;
    middle_func(&timeticks);
    printf("Output from main: %" PRIx32 "\n\n", timeticks);

    return 0;
}