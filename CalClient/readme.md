#CalClient

<h2>CalLibaray에서 만들어진 dll을 사용하기 위한 CalClient</h2>

<h3>visual studio 2019기준</h3>

<h3>CalClient라는 이름의 콘솔 앱 생성</h3>

![create](https://user-images.githubusercontent.com/71477375/149174917-60c94be0-d86b-4c24-af91-2e1d4f519601.PNG)

<h3>속성에서 경로를 설정해줘야 한다</h3>

CalLibrary의 폴더 경로(C:\Users\msi\Desktop\새 폴더\공부중\코딩 연습\STUDY\CalLibrary)

![1](https://user-images.githubusercontent.com/71477375/149174923-258e94e6-662b-4eea-8cc4-e1fda39e3dde.PNG)

CalLibrary의 폴더 경로(C:\Users\msi\Desktop\새 폴더\공부중\코딩 연습\STUDY\CalLibrary\$(IntDir))

IntDir는 CalLibrary폴더안의 폴더(Debug)폴더를 말한다

![2](https://user-images.githubusercontent.com/71477375/149174928-a89388a3-d1fc-4848-8597-cb23fe88f68e.PNG)

CalLibrary.lib 추가

![3](https://user-images.githubusercontent.com/71477375/149174930-2f4c1c1a-460f-4a3f-8f53-349c4b048cc1.PNG)

위와 같이 설정 후 디버그를 해보면 dll이 없다는 에러 메시지가 나온다
