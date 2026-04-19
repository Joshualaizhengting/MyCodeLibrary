class HashTableNode:
    def __init__(self, key=None):
        self.key = key
        self.deleted = False


class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def _hash(self, key, i):
        return (key + i) % self.size

    def hash_delete(self, key):
        i = 0
        index = self._hash(key, i)

        while self.table[index] is not None:
            if self.table[index].key == key and not self.table[index].deleted:
                self.table[index].deleted = True
                return True
            i += 1
            if i >= self.size:
                return False
            index = self._hash(key, i)

        return False

    def hash_search(self, key):
        i = 0
        index = self._hash(key, i)

        while self.table[index] is not None:
            if self.table[index].key == key and not self.table[index].deleted:
                return True
            i += 1
            if i >= self.size:
                return False
            index = self._hash(key, i)

        return False
        
        
    def hash_insert(self, key):
        #add your codes
        for i in range(self.size):
            index = self._hash(key, i)

            if self.table[index] is None:
                self.table[index] = HashTableNode(key)
                return True
            
            if self.table[index].key == key:
                return False
        return False




def count_unique(nums):
    ht = HashTable(max(2 * len(nums), 1))
    #add your codes
    count = 0

    for num in nums:
        if not ht.hash_search(num):
            count += 1
            ht.hash_insert(num)
    
    return count
    
    

    


nums = list(map(int, input().split()))
result = count_unique(nums)
print(result)