#include<iostream>
#include<string>
#include<string_view>
#include<format>

int main(){
    std::string_view v1{"hello\n"};
    std::string s2{" uh"};
    std::string s1{"nah"+s2};
    std::cout<<v1;
}

