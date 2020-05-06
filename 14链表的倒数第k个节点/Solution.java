
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        if (head==null) return null;
      ListNode p1=head;
      while(p1!=null&&k-- >0){
          p1=p1.next;
      }
      if (k>0){
          return null;
      }
      ListNode p2=head;
      while(p1!=null){
          p1=p1.next;
          p2=p2.next;
      }
      return p2;
  }
}
// 思路和cpp解法一致