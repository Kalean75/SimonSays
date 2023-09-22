#ifndef SIMON_H
#define SIMON_H
#include <string>
#include <vector>
#include <QObject>
#include <QTimer>
//Author:Devin White
// Simon Game
class Simon: public QObject
{
Q_OBJECT
public:
    explicit Simon(QObject *parent = nullptr);
    enum colors{Red,Blue};
    std::vector<colors> computerInputs;
    void pickRandomColor();
    void compareInputs(Simon::colors userInput);
    bool playerLost;
    int sequenceLength;
    int currentIndex;
    float delaytime;
    int numCorrect;
    int timer;

 private:
    int lightingIndex;
    bool easyMode;
    int lives;

public slots:
    void beginPlay();
    void lightColors();
    void easyModeEngaged();

signals:
    void updateProgress(float progress);
    void progressRange(float range);
    void isPlayerTurn();
    void restartGame();
    void changeColor(Simon::colors color);
    void lightButton(int timer, Simon::colors colors);
    void successfulGuess();
    void updateLives(int lives);
};

#endif // SIMON_H
