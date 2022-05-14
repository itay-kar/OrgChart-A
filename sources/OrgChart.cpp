#include "OrgChart.hpp"
using namespace ariel;

namespace ariel
{
    OrgChart::Node::Node(string str) : name(str){};

    OrgChart &OrgChart::add_root(string name)
    {
        return *this;
    };
    OrgChart &OrgChart::add_sub(string name, string name2)
    {
        return *this;
    };

    ostream &operator<<(ostream &os, const OrgChart &org) { return os; };
    OrgChart::Iterator OrgChart::begin() { return Iterator(); };
    OrgChart::Iterator OrgChart::end() { return Iterator(nullptr); };
    OrgChart::Iterator OrgChart::begin_level_order() { return Iterator(); };
    OrgChart::Iterator OrgChart::end_level_order() { return Iterator(nullptr); };
    OrgChart::Iterator OrgChart::begin_reverse_order() { return Iterator(); };
    OrgChart::Iterator OrgChart::reverse_order() { return Iterator(nullptr); };
    OrgChart::Iterator OrgChart::begin_preorder() { return Iterator(); };
    OrgChart::Iterator OrgChart::end_preorder() { return Iterator(nullptr); };

    // --------------- Iterator Functions ----- //

    OrgChart::Iterator::Iterator(Node *node){};

    OrgChart::Iterator::Iterator(Node *root, Iter_Type type){};

    bool operator!=(const OrgChart::Iterator &a, const OrgChart::Iterator &b)
    {
        return false;
    };

    OrgChart::Iterator &OrgChart::Iterator::operator++()
    {
        return *this;
    };

    OrgChart::Iterator &OrgChart::Iterator::operator++(int)
    {
        return *this;
    };

    string *OrgChart::Iterator::operator->() { return &empty; };
    string OrgChart::Iterator::operator*() { return ""; };
    int OrgChart::Iterator::size() { return 0; };

};
