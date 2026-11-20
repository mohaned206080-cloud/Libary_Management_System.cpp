#include <bits/stdc++.h>
using namespace std;
class Library {
    public:
    vector<tuple<string,string,string>> Books;
    void addbook(string name, string author) {
        Books.push_back({name, author,"Available"});
        cout << name << " book added." << endl;
    };
    void Removebook(string name) {
        bool found = false;
        int foundindex = 0;
        for (int i = 0; i < Books.size(); i++) {
            if (get<0>(Books[i]) == name) {
                found = true;
                foundindex = i;
                break;
            }
        }
        if (found) {
            Books.erase(Books.begin() + foundindex);
            cout << name << " book removed." << endl;
        }else {
            cout << name << " book not found." << endl;
        }
    }
    void BorrowBook(string name) {
        bool found = false;
        int foundindex = 0;
        for (int i = 0; i < Books.size(); i++) {
            if (get<0>(Books[i]) == name) {
                found = true;
                foundindex = i;
                break;
            }
        }
        if (found==true&&get<2>(Books[foundindex])=="Available") {
            get<2>(Books[foundindex]) = "Borrowed";
            cout << name << " borrowed successfully." << endl;
        }else if (found==true&&get<2>(Books[foundindex])=="Borrowed") {
            cout<<"This book is already borrowed."<<endl;
        }else {
            cout<<"This book does not exist."<<endl;
        }
    }
    void ReturnBook(string name) {
        bool found = false;
        int foundindex = 0;
        for (int i = 0; i < Books.size(); i++) {
            if (get<0>(Books[i]) == name) {
                found = true;
                foundindex = i;
                break;
            }
        }
        if (found==true&&get<2>(Books[foundindex])=="Available") {
            cout<<"This book is already available."<<endl;
        }else if (found==true&&get<2>(Books[foundindex])=="Borrowed") {
            get<2>(Books[foundindex]) = "Available";
            cout << name << " book returned." << endl;
        }else {
            cout<<"This book does not exist."<<endl;
        }
    }
    void SearchBook(string name) {
        bool found = false;
        int foundindex = 0;
        for (int i = 0; i < Books.size(); i++) {
            if (get<0>(Books[i]) == name) {
                found = true;
                foundindex = i;
                break;
            }
        }
        if (found==true) {
            cout<<"Tile: "<<get<0>(Books[foundindex])<<" | Author: "<<get<1>(Books[foundindex])<<" | Status: "<<get<2>(Books[foundindex])<<endl;
        }else {
            cout<<"This book does not exist."<<endl;
        }
    }
    void displayBooks() {
        if (Books.empty()) {
            cout<<"No Books found."<<endl;
        }else{
            for (int i = 0; i < Books.size(); i++) {
                cout<<i+1<<"- "<<"Tile: "<<get<0>(Books[i])<<" | Author: "<<get<1>(Books[i])<<" | Status: "<<get<2>(Books[i])<<endl;
            }
        }
    }
};
int main() {
    bool v=true;
    int option;
    string title, author;
    Library l;
    while (v) {
        cout<<"=== Library Management System ==="<<endl;
        cout<<"1. Add Book\n2. Remove Book\n3. Borrow Book\n4. Return Book\n5. Search Book\n6. Display ALl Books\n7. Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>option;
        cout<<endl;
        switch (option) {
            case 1:
                cout<<"Notice there is no space in book title or author"<<endl;
                cout<<"Enter Book title: ";
                cin>>title;
                cout<<endl;
                cout<<"Enter Author: ";
                cin>>author;
                cout<<endl;
                l.addbook(title, author);
                break;
            case 2:
                cout<<"Enter Book title whose do you want to remove: ";
                cin>>title;
                cout<<endl;
                l.Removebook(title);
                break;
            case 3:
                cout<<"Enter Book title whose do you want to borrow: ";
                cin>>title;
                cout<<endl;
                l.BorrowBook(title);
                break;
            case 4:
                cout<<"Enter Book title whose do you want to return: ";
                cin>>title;
                cout<<endl;
                l.ReturnBook(title);
                break;
            case 5:
                cout<<"Enter Book title ,you want to search for: ";
                cin>>title;
                cout<<endl;
                l.SearchBook(title);
                break;
            case 6:
                l.displayBooks();
                break;
            case 7:
                cout<<"Goodbye!"<<endl;
                v=false;
                break;
            default:
                cout<<"Invalid option."<<endl;
                break;
        }
        cout<<endl;
    }
}
