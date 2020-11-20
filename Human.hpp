#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

class Human
{
public:
    Human() : name{"Anonymous"}, age{0}, likes_dogs{true}, likes_cats{true} {}
    Human(std::string name_, unsigned int age_, bool ld, bool lk)
        : name{std::move(name_)}, age{age_}, likes_dogs{ld}, likes_cats{lk}
    {}

    const std::string& getName() const { return name; }
    unsigned int       getAge() const { return age; }
    bool               isMonster() const { return !likes_dogs && !likes_cats; }

private:
    std::string  name;
    unsigned int age;
    bool         likes_dogs;
    bool         likes_cats;
};

#endif
