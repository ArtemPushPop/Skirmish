#include "PlayerEvent.h"
#include <iostream>
#include "ConnectionClient.h"

int main(){
    Client::ConnectionClient cc;
    cc.setSnapshotRecieveCallback([](const std::string &s){std::cout << s;});

    int ev;
    while(std::cin >> ev){
        switch (ev) {
            case 1: cc.registerPlayer(); break;
            case 2: {// move
                int type;
                std::cin >> type;
                ClientServer::MoveEvent ev_send{type};
                cc.sendEvent(ev_send);
                break;
            }
            case 3: {// shoot
                float x, y;
                int weapon;
                std::cin >> x >> y >> weapon;
                ClientServer::ShootEvent ev_send{x, y, weapon};

                char* data = reinterpret_cast<char*>(&ev_send);
                std::string request = (std::string() + (char)ClientServer::Type::tShoot).append(data, sizeof(ev_send));
                const ClientServer::ShootEvent
                    *event = reinterpret_cast<const ClientServer::ShootEvent *>(request.data() + 1);

                cc.sendEvent(ev_send);
                break;
            }
            case 4:
                cc.sendEvent();
                break;
            default:break;
        }
    }
    return 0;
}