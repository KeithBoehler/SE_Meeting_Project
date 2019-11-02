#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <string>

class Database{

  public:
    Database(); // defult constructor
    Database(std::string);
    void closeDB();
    void insertData();

  private:
    // Variables
    sqlite3* DB = NULL;
    std::string dbLocation;
    // Tests
    bool dbExist(std::string, sqlite3*);
    bool tableExist(std::string);
    void tablesInit(sqlite3* sqlptr);

    // from the sql tutorial
    int callback(void* data, int argc, char** argv, char** azColName);
}; // end class DB
