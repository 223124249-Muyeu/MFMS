#ifndef VALIDATION_H
#define VALIDATION_H

#define MAX_INPUT 100

void readLine(char *buffer, int size);
int readInt(const char *prompt, int min, int max);
double readDouble(const char *prompt, double min);
void readString(const char *prompt, char *dest, int size);
void pauseScreen(void);

#endif