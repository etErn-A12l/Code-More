// C program to illustrate 
// isspace() function 
#include <ctype.h> 
#include <stdio.h> 
  
// Function for counting spaces 
int cnt_space(int i, int count, char ch) 
{ 
  
    // input sentence 
    char buf[50] = "Geeks for Geeks"; 
    ch = buf[0]; 
  
    // counting spaces 
    while (ch != '\0') { 
        ch = buf[i]; 
        if (isspace(ch)) 
            count++; 
  
        i++; 
    } 
  
    // returning number of spaces 
    return (count); 
} 
int main() 
{ 
  
    char ch; 
    int i = 0, count = 0; 
  
    // Calling function 
    count = cnt_space(i, count, ch); 
  
    // printing number of spaces 
    printf("\nNumber of spaces in the sentence is : %d", count); 
  
    return 0; 
} 
