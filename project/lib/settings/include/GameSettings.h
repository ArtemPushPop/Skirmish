#pragma once

#include <string>

// main game parameters
const int game_tick = 10; // miliseconds
const float physics_tick = static_cast<double>(game_tick) / 1000;   // meters per second -> meters per 10 milliseconds
const float bullet_speed = 400;    // meters per seconds
const float player_speed = 50;     // meters per seconds
const float default_player_radius = 1;
const float default_bullet_radius = 0.4;
const float default_spawn_x = 0;
const float default_spawn_y = 0;
const float default_spawn_vx = 0;
const float default_spawn_vy = 0;

// main game parameters

// client server settings
const std::string host_server = "127.0.0.1";
const std::string port_server = "5000";
const size_t default_client_port = 5001;
const int udp_size = 65527;

const int max_transfer_event_bytes = 40;
// client server settings

//map size 2000

// textures settings
const float size_of_player = default_player_radius;
const float size_of_bullet = default_bullet_radius;
const size_t textures_num = 8;

// textures settings

// map settings
const size_t map_size = 2000;
// map settings
