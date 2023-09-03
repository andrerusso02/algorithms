#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> T) {
    for (int i = 0; i < T.size(); i++) {
        cout << to_string(T[i]) + ", ";
    }
    cout << endl;
}

void echanger(vector<int> &T, int i, int j) {
    int temp = T[i];
    T[i] = T[j];
    T[j] = temp;
}

int choix_pivot(vector<int> &T, int premier, int dernier) {
    return dernier;
}

int partitionner(vector<int> &T, int premier, int dernier, int pivot) {

    echanger(T, pivot, dernier);

    int j = premier;

    for(int i=premier; i<dernier; i++) {
        if(T[i] <= T[dernier]) {
            echanger(T, i, j);
            j++;  
        }
    }
    echanger(T, j, dernier);

    return j; // position du pivot
}

void tri_rapide(vector<int> &T, int premier, int dernier) {
    if(premier < dernier) { // taille du sous-tableau supérieure à 1
        int pivot = choix_pivot(T, premier, dernier);
        pivot = partitionner(T, premier, dernier, pivot);
        tri_rapide(T, premier, pivot-1);
        tri_rapide(T, pivot+1, dernier);
    }
}

int main() {
    vector<int> T{10, 1, 2, 3, 4, 5, 32, 1, 4, 8, 12, 121};
    tri_rapide(T, 0, T.size()-1);
    print_vector(T);
}
