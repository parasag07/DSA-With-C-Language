#include <stdio.h>

int main() {
    printf("Let's learn about pointers\n");
    int a=75;
    int* ptra = &a;
    int *ptr = NULL;
    
    // Use %d for actual value and %x for it's address
    // %d with *ptra and %x with ptra (x for hexadecimal)
    printf("The value of a is %d\n", a);
    printf("The value of a is %d\n", *ptra);    
    printf("Address of variable 'a': %p\n", &a);    
    printf("Address of variable 'a': %p\n", ptra);    
    printf("Address of pointer 'ptra': %p\n", &ptra);    
    
    // NULL Pointer
    printf("The value of NULL Pointer is %d\n", ptr);
    printf("The address of NULL Pointer is %p\n", ptr);
    
    
    return 0;
}


/* 
%c: Character
%s: String
%d or %i: Signed integer
%u: Unsigned integer
%f: Floating-point number
%e or %E: Exponential notation
%g or %G: Shorter of %f or %e
%o: Octal number
%x or %X: Hexadecimal number
%p: Pointer address
*/