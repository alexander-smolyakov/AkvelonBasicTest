# Link on task -> https://www.codewars.com/kata/55cc33e97259667a08000044

class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def sorted_insert(head, data):
    if head is None:
        return Node(data)
    if data < head.data:
        newHead = Node(data)
        newHead.next = head
        return newHead
    currentNode = head
    while currentNode.next is not None and currentNode.next.data < data:
        currentNode = currentNode.next
    insertNode = Node(data)
    insertNode.next = currentNode.next
    currentNode.next = insertNode
    return head

#Test case from Codewars
print("should be able to handle an empty list.")
print(sorted_insert(None, 23).data == 23, "should be able to insert a node on an empty/None list.")
print(sorted_insert(None, 23).next == None, "value at index 1 should be None.")
