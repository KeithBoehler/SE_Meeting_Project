#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <string>
#include "Database.h"

Database::Database(void){
  std::cout << "Making DB" << std::endl;
  DB = NULL;
  int exit = 0;
  exit = sqlite3_open("example.db", &DB);
  if (exit){
    std::cerr << "Could not Open example.db " << sqlite3_errmsg(DB) << std::endl;
  }
  else
    std::cout << "Databse is now open. " << std::endl;
  //sqlite3_close(DB);
  //closeDB();
} // end defult const

void Database::closeDB(){
  sqlite3_close(DB);
} // fun to close db end


/*
bool Database::dbExist(string dbName, sqlite3* DB){
  int exit = 0;
  exit = sqlite3_open(dbName, &DB);
  char* messaggeError;
  exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

  if (exit != SQLITE_OK) {
      std::cerr << "Error Create Table" << std::endl;
      sqlite3_free(messaggeError);
      return FALSE;
  }
  else
      return TRUE; //std::cout << "Table created Successfully" << std::endl;
} // end check if db exists
*/
