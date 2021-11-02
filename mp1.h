#ifndef MP1_H
#define MP1_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef std::string pkmn_name;
typedef unsigned short pkdx_number;
typedef unsigned short level;
typedef unsigned short pkmn_type;
int count = 0;

////////////////////// Pokemon Object //////////////////////////

class Pokemon
{
    private:
        pkmn_name name;
        pkdx_number number;
        pkmn_type type;
        level lvl;

    public:
        Pokemon();
        Pokemon(pkmn_name name, pkdx_number num, pkmn_type type, level lvl) 
        : name{ name }, number{ num }, type{ type }, lvl{ lvl } {}

        template <typename T2> friend class Boxes_BT;
        template <typename T2> friend class PC_CircularLinkedList;
        friend ostream& operator <<(ostream& print, const Pokemon& pokemon);

};

ostream& operator <<(ostream& print, const Pokemon& pokemon)
{
    print << " PkDx " << pokemon.number << " " << pokemon.name << " lvl " << pokemon.lvl;
    return print;
}

/////////////////////////// Binary Search Tree ///////////////////////

template <typename T>
struct Boxes_BTNode 
{
    Boxes_BTNode(T value): data(value), left(NULL), right(NULL) {}
    T data;
    Boxes_BTNode *left;
    Boxes_BTNode *right;
};

// template <typename T>
// class Boxes_BTNode
// {
//     private:
//         T data;
//         Boxes_BTNode<T> *left;
//         Boxes_BTNode<T> *right;
//     public:
//         Boxes_BTNode(T data, Boxes_BTNode<T> *left = nullptr, Boxes_BTNode<T> *right = nullptr);
//         template <typename T2> friend class Boxes_BT;
// };

// template <typename T>
// Boxes_BTNode<T>::Boxes_BTNode(T data, Boxes_BTNode<T> *left, Boxes_BTNode<T> *right)
// {
//     this->data = data;
//     this->left = left;
//     this->right = right;
// }

template <typename T>
class Boxes_BT
{
    private:
        Boxes_BTNode<T> *root;
        int category;
        unsigned short size;
        void insert(Boxes_BTNode<T> *node, T data);
        void insertName(Boxes_BTNode<T> *node, T data);
        void insertLevel(Boxes_BTNode<T> *node, T data);
        void displayInOrder(Boxes_BTNode<T> *root);
        void searchBox(Boxes_BTNode<T> *root, unsigned short category, T data);
        Boxes_BTNode<T> *getPkmn(Boxes_BTNode<T> *root, int countBox);

    public:
        Boxes_BT();
        void searchBox(unsigned short category, T data) { return searchBox(root, category, data); }
        void insert(T data) { insert(root, data); }
        void insertName(T data) { insertName(root, data); }
        void insertLevel(T data) { insertLevel(root, data); }
        void displayInOrder() { displayInOrder(root); }
        Boxes_BTNode<T> *getPkmn(int countBox) { return getPkmn(root, countBox); }

        template <typename T2> friend class PC_CircularLinkedList;
};

template <typename T>
Boxes_BT<T>::Boxes_BT()
{
    this->root = NULL;
    this->category = 0;
    this->size = 0;
}

template <typename T>
void Boxes_BT<T>::insert(Boxes_BTNode<T> *node, T data)
{
    count = 0;
    if (node == NULL) {
        root = node = new Boxes_BTNode<T>(data);
    } 
    else {
        if (data.number < node->data.number) {
            if (!node->left) {
                Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                node->left = tmp;
            }
            else {
                insert(node->left, data);
            } 
        }
        else if (data.number == node->data.number) {
            if (data.lvl < node->data.lvl) {
                if (!node->left) {
                    Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                    node->left = tmp;
                }
                else
                    insert(node->left, data);
            }
            else {
                if (!node->right) {
                    Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                    node->right = tmp;
                }
                else
                    insert(node->right, data);
            }
        }
        else {
            if(!node->right) {
                Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                node->right = tmp;
            }
            else {
                insert(node->right, data);
            }
        } 
    }  
}

template <typename T>
void Boxes_BT<T>::insertName(Boxes_BTNode<T> *node, T data)
{
    count = 0;
    if (node == NULL) {
        root = node = new Boxes_BTNode<T>(data);
    } 
    else {
        if (data.name < node->data.name) {
            if (!node->left) {
                Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                node->left = tmp;
            }
            else {
                insert(node->left, data);
            } 
        }
        else if (data.name == node->data.name) {
            if (data.lvl < node->data.lvl) {
                if (!node->left) {
                    Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                    node->left = tmp;
                }
                else
                    insert(node->left, data);
            }
            else {
                if (!node->right) {
                    Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                    node->right = tmp;
                }
                else
                    insert(node->right, data);
            }
        }
        else {
            if(!node->right) {
                Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                node->right = tmp;
            }
            else {
                insert(node->right, data);
            }
        } 
    }  
}

