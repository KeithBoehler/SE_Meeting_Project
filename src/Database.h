#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <string>

class Database{

  public:
    Database(); // defult constructor
    Database(std::string);
    void closeDB();

  private:
    // Variables
    sqlite3* DB = NULL;
    // Tests
    bool dbExist(std::string, sqlite3*);
    bool tableExist(std::string);
}; // end class DB
