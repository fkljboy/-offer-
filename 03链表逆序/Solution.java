import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> res =new ArrayList<>();
        if (listNode!=null){
            res.addAll(printListFromTailToHead(listNode.next));
            res.add(listNode.next);
        }
        return res;
    }
}
/* 方法二，使用递归，一直走到链表的最后一个值，然后逐级返回，一边
返回一边将当前链表值存入arraylist */