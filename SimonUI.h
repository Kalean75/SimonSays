#ifndef SIMONUI_H
#define SIMONUI_H

#include <QMainWindow>
#include "simon.h"
#include <QTimer>
//Author:Devin White
//Cs 3505
//A5 Simon Game
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private: int lightTimer;


public slots:
    void updateProgress(float progressValue);
    void setProgressRange(float range);
    void isPlayerTurn();
    void restartGame();
    void lightButton(int timer,Simon::colors color);
    void revertButtons();
    void correctGuess();
    void displayLives(int lives);

private slots:
    void on_RedButton_pressed();
    void disableButtons();
    void on_BlueButton_pressed();

    void on_StartButton_pressed();

    void on_EasyMode_pressed();

private:
    Simon simon;
    Ui::MainWindow *ui;
};

#endif // SIMONUI_H
