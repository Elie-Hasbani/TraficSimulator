#include <iostream>
#include <list>

void supprimerElement(std::list<int>& lst, std::list<int>::iterator it) {
    // Supprime l'élément pointé par l'itérateur
    it = lst.erase(it);
    // it est maintenant mis à jour pour pointer sur l'élément suivant
}

int main() {
    std::list<int> lst = {10, 20, 30, 40, 50};

    // Obtenir un itérateur pointant sur l'élément à supprimer
    auto it = lst.begin();
    //std::advance(it, 2); // Avancer de deux positions pour pointer sur 30

    // Appeler la fonction pour supprimer l'élément pointé
    supprimerElement(lst, it);

    // Afficher la liste après la suppression
    std::cout << "Liste après suppression : ";
    for (int val : lst) {
        std::cout << val << " "; // Affichera : 10 20 40 50
    }
    std::cout << std::endl;

    return 0;
}
