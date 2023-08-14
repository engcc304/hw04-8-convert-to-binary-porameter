/*
    จงแปลงเลขฐาน 16 ที่รับมาจากผู้ใช้ให้กลายเป็นเลขฐาน 2
    
    Test case:
        User input :
            FB
    Output:
        11111011

    Test case:
        User input :
            19
    Output:
        11001
*/

#include <stdio.h>
#include <string.h>

int hexDigitToBinary(char hexDigit) { //When accepting a player as a hexadecimal number and converting it to a binary value (binary)
    //then giving a comparison table to convert the hexadecimal number to a binary number and then return the converted binary value.
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0' ;
    } else if (hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10 ;
    } else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10 ;
    }
    return -1;
}

void hexToBinary(const char *hexString, char *binaryResult) { //A function that takes a string hex parameter to convert to binary. and store the result in a variable binaryResult.
    int length = strlen(hexString) ; //Calculate the length of the supplied hex string.
    for (int i = 0; i < length; i++) { //loop for the number of characters in a string.
        int digitValue = hexDigitToBinary(hexString[i]) ;  //to convert the hex number in the i position of the hex string to binary.
        if (digitValue >= 0) { //if line 36  the condition can be executed.
            for (int j = 3; j >= 0; j--) {
                binaryResult[i * 4 + (3 - j)] = (digitValue >> j) & 1 ? '1' : '0' ; //Determine the last character of a string correctly.
            }//end for
        } else {
            // Invalid hex digit
            binaryResult[0] = '\0' ;
            return;
        }//end else
    }//end for
    binaryResult[length * 4] = '\0';
}//end void 
//Lines 21-35: Save the hex to binary conversion result in the binaryResult variable and print the result.
int main() {
    char hexString[16] ; //Declare a variable to hold a value of no more than 16 characters.
    char binaryResult[65] ; // To hold 16 hex digits * 4 bits/digit + null terminator

    printf( "User input :\n") ;
    scanf( "%s", hexString) ;

    hexToBinary(hexString, binaryResult); //Converts hex strings to binary numbers.

    if (binaryResult[0] != '\0') { // if condition is true can ba executed.
        printf( "Output:\n") ; // output variable binaryresult on display.
        printf( "%s\n", binaryResult);
    } else { //if condition is false can be executed.
        printf( "Invalid input\n" ) ; //output invlid input on display
    }//end else

    return 0 ;
}//end main funtion

