//gör klart en färdig implementation


#include "Score.h"

namespace cwing {

    Score::Score() : currentScore(0) {}

    Score* Score::getInstance() {
        static Score instance;
        return &instance;
    }

    void Score::reset() {
        currentScore = 0;
    }

    void Score::addPoints(int points) {
        currentScore += points;
    }

    int Score::getScore() const {
        return currentScore;
    }

}
