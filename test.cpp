#include <iostream>
#include <list>
#include <algorithm> // pour std::lower_bound

using namespace std;

void insertInSortedList(std::list<int>& lst, int value) {
    /*auto it = std::find_if(lst.begin(), lst.end(), [value](int elem) { return elem >= value; });
    lst.insert(it, value); // Insère l'élément*/

    cout << (lst.begin() == lst.end()) <<endl;
    list <int>::iterator it = lst.begin();
    while ((*it) <= value && it != lst.end()){
        ++it;
    
        
    }

    lst.insert(it, value);


}

int main() {
    std::list<int> sortedList;
    int valueToInsert = 0;
    int valueToInsert2 = 10;

    insertInSortedList(sortedList, valueToInsert);
    insertInSortedList(sortedList, valueToInsert2);

    // Affichage de la liste
    for (int num : sortedList) {
        std::cout << num << " ";
    }

    return 0;
}
