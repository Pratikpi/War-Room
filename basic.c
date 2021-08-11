
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

/**
Header files for using predefined functions.
**/


///Data structure for storing equipment name and units deployed.

struct DEFENCE
{
    char name[30];

    int unit;

};

typedef struct DEFENCE DEFENCE;

///Data structure for storing information of a particular district

struct DISTRICT
{
    ///No. for referring a particular district
    int index;

    ///Name of the district
    char name[20];

    ///Area occupied
    int area;

    ///Distance from New Delhi
    int distance;

    ///Population of this district
    int population;

    ///No. of troops currently deployed
    int troops;

    ///Equipments currently deployed
    int equipments;

    ///To check availability of hospitals
    bool hospital;

    ///Checks whether army is presents here or not
    bool army_base;

    ///To check if it is a border districts
    bool border_state;

    ///Keeps the record of equipments currently deployed
    DEFENCE tools[4];

};

typedef struct DISTRICT DISTRICT;


///Globally declared 1D array of districts

DISTRICT Crown[22];

///Globally declared 2D array for stored for storing distance between 2 distinct districts.

int m[23][23];
