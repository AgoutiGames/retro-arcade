#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Snake : public GameCharacter {
    public:
        Snake(salmon::ActorRef actor, GameScene* scene);
        virtual Snake* create(salmon::ActorRef actor, GameScene* scene) const override {return new Snake(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        void step();

        static const char* type;
    protected:
        // Add members here
        salmon::Direction m_dir = salmon::Direction::none;

        // Relevant to head only
        salmon::Direction m_next_dir = salmon::Direction::none;

        Snake* m_to_head = nullptr;
        Snake* m_to_tail = nullptr;

    private:
        void init_dir(salmon::Direction dir) {m_dir = dir; m_next_dir = dir;}

        void set_next_head(Snake* head) {m_to_head = head;}
        void drag_tail(salmon::Direction dir, bool grow = true);

        static const bool good;
};


#endif // SNAKE_HPP_INCLUDED
