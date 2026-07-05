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
