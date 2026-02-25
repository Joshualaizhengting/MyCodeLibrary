class BTNode:
    def __init__(self, item, left=None, right=None):
        self.item = item  # Store the item (integer)
        self.left = left  # Reference to the left child node
        self.right = right  # Reference to the right child node

def insertBSTNode(root, value):
    """ Recursive approach to insert a node into a BST. """
    if root is None:
        return BTNode(value)
    
    if value < root.item:
        root.left = insertBSTNode(root.left, value)
    elif value > root.item:
        root.right = insertBSTNode(root.right, value)
    return root  # Ensure the modified node is returned

def findMin(node):
    """ Find the node with the smallest value in a subtree. """
    while node.left is not None:
        node = node.left
    return node

def removeBSTNode(node, value):
 # Write your code here #
    if node is None:
        return node
    
    if node.item > value:
        #if root is larger recurse left because value is smaller than root 
        node.left = removeBSTNode(node.left, value)

    elif node.item < value:
        #if root is smaller recurse right because value is larger
        node.right = removeBSTNode(node.right, value)


        #found the node now we handle deletion based on chidlren count
    else:

        #case 1: node has no left child (0/1 on right)
        if node.left is None:
            return node.right   #replace with right node
        
        #case 2: node has no right child(1 on left)
        if node.right is None:
            return node.left    #replace with left node
        
        #for nodes with 2 children

        #get successor node
        succ = getsuccessor(node)
        
        #copy successor val into current node
        node.item = succ.item

        #remove the successor from the tree
        node.right = removeBSTNode(node.right, succ.item)

        #much easier as it now changes the 2 children problem to only 1 children or no children => 
        #copy the succssor value into the node to be removed and then remove the successor

    return node
    
def getsuccessor(curr):
    """get inorder successor => the node that is slightly greater than the target node to remove 
        when we delete a node with 2 children we must have another node replace it so that 2 children isnt removed =>
        look for the next slightly greater node so that bst remains intact """
    
    curr = curr.right
    while curr is not None and curr.left is not None:
        curr = curr.left
    return curr
    #at this point curr is at the node that is slightly larger than the target node


def printBSTInOrder(node):
    """ Print BST items in sorted order using in-order traversal. """
    if node:
        printBSTInOrder(node.left)
        print(node.item, end=" ")
        printBSTInOrder(node.right)

def printTree(node, level=0, prefix="Root: "):
    """ Pretty prints the tree structure for better visualization """
    if node is not None:
        print(" " * level + prefix + str(node.item))
        if node.left or node.right:
            if node.left:
                printTree(node.left, level + 4, "L--- ")
            if node.right:
                printTree(node.right, level + 4, "R--- ")

if __name__ == "__main__":
    root = None
    print("Binary Search Tree Node Removal Program")
    print("=====================================")
    
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
            print("\nCurrent BST structure:")
            printTree(root)
            print("\nIn-order traversal: ", end="")
            printBSTInOrder(root)
            print()
            
        except ValueError:
            print("Invalid input! Please enter an integer.")

    print("\nNow let's remove nodes:")
    while True:
        try:
            value = input("\nEnter a value to remove (-1 to quit): ")
            if not value:
                continue  # Ignore empty inputs
                
            i = int(value)
            if i == -1:
                break
                
            result = removeBSTNode(root, i)
            if result == 0:
                print("\nBST structure after removal:")
                printTree(root)
                print("\nIn-order traversal: ", end="")
                printBSTInOrder(root)
                print()
            else:  # result == -1
                print("Value not found in the tree!")
            
        except ValueError:
            print("Invalid input! Please enter an integer.")