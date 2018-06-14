class Node():
    def __init__(self, data):
        # string
        self.data = data
        self.children = dict()
        
class Tries():
    def __init__(self):
        self.head = Node("*")

    def add(self, string):
        nodelist = [Node(char) for char in string]
        cur_node = self.head
        for node in nodelist:
            char = node.data
            if char not in cur_node.children:
                cur_node.children[char] = node
                cur_node = cur_node.children[char]
            else:
                cur_node = cur_node.children[char]
        cur_node.children["*"] = 0

    def _add(self, string):
        '''
        deprecated
        '''
        
        nodelist = [Node(char) for char in string]
        cur_node = self.head
        i = 0
        
        while(i < len(nodelist)):
            node = nodelist[i]
            char = node.data
            
            if char not in cur_node.children:
                cur_node.children[char] = nodelist[i]
                cur_node = cur_node.children[char]

            else:
                # cur_node.children[char]
                cur_node = cur_node.children[char]

            i += 1
            
    def find(self, string):
        i = 0
        cur_node = self.head
        while(i <= len(string)-1):
            
            char = string[i]
            if char in cur_node.children:
                cur_node = cur_node.children[char]
                i += 1
            else:
                return False
        if cur_node.children.get("*") == None:
            return False
        return True
                
if __name__ == "__main__":
    
    n = int(input())
    ops = []
    words = []
    for _ in range(n):
        op, word = input().split()
        ops.append(op)
        words.append(word)
    
    tries = Tries()
    for op, word in zip(ops, words):
        if op=='insert':
            tries.add(word)
        else:
            if tries.find(word)==True:
                print("yes")
            else:
                print("no")
