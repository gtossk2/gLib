#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/DynamicString.h"

int main(){

  DString *dString = StrNew();
  StrAppend(dString, "Hello World ");
  printf("String : %s \n", dString->s);

  StrAppend(dString, " --> Dynamic String");
  printf("String : %s \n", dString->s);

  return 0;
}
