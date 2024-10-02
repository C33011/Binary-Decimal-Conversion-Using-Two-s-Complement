# Binary-Decimal Conversion Using Two's Complement

## Overview

This program converts a binary string into an integer (decimal) and vice versa using two's complement representation. The conversion depends on the command-line arguments provided, which include flags to specify the operation and bit size. The program handles both conversions regardless of the position of flags in the command-line input by dynamically assigning variables. The program also handles user errors properly, such as improper flag or input syntax, returning a warning.

## Features

- **Two's Complement Conversion**: Converts between binary and decimal using two's complement.
- **Dynamic Flag Handling**: Recognizes flag positions in any order for specifying binary or decimal input.
- **Bit Size Control**: The user can specify the bit size for the conversion process.
  
## How to Use

The program accepts the following command-line arguments:

- `-bits`: Specifies the bit size for the conversion (used for both binary and decimal conversions).
- `-decimal`: Converts a given decimal number to its binary representation.
- `-binary`: Converts a given binary string to its decimal representation.

### Example Usages:

1. **Binary to Decimal Conversion**:
   ```bash
   ./program -binary 1101 -bits 4

## Compilation

To compile the program, use:
gcc -o program main.c

## License

This project is licensed under the MIT License.
