// Ata Çuhan 2637585
#include <stdio.h>

int main() {
    char selection = 0;
    int base,s1, s0, d, y0, y1, y2, y3, base10input;
    char s1c , s0c , dc , eof; // char versions of variables. eof is for checking if more than 3 bits entered

    while (selection != 'b') { // This loop keeps the program running till quit option (b) is entered.
        printf("\n\nWelcome to 1 TO 4 DEMULTIPLEXER!\n");
        printf("\na) Compute and Display the outputs\nb) Quit \n");

        do  { // Keeps asking for a valid input for the selection.
            printf("You choose: ");
            scanf(" %c", &selection);

            if (selection == 'a') {
                printf("You have chosen option %c", selection);
            }   else if (selection == 'b') {
                printf("You have chosen option %c\n", selection);
                printf("BYEE!!");
                return 0;
            }   else {
                printf("Invalid option! Choose either a or b!\n\n");
            }
        } while (selection !='a' && selection !='b' );

        int isValid = 0;

        do { // Do while loop to repeat asking if base input is different then 2 or 10.
            printf("\n\nWhich base will you use to enter input (base 2 or base 10)? ");
            scanf("%d", &base);


            do {
                if (base == 2) {
                    printf("Please enter your input:"); // Press enter more than once if code doesn't work !!!
                    scanf(" %c%c%c%c", &s1c, &s0c, &dc, &eof);

                    if ((s1c != '0' && s1c != '1') || (s0c != '0' && s0c != '1') || (dc != '0' && dc != '1' && dc != '\n' )) {
                        printf(" %c%c%c%c is not a valid number in base 2! Please try again!\n", s1c, s0c, dc, eof);
                        fflush(stdin);
                    }   else if (eof != '\n') { // eof is an extra char to test if more than 3 bits are entered.
                        printf("You entered more than 3-bits! Please try again!\n");
                        fflush(stdin);

                    }   else if (s1c == '\n' || s0c == '\n' || dc == '\n' ){
                        printf("You entered less than 3-bits! Please try again!\n");
                        fflush(stdin);
                    }   else {
                        isValid = 1;
                        s1 = s1c - 48;
                        s0 = s0c - 48;
                        d = dc - 48;

                        y0 = (!s1) && (!s0) && d;
                        y1 = (!s1) && s0 && d;
                        y2 = s1 && (!s0) && d;
                        y3 = s1 && s0 && d;
                        printf("Y3 is %d Y2 is %d Y1 is %d Y0 is %d", y3, y2, y1, y0);

                    }
                }


                if (base == 10) {
                    do {
                        printf("Please enter you input: ");
                        scanf("%d", &base10input);
                        if (base10input > 7) { // Error if any input > 7 entered for base 10 input.
                            printf("Decimal %d cannot be represented with 3 bits. Please try again!\n", base10input);
                        }
                    } while (base10input > 7);

                    // Base10 to base2 converter.
                    s1 = base10input / 4;
                    s0 = (base10input % 4) / 2;
                    d = base10input % 2;
                    y0 = (!s1) && (!s0) && d;
                    y1 = (!s1) && s0 && d;
                    y2 = s1 && (!s0) && d;
                    y3 = s1 && s0 && d;
                    printf("Y3 is %d Y2 is %d Y1 is %d Y0 is %d\n", y3, y2, y1, y0);
                    isValid = 1;

                } if(base != 2 && base != 10) {
                    printf("\nInvalid base number !\n");
                    printf("Please re-enter a valid base number (2 or 10)");
                }
            }while (isValid != 1);
        } while (base != 2 && base != 10);
    }
    return 0;
}
