class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         s+=ch;
         count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len =s.size();
        for (int i=0;i<len;i++){
           if (count[s[i]]==1)
               return s[i];
            
        }
        return  '#';
    }
private:
    string s;
    map<char,int> count;

};
// 常规的map解法