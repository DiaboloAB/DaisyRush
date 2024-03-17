#include "Core.hpp"

int main() {

    entt::registry registry;
    Core core(registry);
    core.run();

    return 0;
}