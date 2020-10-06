#include<iostream>

using namespace std;

class DoublyLinkedList
{
    public:
        class Node
        {
            public:
                int data;
                Node* prev;
                Node* next;

                Node(int data)
                {
                        cout<<"   Node("<<data<<")"<<endl;
                        this->data = data;
                        this->prev = nullptr;
                        this->next = nullptr;
                }

                ~Node() //destructor
                {
                        cout<<"  ~Node("<<data<<")"<<endl;
                }

                friend ostream& operator<<(ostream& output,const Node& n)//imprimir
                {
                        output<< "(data:"<< n.data <<" prev:"<< n.prev <<" next:"<<n.next<<")";
                        return output;
                }
       };

       //DoublyLinkedList::Node* head;

       DoublyLinkedList::Node* first;
       DoublyLinkedList::Node* last;
       DoublyLinkedList()
       {
            first = nullptr;
            cout<<" DoublyLinkedList()"<<endl;
       }

       ~DoublyLinkedList()
       {
            cout<<" ~DoublyLinkedList()"<<endl;
            if(first == nullptr)
            {
               return;
            }

            DoublyLinkedList::Node* aux = first;
            DoublyLinkedList::Node* aux2 = aux->next;
            while(aux != nullptr)
            {
                delete aux;
                aux = aux2;
                if(aux2 != nullptr)
                {
                    aux2 = aux2->next;
                }
            }
       }

       void push_front(int data) //para insertar un nodo al inicio de la lista
       {
           DoublyLinkedList::Node* n = new Node(data);
           if(first == nullptr)
           {
               first = n;
               last = n;
           }
           else
           {
               n->next = first;
               first->prev = n;
               first = n;
           }
       }

       void push_back(int data) //para insertar al último de la lista
       {
           DoublyLinkedList::Node* n = new Node(data);
           if(first == nullptr)//si el primero apunta a nulo (no hay nada)
           {
               first=n; //el primero y el ultimo son n (porque es el mismo)
               last=n;
           }
           else
           {
               last->next = n;
               n->prev = last;
               last = n;
           }
       }

       void pop_front() //borra el primero
       {
           if(first == nullptr) //si no hay nada en la lista (porque el primero apunta a nulo)
           {
               return; //no hace nada
           }
           if(first == last) //si la lista solo tiene un elemento (porque el primero y el ultimo son iguales)
           {
               delete first; //borra el primero 
               first = nullptr; //el primero y el ultimo apuntan a nulo y se queda la lista vacia
               last = nullptr;
           }
           else //si hay mas de un elemento en la lista
           {
               DoublyLinkedList::Node* aux = first;
               first->next->prev = nullptr;
               first = first->next; //hace el puente
               delete aux;
           }

       }

       void pop_back() //borra el ultimo nodo de la lista
       {
           if(first == nullptr) //si el primero apunta a nulo (la lista está vacia)
           {
               return; //no hace nada
           }
           if(first==last) //si el primero es igual al ultimo (solo hay un elemento en la lista)
           {
               delete first; //borra el primero (que seria lo mismo que borrar el ultimo porque son el mismo)
               first = nullptr;
               last = nullptr;
           }
           else
           {
               DoublyLinkedList::Node* aux = last;
               last->prev->next = nullptr;
               last = last->prev; //puente
               delete aux; //borra el nodo
           }
       }

       void print_reverse()
       {
           if(first == nullptr) //si la lista está vacía
           {
               cout<<"[]";
           } 
           DoublyLinkedList::Node* aux = last; //empieza de atrás hacia adelante
           cout<<"[";
           while(aux!=nullptr) //mientras siga habiendo elementos
           {
               cout<<aux->data<<",";
               aux = aux->prev; //avanza de "derecha a izquierda"
           }
           cout<<"]";
       }

       void remove(int data) //borrar elementos
       {
           if(first==nullptr) //si la lista está vacia
           {
               return;
           }
           if(first==last) // si la lista tiene un solo elemento
           {
               if(first->data == data) //si el dato que queremos borrar es el primero de la lista
               {
                   pop_front(); //llama al metodo de borrar el primer elemento (no hay necesidad de hacer delete directamente en este metodo)
                   return;
               }
               else
               {
                   return;
               }
           }
           if(first->data == data)//si el dato que esta en el primer elemento es el que desamos borrar (caso en el que hay mas de un elemento en la lista)
           {
               pop_front(); //llama al metodo para borrar el primer elemento
               return; 
           }
           if(last->data == data) //si el dato que deseamos borrar es el ultimo de la lista
           {
               pop_back(); //manda llamar el metodo para borrar el ultimo elemento de la lista
               return;
           }

           DoublyLinkedList::Node* aux = first;
           while(aux != nullptr) //mientras siga habiendo elementos
           {
               if(aux->data == data) //si es el dato que deseamos borrar
               {
                   break;
               }
               aux = aux->next; 
           }
           if(aux == nullptr)
           {
               return;
           }
           aux->prev->next = aux->next; //puentes
           aux->next->prev = aux->prev;
           delete aux; //Hacemos delete directo porque no es ni el primero ni el ultimo de la lista
       }

    friend ostream& operator<<(ostream& output,const DoublyLinkedList& l)
    {
        output<< "[";
        if(l.first != nullptr)
        {
            DoublyLinkedList::Node* aux = l.first;
            while( aux != NULL)
            {
                output<<(*aux);
                aux = aux->next;
            }
        }
        output<< "]";
        return output;
    }

    void print_memory() //metodo recomendado para comprobar
    {
        cout<<"[ first:"<<first<<" last:"<<last<<endl;
        if( first != nullptr)
        {
            DoublyLinkedList::Node* aux = first;
            while(aux != NULL)
            {
                cout<<" ("<< aux->data<<":"<<aux<<" prev:"<<aux->prev<<" sig:"<<aux->next<<")";
                aux = aux->next;
            }
        }
        cout<< "]"<<endl;
    }
};

int main()
{
    DoublyLinkedList lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_back(4);
    lista.push_back(5);
    cout<<"Lista: "<<lista<<endl;
    lista.print_reverse();
    //doubly.print_memory();
    /*lista.pop_front();
    cout<<"Lista: "<<lista<<endl;
    //doubly.print_memory();
    lista.pop_front();
    cout<<"Lista: "<<lista<<endl;
    //doubly.print_memory();
    lista.pop_front();
    cout<<"Lista: "<<lista<<endl;
    //doubly.print_memory();
    lista.pop_front();
    cout<<"Lista: "<<lista<<endl;
    //doubly.print_memory();
    lista.pop_front();
    cout<<"Lista: "<<lista<<endl;
    //doubly.print_memory();
    lista.pop_front();
    cout<<"Lista: "<<lista<<endl;
    //doubly.print_memory();
    lista.pop_front();
    cout<<"Lista: "<<lista<<endl;
    //doubly.print_memory();*/
    return 0;
}