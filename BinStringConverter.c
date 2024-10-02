#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Prototype functions
int binaryStringtoInt(char *convBin, int maxLength);
int convertToBase(const char *binaryString);
void fillChar(char convBin[], int convNum, int maxLength);
bool isBinaryStringValid(const char *binaryString, int length);
bool isNumber(const char *str);

/*
    MAIN EXPLANATION: This program uses two's complement to convert
    a binary string into an integer, and vice versa, given the proper arguments.
    It handles binary-to-decimal and decimal-to-binary conversions based on the flags provided.
*/
int main(int argc, char *argv[])
{
    // Initializes the variables to be used in the for loop ahead
    int bitSize = 0;
    char *bitArg = NULL;
    int decNum = 0;
    char *decArg = NULL;
    char *binArg = NULL;
    char *binString = NULL;
    int binStrLength = 0;
    bool isBinary = false;
    bool decimalFlag = false;

    // Check if there are enough arguments provided
    if (argc < 3) {
        fprintf(stderr, "Error: Insufficient arguments provided.\n");
        fprintf(stderr, "Usage: ./program -bits <bit_size> [-decimal <decimal_value> | -binary <binary_string>]\n");
        return 1;
    }

    // Loop to process the flags and arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-bits") == 0) {
            if (i + 1 >= argc || !isNumber(argv[i + 1])) {
                fprintf(stderr, "Error: Invalid or missing bit size.\n");
                return 1;
            }
            bitArg = argv[i];
            bitSize = atoi(argv[i + 1]);
            if (bitSize <= 0) {
                fprintf(stderr, "Error: Bit size must be a positive integer.\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-decimal") == 0) {
            if (i + 1 >= argc || !isNumber(argv[i + 1])) {
                fprintf(stderr, "Error: Invalid or missing decimal value.\n");
                return 1;
            }
            decArg = argv[i];
            decNum = atoi(argv[i + 1]);
            decimalFlag = true;
        }
        else if (strcmp(argv[i], "-binary") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: Missing binary string.\n");
                return 1;
            }
            binArg = argv[i];
            binString = argv[i + 1];
            binStrLength = strlen(binString);
            if (!isBinaryStringValid(binString, binStrLength)) {
                fprintf(stderr, "Error: Invalid binary string. Only '0' and '1' are allowed.\n");
                return 1;
            }
            isBinary = true;
        }
    }

    // Check if the necessary flags were provided
    if (!decArg && !binArg) {
        fprintf(stderr, "Error: Either -decimal or -binary flag must be provided.\n");
        return 1;
    }

    // Determines whether the program will convert binary to decimal or vice versa
    if (isBinary) {
        // Convert binary to decimal
        int convDecNum = binaryStringtoInt(binString, binStrLength);
        printf("%s in binary is equal to %d in decimal using %d-bit two's complement representation.\n",
               binString, convDecNum, binStrLength);
    } else if (decimalFlag) {
        // Convert decimal to binary
        if (!bitArg) {
            fprintf(stderr, "Error: -bits flag is required for decimal conversion.\n");
            return 1;
        }
        char decimalString[bitSize + 1];
        for (int i = 0; i < bitSize; i++) {
            decimalString[i] = '0';
        }
        decimalString[bitSize] = '\0';
        fillChar(decimalString, decNum, bitSize);
        printf("%i in decimal is equal to %s in binary using %d-bit two's complement representation.\n",
               decNum, decimalString, bitSize);
    }

    return 0;
}

// Uses a for loop to convert a number into binary and add it into an empty array
void fillChar(char *convBin, int convNum, int maxLength) {
    for (int i = maxLength - 1; i >= 0; i--) {
        convBin[maxLength - 1 - i] = (convNum & (1 << i)) ? '1' : '0';
    }
}

// Returns the integer conversion of a binary string
int binaryStringtoInt(char *convBin, int maxLength) {
    int result = 0;

    if (convBin[0] == '1') {
        for (int i = 0; i < maxLength; i++) {
            result = (result << 1) | (convBin[i] == '0');
        }
        result = ~result;
    } else {
        for (int i = 0; i < maxLength; i++) {
            result = (result << 1) | (convBin[i] - '0');
        }
    }

    return result;
}

// Validates whether a string consists only of '0's and '1's
bool isBinaryStringValid(const char *binaryString, int length) {
    for (int i = 0; i < length; i++) {
        if (binaryString[i] != '0' && binaryString[i] != '1') {
            return false;
        }
    }
    return true;
}

// Checks if a string represents a valid integer number
bool isNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
