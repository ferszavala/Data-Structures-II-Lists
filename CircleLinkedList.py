class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
    def __str__(self):
        return str(self.data)

class CircularLinkedList:
    def __init__(self):
        self.head = None
    
    def insert_head(self, data):
        n = Node(data)
        if self.head is None:
            self.head = n
            n.next = n
            return
        n.next = aux = self.head
        while aux.next is not self.head:
            aux = aux.next
        aux.next = self.head = n
    
    def insert_tail(self,data):
        n = Node(data)
        if self.head is None:
            self.head = n
        else:
            aux = self.head
            while aux.next is not self.head:
                aux = aux.next
            aux.next = n
        n.next = self.head
    
    def remove(self,data):
        if data is not self.head.data:
            aux=self.head
            while (aux.next.data != data and aux.next != self.head):
                aux=aux.next
            if aux.next.data == data:

                aux.next=aux.next.next

        if self.head.data == data:
            aux = self.head
            while aux.next is not self.head:
                aux=aux.next
            
            aux.next=self.head.next
            self.head= aux.next
    
    def __str__(self):
        if self.head is None:
            return "[]"
        s = "["
        aux = self.head
        while True:
            s+= str(aux.data)+", "
            if aux.next is self.head:
                break
            else:
                aux = aux.next
        return s + "]"
    
l = CircularLinkedList()
l.insert_head(1)
l.insert_head(2)
l.insert_head(3)
l.insert_head(4)
print(l)
