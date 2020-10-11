#include <iostream>
#include <string>
#include <unistd.h>
#include <zmq.h>

int main(int argc, char** argv)
{
    std::cout << "ZMQ Subscriber using libzmq" << std::endl;
    std::string pattern = "msg";
    void* ctx = zmq_ctx_new();
    void* sub = zmq_socket(ctx, ZMQ_SUB);

    zmq_connect(sub, "tcp://localhost:5570");
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, pattern.c_str(),
        pattern.length()); // subscribe to pattern specified

    for (;;) {
        char buffer[10];
        zmq_recv(sub, buffer, 10, 0);
        std::cout << "Received from server: " << buffer << std::endl;
    }

    zmq_close(sub);
    zmq_ctx_destroy(ctx);

    return 0;
}
