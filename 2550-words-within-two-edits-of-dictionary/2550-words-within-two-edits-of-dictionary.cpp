class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(int i = 0; i < queries.size(); i++)
        {
             
            for(int j = 0; j < dictionary.size(); j++)
            {   
                int error = 0;     
                for(int k = 0; k < queries[0].size(); k++)
                {
                    if(queries[i][k] != dictionary[j][k])
                    {
                        error++;
                    }
                }
                if(error <= 2)
                {
                    result.push_back(queries[i]);
                    break;
                }
            }
            
        }
    return result;
    }
};