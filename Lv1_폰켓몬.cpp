/*
  문제: 프로그래머스 Lvl 1 - 폰켓몬
 [고민 및 해결 과정]
 1. 폰켓몬 종류의 중복을 제거하기 위해 std::set 컨테이너를 활용함.
 - s(nums.begin(), nums.end()) 형태로 이터레이터를 전달하여 vector 데이터를 set에 대입 및 중복 자동 제거.
 2. C++ 타입 불일치 트러블슈팅
- std::min 함수를 쓸 때 비교하려는 두 값의 타입이 다르면 컴파일 에러가 발생함.
- s.size()가 반환하는 size_t와 int 타입인 min_size를 맞춰주기 위해 size_t 또는 int로 명시적 형변환(casting) 처리함.
 */

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s(nums.begin(), nums.end());
    answer = (int)s.size();
    int min_size = nums.size() / 2;
    return min(answer, min_size);
}
