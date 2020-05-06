import java.util.ArrayList;

public class Solution {
    public String PrintMinNumber(int [] numbers) {
  if (numbers == null || numbers.length == 0)
        return "";
    int n = numbers.length;
    String[] nums = new String[n];
    for (int i = 0; i < n; i++)
        nums[i] = numbers[i] + "";
    Arrays.sort(nums, (s1, s2) -> (s1 + s2).compareTo(s2 + s1));
    String ret = "";
    for (String str : nums)
        ret += str;
    return ret;
    }
}
/* java 的写法和cpp的区别在于，java需要先将数组转入字符串数组，但好处是
字符串的comparetoTo函数默认支持按字典序的元素排序 */