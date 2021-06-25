/*
 * CS:APP Data Lab
 *
 * Songchen Tan <songchen@mit.edu>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(x & y) & ~(~x & ~y);
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !((x + x) ^ (~2 + 1)) & !!(x + 1);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int x0 = 0xAA;
  int x1 = (x0 << 8) + x0;
  int x2 = (x1 << 16) + x1;
  return !(x2 ^ (x & x2));
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int tmin = 1 << 31;
  int mask = tmin >> 27;
  int bool1 = !((x & mask) ^ 0x30);
  int bool2 = !(x & 8);
  int bool3 = !((x & 14) ^ 8);
  return bool1 & (bool2 | bool3);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int a = ~!!x + 1;
  int b = ~a;
  return (y & a) | (z & b);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int neg_x = ~x + 1;
  int y_minus_x = y + neg_x;
  int tmin = 1 << 31;
  return ((!!(x & tmin) & !(y & tmin)) | !(y_minus_x & tmin)) & !(!(x & tmin) & !!(y & tmin));
}
//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  int x0 = ~x;
  int x1 = x0 & (x0 >> 16);
  int x2 = x1 & (x1 >> 8);
  int x3 = x2 & (x2 >> 4);
  int x4 = x3 & (x3 >> 2);
  int x5 = x4 & (x4 >> 1);
  return x5 & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */

int howManyBits(int x) {
  int mask = 1 << 31;
  int sign = x & (1 << 31);
  int number0 = 0;
  int trial1 = 16;
  int mask1 = ~!!(((sign >> trial1) ^ x) & (mask >> trial1)) + 1;
  int number1 = (trial1 & ~mask1) | (number0 & mask1);
  int trial2 = number1 + 8;
  int mask2 = ~!!(((sign >> trial2) ^ x) & (mask >> trial2)) + 1;
  int number2 = (trial2 & ~mask2) | (number1 & mask2);
  int trial3 = number2 + 4;
  int mask3 = ~!!(((sign >> trial3) ^ x) & (mask >> trial3)) + 1;
  int number3 = (trial3 & ~mask3) | (number2 & mask3);
  int trial4 = number3 + 2;
  int mask4 = ~!!(((sign >> trial4) ^ x) & (mask >> trial4)) + 1;
  int number4 = (trial4 & ~mask4) | (number3 & mask4);
  int trial5 = number4 + 1;
  int mask5 = ~!!(((sign >> trial5) ^ x) & (mask >> trial5)) + 1;
  int number5 = (trial5 & ~mask5) | (number4 & mask5);
  return 33 + ~number5;
}
//float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exponent_value = (uf >> 23) & 0xffu;
  unsigned exponent_field = uf & (0xffu << 23);
  unsigned sign_field = uf & (1u << 31);
  unsigned fraction_field = uf & ((1u << 23) - 1);
  unsigned ret = 0;
  if (exponent_value == 0xffu) {
    ret = uf;
  } else if (exponent_value == 0xfeu) {
    ret = sign_field | (0xff << 23);
  } else if (exponent_value == 0u) {
    ret = sign_field | (fraction_field << 1);
  } else {
    ret = sign_field | (exponent_field + (1 << 23)) | fraction_field;
  }
  return ret;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned exponent_value = (uf >> 23) & 0xffu;
  int exponent_value_without_bias = exponent_value - 127;
  // unsigned exponent_field = uf & (0xffu << 23);
  unsigned sign_field = uf & (1u << 31);
  unsigned fraction_field = uf & ((1u << 23) - 1);
  unsigned recovered_fraction_field = fraction_field | (1u << 23);
  unsigned value_field = 0;
  int ret = 0;
  if (exponent_value_without_bias >= 31) {
    ret = 1 << 31;
  } else if (exponent_value_without_bias < 0) {
    ret = 0;
  } else {
    if (exponent_value_without_bias >= 23) {
      value_field = recovered_fraction_field << (exponent_value_without_bias - 23);
    } else {
      value_field = recovered_fraction_field >> (23 - exponent_value_without_bias);
    }
    if (sign_field) {
      ret = -value_field;
    } else {
      ret = value_field;
    }
  }
  return ret;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  unsigned ret = 0u;
  if (x <= -150) {
    // do nothing
  } else if (x <= -127) {
    ret = 1 << (x + 149);
  } else if (x <= 127) {
    ret = (x + 127) << 23;
  } else {
    ret = 255 << 23;
  }
  return ret;
}
