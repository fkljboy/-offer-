import java.util.Collections;
import java.util.Map;
import java.util.HashMap;
public class Solution {
    public int FirstNotRepeatingChar(String str) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();
		//str = str.toLowerCase(); //防止出现大小写混乱
		int len = str.length();
		int count = 0;
		for(int i = 0; i < len; i++){
			if(map.containsKey(str.charAt(i))){
				count = map.get(str.charAt(i));
				map.put(str.charAt(i), ++count);
			}else{
				map.put(str.charAt(i), 1);
			}
		}
		for(int i = 0; i < len; i++){
			if(map.get(str.charAt(i)) == 1){
				return i;
			}
		}

        return -1;
    }
}
/* java 同样的方法代码量更大，原因是java不提供类似cpp中stl的map的value
自增功能，所以只能曲线救国，使用put方法对value进行自增 */