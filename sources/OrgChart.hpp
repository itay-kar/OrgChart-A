#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

namespace ariel
{
    class OrgChart
    {

        class Node
        {
            string str;
            vector<Node *> childrens;
            Node *Papa;

        public:
            Node(){};
            Node(string str){};
            Node &add_father();
            Node &add_children();
            string get_data();
            Node *get_papa();
            void set_children(vector<Node *> childrens);
            vector<Node *> get_children();
        };

    private:
        Node *root;

    public:
        class Iterator;
        OrgChart(){root = nullptr;};
        OrgChart &add_root(string name);
        OrgChart &add_sub(string name, string name2);
        friend ostream &operator<<(ostream &os, const OrgChart &org);

        auto begin() { return begin_level_order(); };
        auto end() { return end_level_order(); };
        
            Iterator
            begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        class Iterator
        {
        public:
            Iterator(){};
            string operator*();
            friend bool operator!=(Iterator a, Iterator b);
            Iterator &operator++();
            Iterator &operator++(int);
            Iterator *operator->();
            int size();
        };
    };

};