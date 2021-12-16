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
