#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"

/* Returns 1 if the text is empty or only spaces, otherwise 0 */
static int isBlank(const char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)text[i]))
        {
            return 0;
        }
    }
    return 1;
}

/* Reads one line safely and removes the Enter key */
void readLine(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) == NULL)
    {
        printf("\nInput closed. Exiting program.\n");
        exit(1);
    }

    size_t len = strlen(buffer);

    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
    else
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    }
}

/* Keeps asking until the user enters a whole number from min to max */
int readInt(const char *prompt, int min, int max)
{
    char buffer[MAX_INPUT];
    char *end;
    long value;

    while (1)
    {
        printf("%s", prompt);
        readLine(buffer, sizeof(buffer));

        if (isBlank(buffer))
        {
            printf("Error: input cannot be empty.\n");
            continue;
        }

        value = strtol(buffer, &end, 10);

        if (*end != '\0')
        {
            printf("Error: please enter a whole number.\n");
            continue;
        }

        if (value < min || value > max)
        {
            printf("Error: enter a number between %d and %d.\n", min, max);
            continue;
        }

        return (int)value;
    }
}

/* Keeps asking until the user enters a number that is at least min */
double readDouble(const char *prompt, double min)
{
    char buffer[MAX_INPUT];
    char *end;
    double value;

    while (1)
    {
        printf("%s", prompt);
        readLine(buffer, sizeof(buffer));

        if (isBlank(buffer))
        {
            printf("Error: input cannot be empty.\n");
            continue;
        }

        value = strtod(buffer, &end);

        if (*end != '\0')
        {
            printf("Error: please enter a valid number.\n");
            continue;
        }

        if (value < min)
        {
            printf("Error: value cannot be less than %.2f.\n", min);
            continue;
        }

        return value;
    }
}

/* Keeps asking until the user enters non-empty text that fits */
void readString(const char *prompt, char *dest, int size)
{
    char buffer[MAX_INPUT];

    while (1)
    {
        printf("%s", prompt);
        readLine(buffer, sizeof(buffer));

        if (isBlank(buffer))
        {
            printf("Error: this field cannot be empty.\n");
            continue;
        }

        if ((int)strlen(buffer) >= size)
        {
            printf("Error: too long (maximum %d characters).\n", size - 1);
            continue;
        }

        strcpy(dest, buffer);
        return;
    }
}

void pauseScreen(void)
{
    char buffer[MAX_INPUT];
    printf("\nPress Enter to continue...");
    readLine(buffer, sizeof(buffer));
}