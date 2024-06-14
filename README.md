<div align=center>
  
![header](https://capsule-render.vercel.app/api?type=waving&height=300&color=gradient&text=2024%20Snake%20Game&desc=Kookmin%20Univ.%20C%2B%2B프로그래밍%20"하브사케"%20팀&descAlignY=55&animation=fadeIn&fontAlignY=40&section=header&reversal=true)

## 프로젝트 구조
<div align=left>
  
```plaintext
CPP_SNAKE_GAME/
├── include/
│   ├── data.h                // 프로젝트 전반에서 사용할 데이터 및 상수 정의 (필요시)
│   ├── MapData.h             // 맵 데이터를 외부에서 사용할 수 있도록 선언
│   ├── Snake.h               // Snake 클래스 선언, 뱀의 상태와 동작을 정의
│   └── SnakeMap.h            // SnakeMap 클래스 선언, 게임 맵의 상태와 동작을 정의
├── obj/
│   ├── main.d                // main.cpp의 종속성 파일
│   ├── main.o                // main.cpp의 오브젝트 파일
│   ├── MapData.d             // MapData.cpp의 종속성 파일
│   ├── MapData.o             // MapData.cpp의 오브젝트 파일
│   ├── Snake.d               // Snake.cpp의 종속성 파일
│   ├── Snake.o               // Snake.cpp의 오브젝트 파일
│   ├── SnakeMap.d            // SnakeMap.cpp의 종속성 파일
│   └── SnakeMap.o            // SnakeMap.cpp의 오브젝트 파일
├── src/
│   ├── main.cpp              // 메인 실행 파일, 게임 초기화 및 메인 루프 처리
│   ├── MapData.cpp           // 맵 데이터 정의, 다양한 레벨의 맵 데이터를 포함
│   ├── Snake.cpp             // Snake 클래스의 구현, 뱀의 움직임과 충돌 처리 로직 포함
│   └── SnakeMap.cpp          // SnakeMap 클래스의 구현, 게임 맵 그리기 및 충돌 처리 로직 포함
├── test/
│   └── credit_screen_test.cpp // 크레딧 화면 등의 테스트 코드 (예시)
├── .gitignore                // Git에서 무시할 파일/디렉토리 지정
├── Makefile                  // 빌드 자동화를 위한 Makefile, 컴파일 및 실행 설정
├── README.md                 // 프로젝트 설명 및 사용법을 담은 문서
└── run                       // 생성된 실행 파일 (빌드 후 생성됨)
```
</div>
  
## 구현 단계 도식화
<table>
  <thead>
    <tr>
      <th style="text-align: center;">단계</th>
      <th style="text-align: center;">구현 내역</th>
      <th style="text-align: center;">상태</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: center;"><strong>1</strong></td>
      <td>
        <br><strong>2차원 배열로 이루어진 Snake Map 구현</strong><br><br>(1) Map의 구성 요소<br>> Data 처리 방법, Map Data Import/Export 등<br><br>(2) Map과 다른 객체와의 상호작용<br>> Snake, Items, … <br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>⚠️</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>2</strong></td>
      <td>
        <br><strong>Snake 구현 ( *규칙1 준수 )</strong><br><br>(1) 키 입력 처리 방법 (기본)<br>(2) Tick 에 대한 변화 구현<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>❌</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>3</strong></td>
      <td>
        <br><strong>Growth Item과 Poison Item 구현 ( *규칙2 준수 )</strong><br><br>(1) Map에 Growth Item과 Poison Item 출현<br>(2) Snake와 Item의 상호작용 처리<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>❌</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>4</strong></td>
      <td>
        <br><strong>Gate 구현 ( *규칙3, 4, 5 준수 )</strong><br><br>(1) Wall의 임의 위치에 Gate 출현<br>(2) Snake와 Gate의 상호작용 처리<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>❌</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>5</strong></td>
      <td>
        <br><strong>Score Board 구현 ( *규칙6 준수 )</strong><br><br>(1) 게임 점수 표시<br>(2) 미션 달성 시 다음 Map 진행<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>❌</strong></td>
    </tr>
  </tbody>
</table>

<p style="text-align: center;">✅ : 완료 | ⚠️ : 부분 완료 | ❌ : 미완료</p>


## 🧑🏻‍💻 Teammates
<table>
  <td align="center"><a href="https://github.com/inqueue0979"><img src="https://avatars.githubusercontent.com/u/69336138?v=4" width="100px;" alt=""/><br /><sub><b>조원재</b></sub></a><br /><sub>팀장 | 소프트웨어학부 23</sub><br /></td>
  <td align="center"><a href="https://github.com/joseokbin0125"><img src="https://avatars.githubusercontent.com/u/170411407?v=4" width="100px;" alt=""/><br /><sub><b>조석빈</b></sub></a><br /><sub>소프트웨어학부 23</sub><br /></td>
  <td align="center"><a href="https://github.com/jooya38"><img src="https://avatars.githubusercontent.com/u/107492177?v=4" width="100px;" alt=""/><br /><sub><b>황연주</b></sub></a><br /><sub>소프트웨어학부 23</sub><br /></td>
</table>
</div>
