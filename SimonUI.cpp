#include "SimonUI.h"
#include "ui_SimonUi.h"
#include "simon.h"
#include <iostream>
#include <string>

//A5: Simon UI
//Author Devin White
//Cs 3505
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), simon(this)
{
    ui->setupUi(this);
    connect(ui->StartButton,&QPushButton::pressed,&simon,&Simon::beginPlay);
    connect(ui->EasyMode,&QPushButton::pressed,&simon,&Simon::easyModeEngaged);
    connect(&simon, &Simon::updateProgress, this, &MainWindow::updateProgress);
    connect(&simon, &Simon::progressRange, this, &MainWindow::setProgressRange);
    connect(&simon, &Simon::isPlayerTurn, this, &MainWindow::isPlayerTurn);
    connect(&simon, &Simon::restartGame, this, &MainWindow::restartGame);
    connect(&simon, &Simon::changeColor, this, &MainWindow::revertButtons);
    connect(&simon, &Simon::lightButton, this, &MainWindow::lightButton);
    connect(&simon,&Simon::successfulGuess, this, &MainWindow::correctGuess);
    connect(&simon,&Simon::updateLives, this, &MainWindow::displayLives);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//when redbutton is pressed, checks it against the computer sequence
void MainWindow::on_RedButton_pressed()
{
    ui->RedButton->setStyleSheet(("QPushButton {background-color: rgb(170, 0, 0);} QPushButton:pressed { background-color: rgb(255, 67, 70); }"));

    simon.compareInputs(Simon::Red);
}

//when bluebutton is pressed, checks it against the computer sequence
void MainWindow::on_BlueButton_pressed()
{
    ui->BlueButton->setStyleSheet(("QPushButton {background-color: rgb(0, 0, 127);} QPushButton:pressed { background-color: rgb(37, 150, 255); }"));

    simon.compareInputs(Simon::Blue);
}
//starts the game when the button is pressed
void MainWindow::on_StartButton_pressed()
{
    ui->MessageLabel->setText("Remember The Sequence..");
    ui->RedButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->BlueButton->setEnabled(false);
    ui->StartButton->setEnabled(false);
    ui->EasyMode->setEnabled(false);
    ui->StartButton->setStyleSheet(("QPushButton {background-color: grey;} QPushButton {color: white;}"));
    ui->EasyMode->setStyleSheet(("QPushButton {background-color: grey;} QPushButton {color: white;}"));
    ui->LivesLabel->setText("");
}

//Starts the game in easy mode, where there are lives and it never speeds up
void MainWindow::on_EasyMode_pressed()
{
    ui->LivesLabel->setText("Lives " + QString::number(3));
}

//changes the buttons back to dim after lighting
void MainWindow::revertButtons()
{
        ui->BlueButton->setStyleSheet(("QPushButton {background-color: rgb(0, 0, 127);}"));
        ui->RedButton->setStyleSheet(("QPushButton {background-color: rgb(170, 0, 0);}"));
        QTimer::singleShot(lightTimer, &simon, &Simon::lightColors);
}

//when it's the players turn, reenables the colors
void MainWindow::isPlayerTurn()
{
    ui->MessageLabel->setText("Select the Colors");
    ui->RedButton->setEnabled(true);
    ui->BlueButton->setEnabled(true);
    ui->BlueButton->setStyleSheet(("QPushButton {background-color: rgb(0, 0, 127);}"));
    ui->RedButton->setStyleSheet(("QPushButton {background-color: rgb(170, 0, 0);}"));
}

//updates the progress bar
void MainWindow::updateProgress(float progressValue)
{
    ui->progressBar->setValue(progressValue);
}

//sets progress bar range
void MainWindow::setProgressRange(float range)
{
    ui->progressBar->setRange(0, range);
}

//in easy mode, displays lives, disables unncecessary buttons
void MainWindow::displayLives(int lives)
{
    ui->StartButton->setEnabled(false);
    ui->EasyMode->setEnabled(false);
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);
    ui->StartButton->setStyleSheet(("QPushButton {background-color: grey;} QPushButton {color: white;}"));
    ui->EasyMode->setStyleSheet(("QPushButton {background-color: grey;} QPushButton {color: white;}"));
    ui->LivesLabel->setText("Lives " + QString::number(lives));
    ui->MessageLabel->setText("you lost a life!");
    if(lives < 3)
    {
        QTimer::singleShot(500, this, &MainWindow::correctGuess);
    }
}

//upon failure, restarts the game(after all lives lost in easy mode) and updates message
void MainWindow::restartGame()
{
    ui->StartButton->setEnabled(true);
    ui->EasyMode->setEnabled(true);
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->StartButton->setStyleSheet(("QPushButton {background-color: white;} QPushButton {color: black;}"));
    ui->EasyMode->setStyleSheet(("QPushButton {background-color: white;} QPushButton {color: black;}"));
    ui->MessageLabel->setText("You Lose!");
}

//indicates and lights new sequence if player gets all presses correct
void MainWindow::correctGuess()
{
        //gives extra time before initiating next sequence of colors
        ui->MessageLabel->setText("You are Correct! Get ready...");
        QTimer::singleShot(2000,&simon,&Simon::lightColors);
        QTimer::singleShot(700, this, &MainWindow::disableButtons);
}
//disables buttons from being clicked
void MainWindow::disableButtons()
{
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);
}

//lights up the new sequence
void MainWindow::lightButton(int timer, Simon::colors color)
{
    ui->MessageLabel->setText("remember the sequence");
    lightTimer = timer;
    ui->progressBar->setValue(0);
    switch(color)
    {
        case Simon::Blue:
        ui->BlueButton->setStyleSheet(("QPushButton {background-color: rgb(37, 150, 255); }"));
        break;

        case Simon::Red:
        ui->RedButton->setStyleSheet(("QPushButton {background-color: rgb(255, 67, 70); }"));
        break;
    }
    QTimer::singleShot(lightTimer, this, &MainWindow::revertButtons);
}


