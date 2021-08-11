/**data can be manipulated by changing the data in the file**/

#include "basic.c"


/**
Name: Main Function

Input parameter : int

Output parameter : int

Description :  It is the main program which drives the whole project.

**/

int main()
{
    ///Variable for choosing operation

    int choice;

    /**
    Name : input

    Input parameter : NULL

    Output parameter : NULL

    Description : This program takes input from file and stores the given data into memory.
                  Here the input taken is in the form of square matrix.
                  The data is distance between two distinct district head quarters.

    **/

    input();

     /**
    Name : input_district

    Input parameter : NULL

    Output parameter : NULL

    Description : This program takes input from file and stores the given data into memory.
                  Here the input is taken in sequence as specified in the function below.

    **/


    input_district();

    printf("Tribute to INDIAN ARMED FORECES");


    while(1)

    {
        printf("\n*******************************\n");

        printf("1.Cease fire violation.\n");

        printf("2.Enemy encroach.\n");

        printf("3.War declared.\n");

        printf("4.Clear all databases.\n");

        printf("5.Show details.\n");

        printf("6.Exit.");

        printf("\n*******************************\n");

        printf("Enter your choice:");

        scanf("%d", &choice);


            switch(choice)
            {

            case 1:

                    ///Clears the screen
                    system("cls");

                    ceasefire();

                break;


            case 2:

                    ///Clears the screen
                    system("cls");

                    enchroach();

                break;


            case 3:

                    ///Clears the screen
                    system("cls");

                    war();

                break;


            case 4:

                    ///Clears the screen
                    system("cls");

                    printf("Your data is deleted..\n");

                    free_all();

                break;


            case 5:

                ///Clears the screen
                system("cls");

                display();

                break;


            case 6:

                    ///Clears the screen
                    system("cls");

                    jai_hind();

                    return 0;


            default:

                ///Clears the screen
                system("cls");

                printf("Please enter a valid input.\n");

                break;

        }

    }

    return 0;
}
