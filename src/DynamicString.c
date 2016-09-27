#include "DynamicString.h"

/*
 *  Allocate for a dynamic string
 */
DString *StrNew() {
  DString *str = malloc(sizeof(DString));

  str->s = malloc(1);
  str->s[0] = '\0';
  str->len = 0;
  str->size = 1;

  return str;
}


/*
 *  Append the string at the end of the position
 */
void StrAppend(DString *str, char *s) {
  int newLen = str->len + strlen(s);

  // Allocate more space for incoming string
  if (newLen+1 > str->size) {
    int newSize = MAX(str->size*2, newLen+1);
    char *t = malloc(newSize);

    sprintf(t, "%s%s", str->s, s);
    free(str->s);

    str->s = t;
    str->len = newLen;
    str->size = newSize;
  } else {  // Enough space for appending incoming string
    strcat(&str->s[str->len], s);
    str->len += strlen(s);
  }

  return;
}

/*
 *  Free dynamic string resource
 */
void StrFree(DString* str){

  // Free string
  if(str->s){
    free(str->s);
  }

  // Free DString struct
  if(str){
    free(str);
  }

  return;
}

