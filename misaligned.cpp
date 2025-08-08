#include <stdio.h>
#include <string.h>
#include <assert.h>
 
struct 
{
   int Colour_Index[25];
   char MajorColour[25][8]; 
   char MinorColour[25][8];
} Store_Colour_Comb;
 
int printColorMap() {
    const char* majorColor[] = {"White ", "Red   ", "Black ", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue  ", "Orange", "Green ", "Brown ", "Slate"};
    int i = 0, j = 0, k = 0, p = 0 , len = 0;
 
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            k = (i * 5 + j);
            if (k < 9)
                printf("%d  | %s | %s\n", k + 1, majorColor[i], minorColor[j]);
            else
                printf("%d | %s | %s\n", k + 1, majorColor[i], minorColor[j]);
 
            Store_Colour_Comb.Colour_Index[k] = k + 1;
 
            for (p = 0; p < 7; p++) {
                Store_Colour_Comb.MajorColour[k][p] = majorColor[i][p];
            }
            Store_Colour_Comb.MajorColour[k][7] = '\0';
 
            for (p = 0; p < 7; p++) {
                Store_Colour_Comb.MinorColour[k][p] = minorColor[j][p];
            }
            Store_Colour_Comb.MinorColour[k][7] = '\0';
        }
    }
    return i * j;
}
 
int testPrintColorMap() {
    int i,j,len,Equality_Of_Strings = 1,result;
 
    const char* string_Expected_MajColour[25] = {
        "White ", "White ", "White ", "White ", "White ",
        "Red   ", "Red   ", "Red   ", "Red   ", "Red   ",
        "Black ", "Black ", "Black ", "Black ", "Black ",
        "Yellow", "Yellow", "Yellow", "Yellow", "Yellow",
        "Violet", "Violet", "Violet", "Violet", "Violet"
    };
 
    const char* string_Expected_MinColour[25] = {
        "Blue  ", "Orange", "Green ", "Brown ", "Slate",
        "Blue  ", "Orange", "Green ", "Brown ", "Slate",
        "Blue  ", "Orange", "Green ", "Brown ", "Slate",
        "Blue  ", "Orange", "Green ", "Brown ", "Slate",
        "Blue  ", "Orange", "Green ", "Brown ", "Slate"
    };
 
   result = printColorMap();
    for (i = 0; i < 25; i++) {
        if ((strcmp(string_Expected_MinColour[i], Store_Colour_Comb.MinorColour[i]) != 0) || 
        (strcmp(string_Expected_MajColour[i], Store_Colour_Comb.MajorColour[i]) != 0)) {
            printf("Mismatch at index %d:\nExpected: %s\nActual  : %s\n", 
                   i + 1, string_Expected_MinColour[i], Store_Colour_Comb.MinorColour[i]);
            Equality_Of_Strings = 0;
        }
    }
 
    if(Equality_Of_Strings == 1)
    {
        printf("Testcase passed, Calculated Values are same as expected");
    }
    else
    {
        printf("Testcase failed, Calculated Values are not same as expected");
    }
    return 0;
}
 
