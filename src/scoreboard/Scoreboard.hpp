/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Scoreboard
*/

#ifndef SCOREBOARD_HPP_
#define SCOREBOARD_HPP_

#include <string>
#include <tuple>
#include <vector>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

#include <nlohmann/json.hpp>

class Scoreboard {
    public:
        Scoreboard() {};
        ~Scoreboard() {};

        std::vector<std::tuple<std::string, int>> getScores() const { return _scores; }

        void updateScores() {
            curlpp::Cleanup myCleanup;

            std::ostringstream os;
            os << curlpp::options::Url(std::string("https://daisyrush.jam.jeffroy.eu"));

            std::string json = os.str();

            nlohmann::json j = nlohmann::json::parse(json);
            std::vector<std::tuple<std::string, int>> scores;
            for (auto &el : j) {
                scores.push_back(std::make_tuple(el["name"], el["timestamp"]));
            }
            setScores(scores);
        }

    protected:
    private:
        void setScores(std::vector<std::tuple<std::string, int>> scores) { _scores = scores; }
        std::vector<std::tuple<std::string, int>> _scores;
};

#endif /* !SCOREBOARD_HPP_ */