template <typename T>
void Boxes_BT<T>::insertLevel(Boxes_BTNode<T> *node, T data)
{
    count = 0;
    if (node == NULL) {
        root = node = new Boxes_BTNode<T>(data);
    } 
    else {
        if (data.lvl < node->data.lvl) {
            if (!node->left) {
                Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                node->left = tmp;
            }
            else {
                insert(node->left, data);
            } 
        }
        else if (data.lvl == node->data.lvl) {
            if (data.number < node->data.number) {
                if (!node->left) {
                    Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                    node->left = tmp;
                }
                else
                    insert(node->left, data);
            }
            else {
                if (!node->right) {
                    Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                    node->right = tmp;
                }
                else
                    insert(node->right, data);
            }
        }
        else {
            if(!node->right) {
                Boxes_BTNode<T> *tmp = new Boxes_BTNode<T>(data);
                node->right = tmp;
            }
            else {
                insert(node->right, data);
            }
        } 
    }  
}

template <typename T>
void Boxes_BT<T>::searchBox(Boxes_BTNode<T> *root, unsigned short category, T data)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (category == 0)
        {
            searchBox(root->left, category, data);
            if (root->data.number == data.number)
            {
                count++;
                cout << count << root->data << endl;
            }
            searchBox(root->right, category, data);
        }
        else if (category == 1)
        {
            searchBox(root->left, category, data);
            if (root->data.name == data.name)
            {
                count++;
                cout << count << root->data << endl;
            }
            searchBox(root->right, category, data);
        }
        else if (category == 2)
        {
            searchBox(root->left, category, data);
            if (root->data.lvl == data.lvl)
            {
                count++;
                cout << count << root->data << endl;
            }
            searchBox(root->right, category, data);
        }
        else {
            searchBox(root->left, category, data);
            if (root->data.type == data.type)
            {
                count++;
                cout << count << root->data << endl;
            }
            searchBox(root->right, category, data);
        }
    }
}

template <typename T>
void Boxes_BT<T>::displayInOrder(Boxes_BTNode<T> *root)
{
    if (root != NULL)
    {
        displayInOrder(root->left);
        count++;
        cout << count << root->data << endl;
        displayInOrder(root->right);
    }
}

template <typename T>
Boxes_BTNode<T> *Boxes_BT<T>::getPkmn(Boxes_BTNode<T> *root, int countBox)
{

    int countTemp = 1;
    // getPkmn(root->left, countBox);
    // if (countBox == countTemp) {
    //     return root;
    // }
    // ++countTemp;
    // getPkmn(root->right, countBox);
    // return root;

    stack<Boxes_BTNode<T> *> s;
    Boxes_BTNode<T> *tmp = root;
    while (tmp != NULL || s.empty() == false) {
        while (tmp != NULL) {
            s.push(tmp);
            tmp = tmp->left;
        }
        tmp = s.top();
        s.pop();
        if (countBox == countTemp) {
            break;
        }
        ++countTemp;
        tmp = tmp->right;
    }
    return tmp;
}

///////////////////// Circular Doubly-Linked List ///////////////////

template <typename T>
class PC_Node
{
    private:
        T data;
        PC_Node<T> *next;
        PC_Node<T> *prev;
    public:
        PC_Node(T data, PC_Node<T> *next = nullptr, PC_Node<T> *prev = nullptr); 
        template <typename T2> friend class PC_CircularLinkedList;
};

