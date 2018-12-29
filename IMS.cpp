/*
    Update -- 12/29: Created IMS project; Building the underlying functions of
                     the application consisting of the basic structure of the
                     Item along with some basic functions to create and
                     update inventory items
*/

#include <iostream>
#include <vector>
using namespace std;

/*
    Definition of Item structure. Items must have an id to identify the product,
    a name, a description, a price, and quantity (amount of the Item in stock)
*/
struct Item {
    short id;
    string name;
    string description;
    double price;
    int quantity;
};

//Node for ID queue --- will be implemented in a future release
struct node {
    short id;
    node* next;
};

//Function to create item given user input
Item createItem(int id)
{
    Item newItem;
    newItem.id = id;
    cout << "Please enter the name of this item" << endl;
    cin >> newItem.name;
    cout << "Please enter a description of this item" << endl;
    std::getline(std::cin >> std::ws, newItem.description);
    string price;
    cout << "Please enter the price of this item (format: [dollars].[cents])" << endl;
    cin >> price;
    newItem.price = stof(price);
    cout << "Please provide the number of items in stock" << endl;
    string quantity;
    cin >>  quantity;
    newItem.quantity = stoi(quantity);
    cout << "Item added successfully!" << endl;
    return newItem;
}

//Function to print current inventory
void printInventory(vector<Item> &inventory)
{
    cout << "Current Inventory: " << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    int size = inventory.size();
    if(size == 0) return;
    for(int i = 0; i<size; i++) {
        Item item = inventory.at(i);
        cout << "ID: " << item.id << " || Name: " << item.name << " || Description: " << item.description << " || Price: $" << item.price << " || Quantity: " << item.quantity << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;
}


int main()
{
    cout << "Welcome to the Inventory Management System!" << endl;
    char input;
    int currId = 0;
    vector<Item> inventory;
    //Main menu for user -- currently, only commands c, v, r, and q have been built
    while(input != 'q')
    {
        cout <<  "Please enter a command or enter h to see a list of commands!" << endl;
        cin >> input;
        switch(input)
        {
            case 'q':
                break;
            case 'c':
                inventory.push_back(createItem(currId));
                currId++;
                break;
            case 'v':
                printInventory(inventory);
                break;
            case 't':
                //restockItem(inventory[n]);
                break;
            case 'u':
                //updateItem(inventory[n]);
                break;
            case 'd':
                //deleteItem(inventory);
                break;
            case 'r':
                inventory.clear();
                break;
            case 'h':
                cout << "Commands: " << endl;
                cout << "q: quit" << endl;
                cout << "c: create item" << endl;
                cout << "v: view items" << endl;
                cout << "r: restock item" << endl;
                cout << "u: update item" << endl;
                cout << "d: delete item" << endl;
                cout << "r: reset" << endl;
                break;
            default:
                cout << "Not a valid command! Please enter h for a list of valid commands!" << endl;
                break;


        }
    }

}
