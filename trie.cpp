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

class Node
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
    info arr[100];
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

    void search_id(int size)
    {
        int index1, i, f = 0;
        cout << "\nENTER ID: ";
        cin >> i;
        index1 = i % size;
        for (int k = 0; k < size; k++)
        {
            if (arr[index1].id == i)
            {
                cout << "\nID: " << arr[index1].id;
                cout << "\nNAME: " << arr[index1].name;
                cout << "\nPHONE: " << arr[index1].telephone;
                cout << "\nGMAIL: " << arr[index1].email;
                f = 1;
                break;
            }
            else
                index1 = (index1 + 1) % size;
        }
        if (f == 0)
            cout << "NOT FOUND!!\n";

        cout << endl
             << endl;
    }

    void search_phone(int size)
    {

        int index1, f = 0;
        string prefix;
        cout << "\nENTER PHONE PREFIX: " << endl;
        cin >> prefix;

        cout << endl;

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
                cout << "NAME: " << arr[k].name;
                cout << "\nPHONE: " << arr[k].telephone;
                cout << "\nGMAIL: " << arr[k].email;
                f = 1;
            }

            count = 0;

            cout << endl
                 << endl;
        }
        if (f == 0)
            cout << "NOT FOUND!!\n";

        cout << endl;
    }

    void delete_rec(int size)
    {
        int index1, i, f = 0;
        cout << "\nENTER ID: ";
        cin >> i;
        cout << endl;
        index1 = i % size;
        for (int k = 0; k < size; k++)
        {
            if (arr[index1].id == i)
            {
                cout << "\nDELETED!!\n";
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
            cout << "\nNOT FOUND!!";
    }

    void update_rec(int size)
    {
        int index1, i, f = 0;
        cout << "\nENTER ID: ";
        cin >> i;

        cout << endl;
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
            cout << "\nENTER NEW NAME: ";
            cin >> n;
            cout << "\nENTER NEW TELEPHONE: ";
            cin >> t;
            cout << "\nENTER NEW GMAIL: ";
            cin >> e;
            arr[index1].name = n;
            arr[index1].telephone = t;
            arr[index1].email = e;
            cout << endl;
            cout << "\nUPDATED!!";
        }
        else
        {
            cout << "\nNOT FOUND!!";
        }
    }

    void display_rec(int size)
    {
        cout << endl;
        for (int k = 0; k < size; k++)
        {
            if (arr[k].id != 0)
            {
                cout << "NAME: " << arr[k].name << endl
                     << "PHONE: " << arr[k].telephone << endl
                     << "GMAIL: " << arr[k].email << endl;

                cout << endl;
            }
        }
    }

    Node *root = NULL;

    void insertIntoTrie(int n)
    {
        root = new Node();
        for (int i = 0; i < n; i++)
        {
            transform(arr[i].name.begin(), arr[i].name.end(), arr[i].name.begin(), ::toupper);
            insert_name(arr[i].name);
        }
    }

    void insert_name(string s)
    {
        int l = s.length();
        Node *itr = root;
        for (int i = 0; i < l; i++)
        {
            Node *next = itr->child[s[i]];
            if (next == NULL)
            {
                next = new Node();
                itr->child[s[i]] = next;
            }
            itr = next;
            if (i == (l - 1))
                itr->isLast = true;
        }
    }

    void display_query(string q)
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
            cout << "\nNAMES STARTING WITH " << prefix << " are"
                 << "\n";
            displayContactsUtil(curNode, prefix);

            prev = curNode;
        }
        for (; i < l; i++)
        {
            prefix += (char)q[i];
            cout << "\nNo Results Found for " << prefix << "\n";
        }
    }

    void displayContactsUtil(Node *curNode, string prefix)
    {
        if (curNode->isLast)
            cout << prefix << endl;

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
    cout << "\n5: UPDATE RECORD";
    cout << "\n6: DELETE RECORD";

    cout << "\n0: EXIT";
    while (true)
    {
        cout << "\n\nENTER CHOICE: ";
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
            h.search_phone(size);

        if (ch == 4)
            h.search_id(size);
        if (ch == 5)
            h.update_rec(size);
        if (ch == 6)
            h.delete_rec(size);

        if (ch == 0)
            break;
    }
    return 0;
}
