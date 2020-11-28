#include <algorithm>
#include <functional>
#include <random>
#include <string_view>

#include "RandomNameGenerator.hpp"
#include "catch.hpp"

TEST_CASE("Zaliczenie" "[]")
{
    // Setup
    using std::size_t;
    const size_t n_ppl = std::uniform_int_distribution<std::size_t>{500, 1000}(RandomIntGenerator::prng);
    auto random_bool_generator = [d = std::uniform_int_distribution<unsigned short>{0, 1}]{
        return d(RandomIntGenerator::prng);
    };

    constexpr size_t age = 42;
    std::list<Human> ppl;
    std::generate_n(std::back_inserter(ppl), n_ppl, [&](){
            return Human{get_random_name(), age, rbg(), rbg()};
        });
    std::string monsters{n_ppl, 'n'};
    std::transform(ppl.cbegin(), ppl.cend(), monsters.rbegin(), [](const Human& h){
            return h->isMonster() ? 'n' : 'y';
        });
    size_t expected_result_hash = std::hash<std::string>{}(monsters);
    
    // Inoke foo
    auto   r = foo(ppl);
    size_t result_hash = std::hash<std::string_view>{}(r.data(), r.size());

    // Assertions
    CHECK(expected_result_hash == result_hash);
    CHECK(std::all_of(r.cbegin(), r.cend(), [&](const Human& h){return h->getAge() == age + 1;}) == true);
}
