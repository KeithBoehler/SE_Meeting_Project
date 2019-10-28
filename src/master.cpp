#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <string>

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
/*
    std::cout << "Hello world! " << std::endl;
    MYSQL* conn;
    conn = mysql_init(0);
    char localIP[] = {'1', '7', '2', '.', '2', '8', '.', '1', '4', '9', '.', '4', '9'}; //std::string localIP = "172.28.149.49";
    char user [] = {'r', 'o', 'o', 't'};//std::string user = "root";
    char password[] = {'1', '2', '3', '4', '5', '6'};//std::string password = "123456";
    char dbName[] = {'w', 'h', 'e', 'r', 'e', '2', 'm', 'e', 'e', 't'};//std::string dbName = "where2meet";
    conn = mysql_real_connect(conn,localIP, user, password, dbName, 0, "NULL", 0);
    if (conn)
        std::cout << "Connection Made. " << std::endl;
    else
        std::cout << "Not connected. " << std::endl;

    // Testing some Qurries

    int test = mysql_query(conn, char *stmt_str) //(MYSQL *mysql, const char *stmt_str)
    return 0; */
    sqlite3* DB;
    std::string sql = "CREATE TABLE CALENDER("
                      "YEAR INT PRIMARY KEY     NOT NULL, "
                      "MONTH INT NOT NULL, "
                      "DAY INT   NOT NULL, "
                      "HOUR      INT     NOT NULL, "
                      "MINUTE INT NOT NULL);";
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;

std::string query = "Select * FROM CALENDER;";
sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
std::string sql2("INSERT INTO CALENDER VALUES(2019, 01, 01, 12, 12);");
exit = sqlite3_exec(DB, sql2.c_str(), NULL, 0, &messaggeError);
if (exit != SQLITE_OK) {
    std::cerr << "Error Insert" << std::endl;
    sqlite3_free(messaggeError);
}
else
    std::cout << "Records created Successfully!" << std::endl;

std::cout << "STATE OF TABLE AFTER INSERT" << std::endl; 
sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    sqlite3_close(DB);
    return (0);
}
