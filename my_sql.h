#ifndef MY_SQL_H
#define MY_SQL_H

#include <windows.h>
#include <C:/mysql/include/mysql.h>
//#include <mysql/mysql.h>

class my_sql
{
public:
    my_sql();
    const char* geterror();
    void sql_disconnect();
    int sql_exec(const char* SQL);
    int sql_connect(const char* Hostname, const char *User, const char* Passwd, const char* DBname);
private:
    MYSQL *connection;
    MYSQL mysql;
    char buf[1024];
};

#endif // MY_SQL_H
