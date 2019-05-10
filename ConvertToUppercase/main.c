#include <stdio.h>
#include <stdlib.h>

#define FILENAME "ReaperFile.txt"
#define FILENAME_NEW "ReaperFile_AllCaps.txt"

int main()
{
    remove(FILENAME_NEW);
    printf("\nExisting \'%s\' file deleted. Press ENTER to continue.",FILENAME_NEW);
    getchar();
    FILE *fp = NULL;
    FILE *fp1 = NULL;

    char ch = ' ';

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
    {
        printf("FILE DOES NOT EXIST!\n");
        return -1;
    }

    // create a temp file
    fp1 = fopen(FILENAME_NEW, "w");

    if (fp1 == NULL)
    {
        printf("Temp file not created!\n");
        return -1;
    }

    printf("\nOld contents in '%s' file:\n--------------------------------------------------\n",FILENAME);
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
        if (islower(ch))
        {
            ch = ch-32;
        }

        fputc(ch, fp1);
    }

    fclose(fp);
    fclose(fp1);

    fp = fopen(FILENAME_NEW, "r");

    if (fp == NULL)
        return -1;

    printf("\n\n\n\nNew contents in '%s' file:\n--------------------------------------------------\n",FILENAME_NEW);
    while ((ch =fgetc(fp)) != EOF)
        printf("%c", ch);


    fclose(fp);
    fp = NULL;
    fp1 = NULL;
    printf("\n\n");

    return 0;
}
