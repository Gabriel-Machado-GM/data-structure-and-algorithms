#ifndef DUAL_LIST_H_
#define DUAL_LIST_H_

// Copyright (c) 2022

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.

#include <vector>
#include <string>

using std::string;
using std::vector;

template<class T1, class T2>
class DualList 
{ typedef struct Node{ 
  T1 x_1; 
  T2 x_2;
  struct Node* next;
  struct Node* prev;
};
 public:
  DualList()
  { struct Node* head = NULL;
    return;
  }
  // Função que irá inserir o novo par (x1, x2) na lista de duplas. Como não
  // existe uma ordem obrigatória, uma opção é inserir no final da lista.
  // Começo pelo nó raíz, vá iterando até encontrar o nó que é nulo.
  // Crie um novo nó.
  // Ligue o último nó com o novo nó.
  void Insert(T1 x1, T2 x2)
  {  //alocando memória para o nó
     struct Node* newNode = new Node;
     //declarando last como valor do topo da lista
     struct Node* last = *head;
     //declarando data para o novo nó
     newNode->x_1 = x1;
     newNode->x_2 = x2;
     //como o newNode vai ser colocado por último na lista, é necessário que
     //o proóximo Nó do newNode seja null
     newNode->next = NULL;
     //caso a lista esteja vazia, é necessário criar um novo topo
     if (*head == NULL) {
     newNode->prev = NULL;
     *head = newNode;
      return;
  }
  //atravessando a lista e indo até o último nó
  while (last->next != NULL)
  last = last->next;
  //o próximo nó do penúltimo é o newNode (novo último nó)
  last->next = newNode;
  //o penúltimo nó é o prev do newNode
  newNode->prev = last;
  return;
  }

  // Função que retorna o tamanho da lista (número de duplas).
  // Uma opção é armazenar o valor e sempre que inserir ou remover, atualizar.
  // Ou fazer uma iteração, partindo do nó raíz, até o último, e contando os
  // elementos.
  int Size() const
  { Node* temp = *head;
    int count=0
    while(temp != NULL)
      count = count+1;
      temp = temp->next;
    return count;
  }

  // remove a Key1 mínima e retorna a respectiva Key2
  T2 ExtractMinKey1();
  { Node* temp = *head;
    Node* min = *head;

    while(temp != NULL)
      if (temp->x_1 < min->x_1)
        min = temp;
      if (temp->x_1 = min->x_1)
        if (temp->x_2 < min->x_2)
          min = temp;
      temp = temp->next;
    min2= min->next;
    temp->next = min2;
    min2->prev = temp;
    return min->x_2;
  }
  
  // remove a Key2 mínima e retorna a respectiva Key1
  T1 ExtractMinKey2()
  { Node* temp = *head;
    Node* min = *head;

    while(temp != NULL)
      if (temp->x_2 < min->x_2)
        min = temp;
      if (temp->x_2 = min->x_2)
        if (temp->x_1 > min->x_1)
          min = temp;
      temp = temp->next;
    min2= min->next;
    temp->next = min2;
    min2->prev = temp; 
    
    return min->x_1;
  }}

  // retorna um vector de strings ordenado pela Key1
  vector<string> ListByKey1() const;

  // retorna um vector de strings ordenado pela Key2
  vector<string> ListByKey2() const;
};  // end of class DualList

#include "dual_list.hpp"

#endif  // DUAL_LIST_H_
