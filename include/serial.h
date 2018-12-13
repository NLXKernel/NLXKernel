#ifndef SERIAL_H
#define SERIAL_H

#define PORT 0x3F8

void serialinit();
int serialrecv();
char serialread();
int transmitempty();
void serialwrite(char buf);
void serialstr(char* buffer);

#endif