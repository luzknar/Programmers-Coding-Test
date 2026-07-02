/*
   - 문제: 프로그래머스 Lv.1 바탕화면 정리
   - 날짜: 2026-07-02
   - 핵심 원리 정리 :
     1. 이중 for문으로 격자판의 모든 칸을 (i=세로, j=가로) 순서로 전부 훑는다.
     2. '#'을 만날 때마다 'min'과 'max' 함수를 이용해 드래그 상자의 크기를 실시간으로 늘린다.
     
     3. 왜 min(answer[0], i)를 할까?
        - 사각형의 '천장(sX)'은 모든 파일 중 가장 위쪽(줄 번호가 가장 작은 최솟값)에 그어야 한다.
        - 초기값 100에서 시작해서, 더 작은 줄 번호(더 위쪽)가 나타날 때마다 천장을 위로 바짝 당기는 원리
        - 같은 원리로 '왼쪽 벽(sY)'도 가장 작은 가로 인덱스를 찾아야 하므로 min(answer[1], j)를 쓴다.
        
     4. 왜 max(answer[2], i+1)을 할까?
        - 사각형의 '바닥(eX)'은 모든 파일 중 가장 아래쪽(줄 번호가 가장 큰 최댓값)에 그어야 한다.
        - 초기값 -100에서 시작해서, 더 아래쪽 줄 번호가 나올 때마다 바닥을 밑으로 계속 밀어내는 원리
        - 드래그 끝점은 칸의 우측 하단 꼭짓점이어야 하므로 '+1'  더해준다.

   - 한줄평: flag나 break로 억지로 루프를 끊는 것보다, min/max로 전체를 수렴시키는 이 구조가 2차원 배열 탐색의 정석
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
