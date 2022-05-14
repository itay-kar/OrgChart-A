#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <memory>

using namespace std;

namespace ariel
{
    enum class Iter_Type
    {
        LEVEL,
        REVERSE,
        PREORDER
    };

    class OrgChart
    {
        // Inner class node;
        class Node
        {
            string name;

        public:
            Node(){};
            Node(string str);
            void add_father(Node *node);
            void add_children(Node *node);
            string get_data();
            void set_data(string str);
            vector<Node *> get_children();
            friend ostream &operator<<(ostream &os, Node &node)
            {
                os << node.name;
                return os;
            };
        };
    

    public:
        class Iterator;
        OrgChart() {};
        OrgChart &add_root(string name);
        OrgChart &add_sub(string name, string name2);
        friend ostream &operator<<(ostream &os, const OrgChart &org);

        Iterator begin();
        Iterator end();
        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        class Iterator
        {
            string empty = "";
                    
        public:
            Iterator(){};
            Iterator(Node *node);
            Iterator(Node *root, Iter_Type type);
            ~Iterator(){};
            string operator*();
            friend bool operator!=(const Iterator &a, const Iterator &b);
            Iterator &operator++();
            Iterator &operator++(int);
            string *operator->();
            int size();
        };
    };

};