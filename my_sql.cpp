#include "my_sql.h"
#include <QMessageBox>
#include <stdlib.h>
//
my_sql::my_sql()
{
    mysql_init(&mysql);
    connection = NULL;
    memset(buf, 0, sizeof(buf));
}
int my_sql::sql_connect(const char* Hostname, const char *User,
                const char* Passwd, const char* DBname)
{
    connection = mysql_real_connect(&mysql, Hostname, User, Passwd, DBname, 0, 0, 0);
    if (connection == NULL)
    {
        memset(buf, 0, sizeof(buf));
        strcpy(buf, mysql_error(&mysql));
        //QMessageBox::information(0, "", mysql_error(&mysql));
        return -1;
    }
    mysql_query(connection, "set names utf8");
    return 0;
}
const char* my_sql::geterror()
{
    return buf;
}

void my_sql::sql_disconnect()
{
    if(connection)
    {
        mysql_close(connection);
        connection = NULL;
    }
}

int my_sql::sql_exec(const char *SQL)
{
    if (mysql_query(connection, SQL) == -1)
    {
        memset(buf, 0 , sizeof(buf));
        strcpy(buf, mysql_error(&mysql));
        return -1;
    }
    return 0;
}

