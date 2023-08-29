// Left View of Binary Tree - Easy :o - Java 1.8
/*Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:
Input:
     10
    /  \
  20    30
  / \
40  60
Output: 10 20 40

Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Note:
Input format:
4 5 2 N N 3 1 6 7
means
        4
      /   \
    5      2
  /  \    /  \
N    N   3   1
        / \  
        6 7
*/

//{ Driver Code Starts
import java.util.LinkedList; 
import java.util.Queue; 
import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

class GfG {  
    static Node buildTree(String str){
        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }
        
        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue
        
        Queue<Node> queue = new LinkedList<>(); 
        
        queue.add(root);
        // Starting from the second element
        
        int i = 1;
        while(queue.size()>0 && i < ip.length) {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N")) {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N")) {
                    
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                    
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        
        return root;
    }
    static void printInorder(Node root)
    {
        if(root == null)
            return;
            
        printInorder(root.left);
        System.out.print(root.data+" ");
        
        printInorder(root.right);
    }
    
	public static void main (String[] args) throws IOException{
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	        int t=Integer.parseInt(br.readLine());
    
	        while(t > 0){
	            String s = br.readLine();
    	    	Node root = buildTree(s);
        	    Tree g = new Tree();
    			ArrayList<Integer> result = g.leftView(root);
    			for(int value : result){
    			    System.out.print(value + " ");
    			}
    			System.out.println();
                t--;
        }
    }
}

// } Driver Code Ends


//User function Template for Java

/* A Binary Tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}*/
class Tree
{
    //Function to return list containing elements of left view of binary tree.
    ArrayList<Integer> leftView(Node root)
    {
      // Your code here
        // Try 1: 600/603 cases passed. Issue when NULL left and NULL right comes together for same node. e.g. 4 5 2 N N 3 1 6 7 
        //   ArrayList<Integer> a = new ArrayList<Integer>();
        //   Node ptr=root;
        //   while (ptr!=null)
        //   {
        //       a.add(ptr.data);
        //       if (ptr.left!=null)
        //         ptr=ptr.left;
        //         else if (ptr.right!=null) 
        //             ptr=ptr.right;
        //             else ptr=null;
        //   }
        //   return a;
        
        // Try 2:   602/603 cases passed. 
        //          Error with e.g. 1 2 3 4 5 6 7 N N N N 8 N N N
        //          Expected Output: 1 2 4 8. My output: 1 2 4.
        // ArrayList<Integer> a = new ArrayList<Integer>();
        // Node ptr=root,parent=null;
        // while (ptr!=null)
        // {   a.add(ptr.data);
        //     // System.out.print("ptr = "+ptr.data+" parent = ");
        //     // if (parent!=null)System.out.println(parent.data);
        //     // else System.out.println("null");
        //     if (ptr.left!=null)         {parent = ptr;ptr=ptr.left;}
        //     else if (ptr.right!=null)   {parent = ptr;ptr=ptr.right;}
        //     else
        //     {   if (parent!=null)
        //         {   if (parent.right!=null)
        //             {   if (parent.right.left!=null)            {ptr=parent.right.left;parent=parent.right;}
        //                 else if (parent.right.right!=null)      {ptr=parent.right.right;parent=parent.right;}
        //                 else ptr=null;
        //             }
        //             else ptr=null;
        //         }
        //         else ptr=null;
        //     }
        // }
        // return a;
    
        // Try 3:   Idea: Use queue to traverse levelwise nodes. Left most is added to arraylist to be printed
        //          603/603 testcases passed
        ArrayList <Integer> a = new ArrayList<Integer>();
        Queue<Node> q = new LinkedList<Node>();
        if (root!=null)
        {   q.add(root); q.add(null); //Add delimiter after first level
            while(q.size()>0)
            {   Node temp=q.peek();
                if (temp!=null)
                {   a.add(temp.data); // Only left most item in each level is Printed
                    while(temp!=null) // Add the rest of the elements in same level into queue
                    {   if(temp.left!=null)     q.add(temp.left);
                        if(temp.right!=null)    q.add(temp.right);
                        q.remove();   // Remove item from previous level
                        temp=q.peek(); 
                    }
                    q.add(null);// set delimiter since all elements in current level is traversed
                }
                q.remove(); // Remove the delimiter for the finished level
            }
        }
        return a;
        
    }
}
