/*
   - 문제: 프로그래머스 Lv.1 바탕화면 정리
   - 날짜: 2026-07-02
   - 느낀 점: 이중 for문과 flag를 써서 예외 처리를 하며 정답을 맞힘.
             하지만 다른 사람의 풀이를 보니 string::find()와 rfind()를 사용하면 
             1중 for문과 min/max 함수만으로도 깔끔하게 끝낼 수 있다는 것을 배움
             다음에는 문자열 안에서 특정 문자의 처음/끝 위치를 찾을 때 활용해야겠다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int sX = 0;
    int sY = 0;
    int eX = 0;
    int eY = 0;
    bool flag = false;

    int row = wallpaper.size(); //행 수
    int column = wallpaper[0].size(); //열 수
    for (int i = 0; i < wallpaper[0].size(); i++) {
        for (int k = 0; k < wallpaper.size(); k++) {
            if (wallpaper[k][i] == '#') {
                sY = i;
                flag = true;
                
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    flag = 0;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int k = 0; k < wallpaper[0].size(); k++) {
            if (wallpaper[i][k] == '#') {
                sX = i;
                flag = 1;
                break;
                
            }
            
        }
        if (flag == 1) {
            break;
        }
    }
    flag = 0;
    for (int k = 0; k < wallpaper[0].size(); k++) {
        for (int i = 0; i < wallpaper.size(); i++) {
            if (wallpaper[row-i-1][column-k-1] == '#') {
                eY = column - k;
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    flag = 0;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int k = 0; k < wallpaper[0].size(); k++) {
            if (wallpaper[row-i-1][column-k-1] == '#') {
                eX = row - i;
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    answer.push_back(sX);
    answer.push_back(sY);
    answer.push_back(eX);
    answer.push_back(eY);
    return answer;
}
