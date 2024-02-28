#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string is a palindrome
bool palindrome(char* str) {
    int l = 0, r = strlen(str) - 1;
    while (l <= r) {
        if (str[l] != str[r]) // Corrected the condition here
            return false;
        l++;
        r--;
    }
    return true;
}

// function de in ra phan tu nhieu nhat 
char mostfrequentchar(char *s) {
    int count[256] = {0}; //mang dem so lan xuat hien
    for (size_t i = 0; i < strlen(s); i++) {
        count[(char)s[i]]++; 
    }
    //Dung res de tim so lan xuat hien va phan tu cua no
    int max = 0;
    char res; 
    for (size_t i = 0; i < 256; i++) {
        if (count[i] > max) {
            max = count[i];
            res = (char)i;
        }
    }
    return res;
}

// function tim so lan xuat hien
int element(char *s) {
    int count[256] = {0}; //mang dem so lan xuat hien
    for (size_t i = 0; i < strlen(s); i++) {
        count[(char)s[i]]++; 
    }
    //Dung res de tim so lan xuat hien va phan tu cua no
    int max = 0;
    char res; 
    for (size_t i = 0; i < 256; i++) {
        if (count[i] > max) {
            max = count[i];
            res = (char)i;
        }
    }
    return max;
}

int main() {
    char string[18] = "518512958851295341";

    if (palindrome(string)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    char v = mostfrequentchar(string);
    int e = element(string);
    printf("Character %c appears %d times(max) in the string\n", v,e);

    
    return 0;
}
