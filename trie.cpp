#include <bits/stdc++.h>
using namespace std;

class info
{
    int id;
    string name;
    string telephone;
    string email;

public:
    info()
    {
        id = 0;
        telephone = "";
        email = "";
    }

    friend class Node;
    friend class phone_details;
};

class Node // the unordered map to store the names using Node concept
{
    unordered_map<char, Node *> child;
    bool isLast;

public:
    Node()
    {
        for (char i = 'A'; i <= 'Z'; i++)
            child[i] = NULL;

        isLast = false;
    }
    friend class phone_details;
};

class phone_details
{
    info arr[100]; // maximum size of the infoory is 100
    string n;
    string t;
    string e;
    int i, index;

public:
    phone_details()
    {
        i = 0;
        t = "";
        e = "";
    }

    void create(int size)
    {
        cout << "\nENTER S NO.: ";
        cin >> i;
        cout << "\nENTER NAME: ";
        cin >> n;
        cout << "\nENTER TELEPHONE: ";
        cin >> t;

        while (t.length() != 10)
        {
            cout << "ENTER VALID NUMBER: ";
            cin >> t;
        }

        cout << "\nGmail: ";

        while (1)
        {
            cin >> e;

            bool flag = true;

            int x = e.length();

            if (x < 11)
            {
                cout << "ENTER VALID GMAIL: ";

                continue;
            }

            for (int i = x - 10; i < x and i >= 0; i++)
            {
                if (i == x - 10 and e[i] == '@')
                    continue;

                else if (i == x - 9 and e[i] == 'g')
                    continue;

                else if (i == x - 8 and e[i] == 'm')
                    continue;

                else if (i == x - 7 and e[i] == 'a')
                    continue;

                else if (i == x - 6 and e[i] == 'i')
                    continue;

                else if (i == x - 5 and e[i] == 'l')
                    continue;

                else if (i == x - 4 and e[i] == '.')
                    continue;

                else if (i == x - 3 and e[i] == 'c')
                    continue;

                else if (i == x - 2 and e[i] == 'o')
                    continue;

                else if (i == x - 1 and e[i] == 'm')
                    continue;

                else
                {
                    cout << "ENTER VALID GMAIL: ";
                    break;

                    flag = false;
                }
            }

            if (flag == true)
                break;

            else
                continue;
        }

        index = i % size;
        for (int j = 0; j < size; j++)
        {
            if (arr[index].id == 0)
            {
                transform(n.begin(), n.end(), n.begin(), ::toupper);
                arr[index].id = i;
                arr[index].name = n;
                arr[index].telephone = t;
                arr[index].email = e;
                break;
            }
            else
            {
                index = (index + 1) % size;
            }
        }

        cout << endl
             << endl;
    }

    void search_id(int size) // searches a particular contact on the basis of the id entered by the user
    {
        int index1, i, f = 0;
        cout << "\nEnter the id to be searched: ";
        cin >> i;
        index1 = i % size;
        for (int k = 0; k < size; k++)
        {
            if (arr[index1].id == i)
            {
                cout << "\nRecord found \n";
                cout << "Name: " << arr[index1].name;
                cout << "\nID: " << arr[index1].id;
                cout << "\nContact number: " << arr[index1].telephone;
                f = 1;
                break;
            }
            else
                index1 = (index1 + 1) % size;
        }
        if (f == 0)
            cout << "Record not found\n";
    }

    void search_phone(int size)
    {

        int index1, f = 0;
        string prefix;
        cout << "\nENTER PHONE PREFIX: " << endl;
        cin >> prefix;

        // cout << prefix << endl;

        // index1 = i % size;
        for (int k = 0; k < size; k++)
        {
            string phone_number = arr[k].telephone;
            int len = phone_number.length();

            // cout << "a" << phone_number << endl;

            int count = 0;
            for (int i = 0; i < prefix.length(); i++)
            {
                if (phone_number[i] == prefix[i])
                {
                    count++;
                }
            }

            if (count == prefix.length())
            {
                cout << "Name: " << arr[k].name;
                cout << "\nID: " << arr[k].id;
                cout << "\nContact number: " << arr[k].telephone;
                cout << "\nContact number: " << arr[k].email;
                f = 1;
            }

            count = 0;
        }
        if (f == 0)
            cout << "Record not found\n";

        cout << endl;
    }

    void delete_rec(int size) // deletes the record whose id is entered by the user
    {
        int index1, i, f = 0;
        cout << "\nEnter the id of the record to be deleted: ";
        cin >> i;
        index1 = i % size;
        for (int k = 0; k < size; k++)
        {
            if (arr[index1].id == i)
            {
                cout << "\nRecord found and deleted successfully\n";
                arr[index1].name = " ";
                arr[index1].id = 0;
                arr[index1].telephone = "";
                arr[index1].email = "";
                f = 1;
                break;
            }
            else
                index1 = (index1 + 1) % size;
        }
        if (f == 0)
            cout << "\nRecord not found.";
    }

