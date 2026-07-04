/*
   - 문제: 프로그래머스 Lv.1 명예의 전당 (1) - 내 원래 풀이
   - 날짜: 2026-07-04
   - 해결점: 
     1. 처음에 mini 값이 업데이트되지 않던 로직 오류를 발견 후 'mini = score[i];'를 추가해 디버깅함!
     2. score.size()가 k보다 작을 때 인덱스가 터지는 버그 때문에 'i < min(k, (int)score.size())' 조건식 추가.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer; // 매 날의 명예의 전당의 최하위 점수를 저장하는 배열 
    vector<int> hallOfFame; // 그날의 명예의 전당 
    int mini = score[0];
    
    // k와 score.size() 중 작은 값만큼만 돌도록 안전장치 설정
    for (int i = 0; i < min(k, (int)score.size()); i++) {
        hallOfFame.push_back(score[i]);
        if (score[i] >= mini) {
            answer.push_back(mini);
        } else {
            answer.push_back(score[i]);
            mini = score[i];
        }
    } 
    
    sort(hallOfFame.begin(), hallOfFame.end()); //초기 명예의 전당 
    
    for (int i = k; i < score.size(); i ++) {
        if (score[i] > hallOfFame[0]) {
            hallOfFame[0] = score[i];
            sort(hallOfFame.begin(), hallOfFame.end());
            mini = min(hallOfFame[0], score[i]);
            answer.push_back(mini);
        } else {
            answer.push_back(hallOfFame[0]);
        }
    }
    
    return answer;
}
