class TrieNode:
    def __init__(self, char=None):
        self.char = char
        self.first_child = None
        self.next_sibling = None
        self.is_end_of_word = False

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

class Solution:
    def find_concatenated_words(self, dictionary):
        # -------- DO NOT MODIFY ANYTHING ABOVE THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
        trie = Trie()
        for word in dictionary:
            trie.insert(word)
        
        
        
        def can_form(word, index, count, trie):
            if index == len(word):
                return count >= 2
            
            node = trie.root

            for i in range(index, len(word)):
                node = trie._find_child(node, word[i])
            
                if not node:
                    break
                if node.is_end_of_word:
                    if can_form(word, i+1, count + 1, trie):
                        return True
            return False
        
        result = []
        for word in dictionary:
            if can_form(word, 0, 0, trie):
                result.append(word)
        
        return result


        # -------- DO NOT MODIFY ANYTHING BELOW THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
