#include "simon.h"
#include <math.h>
#include <iostream>
#include <QObject>

// Simon Game
//Author: Devin White
//constructor
Simon::Simon(QObject *parent) : QObject(parent)
{
    sequenceLength = 1;
    playerLost = false;
    lightingIndex = 0;
    timer = 4000;
    lives = 0;
}

//picks a new color at random to add to the sequence
void Simon::pickRandomColor()
{
        //generates a random number between 1 and 4
        int color = rand() % 4 + 1;
        switch(color)
        {
            case 1:
            case 4:
            //press Blue button
            //add blue to vector
            computerInputs.push_back(Blue);
            break;

            case 2:
            case 3:
            //press Red Button
            //add red to vector
            computerInputs.push_back(Red);
            break;
        }
        sequenceLength++;
        //on normal mode, speeds up the next sequence
        if(timer > 500 && !easyMode)
        {
            timer -= sequenceLength * 50;
        }
}

//activates easy mode
void Simon::easyModeEngaged()
{
    lives = 3;
    easyMode = true;
    currentIndex = 0;
    numCorrect = 0;
    sequenceLength = 1;
    computerInputs.clear();
    pickRandomColor();
    emit updateLives(lives);
    emit lightColors();
}

//starts the game
void Simon::beginPlay()
{
    timer = 3000;
    currentIndex = 0;
    easyMode = false;
    lives = 0;
    numCorrect = 0;
    sequenceLength = 1;
    computerInputs.clear();
    pickRandomColor();

    emit lightColors();
}

//calls the lightcolors in UI
//Ui also calls to this for proper delay
void Simon::lightColors()
{
    //if there is still buttons to light, lights them
    if(lightingIndex < computerInputs.size())
    {
      colors color = computerInputs[lightingIndex];
      lightingIndex++;
      emit lightButton(timer, color);
    }
    //if entire sequence has been lit, set to player turn
    else
    {
      lightingIndex = 0;
      emit progressRange(computerInputs.size());
      emit isPlayerTurn();
    }
}

//compares player inputs with the computer's sequence
void Simon::compareInputs(colors userInput)
{
    if(computerInputs[currentIndex] == userInput)
    {
        numCorrect++;
        currentIndex++;
        emit updateProgress(numCorrect);
        if(numCorrect == computerInputs.size())
        {
            pickRandomColor();
            currentIndex = 0;
            numCorrect = 0;
            emit successfulGuess();
        }
    }
    else
    {
        //if on easymode, goes to next sequence if there are still lives
        if(easyMode && lives > 0)
        {
            lives = lives - 1;
            pickRandomColor();
            currentIndex = 0;
            numCorrect = 0;
            emit updateLives(lives);
        }
        //else if normal mode or lives = 0, restarts/ends the game
        else
        {
            lightingIndex = 0;
            currentIndex = 0;
            numCorrect = 0;
            timer = 4000;
            emit restartGame();
        }
    }

}
