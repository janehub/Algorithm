#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;	/* 바구니 */
    int doll;	/* 뽑은인형 */
    
    for(int i=0;i<moves.size();i++){
    	
    	for(int j=0;j<board.size();j++){
    		doll = board.at(j).at(moves.at(i)-1);
			if(doll!=0){
				if(basket.size()==0)
				{
					/* 바구니에 넣기 */
					basket.push_back(doll);
				}
				else
				{	
					/*비교연산*/
					if(basket.back()==doll)
					{
						/*바구니에서 제거*/
						basket.pop_back();
						answer+=2;
					}
					else
					{	
					/* 바구니에 넣기 */
					basket.push_back(doll);
					}
				}
				
				/* 꺼내기 */
				board.at(j).at(moves.at(i)-1) = 0;
				
				break;
				
			}
   		 }

    }
    
    return answer;
}