#ifndef SNAKE_ARENA_HPP_INCLUDED
#define SNAKE_ARENA_HPP_INCLUDED

#include "core/game_scene.hpp"

class SceneManager;
class Snake;

class SnakeArena : public GameScene {
    public:
        SnakeArena(salmon::MapRef map, SceneManager* scene_manager);
        SnakeArena* create(salmon::MapRef map, SceneManager* scene_manager) const override {return new SnakeArena(map,scene_manager);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        static const char* type;

        static const int grid_size = 8;
    protected:
        // Add members here
        float m_next_move = 0;
        float m_move_speed = 1; // Move n tiles per second

        Snake* m_player = nullptr;

    private:
        static const bool good;
};

#endif // SNAKE_ARENA_HPP_INCLUDED
