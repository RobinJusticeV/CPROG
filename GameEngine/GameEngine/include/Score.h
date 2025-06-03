//gör klart en färdig implementation

#ifndef SCORE_H
#define SCORE_H

namespace cwing {

    class Score {
    public:
        static Score* getInstance();
        void reset();
        void addPoints(int points);
        int getScore() const;

    private:
        Score();
        int currentScore;
    };

}
#endif
