
//
//  main.cpp
//  HqOatppDemo
//
//  Created by hehuiqi on 2022/6/17.
//

// 使用前需要先编译安装 
// #include "include/oatpp/web/server/HttpConnectionHandler.hpp"
// #include "include/oatpp/network/Server.hpp"
// #include "include/oatpp/network/tcp/server/ConnectionProvider.hpp"

// 直接使用源码中的头文件
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

/**
 * Custom Request Handler
 */
class Handler : public oatpp::web::server::HttpRequestHandler {
public:
    /**
     * Handle incoming request and return outgoing response.
     */
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
        return ResponseFactory::createResponse(Status::CODE_200, "Hello World!");
    }
    
};

void run() {
    
    /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();
    
    /* Route GET - "/hello" requests to Handler */
    router->route("GET", "/hello", std::make_shared<Handler>());
    
    /* Create HTTP connection handler with router */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
    
    /* Create TCP connection provider */
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 8000, oatpp::network::Address::IP_4});
    
    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
//    oatpp::network::Server server(connectionProvider, connectionHandler);
    oatpp::network::Server server = oatpp::network::Server(connectionProvider, connectionHandler);
    
    /* Priny info about server port */
    OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());
    //Vist http://localhost:8000/hello
    
    /* Run server */
    server.run();
}

int main() {
    
    /* Init oatpp Environment */
    oatpp::base::Environment::init();
    
    /* Run App */
    run();
    
    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();
    
    return 0;
    
}

