#include <iostream>
#include <memory>
#include <string>
using namespace std;

// represents what we are connecting to
struct destination
{
    static unsigned counter;
    // members for realism purposes
    string destName;
    unsigned destId;
    // default constructor
    destination(string dN = "", unsigned dI = counter) : destName(dN), destId(dI) { ++counter; }
};

// information needed to use the connection
struct connection
{
    // pointer to destination
    destination *conToDest;
    // non-default constructor
    connection(destination *dest) : conToDest(dest) {}
};

connection connect(destination *dest); // open the connection
void disconnect(connection p);         // close the given connection

void f(destination &dest);
void end_connection(connection *p) { disconnect(*p); }

unsigned destination::counter = 0;
int main(void)
{
    destination obj("Internet"), obj2("Cloud");
    f(obj);
    f(obj2);
    return 0;
}

void f(destination &dest)
{
    // get a connection; must remember to close it when done
    connection c = connect(&dest);
    shared_ptr<connection> p(&c, end_connection);
    // use the connection
    cout << "Using connection: " << p->conToDest->destName << ", id: "
         << p->conToDest->destId << endl;
}

connection connect(destination *dest)
{
    // return a connection object
    return connection(dest);
}

void disconnect(connection p)
{
    cout << "Disconnecting from: " << p.conToDest->destName << ", id: "
         << p.conToDest->destId << endl;
}
