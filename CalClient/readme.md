#CalClient

<h2>CalLibaray에서 만들어진 dll을 사용하기 위한 CalClient</h2>

<h3>visual studio 2019기준</h3>

<h3>CalClient라는 이름의 콘솔 앱 생성</h3>

![create](https://user-images.githubusercontent.com/71477375/149174917-60c94be0-d86b-4c24-af91-2e1d4f519601.PNG)

<h3>속성에서 경로를 설정해줘야 한다</h3>

CalLibrary의 폴더 경로(C:\Users\msi\Desktop\새 폴더\공부중\코딩 연습\STUDY\CalLibrary)

![1](https://user-images.githubusercontent.com/71477375/149174923-258e94e6-662b-4eea-8cc4-e1fda39e3dde.PNG)

CalLibrary의 폴더 경로(C:\Users\msi\Desktop\새 폴더\공부중\코딩 연습\STUDY\CalLibrary\$(IntDir))

IntDir는 CalLibrary폴더안의 dll파일이 있는 폴더 여기서는 Debug폴더를 뜻한다

![2](https://user-images.githubusercontent.com/71477375/149174928-a89388a3-d1fc-4848-8597-cb23fe88f68e.PNG)

CalLibrary.lib 추가

![3](https://user-images.githubusercontent.com/71477375/149174930-2f4c1c1a-460f-4a3f-8f53-349c4b048cc1.PNG)

위와 같이 설정 후 디버그를 해보면 dll이 없다는 에러 메시지가 나온다

이런 경우 해결법이 2가지가 있는데 

<h3>해결법1 - dll이 있는 폴더의 경로 넣기</h3>

![4](https://user-images.githubusercontent.com/71477375/149176659-5c1fb81f-008a-45e6-bdb2-43a542a71d7a.PNG)

<h3>해결법2 - dll을 직접 Client폴더에 넣기</h3>

![5](https://user-images.githubusercontent.com/71477375/149176649-fd0d9f77-52b7-4c85-87c2-7f80f0b2d5f4.PNG)

위와 같은 방법으로 dll을 넣으면 디버그를 해 결과를 얻을 수 있다.

<h3>결과</h3>

![result](https://user-images.githubusercontent.com/71477375/149176657-583d4c36-18db-4b3c-a4db-105e5345cbbd.PNG)
