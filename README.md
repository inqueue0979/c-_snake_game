<div align=center>
  
![header](https://capsule-render.vercel.app/api?type=waving&height=300&color=gradient&text=2024%20Snake%20Game&desc=Kookmin%20Univ.%20C%2B%2B프로그래밍%20"하브사케"%20팀&descAlignY=55&animation=fadeIn&fontAlignY=40&section=header&reversal=true)

## 프로젝트 구조
<div align=left>
  
```plaintext
CPP_SNAKE_GAME/
├── include/                 # 헤더 파일
│   ├── data.h               # 뱀과 타이틀 아트 데이터 포함
│   ├── Direction.h          # 방향에 대한 열거형
│   ├── Gate.h               # Gate 클래스 정의
│   ├── InputHandler.h       # InputHandler 클래스 정의
│   ├── Item.h               # Item 클래스 정의
│   ├── MainMenu.h           # MainMenu 클래스 정의
│   ├── MapData.h            # 맵 데이터
│   ├── ScoreBoard.h         # ScoreBoard 클래스 정의
│   ├── Snake.h              # Snake 클래스 정의
│   └── SnakeMap.h           # SnakeMap 클래스 정의
├── obj/                     # 컴파일된 오브젝트 파일
├── src/                     # 소스 파일
│   ├── data.cpp             # data.h 내용 구현
│   ├── Gate.cpp             # Gate 클래스 구현
│   ├── InputHandler.cpp     # InputHandler 클래스 구현
│   ├── Item.cpp             # Item 클래스 구현
│   ├── main.cpp             # 메인 게임 루프와 프로그램 시작점
│   ├── MainMenu.cpp         # MainMenu 클래스 구현
│   ├── MapData.cpp          # 맵 데이터 로딩 구현
│   ├── ScoreBoard.cpp       # ScoreBoard 클래스 구현
│   ├── Snake.cpp            # Snake 클래스 구현
│   └── SnakeMap.cpp         # SnakeMap 클래스 구현
├── test/                    # 테스트 파일
│   └── credit_screen_test.cpp # 크레딧 화면 테스트
├── .gitignore               # Git ignore 파일
├── Makefile                 # 프로젝트 빌드를 위한 Makefile
├── README.md                # 프로젝트 README 파일
└── run                      # 컴파일된 실행 파일
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
      <td style="text-align: center;"><strong>✅</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>2</strong></td>
      <td>
        <br><strong>Snake 구현 ( *규칙1 준수 )</strong><br><br>(1) 키 입력 처리 방법 (기본)<br>(2) Tick 에 대한 변화 구현<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>✅</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>3</strong></td>
      <td>
        <br><strong>Growth Item과 Poison Item 구현 ( *규칙2 준수 )</strong><br><br>(1) Map에 Growth Item과 Poison Item 출현<br>(2) Snake와 Item의 상호작용 처리<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>✅</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>4</strong></td>
      <td>
        <br><strong>Gate 구현 ( *규칙3, 4, 5 준수 )</strong><br><br>(1) Wall의 임의 위치에 Gate 출현<br>(2) Snake와 Gate의 상호작용 처리<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>✅</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>5</strong></td>
      <td>
        <br><strong>Score Board 구현 ( *규칙6 준수 )</strong><br><br>(1) 게임 점수 표시<br>(2) 미션 달성 시 다음 Map 진행<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>✅</strong></td>
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
