#include <iostream>
//Slightly more complicated example!!!
enum class Color
{
    red,
    blue,
    yellow,
};

enum class Size
{

    S,
    M,
    L,

};

struct QuantPerSize
{

    Size size{};
    int quantity{};
};

struct Distribution
{

    QuantPerSize sSizeQ{Size::S};
    QuantPerSize mSizeQ{Size::M};
    QuantPerSize lSizeQ{Size::L};
};

struct Product
{
    std::string name{};
    double price{};
    Distribution dist{};
};

int main()
{

    Product redShirt{"Red Shirt", 5.0, {}};
    Distribution distr{};
    distr={{distr.sSizeQ.size,123},{distr.mSizeQ.size,123},
    {distr.lSizeQ.size,123}};

    // Distribution distr={{distr.sSizeQ.size,123},{distr.mSizeQ.size,123},
    // {distr.lSizeQ.size,123}};      Avoid this usage!!!
     
    
    
    std::cout<<"The initialized distribution is:"<<std::endl;
    std::cout<<"Size: "<<static_cast<int>(distr.sSizeQ.size)<<'\t';
    std::cout<<"Count: "<<static_cast<int>(distr.sSizeQ.quantity)<<std::endl;
    std::cout<<"Size: "<<static_cast<int>(distr.mSizeQ.size)<<'\t';
    std::cout<<"Count: "<<static_cast<int>(distr.mSizeQ.quantity)<<std::endl;
    std::cout<<"Size: "<<static_cast<int>(distr.lSizeQ.size)<<'\t';
    std::cout<<"Count: "<<static_cast<int>(distr.lSizeQ.quantity)<<std::endl;

    // redShirt = {redShirt.name,redShirt.price,}; // On this part, a compile error will inform that there is no '=' operator for those operands

    return 0;
}