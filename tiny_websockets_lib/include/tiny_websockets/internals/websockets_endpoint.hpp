#pragma once

#include <tiny_websockets/internals/ws_common.hpp>
#include <tiny_websockets/network/tcp_client.hpp>
#include <tiny_websockets/internals/data_frame.hpp>
#include <tiny_websockets/message.hpp>

namespace websockets { namespace internals {
    class WebsocketsEndpoint {
    public:
        WebsocketsEndpoint(network::TcpClient& socket);
        bool poll();
        WebsocketsMessage recv();
        bool send(const char* data, size_t len, uint8_t opcode, bool fin = true, bool mask = false, uint8_t maskingKey[4] = nullptr);    
        bool send(WSString data, uint8_t opcode, bool fin = true, bool mask = false, uint8_t maskingKey[4] = nullptr);    
        
        bool ping(WSString msg = "");
        bool pong(WSString msg = "");
        void close();
        virtual ~WebsocketsEndpoint();
    private:
        network::TcpClient& _client;
        WebsocketsFrame _recv();

        void handleMessageInternally(WebsocketsMessage& msg);
    };
}} // websockets::internals