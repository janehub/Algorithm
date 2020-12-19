/*
uique
: 중복원소 제거
사이즈 새롭게 정의해야함
바뀌지 않은 값 쓰레기값으로 남음
바뀌지 않은 마지막 위치(쓰레기값 처음) 이터레이터 반환
Removes all but the first element from every consecutive group of equivalent elements in the range [first,last)
The function cannot alter the properties of the object containing the range of elements
(i.e., it cannot alter the size of an array or a container):
The removal is done by replacing the duplicate elements by the next element that is not a duplicate,
and signaling the new size of the shortened range by returning an iterator to the element that should be considered its new past-the-end element.
The relative order of the elements not removed is preserved, while the elements between the returned iterator and last are left in a valid but unspecified state.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    vector<int>::iterator it;

    it = unique(arr.begin(), arr.end());
    
    answer.assign(arr.begin(),it);

    return answer;
}
