<div align=center>
  
![header](https://capsule-render.vercel.app/api?type=waving&height=300&color=gradient&text=2024%20Snake%20Game&desc=Kookmin%20Univ.%20C%2B%2B프로그래밍%20"하브사케"%20팀&descAlignY=55&animation=fadeIn&fontAlignY=40&section=header&reversal=true)

## 프로젝트 구조
<div align=left>
  
```plaintext
CPP_SNAKE_GAME/
├── include/                              # 헤더 파일들이 포함된 디렉토리
│   ├── data.h                            # 게임 내 뱀 아트와 텍스트 타이틀 데이터를 포함
│   ├── InputHandler.h                    # 입력 처리를 위한 클래스 헤더 파일
│   ├── MainMenu.h                        # 메인 메뉴 클래스를 위한 헤더 파일
│   ├── MapData.h                         # 맵 데이터를 포함하는 헤더 파일
│   ├── Snake.h                           # 뱀 클래스 헤더 파일
│   └── SnakeMap.h                        # 맵 클래스를 위한 헤더 파일
├── obj/                                  # 오브젝트 파일들이 저장될 디렉토리 (컴파일된 중간 파일들)
├── src/                                  # 소스 파일들이 포함된 디렉토리
│   ├── data.cpp                          # 게임 내 뱀 아트와 텍스트 타이틀 데이터를 정의
│   ├── InputHandler.cpp                  # 입력 처리를 구현하는 소스 파일
│   ├── main.cpp                          # 프로그램의 진입점
│   ├── MainMenu.cpp                      # 메인 메뉴 클래스를 구현하는 소스 파일
│   ├── MapData.cpp                       # 맵 데이터를 구현하는 소스 파일
│   ├── Snake.cpp                         # 뱀 클래스를 구현하는 소스 파일
│   └── SnakeMap.cpp                      # 맵 클래스를 구현하는 소스 파일
├── test/                                 # 테스트 파일들이 포함된 디렉토리
│   └── credit_screen_test.cpp            # 크레딧 화면 테스트를 위한 소스 파일
├── .gitignore                            # Git에서 추적하지 않을 파일 또는 디렉토리를 명시
├── Makefile                              # 프로젝트 빌드 설정 파일
├── README.md                             # 프로젝트에 대한 설명서
└── run                                   # 컴파일된 실행 파일
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
      <td style="text-align: center;"><strong>⚠️</strong></td>
    </tr>
    <tr>
      <td style="text-align: center;"><strong>5</strong></td>
      <td>
        <br><strong>Score Board 구현 ( *규칙6 준수 )</strong><br><br>(1) 게임 점수 표시<br>(2) 미션 달성 시 다음 Map 진행<br>&nbsp;
      </td>
      <td style="text-align: center;"><strong>⚠️</strong></td>
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
