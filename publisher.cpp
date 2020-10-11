#include <iostream>
#include <zmq.h>
#include <cassert>
#include <unistd.h>

int main(int argc, char** argv)
{
    std::cout << "ZMQ Publiser using libzmq" << std::endl;

    void *ctx = zmq_ctx_new(); // create context
    void *pub = zmq_socket(ctx, ZMQ_PUB); // create a socket that publishes
    int rc = zmq_bind(pub, "tcp://*:5570"); // binds the rep tcp socket to an address and to port 5570
    assert(rc == 0); // bind should return non zero

    for(;;)
    {
        std::string str;
        str = "msg" + std::to_string(rand() % 10000); // publish msg0 up to msg9999
        std::cout << "Publishing " << str << std::endl;
        zmq_send(pub, str.c_str(), str.length(), 0);
        sleep(1);
    }

    return 0;
}
