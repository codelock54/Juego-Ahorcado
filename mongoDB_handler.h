#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"

void()
{
    mongo::DBClientConnection c;
    c.connect("localhost");
}

int main()
{
    try
    {
        run();
        std::cout << "connected ok" << std::endl;
    }
    catch (const mongo::DBException &e)
    {
        std::cout << "caught" < < e.what() << std::endl;
    }
    return (0);
}

