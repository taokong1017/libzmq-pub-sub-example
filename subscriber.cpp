#include <zmq.h>
#include <string>
#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "ZMQ Subscriber using libzmq" << std::endl;
    std::string pattern;
    std::cout << "Enter a pattern to subscribe to: [msg0 -> msg9999] " << std::endl;
    std::cin >> pattern;
    void *ctx = zmq_ctx_new();
    void *sub = zmq_socket(ctx, ZMQ_SUB);
    zmq_connect(sub, "tcp://localhost:5570");
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, pattern.c_str(), pattern.length()); // subscribe to pattern specified

    for(;;)
    {
        char buffer[10];
        zmq_recv(sub, buffer, 10, 0);
        std::cout << "Received from server: " << buffer << std::endl;
        sleep(1);
    }

    zmq_close(sub);
    zmq_ctx_destroy(ctx);

    return 0;
}
