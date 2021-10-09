#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<map>
using namespace std;
int main()
{
int n;
string name;
long num;
cin >> n;
cin.ignore();
map <string,long>Book;
for (int i = 0; i < n; i++) {
    cin >> name;
    cin >> num;
    Book[name] = num;
}
while(cin >> name) {
    if (Book.find(name) != Book.end()) {
        cout << name << "=" <<Book.find(name)->second << endl;
    } else {
        cout << "Not found" << endl;
    }
}
    return 0;
}  

