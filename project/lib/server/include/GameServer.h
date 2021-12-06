#pragma once

#include "GameLoop.h"
#include "ConnectionServer.h"
#include "GlobalEnvironment.h"

#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace Server {

    class GameServer{
    public:
        GameServer();
        void run();
    private:
        void initializeGE();
        std::string requestHandler(const std::string &request);

        /// соответствие игровой сущности игрока и адреса с которого поступил реквест.
        std::vector<int> dkkd;
        GameEntities::GlobalEnvironment _ge;
    };

} // namespace Server