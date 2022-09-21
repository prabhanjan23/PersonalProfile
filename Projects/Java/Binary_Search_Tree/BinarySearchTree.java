/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binarysearchtree;

/**
 *
 * @author PrabhanjanPiwalatkar
 */
public class BinarySearchTree {
   
    public class Node
    {
        int data;
        Node left, right;
 
        public Node(int data)
        {
            this.data = data;
        }
    }
 
    public Node root;
 
    public BinarySearchTree()
    {
         root = null;
    }
 
    void insert(int data)  { 
        root = insert_Recursive(root, data); 
    } 
   
    Node insert_Recursive(Node root, int data) { 
        if (root == null) { 
            root = new Node(data); 
            return root; 
        } 
        if (data < root.data)     
            root.left = insert_Recursive(root.left, data); 
        else if (data > root.data)    
            root.right = insert_Recursive(root.right, data); 
        return root; 
    } 

    
 
    public static void main(String[] args) {
        BinarySearchTree T = new BinarySearchTree();
        T.insert(9);
        System.out.println(9 + " is inserted");
        T.insert(5);
        System.out.println(5 + " is inserted");
        T.insert(10);
        System.out.println(10 + " is inserted");
        T.insert(2);
        System.out.println(2 + " is inserted");
        T.insert(8);
        System.out.println(8 + " is inserted");
        T.insert(3);
        System.out.println(3 + " is inserted");
        
        
        
    }
    
}
