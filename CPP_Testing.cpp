
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <variant>


class Freezable
{
      
    public:
        std::string m_name;
        std::pair<int, int > m_position;
        bool m_frozen;
        bool m_move_forward;
    protected:
        std::deque <void (Freezable::*)(bool) > m_actions;
    public:
        void exec_actions(bool forward)
        {
            if (forward)
            {
                for (int i = 0; i < m_actions.size(); i++)
                {
                    std::invoke(m_actions[i], this, true);
                }
            }
            else
            {
                for (int i = m_actions.size()-1; i >= 0; i--)
                {
                    std::invoke(m_actions[i], this, false);
                }
            }

        }


        void jump(bool forward)
        {
            std::cout << "jump " << std::endl;
        }

        void jump_wrap()
        {
            m_actions.push_back(&Freezable::jump);
            jump(true);
        }
        
        Freezable(std::string name, int x = 0, int y = 0)
        {
            m_name = name;
            m_position = std::pair<int, int>(x, y);
            m_actions = std::deque <void (Freezable::*)(bool)>();
            m_frozen = false;
            m_move_forward = true;
        }

};

class chandelier: public Freezable
{           
    public:

        chandelier(std::string name, int x = 0, int y = 0)
            :Freezable(name,x,y)
        {}
    private:
        void fall(bool forward)
        {
            m_position.first = 10;
            m_position.second = 10;
            std::cout << "fell" << std::endl;

        }

    public:
        void fall_wrap()
        {
            m_actions.push_back(static_cast<void (Freezable::*)(bool)>(&chandelier::fall));
            fall(true);
        }

};


int main()
{
    chandelier j = chandelier("Crystal Chandelier");

    j.fall_wrap();
    j.jump_wrap();
    j.exec_actions(false);



    return 0;
}


