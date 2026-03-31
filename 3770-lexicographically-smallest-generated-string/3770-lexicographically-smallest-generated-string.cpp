class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        string word(n + m - 1, '?');
            for(int i = 0; i < n; i++)
            {
                if(str1[i] != 'T')
                {
                    continue;
                }
                    for(int j = 0; j < m; j++)
                    {
                        char v = word[i + j];
                        if( v != '?' && v != str2[j])
                        {
                            return "";
                        }
                        word[i + j] = str2[j];
                    }
            }

            string old_word = word;
            for(int k = 0; k < word.length(); k++)
            {
                if(word[k] == '?')
                {
                    word[k] = 'a';
                }
            }

            for(int i = 0; i < n; i++)
            {
                if(str1[i] != 'F')
                {
                    continue;
                }

                if(string(word.begin() + i, word.begin() + i + m) != str2)
                {
                    continue;
                }

                bool ok = false;

                for(int j = i + m -1;j >= i; j--)
                {
                    if(old_word[j] == '?')
                    {
                        word[j] = 'b';
                        ok = true;
                        break;
                    }
                }
                if(!ok)
                {
                    return "";
                }
            }
        return word;
    }
};