#include <mysql.h>	//�ȵǸ� #include <mysql/mysql.h> �Ѵ� �õ��غ���.
#include <stdio.h>
#pragma comment (lib, "libmysql.lib")

#define MYSQLUSER "root"				//���� �̸�
#define MYSQLPASSWORD "Wjdtmdeo12@"		//��й�ȣ
#define MYSQLIP "localhost"	

//void loadmysql(const char mysqlip[], MYSQL* cons) {	//MYSQL ���� �ҷ�����
//	if (cons == NULL) //cons�� �ʱ�ȭ�� ��������
//	{
//		fprintf(stderr, "%s\n", mysql_error(cons));		//���� ����Ʈ, printf("%s")�� ����
//		Sleep(1000);
//		exit(1);
//	}
//	if (!(mysql_real_connect(cons, mysqlip, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0) == NULL)) //mysql������ ���� �����ϸ� 0 �ƴϸ� �ٸ��� ��ȯ
//	{
//		printf("����\n");
//		mysql_set_character_set(cons, "euckr");				//MySQL ���ڸ� �����Ѵ�. ���� ���ϸ� �ѱ��� ©��.
//	}
//	else {
//		fprintf(stderr, "���� ���� : %s\n", mysql_error(cons));
//		getchar();
//	}
//	return;
//}

int main(void) {
	MYSQL* cons = mysql_init(NULL);				//MYSQL ���� �ʱ�ȭ.
	mysql_real_connect(cons, "localhost", MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0);
	mysql_set_character_set(cons, "euckr");
	mysql_query(cons, "SELECT * FROM opentutorials.topic");
	MYSQL_RES* result = mysql_store_result(cons);
	//�� row(���ڵ�)���� �Ӽ�(�ʵ�)�� ������ ��
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;

	/*
	row��ü�� ���� ������
	5���� row�� 5�� ��
	*/
	while (row = mysql_fetch_row(result))
	{
		/*
		�� row ���� �Ӽ���ŭ
		row���� id title name���� ������
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