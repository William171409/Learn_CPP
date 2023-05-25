// a) Write a class named Ball. Ball should have two private member variables with default values: 
// m_color (“black”) and m_radius (10.0). Ball should provide constructors to set only m_color, 
// set only m_radius, set both, or set neither value. For this quiz question, 
// do not use default parameters for your constructors. 
// Also write a function to print out the color and radius of the ball.
#include <iostream>
#include <string_view>

enum Color
{
    black,
    white,
    red,
    green,
    blue,
};

class Ball
{
    Color m_color;
    double m_radius;
public:
    Ball(double r=10.0,Color c=blue)
    {
        m_color=c;
        m_radius=r;
    }

    Ball(Color c)
    {
        m_color=c;
        m_radius = 10.0;

    }
    void print()
    {
        std::cout<<"The color of the ball: "<<colorConverter(m_color)<<'\n'<<"The radius of the ball: "<<m_radius<<'\n';
    }
    std::string_view colorConverter(int index)
    {
        switch(index)
        {
            case 0:return "black";
            case 1:return "white ";
            case 2:return "red ";
            case 3:return "green ";
            case 4:return "blue ";
            default:
                return "UNKOWN!";
        }
    }
};

int main()
{
	Ball def{};
	def.print();

	Ball blue_ball{green};
	blue_ball.print();

	Ball twenty{ 100.0 };
	twenty.print();

	Ball blueTwenty{ 20.0,red };
	blueTwenty.print();

	return 0;
}