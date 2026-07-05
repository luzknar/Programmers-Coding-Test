/*
   - 문제: 프로그래머스 Lv.1 외계어 사전 
   - 날짜: 2026-07-05
   - 배운 점:
     1. [변수 리셋]: 단어(i)가 바뀔 때마다 count를 0으로 리셋해주어야 데이터가 누적되지 않는다는 것을 디버깅함
     2. 알파벳 중복 사용을 막기 위해 사용한 글자를 공백(" ")으로 지움
     3. [원본 보호]: spell 배열이 지워지는 것을 방지하기 위해 매 루프마다 'vector<string> tempSpell = spell;' 복사본을 만듦
     4. [타입 매칭]: C++에서 char(dic[i][j])와 string(tempSpell[k])은 직접 비교가 안 되므로, tempSpell[k][0]으로 char 타입을 맞춰주어야함
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    int count = 0;
    
    for (int i = 0; i < dic.size(); i++) {
        count = 0;
        vector<string> tempSpell = spell; // 원본 보호를 위한 복사본 생성
        
        for (int j = 0; j < dic[i].size(); j++) {
            if (tempSpell.size() == dic[i].size()) {
                for (int k = 0; k < tempSpell.size(); k++) {
                    // char형과 string의 0번 인덱스 char형을 매칭!
                    if (dic[i][j] == tempSpell[k][0]) {
                        count++;
                        tempSpell[k] = " "; // 사용한 알파벳 마스킹 처리
                        if (count == tempSpell.size()) {
                            return 1;
                        } 
                    }
                }
            }
        }
    }
    answer = 2;
    
    return answer;
}



/*
   - 문제: 프로그래머스 Lv.1 외계어 사전 - 2차 최적화 버전 
   - 날짜: 2026-07-05
   - 배운 점:
     1. [C++ 내장 함수 활용]: 수동으로 3중 for문을 돌리던 구조에서 `string.find()` 함수를 활용하여 2중 for문으로 압축함.
     2. [Range-based for loop]: `const auto& i : dic` 문법을 사용하여 인덱스 범위 초과(Runtime Error) 예외를 구조적으로 방어함.
     3. [메모리 최적화]: 참조자(&)를 붙여 복사본 생성으로 인한 메모리 낭비를 막고, 읽기 전용(const)으로 안전하게 데이터를 탐색함.
     4. [자동 타입 추론]: `auto` 키워드를 사용하여 데이터 타입을 컴파일러가 알아서 추론하게 만들어 코드 가독성을 높임. 
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    bool flag = true; // 1 대신 직관적인 bool 타입 true 사용
    
    for (const auto& i : dic) {
        flag = true; // 매 단어 검사 시작 시 깃허브(Flag) 초기화
        
        for (const auto& t : spell) {
            // 단어 i 안에 알파벳 t가 포함되어 있지 않다면
            if (i.find(t) == string::npos) {
                flag = false; // 깃발 내림
                break;        // 이미 탈락이므로 남은 알파벳 검사는 중단 
            }
        }
        
        if (flag == true) {
            return 1;  
        }
    }
    
    return answer;
}
