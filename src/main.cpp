#include "Core.hpp"
#include "scoreboard/Scoreboard.hpp"

int main() {

    Scoreboard scoreboard;
    scoreboard.updateScores();
    std::cout << "Scores:" << std::endl;

    for (auto &el : scoreboard.getScores()) {
        std::cout << std::get<0>(el) << " " << std::get<1>(el) << std::endl;
    }


    // entt::registry registry;
    // Core core(registry);
    // core.run();

    return 0;
}