import java.util.*;
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
  
    private int maxpath(TreeNode node, int[] sum) {
        if (node == null) return 0;

       
        int leftMax = Math.max(0, maxpath(node.left, sum));
        int rightMax = Math.max(0, maxpath(node.right, sum));

        sum[0] = Math.max(sum[0], leftMax + rightMax + node.val);

      
        return node.val + Math.max(leftMax, rightMax);
    }

   
    public int maxPathSum(TreeNode root) {
        int[] sum = new int[1];
        sum[0] = Integer.MIN_VALUE; 
        maxpath(root, sum);
        return sum[0];
    }
}


public class BinaryTreeMaxPathSum {
    public static void main(String[] args) {
     
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        
       
        Solution solution = new Solution();
        int maxSum = solution.maxPathSum(root);
        
        System.out.println("Maximum Path Sum: " + maxSum);
    }
}
