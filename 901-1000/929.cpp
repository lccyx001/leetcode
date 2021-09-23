#include <vector>

#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

string checkEmail(string email)
{
    string prefix = "", suffix = "";
    prefix = email.substr(0, email.find_last_of("@"));
    prefix = prefix.substr(0, prefix.find_first_of("+"));
    suffix = email.substr(email.find_last_of("@") + 1);
    while (prefix.find(".") != string::npos)
    {
        prefix.replace(prefix.find("."), 1, "");
    }
    return prefix + "@" + suffix;
}

int numUniqueEmails(vector<string> &emails)
{
    unordered_set<string> ss;
    for (auto &e : emails)
    {
        string s = checkEmail(e);
        cout << s << endl;
        ss.insert(s);
    }

    return ss.size();
}

int main()
{
    vector<string> v;
    v.push_back("fg.r.u.uzj+o.pw@kziczvh.com");
    v.push_back("r.cyo.g+d.h+b.ja@tgsg.z.com");
    v.push_back("fg.r.u.uzj+o.f.d@kziczvh.com");
    v.push_back("fg.r.u.uzj+lp.k@kziczvh.com");
    v.push_back("r.cyo.g+n.h.e+n.g@tgsg.z.com");
    v.push_back("fg.r.u.uzj+k+p.j@kziczvh.com");
    v.push_back("fg.r.u.uzj+w.y+b@kziczvh.com");
    v.push_back("r.cyo.g+x+d.c+f.t@tgsg.z.com");
    v.push_back("r.cyo.g+x+t.y.l.i@tgsg.z.com");
    v.push_back("r.cyo.g+brxxi@tgsg.z.com");
    v.push_back("r.cyo.g+z+dr.k.u@tgsg.z.com");

    v.push_back("r.cyo.g+d+l.c.n+g@tgsg.z.com");
    v.push_back("fg.r.u.uzj+vq.o@kziczvh.com");
    v.push_back("fg.r.u.uzj+uzq@kziczvh.com");
    v.push_back("fg.r.u.uzj+mvz@kziczvh.com");
    v.push_back("fg.r.u.uzj+taj@kziczvh.com");
    v.push_back("fg.r.u.uzj+fek@kziczvh.com");

    cout << numUniqueEmails(v);

    return 0;
}