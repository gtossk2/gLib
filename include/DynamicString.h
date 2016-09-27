#ifndef _DYNAMIC_STRING_H_
#define _DYNAMIC_STRING_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? a : b)

/*
 * DynamicString Structure
 */
typedef struct DynamicString{
  int len;
  int size;
  char *s;
}DString;

/*
 *  Allocate for a dynamic string
 */
DString* StrNew();

/*
 *  Append the string at the end of the position
 */
void StrAppend(DString* str, char *s);

/*
 *  Free dynamic string resource
 */
void StrFree(DString* str);

#endif
