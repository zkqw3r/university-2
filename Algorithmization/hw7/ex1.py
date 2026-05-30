class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


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
    node_1 = Node(1, 
                Node(2, Node(4), Node(3)),
                Node(2, Node(3), Node(4)))
    node_2 = Node(1, 
                Node(2, Node(3), Node(4)),
                Node(2, Node(3), Node(4)))

    print("Test 1 (True):", isAnagram(node_1))
    print("Test 2 (False):", isAnagram(node_2))


if __name__ == "__main__":
    main()