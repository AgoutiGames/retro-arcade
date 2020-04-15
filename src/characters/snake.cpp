#include "characters/snake.hpp"

#include "core/game_scene.hpp"
#include "scenes/snake_arena.hpp"

#include "collision_ref.hpp"

#include <iostream>

const char* Snake::type = "Snake";
const bool Snake::good = GameCharacter::register_class<Snake>(Snake::type);

Snake::Snake(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Snake::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    if(m_to_head == nullptr && m_to_tail == nullptr) {
        init_dir(salmon::Direction::right);
        m_to_tail = static_cast<Snake*>(m_scene->add_character("Snake", get_layer()));
        if(m_to_tail == nullptr) {
            std::cerr << "Failed to initalize snake tail!\n";
        }
        m_to_tail->set_next_head(this);
        m_to_tail->init_dir(salmon::Direction::right);
        m_to_tail->move_absolute(get_x() - SnakeArena::grid_size,get_y());
    }
    // Clear data accessed via put
    get_data().clear();
}

void Snake::update() {
    // Add character logic here
    if(m_to_head == nullptr) {
        for(salmon::CollisionRef c : get_collisions()) {
            std::cout << "Snake collided and should die now!!\n";
        }

        salmon::InputCacheRef input = m_scene->get_input_cache();
        if(input.just_pressed("Left") && m_dir != salmon::Direction::right) {
            m_next_dir = salmon::Direction::left;
        }
        else if(input.just_pressed("Right") && m_dir != salmon::Direction::left) {
            m_next_dir = salmon::Direction::right;
        }
        else if(input.just_pressed("Up") && m_dir != salmon::Direction::down) {
            m_next_dir = salmon::Direction::up;
        }
        else if(input.just_pressed("Down") && m_dir != salmon::Direction::up) {
            m_next_dir = salmon::Direction::down;
        }
    }

    if(m_to_tail == nullptr) {
       animate("Tail");
    }
    if(m_to_head != nullptr && m_to_tail != nullptr) {
        animate("Body");
    }

    std::cout << get_name() << ": x:" << get_x() << " y:" << get_y() << "\n";

}

void Snake::drag_tail(salmon::Direction dir, bool grow) {
    switch(dir) {
        case salmon::Direction::right : {
            move_relative(SnakeArena::grid_size,0);
            break;
        }
        case salmon::Direction::left : {
            move_relative(-SnakeArena::grid_size,0);
            break;
        }
        case salmon::Direction::up : {
            move_relative(0,-SnakeArena::grid_size);
            break;
        }
        case salmon::Direction::down : {
            move_relative(0,SnakeArena::grid_size);
            break;
        }
        default: {
            std::cerr << "Wrong direction of snake head!\n";
            return;
        }

    }

    if(m_to_tail != nullptr) {
        m_to_tail->drag_tail(m_dir);
    }
    else if(grow) {
        m_to_tail = static_cast<Snake*>(m_scene->add_character("Snake", get_layer()));
        if(m_to_tail == nullptr) {
            std::cerr << "Failed to generate new snake tail!\n";
        }
        m_to_tail->set_next_head(this);
        m_to_tail->init_dir(dir);
        switch(dir) {
            case salmon::Direction::right : {
                m_to_tail->move_absolute(get_x() - SnakeArena::grid_size,get_y());
                break;
            }
            case salmon::Direction::left : {
                m_to_tail->move_absolute(get_x() + SnakeArena::grid_size,get_y());
                break;
            }
            case salmon::Direction::up : {
                m_to_tail->move_absolute(get_x(),get_y() + SnakeArena::grid_size);
                break;
            }
            case salmon::Direction::down : {
                m_to_tail->move_absolute(get_x(),get_y() - SnakeArena::grid_size);
                break;
            }
            default: {
                std::cerr << "Wrong direction of snake head!\n";
                return;
            }
        }
    }
    m_dir = dir;
}

void Snake::step() {
    drag_tail(m_next_dir);
}
