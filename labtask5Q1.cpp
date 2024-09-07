#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
class Playlist {
private:
    struct Song {
        string title;
        string artist;
        Song* next;

        Song(const string& title, const string& artist)
            : title(title), artist(artist), next(nullptr) {}
    };
    Song* head;
public:
    Playlist() : head(nullptr) {}
    void addSongAtBeginning(const string& title, const string& artist) {
        Song* newSong = new Song(title, artist);
        if (!head) {
            newSong->next = newSong;  
        } else {
            newSong->next = head->next;
            head->next = newSong;
        }
        head = newSong;  
    }
    void removeSongAtEnd() {
        if (!head) {
            cout << "Playlist is empty. Cannot remove song." << endl;
            return;
        }
        Song* current = head;
        while (current->next != head) {
            current = current->next;
        }
        if (current == head) {
            delete head;
            head = nullptr;
        } else {
            Song* lastSong = current->next;
            current->next = head->next;
            delete lastSong;
        }
    }
    void displayPlaylist() const {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }
        Song* current = head->next;  
        do {
            cout << "Title: " << current->title << ", Artist: " << current->artist << endl;
            current = current->next;
        } while (current != head->next);
    }
};
int main() {
    Playlist playlist;
    int choice;
    do {
        cout << "\n==== Playlist Management ====\n";
        cout << "1. Add Song at Beginning\n";
        cout << "2. Remove Song at End\n";
        cout << "3. Display Playlist\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string title, artist;
                cout << "Enter song details:\n";
                cout << "Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Artist: ";
                getline(cin, artist);
                playlist.addSongAtBeginning(title, artist);
                break;
            }
            case 2:
                playlist.removeSongAtEnd();
                break;

            case 3:
                playlist.displayPlaylist();
                break;

            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);
}

class Inventory {
private:
    class Node {
    public:
        Node* prev;
        int ID;
        string name;
        double price;
        int quantity;
        Node* next;
        Node(int ID, string name, double price, int quantity)
            : ID(ID), name(name), price(price), quantity(quantity), prev(nullptr), next(nullptr) {}
    };
    Node* head;
public:
    Inventory() : head(nullptr) {}
    void addProduct(int ID, string name, double price, int quantity) {
        Node* newNode = new Node(ID, name, price, quantity);
        if (!head || ID < head->ID) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next && curr->next->ID < ID) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next) {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
        }
    }
    void removeProduct(int ID) {
        if (!head) {
            cout << "Inventory is empty. Cannot remove product." << endl;
            return;
        }
        Node* current = head;
        while (current && current->ID != ID) {
            current = current->next;
        }
        if (!current) {
            cout << "Product with ID " << ID << " not found. Cannot remove." << endl;
            return;
        }
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Product removed successfully!" << endl;
    }
    void displayProducts() {
        if (!head) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << endl;
        cout << "-----------------------------------------------" << endl;
        Node* current = head;
        while (current) {
            cout << setw(10) << current->ID << setw(20) << current->name
                 << setw(15) << current->price << setw(15) << current->quantity << endl;
            current = current->next;
        }
    }
    void updatePrice(int ID, double newPrice) {
        Node* current = head;
        while (current && current->ID != ID) {
            current = current->next;
        }
        if (!current) {
            cout << "Product with ID " << ID << " not found. Cannot update price." << endl;
            return;
        }
        current->price = newPrice;
        cout << "Price updated successfully!" << endl;
    }
    void findProduct(int ID) {
        Node* current = head;
        while (current && current->ID != ID) {
            current = current->next;
        }
        if (!current) {
            cout << "Product with ID " << ID << " not found." << endl;
        } else {
            cout << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << setw(10) << current->ID << setw(20) << current->name
                 << setw(15) << current->price << setw(15) << current->quantity << endl;
        }
    }
};
int main() {
    Inventory inventory;
    int choice;
    do {
        cout << "\n==== Inventory Management System ====\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Display Products\n";
        cout << "4. Update Price\n";
        cout << "5. Find Product\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int ID, quantity;
                double price;
                string name;

                cout << "Enter product details:\n";
                cout << "ID: ";
                cin >> ID;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Price: ";
                cin >> price;
                cout << "Quantity: ";
                cin >> quantity;

                inventory.addProduct(ID, name, price, quantity);
                break;
            }
            case 2: {
                int ID;
                cout << "Enter the ID of the product to remove: ";
                cin >> ID;
                inventory.removeProduct(ID);
                break;
            }
            case 3:
                inventory.displayProducts();
                break;
           case 4: {
                int ID;
                double newPrice;
                cout << "Enter the ID of the product to update price: ";
                cin >> ID;
                cout << "Enter the new price: ";
                cin >> newPrice;
                inventory.updatePrice(ID, newPrice);
                break;
            }
            case 5: {
                int ID;
                cout << "Enter the ID of the product to find: ";
                cin >> ID;
                inventory.findProduct(ID);
                break;
            }
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);
}
// class LinkedList {
// private:
//     class Node {
//     public:
//         int data;
//         Node* prev;
//         Node* next;
//         Node(int _data) : data(_data), prev(nullptr), next(nullptr) {}
//     };
//     Node* head;
// public:
//     LinkedList() : head(nullptr) {}
//     void insertNode(int data) {
//         Node* newNode = new Node(data);
//         if (!head) {
//             head = newNode;
//         } else {
//             Node* current = head;
//             while (current->next) {
//                 current = current->next;
//             }
//             current->next = newNode;
//             newNode->prev = current;
//         }
//     }
//     void splitLists(LinkedList& evenList, LinkedList& oddList) {
//         Node* current = head;
//         while (current) {
//             if (current->data % 2 == 0) {
//                 evenList.insertNode(current->data);
//             } else {
//                 oddList.insertNode(current->data);
//             }
//             current = current->next;
//         }
//     }
//     void displayList() {
//         Node* current = head;
//         while (current) {
//             cout << current->data << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }
//     void displayLists(const string& listName) {
//         Node* current = head;
//         cout << listName << " List: ";
//         while (current) {
//             cout << current->data << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }
// };
// int main() {
//     LinkedList originalList;
//     originalList.insertNode(1);
//     originalList.insertNode(2);
//     originalList.insertNode(3);
//     originalList.insertNode(4);
//     originalList.insertNode(5);
//     LinkedList evenList;
//     LinkedList oddList;
//     originalList.displayList();
//     originalList.splitLists(evenList, oddList);
//     evenList.displayLists("Even");
//     oddList.displayLists("Odd");
// }
