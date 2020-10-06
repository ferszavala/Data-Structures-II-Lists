#include <iostream>
using namespace std;

class SinglyLinkedList{ //creamos la clase lista
public: 
            class Node{ //clase interna (clase dentro de otra clase)
                  public:
                    int data; //declaramos la variable que contiene la info del nodo
                    Node* next; //declaramos un apuntador

                    Node(int data){ //creamos el nodo (constructor)
                        cout<<"  Node("<<data<<")"<<endl;
                        this->data = data; //el this se usa para espacios de memoria en vez del . en variables normales,estamos reservando memoria
                        this->next = nullptr;//apunta a nulo
                    }
                    ~Node(){ //destructor
                        cout<<"  ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){ //esto siempre va (formulita)
                        output<< "(data:"<< n.data <<" next:"<< n.next <<")";
                        return output;
                    }
            };

    SinglyLinkedList::Node* head; //El nodo va a estar aapuntando a la cabeza
    SinglyLinkedList(){
        head = nullptr;//la cabeza apunta a nulo
        cout<<"  SinglyLinkedList()"<<endl;//No imprime nada, solo el nombre de la lista
    }
    ~SinglyLinkedList(){//destructor
        cout<<"  ~SinglyLinkedList()"<<endl;//imprime el nombre de la lista con el destructor cuando lo mandamos llamar
        if( head == nullptr ) //si la cabeza de la lista apunta a nulo (no tiene más elementos) se termina
            return;
        SinglyLinkedList::Node* aux = head; //Si si hay elementos a la cabeza, ahora apunta a next lo que estaba en head
        SinglyLinkedList::Node* aux2 = aux->next; //Creamos un nuevo auxiliar que apunta a aux2 lo que estaba en aux->next
        while( aux != nullptr){//mientras despues de aux siga haciendo elementos  (no apunte a nulo)
            delete aux; //liberamos la memoria de aux
            aux = aux2; //le damos el valor de aux2 a aux
            if( aux2 != nullptr ) aux2 = aux2->next; //si aux2 no es nulo entonces aux2 se queda con lo que tenia aux2->next
        }
    }
    void insert_head(int data){//método para insertar a la cabeza
        SinglyLinkedList::Node* n = new Node(data); //creamos el nodo con la info
        if(head==nullptr){ //si la cabeza es nula
            head = n; //head se queda con el dato que queremos ingresar (la lista solo tendrá un elemento, y será la cabeza)
        }else{ //si ya hay dato en la cabeza (hay 1 o mas datos en la lista antes de agregar)
            n->next = head; //head se queda con el espacio de n->next
            head = n; //n se vuelve la nueva cabeza
        }
    }
    void insert_tail(int data){//metodo para insertar a la cola
        SinglyLinkedList::Node* n = new Node(data); //creamos el nodo con la info necesaria

        if( head == nullptr ){ //si la cabeza apunta a nulo (la lista esta vacia antes de agregar)
            head = n;//n se vuelve la cabeza
        }else{//si ya hay uno o mas elementos en la lista entes de agregar
            SinglyLinkedList::Node* aux = head;//guardamos head en aux
            while( aux->next != NULL){//mientras siga habiendo más elementos
                aux = aux->next;//seguimos avanzando aux=aux->next
            }
            aux->next = n; //una vez que termina el while y verifica que ya no hay mas datos despues de next determina que n es el ultimo elemento de la lisa (tail) con aux->next
        }
    }
    void remove(int data){//metodo para borrar un nodo
        if( head == nullptr ) return; //si la cabeza apunta a nulo (la lista esta vacia) entonces se sale
        if( head->data == data){ //si el dato que esta a la cabeza es el que queremos borrar
            SinglyLinkedList::Node* ndelete = head; //creamos un apuntador que apunta hacia head
            head = head->next; //head.next se queda con head
            delete ndelete; //borramos la memoria que habiamos reservado para head y que despues apuntamos con ndelete
            return;
        }else{//si el nodo que deseamos borrar no es el que está en la cabeza
            SinglyLinkedList::Node* aux = head; //head lo guardamos en un auxiliar
            while( aux!=nullptr && aux->next!=nullptr && aux->next->data != data )//mientras aux no sea nulo, lo que sigue de next no sea nulo y lo qu sigue de aux no sea el dato que estamos buscando
                aux = aux->next; //seguimos avanzando

            if( aux->next!=nullptr && aux->next->data == data  ){//si lo que sigue de aux no apunta a nulo, y el dato que sigue de next ES el que queremos eliminar
                SinglyLinkedList::Node* ndelete = aux->next; //creamos un apuntador que se dirija a lo que sigue de next
                aux->next = aux->next->next; //se crea el puente
                delete ndelete; //eliminamos el nodo, basandonos en el apuntador que dirigimos hacia lo que queriamos eliminar
            }
        }
    }
    friend ostream& operator<<(ostream& output,const SinglyLinkedList& l){ //se manda a llamar para imprimir, siempre se pone, lo vamos a usar para comprobar que todo esté funcionando correctamente con dato y dirección de memoria
        output<< "[";
        if( l.head != nullptr){ //si la lista no está vacía (sabemos que está vacía porque forzosamente tiene que haber algo en la cabeza si tiene uno o más datos)
            SinglyLinkedList::Node* aux = l.head; //ponemos head en aux
            while( aux != NULL){ //mientras aux no sea nulo (de ley entre mínimo una vez)
                output<< (*aux); //imprimimos el valor en memoria de aux
                aux = aux->next; //avanzamos
            }
        }
        output<< "]";
        return output;
    }
};

int main(){
    SinglyLinkedList lista; //creamos la lista
    lista.insert_head(1); //insertamos valores a la cabeza
    lista.insert_head(2);
    lista.insert_head(3);
    lista.insert_head(4);
    cout<<"Lista:"<<lista<<endl; //imprimimos la lista
    lista.remove(4); //eliminamos un nodo de la lista
    cout<<"Lista:"<<lista<<endl; //volvemos a imprimir
    return 0;
}

