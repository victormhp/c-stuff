#include "cmd.h"

void str_to_numerical(const unsigned char* str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    printf("C       Bin  Oct  Hex\n");
    printf("-  --------  ---  ---\n");

    for (int i = 0; i < len; i++) {
        printf("%c  %08b  %3o  %3x\n", str[i], str[i], str[i], str[i]);
    }
}
