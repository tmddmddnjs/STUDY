<h2>connect database</h2>

<h3>MYSQL 연결 초기화</h3>
- MYSQL* cons = mysql_init(NULL);

<h3>데이터 베이스 연결</h3>
- mysql_real_connect(cons, MYSQLIP, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0); 

<h3>이거 안하면 한국어 깨져서 나온다</h3>
- mysql_set_character_set(cons, "euckr");

<h3>query를 이용해 sql문을 사용</h3>
- mysql_query(cons, "SELECT * FROM opentutorials.topic");

<h3>데이터 베이스 내용 불러온 사진</h3>

![database](https://user-images.githubusercontent.com/71477375/146366052-6541457a-0823-4e1f-8500-b9c176b77ab8.PNG)

<h3>가져오는 방법</h3>
- 1

디버그 - 속성 - V/C++ 디렉터리

포함 디렉터리 - mysql-connector-c-6.1.11-winx64\include

라이브러기 디렉터리 - mysql-connector-c-6.1.11-winx64\lib

- 2

x86 -> x64로 바꾸고

현재 디렉토리 안에 

mysql-connector-c-6.1.11-winx64\lib 경로의 libmysql.dll을 복사해서 넣어야한다.

- 3

소스 안에서

#include <mysql.h>

#pragma comment (lib, "libmysql.lib")

- 4

디버그 - 속성 - C/C++ / 코드 생성에서

런타임 라이브러리를 다중 스레드(/MT)로 바꿈
