#include <future>
#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Please input one argument. (number of subscriber)"
                  << std::endl;
        return 0;
    } else {
        int n = std::stoi(argv[1]);
        if (n <= 0) {
            std::cout << "number of subscribers should be greater than 0"
                      << std::endl;
            return 0;
        }

        std::vector<std::future<void>> fv;
        fv.push_back(std::async(std::launch::async, [] { system("./publisher"); }));
        for (int i = 0; i < n; i++)
            fv.push_back(
                std::async(std::launch::async, [] { system("./subscriber"); }));

        for (auto& f : fv)
            f.wait();
    }
}
