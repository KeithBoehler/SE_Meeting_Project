	#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>

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

std::string getWorkingDir();


int main(){
  std::cout << "Hi" << std::endl;
  std::string path = "/Users/keithnator3000/OneDrive - The University of Texas-Rio Grande Valley/Classes/STEM/Computer_Science/Software Engineering I - CSCI 3340/SE_Fall19/project/SE_Meeting_Project/sqlite/where2meet.db";
  Database DBObj(path);
  std::cout << "Bye!" << std::endl;
  return 0;
}

std::string getWorkingDir(){
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}// end getWorkingDir()
