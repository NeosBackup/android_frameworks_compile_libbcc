/* ====-- ashldi3.c - Implement __ashldi3 -----------------------------------===
 *
 *                     The LLVM Compiler Infrastructure
 *
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 *
 * ===----------------------------------------------------------------------===
 *
 * This file implements __ashldi3 for the compiler_rt library.
 *
 * ===----------------------------------------------------------------------===
 */

<<<<<<< HEAD
#if !defined(__GNUC__) || (__GNUC__ < 4) || (__GNUC__ == 4 && __GNUC_MINOR__ < 6)
=======
#if !defined(__GNUC__) || __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 8) // gcc >= 4.8 implements this in libgcc
>>>>>>> 78759b0... libbcc: Fix build with gcc 4.8+
#include "int_lib.h"

/* Returns: a << b */

/* Precondition:  0 <= b < bits_in_dword */

di_int
__ashldi3(di_int a, si_int b)
{
    const int bits_in_word = (int)(sizeof(si_int) * CHAR_BIT);
    dwords input;
    dwords result;
    input.all = a;
    if (b & bits_in_word)  /* bits_in_word <= b < bits_in_dword */
    {
        result.s.low = 0;
        result.s.high = input.s.low << (b - bits_in_word);
    }
    else  /* 0 <= b < bits_in_word */
    {
        if (b == 0)
            return a;
        result.s.low  = input.s.low << b;
        result.s.high = (input.s.high << b) | (input.s.low >> (bits_in_word - b));
    }
    return result.all;
}
#endif
