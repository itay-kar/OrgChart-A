#include "OrgChart.hpp"
using namespace ariel;

#include "doctest.h"

TEST_CASE("Small org\family")
{
    OrgChart org;
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "ZTF"));
    CHECK_NOTHROW(org.add_sub("CEO", "OPE"));
    CHECK_NOTHROW(org.add_sub("CEO", "MAL"));
    CHECK_NOTHROW(org.add_sub("ZTF", "MOG"));
    CHECK_NOTHROW(org.add_sub("MAL", "FER"));

    vector<string> names = {"CEO", "ZTF", "OPE", "MAL", "MOG", "FER"};
    vector<string> reverse_names = {"MOG", "FER", "ZTF", "OPE", "MAL", "CEO"};

    size_t i = 0;
    for (auto it = org.begin_level_order(); it != org.end_level_order(); it++)
    {
        cout << *it << endl;
        CHECK_EQ((*it), names[i++]);
    }

    cout << " Finished loop 1" << endl;
    i = 0 ;
    for (auto it = org.begin_reverse_order(); it != org.reverse_order(); it++)
    {
        cout << *it << endl;
        CHECK_EQ((*it), reverse_names[i++]);
    }

    CHECK_NOTHROW(org.add_root("CFO"));
    // Mos was never in the orgchart
    CHECK_THROWS(org.add_sub("MOS", "RON"));
    // ceo is deleted from org chart when root changed
    CHECK_THROWS(org.add_sub("CEO", "RON"));

    OrgChart::Iterator iter = org.begin_preorder();

    CHECK_NE((*iter), "CEO");
    CHECK_EQ((*iter), "CFO");

    CHECK_NOTHROW(iter++);
    CHECK_NOTHROW(cout << *iter);

    string a = "Moshe";
    string b = "Rami";
    OrgChart org_b;
    org_b.add_root(a);
    // a family tree where every son is called Moshe or Rami.
    for (size_t i = 0; i < 100; i++)
    {
        string temp = a;
        a = b;
        b = temp;

        CHECK_NOTHROW(org_b.add_sub(b, a));
    }
}
