class Node:
    def __init__(self, name = ""):
        self.name = name
        self.next = None

class LinkedList:
    def __init__(self, name_nodes = None):
        self.head = None
        if name_nodes is not None:
            # Put names in alphabetical order
            name_nodes = sorted(name_nodes)
            name_dict = {}
            # The first name in the list is the Head
            new_node = Node(name=name_nodes[0])
            self.head = new_node

            # Add all names to the linked list
            for name in name_nodes:
                # Keep count of how many times a name has appeared in dictionary
                name_dict[name] = name_dict.get(name, 0) + 1
                if name != new_node.name:
                    new_node.next = Node(name=name)
                    new_node = new_node.next
            
            # Remove duplicate names
            # Names with a Value greater than 2 in the dictionary are removed
            for node in self:
                if name_dict[node.name] > 1:
                    self.removeNode(node.name)

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next

    # Function to remove a node from the Linked List
    def removeNode(self, remove_target):
        if self.head is None:
            raise Exception("List is empty")
        
        # Name to remove is at the head
        if self.head.name == remove_target:
            self.head = self.head.next
            return
        
        # Name to remove is elsewhere
        previous_node = self.head
        for node in self:
            if node.name == remove_target:
                previous_node.next = node.next
                return
            previous_node = node
