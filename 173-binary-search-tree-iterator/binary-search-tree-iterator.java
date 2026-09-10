/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    ArrayList<Integer> arr=new ArrayList<>();
    int n,i=0;
    public void solve(TreeNode root){
        if(root==null){
            return;
        }
        solve(root.left);
        arr.add(root.val);
        solve(root.right);
    }
    public BSTIterator(TreeNode root) {
        solve(root);
        n=arr.size();
    }
    public int next() {
        int a=-1;
        if(i<n) a=arr.get(i);
        i++;
        return a;
    }
    
    public boolean hasNext() {
        return i<n;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */