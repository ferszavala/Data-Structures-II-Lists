class Node:
    def __init__(self,data):
        self.data = data
        self.prev = None
        self.next = None
    def __str__(self):
        return str(self.data)

class DoublyLinkedList:
    def __init__(self):
        self.first = None
        self.last = None
    
    def push_front(self,data):
        n = Node(data)
        if self.first is None:
            self.first = n
            self.last = n
        else:
            n.next = self.first
            self.first.prev = n
            self.first = n
    
    def push_back(self,data):
        n = Node(data)
        if self.last is None:
            self.first = n
            self.last = n
        else:
            n.prev = self.last
            self.last.next = n
            self.last = n
    
    def pop_front(self):
        if self.first is None:
            print("No hay nada")
        else:
            self.first = self.first.next
            self.first.prev = None
    
    def pop_back(self):
        if self.last is None:
            print("No hay nada")
        else:
            self.last = self.last.prev
            self.last.next = None
            
    def __str__(self):
        s = "["
        aux = self.first
        while aux is not None:
            s += str(aux.data) + ", "
            aux = aux.next
        return s + "]"
    
    def print_reverse(self):
        aux=self.last
        s="["
        while aux is not None:
            s+= str(aux.data) + " , "
            aux=aux.prev
        return s+ " ]"
    
    def remove(self,data):
        aux = self.first
        while aux is not None:
            if aux.data == data:
                break
            aux = aux.next
        if aux is None: return
        
        if aux.prev is not None:
            aux.prev.next = aux.next
        if aux.next is not None:
            aux.next.prev = aux.prev
        
        if aux is self.first:
            self.first = aux.next
        if aux is self.last:
            self.last = aux.prev
            
        aux.next = None
        aux.prev = None

l = DoublyLinkedList()
l.push_front(25)
l.push_front(20)
l.push_front(10)
l.push_front(5)
print(l)
l.push_back(45)
print(l)
l.pop_back()
print(l)
l.remove(5)
print(l)
print(l.print_reverse())
print(l)