Binary-Decimal Conversion Using Two's Complement

Overview

This program converts a binary string into an integer (decimal) and vice versa using two's complement representation. The conversion depends on the command-line arguments provided, which include flags to specify the operation and bit size. The program handles both conversions regardless of the position of flags in the command-line input by dynamically assigning variables.

Features

- Two's Complement Conversion: Converts between binary and decimal using two's complement.
- Dynamic Flag Handling: Recognizes flag positions in any order for specifying binary or decimal input.
- Bit Size Control: The user can specify the bit size for the conversion process.

How to Use

The program accepts the following command-line arguments:

- -bits: Specifies the bit size for the conversion (used for both binary and decimal conversions).
- -decimal: Converts a given decimal number to its binary representation.
- -binary: Converts a given binary string to its decimal representation.

Example Usages:

1. Binary to Decimal Conversion:
   ./program -binary 1101 -bits 4
   Output:
   1101 in binary is equal to -3 in decimal using 4-bit two's complement representation.

2. Decimal to Binary Conversion:
   ./program -decimal 5 -bits 4
   Output:
   5 in decimal is equal to 0101 in binary using 4-bit two's complement representation.

Note:
- The program assumes correct input and does not perform error handling.
- The maximum bit size should be appropriate for the system's integer representation.

Files

- main.c: Contains the main logic for handling input arguments and conversion between binary and decimal.
- Functions:
  - binaryStringtoInt: Converts a binary string into an integer.
  - fillChar: Converts a decimal number to a binary string.
  - convertToBase: Computes the decimal value of a binary string.

Compilation

To compile the program, use:
gcc -o program main.c

License

This project is licensed under the MIT License.
