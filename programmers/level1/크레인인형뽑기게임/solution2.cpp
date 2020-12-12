/* 스택을 이용한 풀이
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;  //바구니
    int doll;   // 뽑은 인형
    
    for(int i=0;i<moves.size();i++){
    	int chk = moves[i]-1;
    	for(int j=0;j<board.size();j++){
    		doll = board[j][chk];
			if(doll!=0){
				if(basket.empty())
				{
					basket.push(doll);
				}
				else
				{	
					/*비교연산*/
					if(basket.top()==doll)
					{
						/*바스켓에서 제거*/
						basket.pop();
						answer+=2;
					}
					else
					{	
					/* 바스켓에 넣기 */
					basket.push(doll);
					}
				}
				
                /* 뽑기처리 */
				board[j][chk] = 0;
				
				break;
				
			}
   		 }

    }
    
    return answer;
}