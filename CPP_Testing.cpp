
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <deque>


class Freezable
{
    public:
        std::string m_name;
        std::pair<int, int > m_position;
    protected:
        std::deque <void (*)(std::string, bool) > m_actions;
    public:
        void exec_actions(bool forward)
        {
            if (forward)
            {
                for (int i = 0; i < m_actions.size(); i++)
                {
                    m_actions[i](m_name, true);
                }
            }
            else
            {
                for (int i = m_actions.size()-1; i >= 0; i--)
                {
                    m_actions[i](m_name, false);
                }
            }

        }
        
        Freezable(std::string name, int x = 0, int y = 0)
        {
            m_name = name;
            m_position = std::pair<int, int>(x, y);
            m_actions = std::deque <void (*)(std::string, bool)>();
        }

};

class chandelier: public Freezable
{
    public:
        std::string Shape;
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
    Freezable j = Freezable();
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


