#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <string>
#include "Database.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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

/*
*  Intent: Gather User schedual Information and insert into the database.
*
*  Precondition: None.
*
*  Postcondition: User info will now be a record in sqlite.
*
*/

void Database::insertSchedualData(){
  std::string schedualQuery = "SELECT * FROM SCHEDUAL"; // What we are running in sql
  int id = 0;
  //std::string test = "INSERT INTO SCHEDUAL VALUES(0420493, '20191102T0201', '20191102T0301');";
  std::cout << "Enter ID: ";
  std::cin >> id;
  std::cout << "Enter Start: " << std::endl;
  std::string date1 = insertSchedualDataAux();
  std::cout << "Enter End: " << std::endl;
  std::string date2 = insertSchedualDataAux();
  std::string test = "INSERT INTO SCHEDUAL VALUES(" + std::to_string(id) + ", " + "'" + date1 + "'" + ", " + "'" + date2 + "'" + ");";
  std::cout << "Insett sql is: " << test << std::endl;
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

void Database::insertAccountData(){
  std::string email;
  std::cout << "Enter email: ";
  std::cin >> email;
  std::string passwd;
  std::cout << "\n Enter Password: ";
  std::cin >> passwd;
  std::cout << std::endl;
  int id = generateID(email, passwd);
  std::string sql = "INSERT INTO ACCOUNTS VALUES(" + std::to_string(id) + ", '" + email + "'" + ", '" + passwd + "');";
  std::cout << "Insert sql is: " << sql << std::endl;
  int exit = 0;
  char* messaggeError;
  exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  if(exit != SQLITE_OK){
    std::cerr << "Error with insert. " << std::endl;
    sqlite3_free(messaggeError);
  }// end if
  else
    std::cout << "Record has been inserted. " << std::endl;
}// end insert Account Data



void Database::getSchedualData(int id){
  std::cout << "Get TEST" << std::endl;
  std::string sql = "SELECT * FROM SCHEDUAL;";
  if (exit) {
    std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
    //return 1;
  }
  else
    std::cout << "Opened Database Successfully!" << std::endl;

  int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)sql.c_str(), NULL);

  if (rc != SQLITE_OK)
    std::cerr << "Error SELECT" << std::endl;
  else {
    std::cout << "Operation OK!" << std::endl;
    }

}// end get data schedual


/*******************************************
*           Private Methods
*
*********************************************
*/
/*
*   Intent: In the event that the needed tables do not exist this function
*           Has the needed strings to create them with the constructor.
*
*   Precondition: None.
*
*   Postcondition: Approprate tables are created as per the DB requirements.
*                 See the docs for more details.
*/
void Database::tablesInit(sqlite3* sqlptr){
  // Strings for date storage table
  std::string schedualTable = "CREATE TABLE IF NOT EXISTS SCHEDUAL(";
  std::string schID = "AccountID INT PRIMARY KEY NOT NULL, ";
  std::string schDateStart = "START_DATE VARCHAR(14) NOT NULL, "; // YYYYMMDDTHHMM = 13
  std::string schDateEND = "END_DATE VARCHAR(14) NOT NULL); ";
  schedualTable.append(schID);
  schedualTable.append(schDateStart);
  schedualTable.append(schDateEND);
  //std::cout << "SQL str is: " << schedualTable << std::endl;
  int exit = 0;
  char* messaggeError;
  exit = sqlite3_exec(sqlptr, schedualTable.c_str(), NULL, 0, &messaggeError);
  if (exit != SQLITE_OK){
    std::cerr << "Error making table Schedual" << std::endl;
    sqlite3_free(messaggeError);
  }// end if
  else
    std::cout << "Table Schedual has been made. " << std::endl;

  // strings for Accounts
  std::string AccountsTable = "CREATE TABLE IF NOT EXISTS ACCOUNTS(AccountID INT PRIMARY KEY NOT NULL, Email VARCHAR(35) NOT NULL, Password VARCHAR(20) NOT NULL);";
  exit = sqlite3_exec(sqlptr, AccountsTable.c_str(), NULL, 0, &messaggeError);
  if (exit != SQLITE_OK){
    std::cerr << "Error making table Schedual" << std::endl;
    sqlite3_free(messaggeError);
  }// end if
  else
    std::cout << "Table Accounts has been made. " << std::endl;
}// end table inits
/*
*   Intent: The this is to streamline the insertion of data from the
* insert schedual data. There is a duplicity in keyboard inputs of dates
* Helps keep that function easy to read.
*
*   Precondition: None.
*
*   Postcondition: Return a string with YYYYMMDDTHHMM format.
*/
std::string Database::insertSchedualDataAux(){
  std::string date = "empty";
  std::string tmp = "empty";
  std::cout << "\n Enter year: ";
  std::cin >> date;
  std::cout << "\n Enter Month: ";
  std::cin >> tmp;
  date.append(tmp);
  std::cout << "\n Enter Day: ";
  std::cin >> tmp;
  date.append(tmp);
  date.append("T");
  std::cout << "\n Enter Hour: ";
  std::cin >> tmp;
  date.append(tmp);
  std::cout << "\n Enter Minute: ";
  std::cin >> tmp;
  date.append(tmp);
  return date;
} // end of std::string insertSchedualDataAux();

/*
* This function is included to facilitate calls to sql.
* It came from this tutorial. https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
*
*/
int Database::callback(void* data, int argc, char** argv, char** azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

/*
* Precondition: Valid Username and Password as per requirments input.
* Intent: To generate the unique ID for a user Account
* Postcondition: A unique ID number to be genreated. 
*/

int Database::generateID(std::string n, std::string pw){
  int id = 0;
  /* initialize random seed: */
  srand (time(NULL));
  /* generate secret number between 1 and 1000: */
  id = rand() % 1000 + 1;
  return id;
}// end generate ID
