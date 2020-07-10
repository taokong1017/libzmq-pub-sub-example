#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Please input one argument. (number of subscriber)" << std::endl;
        return 0;
    }
    else
    {
        int n = std::stoi(argv[1]);
        if (n <= 0)
        {
            std::cout << "number of subscribers should be greater than 0" << std::endl;
            return 0;
        }
        system("dbus-launch gnome-terminal -- \"./publisher\"");
        for(int i = 0; i < n; i++)
            system("dbus-launch gnome-terminal -- \"./subscriber\"");
    }
}
