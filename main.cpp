#include <iostream>
#include "mp1.h"

using namespace std;

int main() 
{
    PC_CircularLinkedList<Boxes_BT<Pokemon>> pc;
    Boxes_BT<Pokemon> bst;
    pc.insertStart(bst);

    char cmd;

    while (true)
    {
        cout << "Command (a/s/n/p/c/i/h/q): ";
        cin >> cmd;
        if (cmd == 'n')
        {
            pc.next();
            pc.displayNode();
        }
        else if (cmd == 'p')
        {
            pc.prev();
            pc.displayNode();
        }
        else if (cmd == 'a')
        {
            pkmn_name name;
            pkdx_number number;
            level lvl;
            pkmn_type type;

            cout << "Pokedex number: ";
            cin >> number;
            cout << "Pokemon name: ";
            cin >> name;
            cout << "Pokemon level: ";
            cin >> lvl;
            cout << "Pokemon type: ";
            cin >> type;

            Pokemon new_pkmn(name, number, type, lvl);

            pc.insertInBox(new_pkmn);
            pc.displayNode();
        }
        else if (cmd == 's')
        {
            unsigned short category; 
            cout << "Sort by what (0 pkdx number / 1 name / 2 level): ";
            cin >> category;
            pc.reorderBox(category);
            pc.displayNode();
            
        }
        else if (cmd == 'c')
        {
            unsigned short category;

            pkmn_name name = "";
            pkdx_number number = 0;
            level lvl = 0;
            pkmn_type type = 0;

            cout << "Input a category (0 number / 1 name / 2 level / 3 type): ";
            cin >> category;

            if (category == 0)
            {
                cout << "Pokedex number: ";
                cin >> number;
            }
            else if (category == 1)
            {
                cout << "Pokemon name: ";
                cin >> name;
            }
            else if (category == 2)
            {
                cout << "Pokemon lvl: ";
                cin >> lvl;
            }
            else if (category == 3)
            {
                cout << "Pokemon type: ";
                cin >> type;
            }
            else
            {
                cout << "Invalid category." << endl;
                continue;
            }

            Pokemon searchPkmn(name, number, type, lvl);
            pc.searchAllBoxes(category, searchPkmn);
            
        }
        else if (cmd == 'i')
        {
            unsigned int pos;
            cout << "Position to insert the new box: ";
            cin >> pos;

            // Create new box
            Boxes_BT<Pokemon> *newBox = new Boxes_BT<Pokemon>();

            // Insert new box in the given postion
            pc.insert(*newBox, pos);
            // pc.displayAll();
        }
        else if (cmd == 'q')
        {
            break;
        }
        else
        {
            // Help
            cout << endl;
            cout << "a: Add new Pokemon into the current box" << endl;
            cout << "s: Sort the current box based on a specific category" << endl;
            cout << "n: Move to the next box" << endl;
            cout << "p: Move to the previous box" << endl;
            cout << "c: Search for Pokemon following a specific category" << endl;
            cout << "i: Insert a new box" << endl;
            cout << "h: Help" << endl;
            cout << "q: Quit the program" << endl;
            cout << endl;
        } 
    }

    return 0;
}