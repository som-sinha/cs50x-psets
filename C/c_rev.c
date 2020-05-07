// Learning C (again...)
// Somaditya Sinha
// December 24, 2019
// Lecture 1 & 2

// Topics Covered
// Copmiling and running (clang, make, ./)
//  Main Function, Header Files
//  Functions in (stdio, string, cs50).h
//  Variables, getting input
//  Conditionals
//  Loops (for, while, do...while) (not covered: recursive)
//  Functions
//  Using argv and argc

// Header Files
#include <stdio.h>
#include <string.h>
#include <cs50.h>

//  Function Declaration
void conditionals();
void for_loop();
void while_loop();
void do_while_loop();
void argc_argv(int c, string * v);

//  Main Function
int main(int argc, string argv[])
{
    //  Arguments Check
    if (argc == 2)
    {
        //  Explained in demo functions
        string name = argv[1];
        //  Initialising a variable (data-type var-name = value or null or 0)
        int n = 1;
        int option = 0;

        while (option != 5)
        {
        //  printf() - included in stdio.h
        printf("\n");
        printf("================================================================\n");
        printf("Hi %s!\n", name);
        printf("This program gives demos of the fundamental parts of a program (implemented in C)\n");
        printf("Choose a demo by typing a number before it:\n");
        printf("0. Conditionals\n");
        printf("1. For Loop\n");
        printf("2. While Loop\n");
        printf("3. Do...While Loop\n");
        printf("4. Argc and Argv\n");
        printf("5. Quit\n");
        // Getting input (Made easier by cs50.h) [get_data-type("Text to indicate input required")]
        option = get_int("");
        printf("================================================================\n");
        // Out of the area this program covers | But this is how you call functions in a program [function(var1, var2,...)]
        switch (option)
        {
            case 0 : conditionals();
            break;
            case 1 : for_loop();
            break;
            case 2 : while_loop();
            break;
            case 3 : do_while_loop();
            break;
            case 4 : argc_argv(argc, argv);
            break;
            case 5 :
            printf("Bye!\n");
            break;
        }
        }
        // If you want to know more about that google "switch...case in C"

        // 0 means everything went well in main function
        return 0;
    }
    else
    {
        printf("You need to put your first name after ./(program name) for Argc and Argv demo to work\n");
        // 1 means some error, end program
        return 1;
    }

    return 0;
}
//  Functions (Demos are kept here so that they can be called by the "main" function)
//  This is why functions are here, they basically act as smaller subprograms which can be called when needed
void conditionals()
{
    printf("This program checks whether a person is eligible to drive\n");
    printf("It uses if...else if...else statements\n");
    int age = get_int("How old are you? ");
    //Using if, else if and else
    if (age >= 18 && age > 0)
    {
        printf("Hell Yeah!!! You can drive!\n");
    }
    else if (age >= 16 && age < 18 && age > 0)     //  && means AND; || means OR
    {
        printf("You can't drive yet, although you can get a learner's license\n");
        printf("Yeah!!!...I guess :P\n");
    }
    else if (age < 16 && age > 0)
    {
        printf("You ain't driving anything bud\n");
    }
    else
    {
        printf("Ohhkay... either you're from mars, or I have a bug, or you're stoooopid xD\n");
    }
}
void for_loop()
{
    printf("Using for loop to count till 10\n");
    // Loops basically repeat a block of code multiple times
    // for loop is basically a short form of a limited while loop
    int limit = 10;
    for (int i = 1; i <= 10; i++)    //i++ is a shorthand for i = i + 1; (which means adding 1 to i)
    {
        printf("%i\n", i);
    }

}
void while_loop()
{
    // This asks what 2 + 2 is until you give the right answer

    int ans = get_int("What is 2 + 2?");
    while (ans != 4)    // Anything between those () will keep the loop running until they are true
    {
        ans = get_int("What is 2 + 2? ");
    }

}
void do_while_loop()
{
    int ans = 0;
    // This does the same thing the while_loop demo does but with less lines of code
    do
    {
        ans = get_int("What is 2 + 2? ");
    }while(ans != 4);   //Pay attention to ";" only for do...while
}
void argc_argv(int c, string * v)
{
    printf("Number of arguments when running the program (including the name of the program itself)\n");
    printf("argc -> %i\n", c);
    printf("Your name given with the command to run the program\n");
    printf("argv[1] -> %s\n", v[1]);
}