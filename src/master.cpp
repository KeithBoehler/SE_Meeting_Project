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

std::string getWorkingDir();


int main(){
  std::cout << "Hi" << std::endl;
  std::string path = "/Users/keithnator3000/OneDrive - The University of Texas-Rio Grande Valley/Classes/STEM/Computer_Science/Software Engineering I - CSCI 3340/SE_Fall19/project/SE_Meeting_Project/sqlite/where2meet.db";
  Database DBObj(path);
	DBObj.insertSchedualData();
  DBObj.getSchedualData(1);
	DBObj.closeDB();
  std::cout << "Bye!" << std::endl;
  return 0;
}

std::string getWorkingDir(){
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}// end getWorkingDir()
