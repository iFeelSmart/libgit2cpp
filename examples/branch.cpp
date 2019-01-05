#include <iostream>

#include "git2cpp/initializer.h"
#include "git2cpp/repo.h"

int main()
{
    git::Initializer threads_initializer;

    git::Repository repo(".");
    auto branches = repo.branches(git::branch_type::ALL);
    for (auto const & b : branches)
        std::cout << b.name() << std::endl;
}
