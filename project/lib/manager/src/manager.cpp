#include "manager.hpp"

void GameManager::Run() {
    GameEntities::GlobalEnvironment ge;
    Client::ConnectionClient cc;
    cc.setSnapshotRecieveCallback([&ge](std::string &&s){ge.handleServerResponse(std::move(s));});

    Menu menu(&window, frames);
    EventManager command(window.imageList[Tile::GAME_CURSOR]);
    size_t player_id = cc.registerPlayer();
    Camera camera(&window, player_id);
    fps.SetInverseTimer(inverseTimeSeconds);
    fps.Set(frames);

    menu.Load();
    window.SetCursor(window.textures.textureImageMap[Tile::GAME_CURSOR]);
    fps.SetInverseTimer(inverseTimeSeconds);
    while (!command.HandleEvents(cc)) {
        if (fps.Update() >= 1) {
            window.ClearSurface();
            inverseTimeSeconds = fps.InverseTimeCheck();
            if (inverseTimeSeconds > 0)
                menu.InverseTimer(inverseTimeSeconds);
            camera.Update(ge.getPlayers(), ge.getBullets());
            window.Render();
            fps.Release();
        }
    }
}