template <typename T>
PC_Node<T>::PC_Node(T data, PC_Node<T> *next, PC_Node<T> *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

template <typename T>
class PC_CircularLinkedList
{
    private:
        PC_Node<T> *start;
        PC_Node<T> *currentBox;
        unsigned int size;
        PC_Node<T> *gotoNode(unsigned int pos);
    public:
        PC_CircularLinkedList();
        void insert(T data, unsigned int pos = 0);
        void insertStart(T data);
        void insertEnd(T data);
        void insertInBox(Pokemon pkmn);
        void reorderBox(unsigned short category);
        void deleteBox();
        void displayAll();
        void displayNode();
        void searchAllBoxes(unsigned short category, Pokemon pkmn);
        void next();
        void prev();
};

template <typename T>
PC_CircularLinkedList<T>::PC_CircularLinkedList()
{
    this->start = NULL;
    this->currentBox = start;
    this->size = 0;
}

template <typename T>
PC_Node<T> *PC_CircularLinkedList<T>::gotoNode(unsigned int pos)
{
    int n = 1;
    int position = pos;
    PC_Node<T> *tmp = start;
    while (n != position)
    {
        tmp = tmp->next;
        n++;
    }
    return tmp;
}

template <typename T>
void PC_CircularLinkedList<T>::insertStart(T data)
{
    if (start == NULL)
    {
        PC_Node<T> *new_node = new PC_Node<T>(T{});
        new_node->data = data;
        new_node->next = new_node->prev = new_node;
        start = new_node;
        currentBox = start;
        ++(this->size);
        return;
    }
    PC_Node<T> *last = start->prev;
    PC_Node<T> *new_node = new PC_Node<T>(T{});
    new_node->data = data;
    new_node->next = start;
    new_node->prev = last;
    last->next = start->prev = new_node;
    start = new_node;
    currentBox = new_node;
    ++(this->size);
}

template <typename T>
void PC_CircularLinkedList<T>::insertEnd(T data)
{
    if (start == NULL)
    {
        PC_Node<T> *new_node = new PC_Node<T>(T{});
        new_node->data = data;
        new_node->next = new_node->prev = new_node;
        start = new_node;
        currentBox = start;
        ++(this->size);
        return;
    }
    PC_Node<T> *last = start->prev;
    PC_Node<T> *new_node = new PC_Node<T>(T{});
    new_node->data = data;
    new_node->next = start;
    start->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
    currentBox = new_node;
    ++(this->size);
}

template <typename T>
void PC_CircularLinkedList<T>::insert(T data, unsigned int pos)
{
    if (pos == 1)
    {
        insertStart(data);
        return;
    }
    PC_Node<T> *new_node = new PC_Node<T>(T{});
    PC_Node<T> *tmp = gotoNode(pos);
    PC_Node<T> *prev_node = tmp->prev;
    new_node->data = data;
    tmp->prev = new_node;
    new_node->next = tmp;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    currentBox = new_node;
    ++(this->size);
}

template <typename T>
void PC_CircularLinkedList<T>::insertInBox(Pokemon pkmn)
{
    currentBox->data.size++;
    if (currentBox->data.category == 0) {
        currentBox->data.insert(pkmn);    
    }
    if (currentBox->data.category == 1) {
        currentBox->data.insertName(pkmn);
    }
    if (currentBox->data.category == 2) {
        currentBox->data.insertLevel(pkmn);
    }
}

/////////////////////// reorder box /////////////////////////
template <typename T>
void PC_CircularLinkedList<T>::reorderBox(unsigned short category)
{
    currentBox->data.category = category;
    PC_Node<T> *unsortedBox = currentBox;

    // Find position of currentBox
    PC_Node<T> *tmp = start;
    unsigned int pos = 1;
    while (tmp != currentBox) {
        pos++;
        tmp = tmp->next;
    }

    //create new box
    Boxes_BT<Pokemon> *newBox = new Boxes_BT<Pokemon>();
    insert(*newBox, pos);

    currentBox->data.category = category;
    int boxSize = unsortedBox->data.size;
    while (boxSize != 0) {
        unsortedBox->data.category = category;
        insertInBox((unsortedBox->data.getPkmn(boxSize))->data);
        --boxSize;
    }
    deleteBox();
}

template <typename T>
void PC_CircularLinkedList<T>::deleteBox()
{
    PC_Node<T> *prev = currentBox;
    PC_Node<T> *curr = currentBox->next;

    if (start == NULL) {
        return;
    }
    if (curr->next == start && prev == NULL) {
        start = NULL;
        free(curr);
        return;
    }
    if (curr == start) { 
        prev = start->prev; 
        start = start->next;  
        prev->next = start; 
        start->prev = prev; 
        free(curr); 
    } 
    else if (curr->next == start) {  
        prev->next = start; 
        start->prev = prev; 
        free(curr); 
    } 
    else { 
        PC_Node<T> *tmp = curr->next;  
        prev->next = tmp; 
        tmp->prev = prev; 
        free(curr); 
    }
}

template <typename T>
void PC_CircularLinkedList<T>::displayAll()
{
    count = 0;
    PC_Node<T> *tmp;
    if (start == NULL)
    {
        return;
    }
    else
    {
        tmp = start;
        while (tmp->next != start)
        {
            tmp->data.displayInOrder();
            tmp = tmp->next;
            cout << endl;
            count = 0;
        }
        tmp->data.displayInOrder();
        cout << endl;
    }
}

template <typename T>
void PC_CircularLinkedList<T>::displayNode()
{
    count = 0;
    PC_Node<T> *tmp = currentBox;
    if(tmp != NULL)
    {
        // cout << "category: " << currentBox->data.category << endl;
        tmp->data.displayInOrder();
    }
}

template <typename T>
void PC_CircularLinkedList<T>::searchAllBoxes(unsigned short category, Pokemon pkmn)
{
    count = 0;
    PC_Node<T> *tmp = start;
    while (tmp->next != start)
    {
        tmp->data.searchBox(category, pkmn);
        tmp = tmp->next;
    }
    tmp->data.searchBox(category, pkmn);
}

template <typename T>
void PC_CircularLinkedList<T>::next()
{
    count = 0;
    currentBox = currentBox->next;
}

template <typename T>
void PC_CircularLinkedList<T>::prev()
{
    count = 0;
    currentBox = currentBox->prev;
}


#endif