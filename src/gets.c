#include "gets.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100000

char *GetString(char *message) {
  static char buffer[BUFFER_SIZE];

  printf("%s", message);
  if ((fgets(buffer, BUFFER_SIZE, stdin)) == NULL) {
    return NULL;
  };

  size_t bufferLength = strlen(buffer);

  if (bufferLength > 0 && buffer[bufferLength - 1] == '\n') {
    buffer[bufferLength - 1] = '\0';
  } else {
    char extraBuffer;
    while ((extraBuffer = getchar()) != '\n' && extraBuffer != EOF);
  };

  return buffer;
};

int GetInt(char *message) {
  int number = 0, multiplier;
  char *buffer;
  unsigned char notNumber = 0;

  do {
    buffer = GetString(message);
    multiplier = 1;

    for(int length = strlen(buffer) - 1; length >= 0; length--) {
      if (!isdigit(buffer[length])) {
        if (length == 0) {
          if (buffer[0] == '-') {
            number = 0 - number;
            break;
          } else if (buffer[0] == '+') {
            break;
          }
          notNumber = 1;
          break;
        }
        notNumber = 1;
        break;
      }

      number += (buffer[length] * multiplier);
      multiplier *= 10;
    }
  } while (notNumber);


  return number;
}

long int GetLong(char *message) {
  long int number = 0, multiplier;
  char *buffer;
  unsigned char notNumber;

  do {
    buffer = GetString(message);
    multiplier = 1;
    notNumber = 0;

    for(int length = strlen(buffer) - 1; length >= 0; length--) {
      if (!isdigit(buffer[length])) {
        if (length == 0) {
          if (buffer[0] == '-') {
            number = 0 - number;
            break;
          } else if (buffer[0] == '+') {
            break;
          }
          notNumber = 1;
          break;
        }
        notNumber = 1;
        break;
      }

      number += ((buffer[length] - '0') * multiplier);
      multiplier *= 10;
    }
  } while (notNumber);


  return number;
}
