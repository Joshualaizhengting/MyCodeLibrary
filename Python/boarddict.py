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
    def board_dictionary(self, board, dictionary):
        # -------- DO NOT MODIFY ANYTHING ABOVE THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
        #build a trie using the letters in the board

        trie = Trie()
        for word in dictionary:
            trie.insert(word)
        
        result = set()

        #now traverse the board and match 

        def dfs_onboard(row, col, node, path):
            char = board[row][col]
            child = trie._find_child(node, char)
            if child is None:
                return
            path += char
            
            if child.is_end_of_word:
                result.add(path)
                child.is_end_of_word = False
            
            board[row][col] = "#" 
            for dr, dc in [(0,1), (0,-1),(1,0),(-1,0)]:     #this marks all possible paths that cna be taken for next char
                nr, nc = dr + row, dc + col
                if 0<= nr < len(board) and 0<= nc < len(board[0]):
                    dfs_onboard(nr, nc, node, path)
            board[row][col] = char
        
        for r in range(len(board)):
            for c in range(len(board[0])):
                dfs_onboard(r, c, trie.root, "")
        return result





        # -------- DO NOT MODIFY ANYTHING BELOW THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
