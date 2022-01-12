#CalLibrary

<h2>DLL을 만들기 위한 CalLibrary</h2>

<h3>visual studio 2019기준</h3>

<h3>CalLibrary로 DLL프로젝트 생성</h3>

![create](https://user-images.githubusercontent.com/71477375/149172209-8a52be67-2f1b-45b8-a9b4-1253e52ac25e.PNG)

<h3>프로젝트와 같은 이름의 header파일 생성</h3>

![header](https://user-images.githubusercontent.com/71477375/149172218-5faf6b9d-3841-4e35-903c-9d83d914c222.PNG)

헤더파일 생성 시에 사진에 보이는 CALLIBRARY_API는 다른 이름이여도 상관 없지만 
프로젝트랑 같은 이름에 모두 통일시켜주는 것이 중요하다

<h3>프로젝트와 같은 이름의 cpp파일 생성</h3>

헤더와 DLL프로젝트로 생성 시 기본적으로 만들어지는 pch.h도 같이 include해야 한다.

![cpp](https://user-images.githubusercontent.com/71477375/149172219-c51e560c-a25a-4bf4-a6aa-3eaea35060ad.PNG)

<h3>마지막으로 빌드를 눌러주면 dll과 lib파일이 
