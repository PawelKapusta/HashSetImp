//
// Created by sony on 23.03.2020.
//

#ifndef ZESTAW2B_HASHSET_H
#define ZESTAW2B_HASHSET_H

#include <iostream>
using namespace std;

template <class T>
class HashSet {

public:
    struct Node{
        T x;
        Node * next =  nullptr;
    };
    Node * tab[10];

    int sizeSet = 0;
    HashSet(){
        for (int i = 0; i < 10; ++i) {
            tab[i]= nullptr;
        }
    }
    int hashFunction(int number){
        return number % 10;
    }

    void insert(T x) {
        int index = hashFunction(x);
        Node *newNode = new Node;
        newNode->x = x;
        newNode->next = nullptr;
        Node *temp;
        if (tab[index] == nullptr) {
            tab[index] = newNode;
        } else {
            Node *currentNode = tab[index];
            if (isExist(newNode->x)) {
                cout << "This element: " << x << " already exist in this set!" << endl;
                return;
            }else {
//            if( current -> x > newNode -> x){
//                newNode -> next = current;
//                tab[index] = newNode;
//            }else{
                Node *current = tab[index];
                while (current->next != nullptr /*&& current -> next -> x < newNode -> x*/) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
//            }
            }
            sizeSet++;
        }
    }

    void remove(T x ){
        int index = hashFunction(x);
        if(sizeSet == 0){
            cout<<"Set is empty" << endl;
            return;
        }
        Node * temp = tab[index];
        if (temp -> x == x && temp -> next == nullptr){
            delete(temp);
            sizeSet--;
            if(sizeSet == 0){
                return;
            }
            tab[index] = nullptr;
        }else if(temp -> x == x && temp ->next != nullptr){
           tab[index] = temp -> next;
            delete(temp) ;
            sizeSet--;
        } else{
            while(temp!= nullptr && temp -> next -> x != x){
                temp = temp->next;
            }
            Node* toBeforeRemove = temp;
            Node * toRemove = temp -> next;
            temp -> next = temp -> next -> next;
            delete(toRemove);
            sizeSet--;

        }

    }
    static HashSet mergeTwoSets(const HashSet& a, const HashSet& b) {
        HashSet<T> c;
        //auto currentA = a.tab[0];
        for (int i = 0; i < 10; ++i) {
            Node * currentA = a.tab[i];
            while(currentA != nullptr)
            {
                c.insert(currentA ->x);
                currentA = currentA -> next;
            }

        }
        for (int i = 0; i < 10; ++i) {
            Node * currentB = b.tab[i];
            while(currentB != nullptr)
            {
                c.insert(currentB ->x);
                currentB = currentB -> next;
            }

        }
        return c;
    }
    static HashSet productOfTwoSets(HashSet& a,HashSet& b) {
        HashSet<T> c;
        for (int i = 0; i < 10; ++i) {
            Node * currentA = a.tab[i];
            while(currentA != nullptr)
            {
                c.insert(currentA ->x);
                currentA = currentA -> next;
            }
        }
        for (int i = 0; i < 10; ++i) {
            Node * currentC = c.tab[i];
            for (currentC; currentC != nullptr; currentC = currentC -> next) {
                if (!b.isExist(currentC -> x)){
                    c.remove(currentC -> x);
                }
            }
        }
        return c;
    }
    static HashSet differencesBetweenTwoSets(const HashSet& a, const HashSet& b){
        HashSet<T> c;
        for (int i = 0; i < 10; ++i) {
            Node * currentA = a.tab[i];
            while(currentA != nullptr)
            {
                c.insert(currentA ->x);
                currentA = currentA -> next;
            }
        }
        for (int i = 0; i < 10; ++i) {
            Node * currentB = b.tab[i];
            while(currentB != nullptr)
            {
                if(c.isExist(currentB -> x))
                {
                    c.remove(currentB ->x);
                }
                currentB = currentB -> next;
            }
        }
        return c;
    }
     bool areTheSame( HashSet& a , HashSet& b){

        if (a.sizeSet == b.sizeSet) {
        for (int i = 0; i < 10; ++i) {
            Node *currentB = b.tab[i];
                while(currentB != nullptr)
                {
                    if(a.isExist(currentB -> x))
                    {
                        currentB = currentB -> next;
                    } else{
                        return false;
                    }
            }
         }
        } else{
            return false;
        }
        return true;
    }
    bool isExist(T x){
        int index = hashFunction(x);
        for ( Node * temp = tab[index]; temp  != nullptr; temp = temp ->next) {
            if( temp -> x == x){
                return true;
            }
        }
        return false;
    }

    void size(){
        cout << "Size list equals: " << sizeSet << endl;
    }
    void printSet(){
        if (sizeSet == 0) {
            cout <<"Empty Set" << endl;
            return;
        }
        else {
            for (int i = 0; i < 10; ++i) {
                    if(tab[i] != nullptr){
                        for ( Node * start = tab[i]; start  != nullptr; start = start -> next) {
                            cout << start -> x << " ";
                        }
                    }
            }
        }
        cout << endl;
    }


};
#endif //ZESTAW2B_HASHSET_H
