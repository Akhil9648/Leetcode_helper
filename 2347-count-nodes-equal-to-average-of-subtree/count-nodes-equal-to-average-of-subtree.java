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
class Solution {
    HashMap<TreeNode,Integer> map=new HashMap<>();
    int cnt=0;
    public int solve(TreeNode root){
        if(root==null) return 0;
        int l=solve(root.left);
        int r=solve(root.right);
        if(root.left==null && root.right==null) map.put(root,1);
        else if(root.left!=null && root.right==null){
            int lft=map.get(root.left);
            map.put(root,lft+1);
        }
        else if(root.left==null && root.right!=null){
            int rht=map.get(root.right);
            map.put(root,rht+1);
        }
        else{
            int lft=map.get(root.left);
            int rht=map.get(root.right);
            map.put(root,lft+rht+1);
        }
        int a=l+r+root.val;
        int num=map.get(root);
        if(a/num==root.val) cnt++;
        return a;
    }
    public int averageOfSubtree(TreeNode root) {
        solve(root);
        return cnt;
    }
}