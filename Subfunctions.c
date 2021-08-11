#include "basic.c"

#include <stdio.h>

///Function prototype declaration

void free_all();

void evacuate(int);

void air_war();

void ground_war();


/**
Name : free_all
Input parameter : NULL
Output parameter : NULL
Description : Deallocates all the memory space allocated.
              It literally means that all the data stored is deleted and cannot be restored from this program.
**/
void free_all()
{
    free(m);

    free(Crown);

}



/**
Name : ceasefire
Input parameter : NULL
Output parameter : NULL
Description : This function is designed to handle the situation of ceasefire violations.
              It asks for number of districts attacked and their names.
              It also  increases the army shelling in those areas and evacuating the citizens to the safe nearest place.
**/

void ceasefire()
{
    int n,index;

    printf("Enter the Number of Districts:");

    scanf("%d",&n);

    for(int i=0 ; i < n ; i++)
    {
            printf("Enter the index:");

            scanf("%d",&index);

            printf("Troops shelling has been increased in %s district.\n",Crown[index].name);

            evacuate(index);

            Crown[index].troops+=100;
    }
}




/**
Name : encroach
Input parameter : NULL
Output parameter : NULL
Description : This function is used in the situation when the enemy cross international borders.
              Only troops are marched without any fireworks.
              Therefore evacuating citizens is unnecessary and deploying troops can help.
**/

void enchroach()
{
    int n,index;

    printf("Enter the No. of Districts:");

    scanf("%d",&n);

    for(int i=0 ; i < n ; i++)
    {
            printf("Enter the index:");

            scanf("%d",&index);

            printf("Troops shelling has been increased in %s district.\n",Crown[index].name);

            Crown[index].troops+=100;
    }
}



/**
Name : jai_hind
Input parameter : NULL
Output parameter : NULL
Description : To print JAI HIND
**/

void jai_hind()
{
    printf("  *************      *****      *************         ***       ***   *************   ****       ***  *********    \n");

    printf("  *************     *******     *************         ***       ***   *************   *****      ***  **********   \n");

    printf("        ***        ***   ***         ***              ***       ***        ***        ******     ***  ***     **** \n");

    printf("        ***       ***     ***        ***              ***       ***        ***        ***  ***   ***  ***      ****\n");

    printf("        ***      *************       ***              *************        ***        ***   ***  ***  ***       ***\n");

    printf(" ***    ***      *************       ***              *************        ***        ***    *** ***  ***      ****\n");

    printf(" ***    ***      ***       ***       ***              ***       ***        ***        ***     ******  ***     **** \n");

    printf("  ********       ***       ***  *************         ***       ***   *************   ***      *****  **********   \n");

    printf("    *****        ***       ***  *************         ***       ***   *************   ***       ****  ********     \n");
}




/**
Name : war
Input parameter : NULL
Output parameter : NULL
Description : It is used in war scenarios.
              It asks whether the attack is Aerial or Terrestrial.
              It deploys appropriate equipments to handle the situations.
              It also deploys the considerable amount of troops.
**/

void war()
{
    printf ("Which type of attack?\n");

    printf  ("1.Aerial\n");

    printf ("2.Ground\n");

    printf ("Enter your choice:");

    int war_choice;

    scanf ("%d",&war_choice);

    switch(war_choice)
    {

    case 1:

            air_war();

        break;

    case 2:

            ground_war();

        break;

    default:

        printf("PLease enter the valid input.\nWe have time to joke or to commit mistake.\n");

        break;

    }

}




/**
Name : air_war
Input parameter : NULL
Output parameter : NULL
Description : It asks for the number of districts attacked and deploys a defense system.
              Evacuates the citizens to the safest place.

**/


void air_war()
{
    int dist_no,index;

    printf ("Air protection protocol activated.\nMajor defence systems has been activated.\n");

    printf ("Enter the No. of Districts being attacked:");

    scanf("%d",&dist_no);

    for( int i=0;i<dist_no;i++)
    {
        printf("Enter the index of given district:");

        scanf("%d",&index);

        printf ("Citizens from %s will be evacuated as soon as possible.\n",Crown[index].name);

        evacuate(index);

        strcpy(Crown[index].tools[Crown[index].equipments+0].name,"Anti-aircraft missile launchers");

        Crown[index].tools[Crown[index].equipments+0].unit=10;

        strcpy(Crown[index].tools[Crown[index].equipments+1].name,"Anti-ballistic missile launchers");

        Crown[index].tools[Crown[index].equipments+1].unit=5;

        Crown[index].equipments+=2;

        Crown[index].troops+=100;

    }

    printf ("Armed forces are on the way.\n");

    printf("BSF will defend us till then.\n");
}



