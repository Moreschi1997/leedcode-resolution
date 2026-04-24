class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, I = 0;

        for(int i = 0; i < moves.length(); i++)
        {
            if(moves[i] == 'L')
            {
                L++;
            }
            else if(moves[i] == 'R')
            {
                R++;
            }
            else
            {
                I++;
            }
        }
        return abs(R - L) + I;  
    }
};