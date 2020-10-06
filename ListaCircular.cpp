#include <iostream>
using namespace std;

class CircleLinkedList
{
public:
            class Node
            {
                public:
                    int data;
                    Node* next;

                    Node(int data)
                    {
                        cout<<"  Node("<<data<<")"<<endl;
                        this->data = data;
                        this->next = nullptr;
                    }
                    ~Node()
                    {
                        cout<<"  ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n)
                    {
                        output<< "(data:"<< n.data <<" next:"<< n.next <<")";
                        return output;
                    }
            };

    CircleLinkedList::Node* head;
    CircleLinkedList(){
        head = nullptr;
        cout<<"  SinglyLinkedList()"<<endl;
    }

    ~CircleLinkedList()
    {
            cout<<"~CircularLinkedList()"<<endl;
            if(head==nullptr)
            {
                return;
            }
            CircleLinkedList::Node* aux=head->next;
            CircleLinkedList::Node* aux2=aux->next;
            while(aux!=head)
            {
                delete aux;
                aux=aux2;
                if(aux2!=head)
                {
                    aux2=aux2->next;
                }
            }
    }

    void insert_head(int data)
    {
        CircleLinkedList::Node* n = new Node(data);
        if(head==nullptr)
        {
            head = n;
            n->next = n;
            return;
        }
        else
        {
            CircleLinkedList::Node* aux = head;
            n->next = aux = head;
            while(aux->next != head)
            {
                aux = aux->next;
            }
            aux->next = head = n;;
        }
    }
    void insert_tail(int data)
    {
        CircleLinkedList::Node* n = new Node(data);
        if( head == nullptr )
        {
            head = n;
        }
        else
        {
            CircleLinkedList::Node* aux = head;
            while( aux->next != head)
            {
                aux = aux->next;
            }
            aux->next = n;
        }
        n->next = head;
    }
    void remove(int data)
    {
        if( head == nullptr )
        {
            return;
        }
        if( head->data == data)
        {
            CircleLinkedList::Node* ndelete = head;
            if(head->next == head){
                delete ndelete;
                head = nullptr;
                return;
            }else{
                CircleLinkedList::Node* aux = head;
                while(aux->next != head)
                {
                    aux = aux->next;
                }
                aux->next = head->next;
                head = aux->next;
                delete ndelete;
                return;
            }
        }
        if( head->data != data)
        {
            CircleLinkedList::Node* ndelete = head;
            CircleLinkedList::Node* aux = head;
            while(aux->next->data != data && aux->next != head)
            {
                aux = aux->next;
            }
            if(aux->next->data == data)
            {
                aux->next = aux->next->next;
                delete ndelete;
            }

            return;
        }
    }

    void print_memory(){
        cout<<"[ head:"<<head<<endl;
        if(head!=nullptr){
                CircleLinkedList::Node* aux = head;
                while(1){
                    cout<<" ("<< aux->data<<":"<<aux<<" sig:"<<aux->next<<")"<<endl;
                    aux = aux->next;
                    if(aux==head) break;

                }
        }
        cout<< "]"<<endl;
    }

    friend ostream& operator<<(ostream& output,const CircleLinkedList &l)
        {
                output<<"[";
                if(l.head != nullptr)
                {
                    CircleLinkedList::Node* aux=l.head;
                    output<<(*aux);
                    aux=aux->next;
                    while(aux!=l.head)
                    {
                        output<<(*aux);
                        aux=aux->next;
                    }
                }
                output<<"]";
                return output;
        }
};

int main(){
    CircleLinkedList lista; //creamos la lista
    lista.insert_tail(1);
    lista.insert_tail(2);
    lista.insert_tail(3);
    lista.insert_tail(4);
    cout<<"Lista: "<<lista<<endl;
    lista.print_memory();
    lista.insert_head(5);
    cout<<"Lista: "<<lista<<endl;
    lista.print_memory();
    //lista.remove(0);
    //lista.print_memory();
    /*cout<<"Lista: "<<lista<<endl;
    lista.remove(1);
    //lista.print_memory();
    cout<<"Lista: "<<lista<<endl;
    lista.remove(2);
    //lista.print_memory();
    cout<<"Lista: "<<lista<<endl;*/
    lista.remove(4);
    cout<<"Lista: "<<lista<<endl;
    lista.print_memory();
    /*lista.remove(2);
    //lista.print_memory();
    cout<<"Lista: "<<lista<<endl;*/
    /*lista.remove(5);
    //lista.print_memory();
    cout<<"Lista: "<<lista<<endl;
    lista.remove(6);
    //lista.print_memory();
    cout<<"Lista: "<<lista<<endl;*/

    /*
    Checar:
      - Destructor
      - Impresión operador <<

    */
    return 0;
}