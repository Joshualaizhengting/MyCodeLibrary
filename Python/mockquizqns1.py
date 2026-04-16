class TrieNode:
    def __init__(self, char=None):
        self.char = char
        self.first_child = None
        self.next_sibling = None
        self.is_end_of_word = False

class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)  # Add to the end

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)  # Remove from the front
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
        new_node = TrieNode(char)
        new_node.next_sibling = node.first_child
        node.first_child = new_node
        return new_node

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



def count_longest_word(trie):
    #use dfs and brute force the count 

    result = []

    def dfs(node, prefix):
        if node is None:
            return
        
        if node.is_end_of_word:
            result.append(prefix)
        
        child = node.first_child
        while child:
            next = prefix + child.char
            dfs(child, next)
            child = child.next_sibling
        
    child = trie.root.first_child
    while child:
        dfs(child, child.char)
        child = child.next_sibling
    
    if result is None:
        return 0
    
    #now we have our result which will hold all the words in the trie
    #brute force to find max longest

    maxlen = len(result[0])

    for i in range(len(result)):
        if len(result[i]) > maxlen:
            maxlen = len(result[i])
    
    count = sum(1 for word in result if len(word) == maxlen)

    return count

n = int(input())
trie = Trie()

for i in range(n):
    word = input().strip()
    trie.insert(word)
print(count_longest_word(trie))