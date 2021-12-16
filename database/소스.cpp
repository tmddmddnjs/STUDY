#include <mysql.h>	//안되면 #include <mysql/mysql.h> 둘다 시도해본다.
#include <stdio.h>
#pragma comment (lib, "libmysql.lib")

#define MYSQLUSER "root"				//유저 이름
#define MYSQLPASSWORD "Wjdtmdeo12@"		//비밀번호
#define MYSQLIP "localhost"	

//void loadmysql(const char mysqlip[], MYSQL* cons) {	//MYSQL 서버 불러오기
//	if (cons == NULL) //cons가 초기화를 못했으면
//	{
//		fprintf(stderr, "%s\n", mysql_error(cons));		//에러 프린트, printf("%s")와 같음
//		Sleep(1000);
//		exit(1);
//	}
//	if (!(mysql_real_connect(cons, mysqlip, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0) == NULL)) //mysql서버로 연결 성공하면 0 아니면 다른수 반환
//	{
//		printf("성공\n");
//		mysql_set_character_set(cons, "euckr");				//MySQL 문자를 지정한다. 만약 안하면 한글이 짤림.
//	}
//	else {
//		fprintf(stderr, "연결 오류 : %s\n", mysql_error(cons));
//		getchar();
//	}
//	return;
//}

int main(void) {
	MYSQL* cons = mysql_init(NULL);				//MYSQL 연결 초기화.
	mysql_real_connect(cons, "localhost", MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0);
	mysql_set_character_set(cons, "euckr");
	mysql_query(cons, "SELECT * FROM opentutorials.topic");
	MYSQL_RES* result = mysql_store_result(cons);
	//한 row(레코드)안의 속성(필드)의 개수를 셈
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;

	/*
	row전체가 끌날 때까지
	5개의 row면 5번 돔
	*/
	while (row = mysql_fetch_row(result))
	{
		/*
		한 row 안의 속성만큼
		row안의 id title name등을 가져옴
		*/
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