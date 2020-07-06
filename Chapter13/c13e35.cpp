#include <iostream>
using namespace std;

// If we used synthesized versions of copy-control members, then it would not
// be possible to correctly update the Folder objects
// Each time we copy or assign a Message, we need to update the Folder's object
// set<Message *> member, and this is not a part of synthesized copy-control
// members behaviour

int main(void)
{
    return 0;
}