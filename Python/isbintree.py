class BTNode:
    def __init__(self, data, left=None, right=None):
        self.data = data  # Store the data (integer)
        self.left = left  # Reference to the left child node
        self.right = right  # Reference to the right child node

def insertBSTNode(root, value):
    """ Iterative approach to insert a node into a BST. """
    if root is None:
        return BTNode(value)  # If tree is empty, create root
    parent = None
    current = root
    while current:
        parent = current
        if value < current.data:
            current = current.left
        elif value > current.data:
            current = current.right
        else:
            return root  # Value already exists, return root unchanged
    if value < parent.data:
        parent.left = BTNode(value)
    else:
        parent.right = BTNode(value)
    return root

def printBSTInOrder(node):
    """ Print BST items in sorted order using in-order traversal. """
    if node:
        printBSTInOrder(node.left)
        print(node.data, end=" ")
        printBSTInOrder(node.right)

def printTree(node, level=0, prefix="Root: "):
    """ Pretty prints the tree structure for better visualization """
    if node is not None:
        print(" " * level + prefix + str(node.data))
        if node.left or node.right:
            if node.left:
                printTree(node.left, level + 4, "L--- ")
            if node.right:
                printTree(node.right, level + 4, "R--- ")

def createBST(values):
    """ Creates a binary tree from a list using level-order placement. 
        This can create both valid and invalid BSTs.
    """
    if not values or values[0] is None:
        return None
    root = BTNode(values[0])
    queue = [root]
    i = 1
    while i < len(values) and queue:
        node = queue.pop(0)
        if i < len(values) and values[i] is not None:
            node.left = BTNode(values[i])
            queue.append(node.left)
        i += 1
        if i < len(values) and values[i] is not None:
            node.right = BTNode(values[i])
            queue.append(node.right)
        i += 1
    return root

class Solution:
    def isBST(self, root):
        root = createBST(root)
        # -------- DO NOT MODIFY ANYTHING ABOVE THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
        #abuse the fact that it is a bst -> use inorder traversal to append all the values
        #to a list then slowly go thru and compare the values one by one
        #if it is a binary search tree all will be in ascending order but if it is not then 
        #return false

        result = []
        def inorder(root):
            if root is None:
                return result
            
            #traverse left
            inorder(root.left)

            #append the val
            result.append(root.data)

            #traverse right
            inorder(root.right)
        
        inorder(root)

        for i in range(len(result)-1):
            if result[i]>result[i+1]:
                return False
        return True
    
        #Return true if it is a valid BST, false otherwise
        # -------- DO NOT MODIFY ANYTHING BELOW THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------

if __name__ == "__main__":
    root = None
    print("Binary Search Tree In-Order Traversal & Validation Program")
    print("===========================================================")
    print("\nFirst, let's build the BST:")
    while True:
        try:
            value = input("\nEnter a value to insert (-1 to quit): ")
            if not value:
                continue  # Ignore empty inputs
            i = int(value)
            if i == -1:
                break
            root = insertBSTNode(root, i)
            # Print both in-order traversal and tree structure after each insertion
            print("\nCurrent in-order traversal:", end=" ")
            printBSTInOrder(root)
            print("\n\nCurrent BST structure:")
            printTree(root)
            print()  # New line for better readability
        except ValueError:
            print("Invalid input! Please enter an integer.")

    print("\nFinal in-order traversal (sorted order):", end=" ")
    printBSTInOrder(root)
    print("\n\nFinal BST structure:")
    printTree(root)
    print()

    # Validate if the final tree is a BST
    print("\nChecking if the tree is a valid BST...")
    if Solution().isBST(root):
        print("The tree is a valid BST!")
    else:
        print("The tree is NOT a valid BST!")

    # Test with an invalid BST
    print("\nTesting with an invalid binary tree...")
    invalid_root = createBST([5, 3, 7, None, 6, None, None])
    print("\nInvalid BST structure:")
    printTree(invalid_root)
    print("\nChecking if the invalid tree is a BST...")
    if Solution().isBST(invalid_root):
        print("The tree is a valid BST!")
    else:
        print("The tree is NOT a valid BST!")