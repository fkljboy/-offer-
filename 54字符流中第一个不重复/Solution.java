import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
public class Solution {
    //Insert one char from stringstream
   HashMap<Character,Integer> map = new HashMap<Character,Integer>();//存放字符和其出现的次数
	ArrayList<Character> list = new ArrayList<Character>();//存放字符
	//把字符存对应的次数在map中更新，并把字符按照出现顺序存放在list中
	public void Insert(char ch)
	    {
		 //判断map中是否已经包含要插入的字符，如果已经包含则将其次数+1
	      if(map.containsKey(ch))
	      {
	    	 map.put(ch,map.get(ch)+1);//map.get(ch)是根据key得到value的值
	      }
	      else
	      {
	    	  map.put(ch,1);//如果map中还没有包含，则把ch放入map中，并将其值设为1；
	      }
	      list.add(ch);//将ch放入list中，便于根据list中保存的ch到map中去查询出现次数
	    }
	//遍历list去map中寻找出现的次数
	    public char FirstAppearingOnce()
	    {
	    	char ch ='#';
	      for (int i = 0; i < list.size(); i++)
		  {
			if(map.get(list.get(i)) == 1)
			{
				ch = list.get(i);
				break;
			}
		  }
	      return ch;


    }
}
// java的map没有自增功能，只能用put自增