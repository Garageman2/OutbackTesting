
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <variant>


//TODO: is there a way to do this as an interface with child implementation as a template?
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
    private:
        void fall(bool forward)
        {
            m_position.first = 10;
            m_position.second = 10;

        }

    public:
        void fall_wrap()
        {
            auto thing = fall;
            m_actions.push_back(jump);
            m_actions.push_back
        }
};

void fall(std::string name, bool forward)
{
    if (forward)
    {
        std::cout << name + " fell" << std::endl;
    }
    else
    {
        std::cout << name + " rose back into place" << std::endl;
    }
   
}

void shatter(std::string name,bool forward)
{
    if (forward)
    {
        std::cout << name + " shattered" << std::endl;
    }
    else
    {
        std::cout << name + " reconstituted itself" << std::endl;
    }
}

int main()
{
    Freezable j = Freezable("Chandalier");
    std::deque <void (*)(std::string, bool) > actions = std::deque<void (*)(std::string, bool)>();
    
    actions.push_back(shatter);
    actions.push_back(fall);
    
    for (int i = 0; i < actions.size(); i++)
    {
        actions[i]("A rare 14th century Ming Dynasty Vase", true);
    }

    for (int i = actions.size()-1; i >= 0; i--)
    {
        actions[i]("The rare 14th century Ming Dynasty Vase", false);
    }


    return 0;
}


