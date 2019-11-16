#include "loginwindow.h"
#include "include/Database.h"
#include <iostream>
#include <cstdlib>
#include <sqlite3.h>


#include <string>
#include <QApplication>

int main(int argc, char *argv[])
{
    std::cout << "Hi" << std::endl;
    //std::string path = "/Users/keithnator3000/OneDrive - The University of Texas-Rio Grande Valley/Classes/STEM/Computer_Science/Software Engineering I - CSCI 3340/SE_Fall19/project/SE_Meeting_Project/sqlite/where2meet.db";
    std::string path = "/home/keithnator3000/SE_Meeting_Project/sqlite/where2meet.db";
    Database DBObj(path);
    //Database DBObj;
    //DBObj.createAccountData();
    //int id = DBObj.loginAccount();
    //DBObj.insertSchedualData(id);
    //DBObj.getAccountData(id);
    //DBObj.getSchedualData(id);
    //DBObj.closeDB();
    std::cout << "Bye!" << std::endl;
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}
