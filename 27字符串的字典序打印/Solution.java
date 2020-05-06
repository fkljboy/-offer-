import java.util.ArrayList;
import java.util.Arrays;
public class Solution {
    private ArrayList<String> ret = new ArrayList<>();
    public ArrayList<String> Permutation(String str) {
         if (str.length() == 0)
        return ret;
    char[] chars = str.toCharArray();
    Arrays.sort(chars);
    backtracking(chars, new boolean[chars.length], new StringBuilder());
    return ret;
}

private void backtracking(char[] chars, boolean[] hasUsed, StringBuilder s) {
    if (s.length() == chars.length) {
        ret.add(s.toString());
        return;
    }
    for (int i = 0; i < chars.length; i++) {
        if (hasUsed[i])
            continue;
        if (i != 0 && chars[i] == chars[i - 1] && !hasUsed[i - 1]) /* 保证不重复 */
            continue;
        hasUsed[i] = true;
        s.append(chars[i]);
        backtracking(chars, hasUsed, s);
        s.deleteCharAt(s.length() - 1);
        hasUsed[i] = false;
    }
}
}
/* java解法采取了完全不同的 一种思路，dfs，dfs的重点在于终止条件，避免重复
以及回溯，所以需要设置hasused变量来进行判断，以避免重复，同时遇到相等的字符
也要跳过，以避免重复，在一次的dfs结束以后要对hasused变量归零并删去最后一个
字符，以完成回溯 */