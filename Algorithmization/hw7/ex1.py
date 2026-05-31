class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def buildTree(values):
    if not values or values[0] == '0':
        return None
        
    root = Node(int(values[0]))
    queue = [root]
    i = 1
    
    while i < len(values):
        current = queue.pop(0)
        
        if i < len(values):
            val = values[i]
            if val != '0':
                current.left = Node(int(val))
                queue.append(current.left)
            i += 1
            
        if i < len(values):
            val = values[i]
            if val != '0':
                current.right = Node(int(val))
                queue.append(current.right)
            i += 1
            
    return root


def isAnagram(root):
    if root == None:
        return True
    return isMirror(root.left, root.right)


def isMirror(left, right):
    if left == right == None:
        return True
    if (left == None) or (right == None):
        return False
    if left.value != right.value:
        return False
    return isMirror(left.left, right.right) and isMirror(left.right, right.left)


def main():
    print("Введите элементы дерева через пробел (если элемента нет - 0):")
    user_input = input().split()
    
    root = buildTree(user_input)
    
    result = isAnagram(root)
    print("Результат проверки:", result)

if __name__ == "__main__":
    main()