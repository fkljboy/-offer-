
class Solution {
    public:
        int FirstNotRepeatingChar(string str) {
            unordered_map<char,int> Map;
            for (int i=0;i<str.size();i++){
                Map[str[i]]++;
            }
            for(int i=0;i<str.size();i++){
                if (Map[str[i]]==1)
                    return i;
            }
            return -1;
        }
    };
// 这个题用cpp的stl解决就很方便，没什么好说的