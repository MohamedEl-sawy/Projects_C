// Macros Definition Section 

#define PI_VALUE (3.24)
#define ARRY_MAX_SIZE (10U)
#define EXP (2*3)
# \
define \
TEST \
77
// #define MyName "Ahmed Mohamed"
#define SUMMING(Num1,Num2) (Num1+Num2)

// Function macro to swap to number
#define SWAAP(x,y) \
{ \
    *(x) = * (x) ^ *(y); /* dfsg*/ \
    *(y) = * (x) ^ *(y); \
    *(x) = * (x) ^ *(y); \
}




#define SET_BIT(VAR,BIT_POS) ((VAR) |= (1 << BIT_POS) )
#define CLER_BIT(VAR,BIT_POS) ((VAR) &= ~ (1 << BIT_POS) )
#define TOGLE_BIT(VAR,BIT_POS) ((VAR) ^= (1 << BIT_POS) )

//---------------------------------------

#define SQUARE1(num) num*num
#define SQUARE2(num) (num*num)
#define SQUARE3(num) (num)*(num)
#define SQUARE4(num) ((num)*(num))



// #pragma GCC poison printf
// #pragma GCC warning "App.h is used"
// #pragma GCC error "App.h is used"


//-----------------------------------------------
void print_hello(void);

#define HELLO1
#define HELLO2

#if defined(HELLO1) // true
void Fun_dec_1(void);
#else              //False
void Fun_dec_2(void);
#endif

#if !defined(HELLO1)&& defined(HELLO2) // 
#error "HELLO2 Needs HELLO1"
#endif

#define PrintName(F_N,S_N) printf(#F_N" "#S_N"\n")