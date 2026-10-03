#ifndef FILE_C_H     
#define FILE_C_H

#include <stdio.h>
#include <stdlib.h>


/*
   // First of all you need to include #include"file_c.h"
    // and this shows how u can read from the struct file and print it gonna use in the game lol
    int tru = reading_and_writting_FILE();
    if(tru == 0)
    {
        printf("smthg is wrong idk");
    }

*/
typedef struct { int x; int y; } player;

typedef struct {
    player p;
    int p_health;
} charer;

void writeInFileS(FILE *path, const charer *charr)  
{

    fwrite(charr, sizeof(*charr), 1, path);
}


void readFileS(FILE *path,  charer *charr)  
{

    fread(charr, sizeof(*charr), 1, path);
}

int reading_and_writting_FILE()
{
        FILE *fp = fopen("sanc.txt", "w");   
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR: could not open file for writing\n");
        return 1;         
    }
    charer *charr = malloc(sizeof(charer));
    if (charr == NULL)
    {
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        charr->p.x      = i;
        charr->p.y      = i + 1;
        charr->p_health = 20 + i;
        writeInFileS(fp,charr);
    }
    fclose(fp);

    FILE *fpr = fopen("sanc.txt", "r");

    if (fpr == NULL)
    {
        fprintf(stderr, "ERROR: could not open file for reading\n");
        free(charr);
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        readFileS(fpr,charr);
        printf("x: %d, y: %d, health: %d\n", charr->p.x, charr->p.y, charr->p_health);

    }
    fclose(fpr);
    free(charr); 
       return 1;
}

#endif                  