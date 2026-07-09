# Why do computers use binary?

Think of a light switch. It can only be in two states: ON or OFF. That's it. A computer is made of billions of tiny electronic switches called transistors. Each transistor can only hold a high voltage (1) or low voltage (0). So the hardware itself only knows two states.
Real life: A tubelight switch at home. On = 1, Off = 0. If you had 8 switches in a row, you could represent 2⁸ = 256 different patterns. That's exactly what 1 byte of computer memory is — 8 transistors in a row.

# Decimal → Binary (repeated division by 2)
In decimal, each position is a power of 10 (ones, tens, hundreds...). In binary, each position is a power of 2. To convert, keep dividing by 2 and note the remainders — then read them bottom to top.
Example: Convert 13 to binary
Step	Divide	Quotient	Remainder (bit)
1	13 ÷ 2	6	1 ← LSB (rightmost)
2	6 ÷ 2	3	0
3	3 ÷ 2	1	1
4	1 ÷ 2	0	1 ← MSB (leftmost)
Read remainders bottom to top → 1101. So 13 in binary = 1101. Verify: 8+4+0+1 = 13 ✓

Example: Convert 25 to binary
Step	Divide	Quotient	Remainder
1	25 ÷ 2	12	1
2	12 ÷ 2	6	0
3	6 ÷ 2	3	0
4	3 ÷ 2	1	1
5	1 ÷ 2	0	1
Read bottom to top → 11001. Verify: 16+8+0+0+1 = 25 ✓

Example: Convert 100 to binary
Step	Divide	Quotient	Remainder
1	100 ÷ 2	50	0
2	50 ÷ 2	25	0
3	25 ÷ 2	12	1
4	12 ÷ 2	6	0
5	6 ÷ 2	3	0
6	3 ÷ 2	1	1
7	1 ÷ 2	0	1
Read bottom to top → 1100100. Verify: 64+32+0+0+4+0+0 = 100 ✓

# Binary → Decimal (positional value)

Each bit position has a value that's a power of 2. The rightmost bit is 2⁰ = 1, then 2¹ = 2, 2² = 4, 2³ = 8... Just multiply each bit by its position value and sum them.
Think of Indian currency notes — ₹1, ₹2, ₹5, ₹10, ₹20, ₹50, ₹100, ₹500. Each position in binary is like a fixed denomination. A bit of 1 means "you have that note", 0 means "you don't". Your total is the sum of notes you have.
Example: 1101 → Decimal
Bit position	3	2	1	0
Power of 2	2³ = 8	2² = 4	2¹ = 2	2⁰ = 1
Bit value	1	1	0	1
Contribution	8×1 = 8	4×1 = 4	2×0 = 0	1×1 = 1
Total = 8 + 4 + 0 + 1 = 13 ✓

Example: 10110 → Decimal
Position	4	3	2	1	0
Power	16	8	4	2	1
Bit	1	0	1	1	0
Contribution	16	0	4	2	0
Total = 16 + 0 + 4 + 2 + 0 = 22

# 1's Complement - flip every bit
To find the 1's complement of a binary number, simply flip every bit: 0 becomes 1, and 1 becomes 0. That's it.
Analogy: You have a string of light switches. 1's complement means - flip every single switch. Whatever was ON goes OFF, whatever was OFF goes ON.
Example: 1's complement of 00001101 (which is 13)
Original:
00001101
After flipping every bit (1's complement):
11110010

- Problem with 1's complement: It has TWO representations of zero.
+0 = 00000000 and -0 = 11111111. They're both zero but look different. This confuses the hardware and wastes a representation. That's why computers don't actually use 1's complement for integers.


# 2's Complement — the one computers actually use
2's complement = 1's complement + 1. Just take the 1's complement and add 1 to it.
Example: 2's complement of 13 (00001101)
1
Start: 00001101 (this is +13)
2
Flip all bits (1's complement): 11110010
3
Add 1: 11110010 + 1 = 11110011
So 11110011 represents −13 in 2's complement (in an 8-bit system).

Verification: 00001101 + 11110011 = 100000000. The leading 1 overflows (ignored in 8-bit), leaving 00000000 = 0. The number plus its negative gives zero — exactly what we want!
Why 2's complement is brilliant
✓ Only one zero (00000000). No wasted representation.
✓ Subtraction is just addition: A - B becomes A + (2's complement of B). The CPU needs only one adder circuit, not a separate subtractor. Simpler, faster hardware.
✓ Every modern CPU, phone, computer uses 2's complement internally for integers.

# Signed vs unsigned - and the int range in C++
In C++, an int is 32 bits stored in 2's complement. The leftmost (most significant) bit is the sign bit: 0 means positive, 1 means negative. This leaves 31 bits for the actual value.
−2,147,483,648
int minimum (−2³¹)
2,147,483,647
int maximum (2³¹ − 1)
0
to 4,294,967,295
unsigned int range
32
bits in an int (4 bytes)
Overflow — the silent killer: If you do 2,147,483,647 + 1 in a C++ int, you don't get 2,147,483,648. You get −2,147,483,648 (wraps around). The number "overflows" the 32-bit limit. This is a real bug that has crashed rockets and caused financial errors. Always think about your data range!

```
Check it yourself in C++:

#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout << sizeof(int) << " bytes" << endl;   // 4
    cout << INT_MAX << endl;                    // 2147483647
    cout << INT_MIN << endl;                    // -2147483648
    cout << INT_MAX + 1 << endl;               // overflow!
    return 0;
}
````

