#include <iostream>
#include <string>
#include <set>
using namespace std;

class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

public:
    // folders is implicitly initialized to the empty set
    explicit Message(const string &str = "") : contents(str) {}
    // copy control to manage pointers to this Message
    Message(const Message &);            // copy constructor
    Message &operator=(const Message &); // copy assignment
    ~Message();                          // destructor
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);

    void printM() { cout << contents << endl; }
    void folderList();

    void addFldr(Folder *);
    void remFldr(Folder *);

private:
    string contents;       // actual message text
    set<Folder *> folders; // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message &);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};

class Folder
{
public:
    Folder() = default;     // default constructor
    Folder(const Folder &); // copy constructor

    ~Folder(); // destructor

    void save(Message &);
    void remove(Message &);

    void addMsg(Message *);
    void remMsg(Message *);
    void print();

private:
    set<Message *> messages; // messages in this folder
};

void swap(Message &lhs, Message &rhs);
int main(void)
{
    Folder f1, f3;
    Message m1("Legend of the Witcher"), m2("Lord of the Rings"),
        m3("Malazan Book of the Fallen fans protest");
    m1.save(f1);
    m2.save(f1);
    m2.save(f3);
    m3.save(f1);

    cout << "Folder 1:" << endl;
    f1.print();
    Folder f2(f1);
    m1.remove(f1);
    // f1.print();

    m2.folderList();
    m1.folderList();

    m2.remove(f2);
    m2.folderList();

    f2.save(m2);
    m2.folderList();
    cout << "\nFolder 2:" << endl;
    f2.print();
    return 0;
}

// new Message members
void Message::addFldr(Folder *f)
{
    folders.insert(f);
}

void Message::remFldr(Folder *f)
{
    folders.erase(f);
}

///////////////////////////////////////////////////////////////////////////////
// new Folder members
void Folder::save(Message &m)
{
    messages.insert(&m); // add the given message to our list of Messages
    m.addFldr(this);     // add this Folder to m's set of Folders
}
void Folder::remove(Message &m)
{
    messages.erase(&m); // take the given message out of our list of Messages
    m.remFldr(this);    // remove this Folder from m's set of Folders
}

// update the messages member
Folder::Folder(const Folder &f) : messages(f.messages)
{
    // then add this folder to the 'folders' member of each message that is
    // in this folder
    for (auto &m : f.messages)
    {
        m->folders.insert(this);
    }
}

Folder::~Folder()
{
    cout << "Folder destructor: " << this << endl;
    // delete this folder from the 'folders' member of each message that is in
    // this folder
    for (auto &m : messages)
    {
        m->folders.erase(this);
    }
}

void Folder::print()
{
    for (const auto &m : messages)
    {
        m->printM();
    }
}

void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    messages.erase(m);
}
//////////////////////////////////////////////////////////////////////////////
void Message::folderList()
{
    cout << "Message is in " << folders.size() << " folders: ";
    for (const auto &f : folders)
    {
        cout << f << " ";
    }
    cout << endl;
}

void Message::save(Folder &f)
{
    folders.insert(&f); // add the given Folder to our list of Folders
    f.addMsg(this);     // add this Message to f's set of Messages
}
void Message::remove(Folder &f)
{
    folders.erase(&f); // take the given Folder out of our list of Folders
    f.remMsg(this);    // remove this Message to f's set of Messages
}

// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders) // for each Folder that holds m
        f->addMsg(this);     // add a pointer to this Message to that Folder
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); // add this Message to the Folders that point to m
}

// remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
    for (auto f : folders) // for each pointer in folders
        f->remMsg(this);   // remove this Message from that Folder
}

Message::~Message()
{
    cout << "Message destructor" << endl;
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();   // update existing Folders
    contents = rhs.contents; // copy message contents from rhs
    folders = rhs.folders;   // copy Folder pointers from rhs
    add_to_Folders(rhs);     // add this Message to those Folders
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap; // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);   // uses swap(set&, set&)
    swap(lhs.contents, rhs.contents); // swap(string&, string&)
    // add pointers to each Message to their (new) respective Folders
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}