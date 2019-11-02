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
} // end defult const

Database::Database(std::string s){
  std::cout << "Making DB" << std::endl;
  DB = NULL;
  dbLocation = s;
  int exit = 0;
  exit = sqlite3_open(dbLocation.c_str(), &DB); // wont take normal string
  if (exit){
    std::cerr << "Could not Open example.db " << sqlite3_errmsg(DB) << std::endl;
  }
  else
    std::cout << "Databse is now open. " << std::endl;

  tablesInit(DB);
} // end defult const

/*******************************************
*           Public Methods
*
*********************************************
*/

void Database::closeDB(){
  sqlite3_close(DB);
} // fun to close db end

void Database::insertData(){
  std::string schedualQuery = "SELECT * FROM SCHEDUAL";
  std::cout << "Table before dat... " << std::endl;
  sqlite3_exec(DB, schedualQuery.c_str(), callback, NULL, NULL);
  std::cout << "After putting in some test data. " << std::endl;
  std::string test = "INSERT INTO SCHEDUAL VALUES(0420493, '20191102T0201', '20191102T0301');";
  int exit = 0;
  char* messaggeError;
  exit = sqlite3_exec(DB, test.c_str(), NULL, 0, &messaggeError);
  if(exit != SQLITE_OK){
    std::cerr << "Error with insert. " << std::endl;
    sqlite3_free(messaggeError);
  }// end if
  else
    std::cout << "Record has been inserted. " << std::endl;
  sqlite3_exec(DB, schedualQuery.c_str(), callback, NULL, NULL);

}// end insert method

/*******************************************
*           Private Methods
*
*********************************************
*/
void Database::tablesInit(sqlite3* sqlptr){
  // Strings for date storage table
  std::string schedualTable = "CREATE TABLE SCHEDUAL(";
  std::string schID = "AccountID INT PRIMARY KEY NOT NULL, ";
  std::string schDateStart = "START_DATE VARCHAR(13) NOT NULL, ";
  std::string schDateEND = "END_DATE VARCHAR(13) NOT NULL); ";
  schedualTable.append(schID);
  schedualTable.append(schDateStart);
  schedualTable.append(schDateEND);
  int exit = 0;
  char* messaggeError;
  exit = sqlite3_exec(sqlptr, schedualTable.c_str(), NULL, 0, &messaggeError);
  if (exit != SQLITE_OK){
    std::cerr << "Error making table Schedual" << std::endl;
    sqlite3_free(messaggeError);
  }// end if
  else
    std::cout << "Table Schedual has been made. " << std::endl;

  // strings for

}// end table inits

int Database::callback(void* data, int argc, char** argv, char** azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}
