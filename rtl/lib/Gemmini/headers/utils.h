#ifndef UTILS__H
#define UTILS__H

#include <climits>

#define DEBUG_LINE printf("[DEBUG]: %s %d\n", __FILE__, __LINE__);

#define DEBUG_ON 0
#define debugprintf(...) { if (DEBUG_ON) printf(__VA_ARGS__); }

#define DEBUG_DESCTR_ON 0
#define printfinish(...) { if (DEBUG_DESCTR_ON) printf("%s\n", __FUNCTION__); }

#define LOOP(iii,N) for (uint32_t iii = 0; iii < N; iii++)

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define BLUE  "\033[34m"


static char bits[256] =
{
      0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,  /* 0   - 15  */
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  /* 16  - 31  */
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  /* 32  - 47  */
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  /* 48  - 63  */
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  /* 64  - 79  */
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  /* 80  - 95  */
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  /* 96  - 111 */
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  /* 112 - 127 */
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  /* 128 - 143 */
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  /* 144 - 159 */
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  /* 160 - 175 */
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  /* 176 - 191 */
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  /* 192 - 207 */
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  /* 208 - 223 */
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  /* 224 - 239 */
      4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8   /* 240 - 255 */
};


uint32_t popcount(int x)
{
    return bits[ (int) (x & 0x000000FFUL) >> 0  ] +
           bits[ (int)((x & 0x0000FF00UL) >> 8) ] +
           bits[ (int)((x & 0x00FF0000UL) >> 16)] +
           bits[ (int)((x & 0xFF000000UL) >> 24)];
}


uint8_t numPlaces (int n)
{
    uint8_t r = 1;
    
    if (n < 0) 
        n = (n == INT_MIN) ? INT_MAX: -n;
    
    while (n > 9)
    {
        n /= 10;
        r++;
    }
    return r;
}


void ffprintf (FILE *fp, int val) // imprime valor em fp forcando o uso de N_CHARS
{
#if 0
    fprintf(fp, "%d ", val);
#else // injecting at the GL results in many digits. and the code below breaks.
    #define N_CHARS 12
        char str[3*N_CHARS];

        uint8_t digits = numPlaces(val);
        uint8_t rem = 0;

        sprintf (str, "%d", val);

        if (digits < N_CHARS)
            rem = N_CHARS - digits;

        if (val < 0)
            rem--;

        for (uint8_t i = 0; i < rem; i++)
            strcat (str, " ");

        fprintf(fp, "%s", str);
#endif
}
#endif

