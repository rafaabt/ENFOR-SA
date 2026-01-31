#ifndef UTILS__H
#define UTILS__H

#include <climits>

#define DEBUG_LINE printf("[DEBUG]: %s %d\n", __FILE__, __LINE__);

#define DEBUG_ON 0
#define debugprintf(...) { if (DEBUG_ON) printf(__VA_ARGS__); }

#define DEBUG_DESCTR_ON 0
#define printfinish(...) { if (DEBUG_DESCTR_ON) printf("%s\n", __FUNCTION__); }

#define LOOP(iii,N) for (uint32_t iii = 0; iii < N; iii++)

#define RESET2   "\033[0m"  // gemmini.h tem um valor chamado RESET
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

#define BRIGHT_BLACK "\033[90m"
#define BOLDBLACK    "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED      "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN    "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW   "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE     "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA  "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN     "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE    "\033[1m\033[37m"      /* Bold White */

#define UNDERLINE "\033[4m"
#define BLINK     "\033[6m"
#define BOLD      "\033[1m"
#define ITALIC    "\033[3m"





// \033[<style>;<foreground>;<background>m
// colors in https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit

// #define HEADER "\33[1;3;36;44m"  // bold + italic + green text + blue bg

#define HEADER "\33[30m" "\33[104m"   
                 // fg         bg 


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
    #define N_CHARS 10
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

