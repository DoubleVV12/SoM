//
// Created by Walid on 01/06/2016.
//

#include "Dialog.h"

Dialog::Dialog(std::string *m) {
    message = m;
    currentLine = 0;
    endAtLine = 0;
    ended = false;
}

void Dialog::update() {
    currentLine++;
    if(currentLine>endAtLine)
        ended = true;
}

std::string *Dialog::getMessage() {
    return message;
}

int Dialog::getCurrentLine() {
    return currentLine;
}


void Dialog::setCurrentLine(int i) {
    currentLine = i;
}

int Dialog::getEndAtLine() {
    return endAtLine;
}

void Dialog::setEndAtLine(int i) {
    endAtLine = i;
}

bool Dialog::isEnded() {
    return ended;
}













