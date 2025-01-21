#include <iostream>
#include <list>

using namespace std;

void f(int * test){cout<<"toto"<<endl;};
void f(const int* test){cout<<"titi"<<endl;}

void f(int & test){cout<<"toto"<<endl;};
void f(const int & test){cout<<"titi"<<endl;}

int main() {

int i = 2;
int *ptr1 = &i;
const int* ptr2 = &i;

//f(ptr1);
//f(ptr2);

int j = 2;
const int k = 3;

f(j);
f(k);

}
