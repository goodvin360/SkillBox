#include <iostream>
#include "variant"
#include "map"
#include "vector"
#include "string"
#include "any"
#include "sstream"

struct PrintVisitor
{
    template<class T>
    std::string operator()(T&& _in)
    {
        std::stringstream a;
        a << _in;
        return a.str();
    }
};

template<class... T>
struct VariantContainer
{
public:
    using value_type = std::variant<T...>;

public:
    class Pair;
    class Pair{
    public:
        value_type key;
        value_type value;
        Pair(value_type inKey, value_type inValue) : key(inKey), value(inValue){};
        void PrintPair()
        {
            std::cout << std::visit(PrintVisitor{}, key) << " " << std::visit(PrintVisitor{},value) << std::endl;
        }
    };

    std::vector<Pair> data;

    template<typename T1, typename T2>
    void Add(T1 const &_key, T2 const &_val)
    {
        auto p = Pair(_key, _val);
        data.push_back(p);
    }

    template<typename T1>
    std::vector<int> Find(T1 const &_key) {
        T1 key;
        std::vector<int> index;
        for (int i = 0; i < data.size(); i++) {
            auto p = data.at(i);
            auto k = p.key;
            if (std::get_if<T1>(&k)) {
                key = *std::get_if<T1>(&k);
                if (key == _key) {
                    index.push_back(i);
                }
            }
        }
        return index;
    }

    template<typename T1>
    void PrintFind(T1 const &_key){
        auto v = Find(_key);
        if(v.empty()){
            std::cout<<std::endl <<"Key '"<< _key<<"' not found"<<std::endl;
        }
        else{
            std::cout<<std::endl <<"Key '"<< _key<<"' found"<<std::endl;
            for(auto it:v){
                data.at(it).PrintPair();
            }
        }
    }

    template<typename T1>
    void Remove(T1 const &_key){
        auto v = Find(_key);
        if(!v.empty()){
            int i = 0;
            std::cout<<std::endl <<"Key '"<< _key<<"' found"<<std::endl;
            for(auto it:v){
                data.erase(data.begin()+it-i);
                i++;
            }
            std::cout <<"Key '"<< _key<<"' removed"<<std::endl;
        }
        else{
            std::cout <<std::endl<<"Key '"<< _key<<"' not found"<<std::endl;
        }
    }

    void Print()
    {
        for (auto it:data)
        {
            it.PrintPair();
        }
    }
};


int main() {
    std::cout << "Task 3" << std::endl;

    VariantContainer<int, double, std::string> variantCollection;

    variantCollection.Add(6.0,"sdfsfsf");
    variantCollection.Add("2",5);
    variantCollection.Add(3,6.25);
    variantCollection.Print();

    auto v1 = variantCollection.Find(5.0);
    variantCollection.PrintFind(6.0);

    variantCollection.Remove(6.0);
    variantCollection.PrintFind(6.0);

    std::cout << std::endl;

    return 0;
}