/**
Name : ground_war
Input parameter : NULL
Output parameter : NULL
Description : It asks for number of the districts attacked.
              It deploys Terrestrial weapons which are required to handle the situations.
              It also evacuates the citizens.
**/
void ground_war()
{
    int dist_no,index;

    printf ("Ground protection protocol activated.\nMajor defence systems has been activated.\n");

    printf ("Enter the No. of Districts being attacked:");

    scanf("%d",&dist_no);

    for( int i=0;i<dist_no;i++)
    {

        printf("Enter the index of given district:");

        scanf("%d",&index);

        printf ("Citizens from %s will be evacuated as soon as possible.\n",Crown[index].name);

        evacuate(index);

        strcpy(Crown[index].tools[Crown[index].equipments+0].name,"Mortar");

        Crown[index].tools[Crown[index].equipments+0].unit=100;

        strcpy(Crown[index].tools[Crown[i].equipments+1].name,"Tanks");

        Crown[index].tools[Crown[index].equipments+1].unit=5;

        Crown[index].equipments+=2;

        Crown[index].troops+=100;

    }

    printf ("Armed forces are on the way.\n");

    printf("BSF will defend us till then.\n");

}



/**
Name : input
Input parameter : NULL
Output parameter : NULL
Description : Reads data in matrix form.
**/
void input()
{
    int i;

    int j;

    FILE *file;

    file=fopen("dist.txt", "r");

    for(i = 1; i <=22; i++)
    {
        for(j = 1; j <=22 ; j++)
        {
            if (!fscanf(file, "%d", &m[i][j]))
                break;
        }
    }
    fclose(file);

    for(i=1;i<23;i++)
    {
        for(j=1;j<23; j++)
        {
            for(int k=1;k<23;k++)
            {
                if(m[i][j]>m[i][k]+m[k][j])
                {
                    m[i][j]=m[i][k]+m[k][j];
                }
            }
        }
    }
}


/**
Name : input_districts
Input parameter : NULL
Output parameter : NULL
Description : It reads the data sequentially from files.
**/

void input_district()
{

    FILE *fp;

    fp = fopen ("District.txt","r");

    int i=1;

    while(!feof(fp) && i<=22)
    {

            fscanf (fp,"%d",&Crown[i].index);


            fscanf(fp,"%[^\n]%*c",Crown[i].name);


            fscanf(fp,"%d",&Crown[i].area);


            fscanf(fp,"%d",&Crown[i].distance);


            fscanf(fp,"%d",&Crown[i].population);


            fscanf(fp,"%d",&Crown[i].troops);


            fscanf(fp,"%d",&Crown[i].equipments);


            fscanf(fp,"%d",&Crown[i].hospital);


            fscanf(fp,"%d",&Crown[i].army_base);


            fscanf(fp,"%d",&Crown[i].border_state);


            i++;

    }

}



/**
Name : display
Input parameter : NULL
Output parameter : NULL
Description : It displays the information about the district.
**/


void display()
{
    int i;

    printf ("Enter the index:");

    scanf("%d",&i);


        printf("Index:%d\n",Crown[i].index);


        printf("Name:%s\n",Crown[i].name);


        printf("Area:%d\n",Crown[i].area);


        printf("Distance from New Delhi:%d\n",Crown[i].distance);


        printf("Population:%d\n",Crown[i].population);


        printf("Troops:%d\n",Crown[i].troops);


        if( Crown[i].equipments == 0)

            printf ("No equipments deployed.\n");

        else
        {
            for(int j=0 ; j < Crown[i].equipments ; j++)
            {
                printf("%d units of %s deployed.\n",Crown[i].tools[j].unit,Crown[i].tools[j].name);
            }
        }

        if(Crown[i].hospital)

            printf ("Hospital is present.\n");

        else

            printf("Hospital not there\n");

        if(Crown[i].army_base)

            printf ("Army base is present.\n");

        else
            printf("Army base not there\n");

        if(Crown[i].border_state)

            printf ("It is a border state.\n");

        else

            printf("It is not border state.\n");

}



/**
Name : evacuate
Input parameter : Index of the district.
Output parameter : NULL
Description : It searches for the nearest safe place and evacuates the citizens to the same.
**/


void evacuate(int x)
{

    int j;

    int i=x;

    int smallest;

    int z;

    int y[23];

    for(j=1;j<23;j++)
    {
        y[j]=m[i][j];

    }

    smallest=y[0];

    for(i=0;i<22;i++)
    {
        if(y[i]<smallest && y[i]!=0)
        {
            smallest = y[i];

             if(smallest==y[i])
              {
                z=i;
              }
        }
    }

    printf("Citizen will be shifted to %s.\n",Crown[z].name);

}
