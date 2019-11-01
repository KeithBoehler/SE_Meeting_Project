#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <string>
#include "Database.h"

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

int main(){
  std::cout << "Hi" << std::endl;
  Database DBObj;
  DBObj.closeDB();
  std::cout << "Bye!" << std::endl;
  return 0;
}
