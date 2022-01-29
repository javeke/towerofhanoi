/*
Tower of Annoyance
Start Date : October 7, 2017
Expected End Date: October 14,2017
End Date: November 2, 2017
Computer Science 2017/2018™

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //needed to write the time function

#ifndef true //true
#define true 1
#endif

#ifndef false //false
#define false 0
#endif



typedef struct h_struct   //this str
{
    int *f_stack;
    int count_Stack;
    int top;
    int bottom;
} STACK;

int Stack_size;
int func();
int isEmpty(struct h_struct S);
int isFull(struct h_struct S);
STACK init_Stack(struct h_struct S,int lev);
STACK push(int a,struct h_struct S);
STACK pop(struct h_struct S);
int print_Stack(struct h_struct S,STACK,STACK,int);
STACK start_game_Stack(STACK S,int lev);

/*
Colour coding
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White*/

//this function sees to it that there is a time delay in the execution of the code when called
void delay(int delaytimeinmillisecs)
{
    long pause;
    clock_t now,then;

    pause = delaytimeinmillisecs*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int isEmpty(struct h_struct S) //checks to see if the stack is empty
{
    if (S.count_Stack==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isFull(struct h_struct S) // checks to see if the stack is at it's maximum capacity
{
    if(S.count_Stack==Stack_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

STACK push(int a,struct h_struct S) //add the value a to the top of the stack as a new element
{
    S.bottom=0;
    S.top++;
    S.f_stack[S.top]=a;
    S.count_Stack++;
    return S;
}

STACK pop(struct h_struct S) // removes the top element of the stack
{
    if (S.top>0)
    {
        S.bottom=0;
    }
    else if (S.top=0)
    {
        S.bottom=-1;
    }
    S.f_stack[S.top]=0;
    S.top-=1;
    S.count_Stack--;
    return S;
}

//checks to see if the user enters a valid integer data type
//function not yet tested in program

int func()
{
    int temp,myVariable;
    temp=getchar();
    if (temp=='\n')
    {
       return func();
    }
    else
    {
       myVariable=getchar();
    }

     if ((temp>48 && temp<58) && (myVariable=='\n'))
    {
        return temp-48;
    }
    else
    {
        system("cls");
        fseek(stdin,SEEK_CUR,SEEK_END);
        return -1;
    }
}

STACK init_Stack(struct h_struct S,int lev) //initializes the stack reference values
{
    S.f_stack= (int *)malloc(lev*sizeof(int));
    S.bottom=-1;
    S.top=-1;
    S.count_Stack=0;
    return S;
}

int print_Stack(struct h_struct S,STACK S1,STACK S2,int lev) //This function will display the stack elements
{
    int loopCounter;
    for (loopCounter=lev-1; loopCounter>=0; loopCounter--)
    {
        printf("\t  -\t  -\t  -\n");
        if (S.count_Stack>loopCounter)
            printf("\t |%d|\t",S.f_stack[loopCounter]);
        else
        {
            printf("\t | |\t");
        }
        if (S1.count_Stack>loopCounter)
            printf(" |%d|\t",S1.f_stack[loopCounter]);
        else
        {
            printf(" | |\t");
        }
        if (S2.count_Stack>loopCounter)
            printf(" |%d|\n",S2.f_stack[loopCounter]);
        else
        {
            printf(" | |\n");
        }
    }
    printf("\t  -\t  -\t  -\n");
    printf("\tTower 1\tTower 2\tTower 3\n");
    return 0;
}

STACK start_game_Stack(STACK S, int lev)  //Initializes the first tower based on the level
{
    int loopCount;
    Stack_size=lev;
    S=init_Stack(S,lev);
    S.f_stack= (int *)malloc(lev*sizeof(int));
    for (loopCount=1; loopCount<=Stack_size; loopCount++)
    {
        S=push(lev,S); //use of the push function
        lev--;
    }
    return S;
}

int main()
{
    //beginning of program
    system("color 07"); //colors screen to black
    int temp; //temporary story location
    int level=3; //initial level
    int choice=0; //menu option variable
    int sc; //pop stack selection variable
    int cs; //push stack selection variable

    //Splash Screen

    system("COLOR 30");  /*All colour declarations are in the format system("COLOR BackgroundcolorTextcolour")*/
    printf("\aT"); //Prduces an audio when the letter T is printed
    delay(1000);
    system("cls"); /*Cleasrs the screen immediately when called*/
    system("COLOR 90");
    printf("\a\n\t\t\t\tO");
    delay(1000);
    system("cls");
    system("COLOR A0");
    printf("\a\n\n\t\t\t\t\t\tW");
    delay(1000);
    system("cls");
    system("COLOR B0");
    printf("\a\n\n\n\t\t\t\t\t\t\t\t\tE");
    delay(1000);
    system("COLOR C0");
    system("cls");
    printf("\a\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tR");
    delay(1000);
    system("cls");
    system("COLOR D0");
    printf ("\a\t\t\t\t\t\tOF");
    delay(1000);
    system("cls");
    system("COLOR 70");
    printf("\a\n\n\n\n\n\t\t\t\t\t\tA\tN\tN\tO\tY\tA\tN\tC\tE\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCOMSCI2017/2018");
    delay(3000);
    system("cls");


    //Gameplay
    printf("\aThe objective of the game is populate the third tower\n");
    printf("with the elements of the first tower\n");
    printf("\nA larger number cannot be placed on a smaller number\n");
    printf("\nOnly one value can be moved at a time\n");
    printf("\n\n");
    printf("This game accepts only integer values as input\n\n");
    printf("This game has 9 levels\n\n");
    printf("Enter level:\a");
    level=func(); //reads the level from 1 to 9
    system("cls");

    while (level==-1)
    {
        system("cls");
        printf("Invalid!!\n");
        printf("\nThis game has 9 levels\n");
        printf("\nEnter level:");
        level=func();
    }
    system("cls");

    //Ensure to initialize stack prior to use
    STACK Stack1,Stack2,Stack3;    //Declaring tower/stack variables
    Stack1=init_Stack(Stack1,level);   /*Initializing stacks/towers*/
    Stack2=init_Stack(Stack2,level);
    Stack3=init_Stack(Stack3,level);
    Stack1=start_game_Stack(Stack1,level);  //sets the elements of the first tower based on the level
    print_Stack(Stack1,Stack2,Stack3,level); //prints the towers
    printf("\n");


    while (Stack3.count_Stack!=level && choice!=2)
    {
        printf("\nMenu\n");
        printf("1-Pop\n");
        printf("2-Exit\n");
        printf("3-Restart\n");

        choice=func();

        switch(choice)
        {
        case 1:
        {
            printf("Which tower would you like to pop?\n");
            scanf("%d",&sc);
            switch (sc)
            {
            case 1:
            {
                if(isEmpty(Stack1))
                {
                    system("cls");
                    printf("That tower is empty!!\n");
                    print_Stack(Stack1,Stack2,Stack3,level);
                    break;
                }
                else
                {
                    temp=Stack1.f_stack[Stack1.top];
                    Stack1=pop(Stack1);
                    printf("Which tower would you like to add it to?\n");
                    printf("2 or 3?\n");
                    scanf("%d",&cs);
                    switch (cs)
                    {
                    case 2:
                    {
                        if((isEmpty(Stack2)) ||(temp<Stack2.f_stack[Stack2.top]))
                        {
                            system("cls");
                            Stack2=push(temp,Stack2);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        else
                        {
                            system("cls");
                            printf("\nInvalid move!!!\n");
                            Stack1=push(temp,Stack1);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        break;
                    }
                    case 3:
                    {
                        if((isEmpty(Stack3)) ||(temp<Stack3.f_stack[Stack3.top]))
                        {
                            system("cls");
                            Stack3=push(temp,Stack3);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        else
                        {
                            system("cls");
                            printf("\nInvalid move!!!\n");
                            Stack1=push(temp,Stack1);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        break;
                    }
                    default:
                    {
                        system("cls");
                        printf("Not valid!!!\n\a\n");
                        Stack1=push(temp,Stack1);
                        print_Stack(Stack1,Stack2,Stack3,level);
                        break;
                    }
                    }
                }
                break;
            }

            case 2:
            {
                if(isEmpty(Stack2))
                {
                    system("cls");;
                    printf("That tower is empty!!\n");
                    print_Stack(Stack1,Stack2,Stack3,level);
                    break;
                }
                else
                {
                    temp=Stack2.f_stack[Stack2.top];
                    Stack2=pop(Stack2);
                    printf("Which tower would you like to add it to?\n");
                    printf("1 or 3?\n");
                    scanf("%d",&cs);
                    switch (cs)
                    {
                    case 1:
                    {
                        if((isEmpty(Stack1)) ||(temp<Stack1.f_stack[Stack1.top]))
                        {
                            system("cls");
                            Stack1=push(temp,Stack1);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        else
                        {
                            system("cls");
                            printf("\nInvalid move!!!\n");
                            Stack2=push(temp,Stack2);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        break;
                    }
                    case 3:
                    {
                        if((isEmpty(Stack3)) ||(temp<Stack3.f_stack[Stack3.top]))
                        {
                            system("cls");
                            Stack3=push(temp,Stack3);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        else
                        {
                            system("cls");
                            printf("\nInvalid move!!!\n");
                            Stack2=push(temp,Stack2);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        break;
                    }
                    default:
                    {
                        system("cls");
                        printf("Not valid!!!\n\n\a");
                        Stack2=push(temp,Stack2);
                        print_Stack(Stack1,Stack2,Stack3,level);
                        break;
                    }
                    }
                }
                break;
            }
            case 3:
            {
                if(isEmpty(Stack3))
                {
                    system("cls");
                    printf("That tower is empty!!\n");
                    print_Stack(Stack1,Stack2,Stack3,level);
                    break;
                }
                else
                {
                    temp=Stack3.f_stack[Stack3.top];
                    Stack3=pop(Stack3);
                    printf("Which tower would you like to add it to?\n");
                    printf("1 or 2?\n");
                    scanf("%d",&cs);
                    switch (cs)
                    {
                    case 1:
                    {
                        if((isEmpty(Stack1)) ||(temp<Stack1.f_stack[Stack1.top]))
                        {
                            system("cls");
                            Stack1=push(temp,Stack1);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        else
                        {
                            system("cls");
                            printf("\nInvalid move!!!\n");
                            Stack3=push(temp,Stack3);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        break;
                    }
                    case 2:
                    {
                        if((isEmpty(Stack2)) ||(temp<Stack2.f_stack[Stack2.top]))
                        {
                            system("cls");
                            Stack2=push(temp,Stack2);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        else
                        {
                            system("cls");
                            printf("\nInvalid move!!!\n");
                            Stack3=push(temp,Stack3);
                            print_Stack(Stack1,Stack2,Stack3,level);
                        }
                        break;
                    }
                    default:
                    {
                        system("cls");
                        printf("Not valid!!!\a\n\n");
                        Stack3=push(temp,Stack3);
                        print_Stack(Stack1,Stack2,Stack3,level);
                        break;
                    }
                    }
                }
                break;
            }
            }
            break;
        }
        case 2:
        {
            exit(0);
            free(Stack1.f_stack);
            free(Stack2.f_stack);
            free(Stack3.f_stack);
        }
        case 3:
        {
            system("cls");
            printf("\nRestarting...\n");
            delay(3000);
            system("cls");
            main();
        }
        default:
        {
            system("cls");
            print_Stack(Stack1,Stack2,Stack3,level); //prints the towers
            printf("\n");
        }
        }
    }
    printf("YOU WINNNN!!!!\n");

    //end of program

    //frees dynamically allocated memory
    free(Stack1.f_stack);
    free(Stack2.f_stack);
    free(Stack3.f_stack);
    return 0;
}

