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


// 2차 시도 (Refactoring): 다른 사람의 풀이를 참고한 최적화 버전

/*
   - 배운 점: 
     1. 정원을 초과할 때 굳이 루프를 쪼갤 필요 없이, 'greater<int>()' 내림차순 정렬을 활용하면 꼴찌가 항상 맨 뒤(back)에 위치하게 된다.
     2. 'hallOfFame.size() > k'일 때 'pop_back()'으로 맨 뒤를 잘라내면 인원 제한과 예외 처리가 단 한 번에 해결됨
*/

vector<int> solution_optimized(int k, vector<int> score) {
    vector<int> answer;
    vector<int> hallOfFame;
    
    for (int i = 0; i < score.size(); i++) {
        hallOfFame.push_back(score[i]);
        sort(hallOfFame.begin(), hallOfFame.end(), greater<int>());
        
        if (hallOfFame.size() > k) {
            hallOfFame.pop_back();
        }
        answer.push_back(hallOfFame.back());
    }
    return answer;
}


