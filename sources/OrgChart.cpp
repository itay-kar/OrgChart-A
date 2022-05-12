#include "OrgChart.hpp"
using namespace ariel;

namespace ariel
{
    OrgChart &OrgChart::add_root(string name)
    {
        if (root == nullptr)
        {
            root = new Node(name);
        }
        else
        {
            Node *temp = new Node(name);
            temp->set_children(root->get_children());
            root = temp;
        }
        return *this;
    };
    OrgChart &OrgChart::add_sub(string name, string name2) { return *this; };
    ostream &operator<<(ostream &os, const OrgChart &org) { return os; };

    OrgChart::Iterator OrgChart::begin_level_order() { return Iterator(); };
    OrgChart::Iterator OrgChart::end_level_order() { return Iterator(); };
    OrgChart::Iterator OrgChart::begin_reverse_order() { return Iterator(); };
    OrgChart::Iterator OrgChart::reverse_order() { return Iterator(); };
    OrgChart::Iterator OrgChart::begin_preorder() { return Iterator(); };
    OrgChart::Iterator OrgChart::end_preorder() { return Iterator(); };

    // --------------- Iterator Functions ----- //

    bool operator!=(OrgChart::Iterator a, OrgChart::Iterator b) { return false; };
    OrgChart::Iterator &OrgChart::Iterator::operator++() { return *this; };
    OrgChart::Iterator &OrgChart::Iterator::operator++(int) { return *this; };
    OrgChart::Iterator *OrgChart::Iterator::operator->() { return this; };
    string OrgChart::Iterator::operator*() { return ""; };
    int OrgChart::Iterator::size() { return 0; };

    // ------------- Node Functions ----------- //

    void OrgChart::Node::set_children(vector<Node *> childrens) { this->childrens = childrens; };

    vector<OrgChart::Node *> OrgChart::Node::get_children() { return childrens; };

};
