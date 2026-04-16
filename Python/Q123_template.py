class TrieNode:
    def __init__(self, char=None):
        self.char = char
        self.first_child = None
        self.next_sibling = None
        self.is_end_of_word = False

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

    def is_empty(self):
        return len(self.items) == 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def _find_child(self, node, char):
        current = node.first_child
        while current:
            if current.char == char:
                return current
            current = current.next_sibling
        return None

    def _add_child(self, node, char):
        #add your implementations to insert a child following the alphabetical order
    
        if node is None:
            return

        prev = None
        curr = node.first_child

        if curr and curr.char == char:
            return curr

        while curr and curr.char < char:
            prev = curr
            curr = curr.next_sibling

        newnode = TrieNode(char)

        newnode.next_sibling = curr
        if prev is None:
            node.first_child = newnode
        else:
            prev.next_sibling = newnode
        
        return newnode
    
    """
        new_node = TrieNode(char)
        if node.first_child is None or char < node.first_child.char:
            new_node.next_sibling = node.first_child
            node.first_child = new_node
            return new_node
        
        prev = node.first_child
        curr = prev.next_sibling
        while curr and curr.char < char:
            prev = curr
            curr = curr.next_sibling
        
        new_node.next_sibling = curr
        prev.next_sibling = new_node
        return new_node
"""

    def insert(self, word):
        node = self.root
        for char in word:
            child = self._find_child(node, char)
            if not child:
                child = self._add_child(node, char)
            node = child
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            node = self._find_child(node, char)
            if not node:
                return False
        return node.is_end_of_word

    def print_words_alphabetically(self):
        #add you implementations

        def dfs(node, curr):
            if node is None:
                return 
            if node.is_end_of_word:
                print(f"{curr}")
            
            child = node.first_child
            while child:
                next = curr + child.char
                dfs(child, next)
                child = child.next_sibling
            
        child = self.root.first_child
        while child:
            dfs(child, child.char)
            child = child.next_sibling
        


    def print_words_reverse_alphabetically(self):
        #add your implementations

        children = []
        def dfs(node, curr):
            if node is None:
                return
            if node.is_end_of_word:
                children.append(curr)
            
            child = node.first_child
            while child:
                next = curr + child.char
                dfs(child, next)
                child = child.next_sibling
        
        child = self.root.first_child
        while child:
            dfs(child, child.char)
            child = child.next_sibling
        
        for char in reversed(children):
            print(f"{char}")
        


# Assume Trie, TrieNode, and Queue classes have already been defined.
# Create a new Trie instance
trie = Trie()
trie.insert("banana")
trie.insert("apple")
trie.insert("bat")
trie.insert("ball")
trie.insert("band")
trie.insert("cat")

trie.print_words_reverse_alphabetically()

print("\n")

trie.print_words_alphabetically()
