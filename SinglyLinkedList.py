class Node:
    def __init__(self,data=0):
        self.next = None
        self.data = data
    def __str__(self):
        return str(self.data)
    
class SinglyLinkedList:
    def __init__(self):
        self.head = None
        
    def __str__(self):
        if self.head is None:
            return "[]"
        else:
            s = "["
            aux = self.head
            while aux is not None:
                s+= aux.__str__() + ","
                aux = aux.next
            s+="]"
            return s
    
    def insert_head(self,data):
        n = Node(data)
        if self.head is None:
            self.head = n
        else:
            # Opción 1
            aux = self.head
            self.head = n
            self.head.next = aux
            ### Opción 2
            ## n.next = self.head
            ## self.head = n
            
    
    def insert_tail(self,data):
        n = Node(data)
        if self.head is None:
            self.head = n
        else:
            aux = self.head
            while aux.next is not None:
                aux = aux.next
            aux.next = n
    
    def remove(self,data):
        if data is not self.head.data:
            aux = self.head
            while(aux.next.data is not data):
                aux=aux.next
            aux.next = aux.next.next
        if data is self.head.data:
            self.head=self.head.next
    
    def reverse(self):
        pass

l = SinglyLinkedList()
l.insert_head(6)
print(l)
l.insert_tail(80)
print(l)
l.remove(80)
print(l)

