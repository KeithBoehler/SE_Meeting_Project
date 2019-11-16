#include <iostream>
#include <cstdlib>
#include <sqlite3.h>

#include <string>

class Database{

  public:
    Database(); // defult constructor
    Database(std::string);
    void closeDB();
    void insertSchedualData(int);
    void createAccountData();
    int loginAccount();
    void getSchedualData(int);
    void getAccountData(int);

  private:
    // Variables
    sqlite3* DB = NULL;
    std::string dbLocation;
    int userID;
    // Tests
    bool dbExist(std::string, sqlite3*);
    bool tableExist(std::string);
    void tablesInit(sqlite3* sqlptr);
    std::string insertSchedualDataAux();
    int generateID(std::string, std::string);

    // from the sql tutorial
    static int callback(void* data, int argc, char** argv, char** azColName);
}; // end class DB
