#include <iostream>
#include <mysql/mysql.h>
#include <string>

int main(){

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
    
    return 0;
}
