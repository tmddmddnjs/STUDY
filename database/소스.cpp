#include <mysql.h>	
#include <stdio.h>
#pragma comment (lib, "libmysql.lib")

int main(void) {
	MYSQL* cons = mysql_init(NULL);				
	mysql_real_connect(cons, "localhost", MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0);
	mysql_set_character_set(cons, "euckr");
	mysql_query(cons, "SELECT * FROM opentutorials.topic");
	MYSQL_RES* result = mysql_store_result(cons);
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
	/*row = mysql_fetch_row(result);
	printf("%s %s %s %s", row[0], row[1], row[2], row[3]);*/
	mysql_close(cons);
	return 0;
}
