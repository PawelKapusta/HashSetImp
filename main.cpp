#include <iostream>
#include <fstream>
#include <chrono>
#include "HashSet.h"

int main() {
    cout << "Set: " << endl;
    HashSet<int> hashSet;
    hashSet.insert(33);
    hashSet.insert(23);
    hashSet.insert(13);
    hashSet.insert(11);
    hashSet.insert(21);
    hashSet.insert(53);

    hashSet.printSet();
    hashSet.size();

    hashSet.remove(33);
    hashSet.printSet();
    hashSet.size();

    hashSet.remove(11);
    hashSet.printSet();
    hashSet.size();

    cout << "Is this element exist in this SET: " << hashSet.isExist(23) << endl;
    cout << "Is this element exist in this SET: " << hashSet.isExist(2312) << endl;
    cout << "Is this element exist in this SET: " << hashSet.isExist(11) << endl;

    cout << "Set2: " << endl;
    HashSet<int> hashSet2;
    hashSet2.insert(2);
    hashSet2.insert(23);
    hashSet2.insert(99);
    hashSet2.insert(73);
    hashSet2.insert(1);

    hashSet2.printSet();
    hashSet2.size();

    cout << "Set3: " << endl;
    HashSet<int> mergeTwo = HashSet<int>::mergeTwoSets(hashSet,hashSet2);
    mergeTwo.printSet();
    mergeTwo.size();

    cout << "Set4: " << endl;
    HashSet<int> differentTwo = HashSet<int>::differencesBetweenTwoSets(hashSet,hashSet2);
    differentTwo.printSet();
    differentTwo.size();
        cout << "Set5: " << endl;
        HashSet<int> productTwo = HashSet<int>::productOfTwoSets(hashSet,hashSet2);
        productTwo.printSet();
        productTwo.size();

        cout << "Set6: " << endl;
        cout << hashSet.areTheSame(hashSet,hashSet2) <<endl ;
        cout << "Special sets to prove that sets are the same " << endl;
        HashSet<int> firstThesame;
        firstThesame.insert(1);
        firstThesame.insert(23);
        firstThesame.insert(55);
        firstThesame.insert(21);
        firstThesame.insert(99);
        HashSet<int> secondTheSame;
        secondTheSame.insert(1);
        secondTheSame.insert(99);
        secondTheSame.insert(21);
        secondTheSame.insert(55);
        secondTheSame.insert(23);
        cout << "Are special the same: " << firstThesame.areTheSame(firstThesame,secondTheSame) << endl;

    srand(time(NULL));
    HashSet<int> set;
    int n=200000;
    ofstream zapis;

    zapis.open("/home/sony/CLionProjects/AISD2/Zestaw2B/daneInsert.txt",ios::out | ios::app);
    double totalTime=0;
    if (zapis.good()) {
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < n; ++j) {
            set.insert(rand()%100000);
            // sumTime+=elapsed.count();
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        totalTime = elapsed.count();
        //zapis << i << " " << sumTime << endl;
        //setToCountTime.clearSet();
    }
    zapis << n  << " " << totalTime << endl;

   // zapis << "e" << endl;
    zapis.flush();
    zapis.close();

    return 0;
}
