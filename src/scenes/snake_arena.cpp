#include "scenes/snake_arena.hpp"

#include "core/scene_manager.hpp"

#include <iostream>

#include "characters/snake.hpp"

const char* SnakeArena::type = "SnakeArena";
const bool SnakeArena::good = GameScene::register_class<SnakeArena>(SnakeArena::type);

SnakeArena::SnakeArena(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void SnakeArena::init() {
    m_scene_manager->set_game_resolution(200,200);
    m_scene_manager->set_window_size(800,800);
    // Initializes all characters in scene
    GameScene::init();
    // Setup member vars here | example: put(m_speed, "m_speed");
    m_player = static_cast<Snake*>(get_character_by_name("Player"));
    if(m_player == nullptr) {
        std::cerr << "Couldn't find player!\n";
    }
    // Clear data accessed via put
    get_data().clear();
}

void SnakeArena::update() {
    // Just close when pressing escape
    salmon::InputCacheRef input = get_input_cache();
    if(input.just_pressed("Escape")) {
        m_scene_manager->shutdown();
    }

    // Add scene logic here
    m_next_move += get_delta_time();
    if(m_next_move >= m_move_speed) {
        m_player->step();
        m_next_move -= m_move_speed;
    }
    // Calls update on all characters in scene
    GameScene::update();
}
