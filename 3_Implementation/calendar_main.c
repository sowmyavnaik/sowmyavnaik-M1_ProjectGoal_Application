/**
 * @file Calendar.c
 * @author Sowmya (you@domain.com)
 * @brief Calendar application
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "stdio.h"
#include <stdlib.h>
#include <calendar_func.h>
#include "calendar_func.h"

int main(int argc, char* argv[]){
    int year,month, day;
    char choice;
    Note note;
    FILE *fp;

    fp = fopen("note.bin", "r");
    if (fp == NULL) {
      fp = fopen("note.bin", "w");
    }
    fclose(fp);

    while(1) {
      printf("1. Find the day\n");
      printf("2. Print the calendar of a month\n");
      printf("3. Add a Note\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("\n%c", &choice);
      switch(choice) {
        case '1':
        printf("Enter the day, month and year: ");
        scanf("%d %d %d", &day, &month, &year);
        printf("The day is : %s\n", getName(getDayNumber(day, month, year)));
        break;
        case '2':
        printf("Enter the month and year: ");
        scanf("%d %d", &month, &year);
        printf("Please enter 's' to see the notes\n Press any other key to continue\n");
        calendar(year, month);
        break;
        case '3':
        printf("Enter the day, month and year: ");
        scanf("%d %d %d", &note.day, &note.month, &note.year);
        flush();
        printf("Enter the note: ");
        fgets(note.note, 255, stdin);
        fp = fopen("note.bin", "a+");
        if (fp == NULL) {
          printf("File note.bin can not be opened\n");
          exit(1);
        }
        fwrite(&note, sizeof(Note), 1, fp);
        printf("Note added sucessfully\n");
        fclose(fp);
        break;
        case '4':
        printf("Done!!");
        exit(0);
        break;
        default:
        printf("Not a valid option\n");
        break;
      }
    }
    return 0;
}

void calendar(int y, int m)
{
    FILE *fp;
    Note* notes, note;
    int len, j;
    char choice;
    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su   Mo   Tu   We   Th   Fr   Sa";
    int DayOfMonth[] =
        { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days(y, m, 1) % 7;

    fp = fopen("note.bin", "rb");
    len = 0;
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        len++;
      }
    }
    rewind(fp);
    j = 0;
    notes = (Note*) malloc (sizeof(Note) * len);
    while(fread(&note, sizeof(Note), 1, fp))
     {
      if (note.year == y && note.month == m) {
        notes[j] = note;
        j++;
      }
    }

    fclose(fp);

    if(LeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        int hasNote = 0;
        for (j = 0; j < len; j++) {
          if (notes[j].day == day) {
            printf("|%2d| ",day);
            hasNote = 1;
            break;
          }
        }
        if (hasNote == 0) {
          printf("%2d   ",day);
        }
        if(i % 7 == 6)
            printf("\n");
    }
    printf("\n");
    scanf("\n%c", &choice);
    if (choice == 's') {
      printf("Here are list of notes for %d %d\n", m, y);
      for (j = 0; j < len; j++) {
        printf("%d: %s\n", notes[j].day, notes[j].note);
      }
    } else {
      return;
    }
}



