import ast

"""
# Definition for a Node.
"""
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        tree_lst = []
        if root is None:
            return str(tree_lst)
        
        tree_lst.append(root.val)

        if root.children is not None:
            children = []
            for child in root.children:
                children.append(self.serialize(child))
            
            tree_lst.append(children)

        return str(tree_lst)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        # Convert string data to list
        tree_lst = ast.literal_eval(data)
        if len(tree_lst) == 0:
            return None
        
        
        children = []
        for child in tree_lst[1:]:
            children.append(self.deserialize(child))

        root = Node(int(tree_lst[0]), children)
        return root


# Your Codec object will be instantiated and called as such:
codec = Codec()
root = Node(1, [Node(3, [Node(5, None), Node(6, None)]), Node(2, None), Node(4, None)])
print(codec.serialize(root))

print(codec.serialize(codec.deserialize(codec.serialize(root))))