    void update_rec(int size) // updates the record of the person whose id is entered by the user
    {
        int index1, i, f = 0;
        cout << "\nEnter the id of the record that needs to be updated: ";
        cin >> i;
        index1 = i % size;
        for (int k = 0; k < size; k++)
        {
            if (arr[index1].id == i)
            {
                f = 1;
                break;
            }
            else
            {
                index1 = (index1 + 1) % size;
            }
        }
        if (f == 1)
        {
            cout << "\nEnter name to be updated: ";
            cin >> n;
            cout << "\nEnter telephone number: ";
            cin >> t;
            arr[index1].name = n;
            arr[index1].telephone = t;
            cout << "\nDetails updated";
        }
        else
        {
            cout << "\nRecord not found";
        }
    }

    void display_rec(int size) // displays the social register
    {
        cout << "\n\tID \tNAME \t\tCONTACT NUMBER";
        for (int k = 0; k < size; k++)
        {
            if (arr[k].id != 0)
            {
                cout << "\n\t" << arr[k].id << "\t" << arr[k].name << "\t\t" << arr[k].telephone;
            }
        }
    }

    Node *root = NULL; // initializing the root node here so that it doesn't have to be passed to all functions

    void insertIntoTrie(int n) // inserts all contacts into the trie
    {
        root = new Node();
        for (int i = 0; i < n; i++)
        {
            transform(arr[i].name.begin(), arr[i].name.end(), arr[i].name.begin(), ::toupper);
            insert_name(arr[i].name); // each contact is inserted into the trie one by one
        }
    }

    void insert_name(string s) // inserts a contact name in trie
    {
        int l = s.length();
        Node *itr = root; // itr iterates through the trie nodes
        for (int i = 0; i < l; i++)
        {
            Node *next = itr->child[s[i]];
            if (next == NULL)
            {
                next = new Node();
                itr->child[s[i]] = next; // inserts into the map if next node is not found
            }
            itr = next;
            if (i == (l - 1))
                itr->isLast = true; // when the end of string is reached, the last ndoe is marked true
        }
    }

    void display_query(string q) // displays suggestions for every character the user enters in string q
    {
        int i;
        Node *prev = root;
        string prefix = "";
        int l = q.length();
        for (i = 0; i < l; i++)
        {
            prefix += (char)q[i];
            char lastchar = prefix[i];
            Node *curNode = prev->child[lastchar];
            if (curNode == NULL)
            {
                cout << "\nNo Results Found for " << prefix << "\n";
                i++;
                break;
            }
            cout << "\nSuggestions based on " << prefix << " are"
                 << "\n";                         // if a suggested name is found
            displayContactsUtil(curNode, prefix); // then the contact details are displayed by this function

            prev = curNode;
        }
        for (; i < l; i++)
        {
            prefix += (char)q[i];
            cout << "\nNo Results Found for " << prefix << "\n";
        }
    }

    void displayContactsUtil(Node *curNode, string prefix) // displays all the contact details with respect to prefix
    {
        if (curNode->isLast)
            cout << prefix << endl;

        // Find all the adjacent nodes to the current
        // node and then call the function recursively
        // This is similar to performing DFS on a graph
        for (char i = 'A'; i <= 'Z'; i++)
        {
            Node *nextNode = curNode->child[i];
            if (nextNode != NULL)
                displayContactsUtil(nextNode, prefix + (char)i);
        }
    }
};
int main()
{
    string name;
    cout << "*************************                PHONE DIRECTORY MANAGEMENT SYSTEM                  *************************";
    cout << "\n\nENTER ADMIN NAME\n";
    cin >> name;

    cout << "\n\nWELCOME " << name << "!!";
    cout << "\n\n\nLET'S CREATE OUR OWN PHONEBOOK DIRECTORY " << name
         << "\n";

    cout << "MENU DRIVEN PROGRAM, ENTER CORRECT VALUES AT ALL STEPS!!!!";

    int size, ch;
    string query;

    phone_details h;

    cout << endl
         << endl
         << "ENTER NUMBER OF CONTACTS: ";
    cin >> size;
    for (int k = 0; k < size; k++)
    {
        h.create(size);
    }
    cout
        << "\n1: DISPLAY ALL RECORDS";
    cout << "\n2: PREFIX SEARCH VIA NAME";
    cout << "\n3: PREFIX SEARCH VIA NUMBER";
    cout << "\n4: SEARCH RECORD";
    cout << "\n5: DELETE RECORD";
    cout << "\n6: UPDATE RECORD";

    cout << "\n0: EXIT";
    while (true)
    {
        cout << "\n\nEnter your choice ";
        cin >> ch;
        if (ch == 1)
            h.display_rec(size);
        if (ch == 2)
        {
            cout << "\nENTER NAME PREFIX: ";
            cin >> query;
            transform(query.begin(), query.end(), query.begin(), ::toupper);
            h.insertIntoTrie(size);
            h.display_query(query);
        }
        if (ch == 3)
        {
            h.search_phone(size);
        }

        if (ch == 4)
            h.search_id(size);
        // if (ch == 5)
        //     h.delete_rec(size);
        if (ch == 6)
            h.update_rec(size);

        if (ch == 0)
            break;
    }
    return 0;
}
