//
// Created by Walid on 01/06/2016.
//

#ifndef SOM_DIALOG_H
#define SOM_DIALOG_H


#include <c++/string>

class Dialog {
private:

    std::string *message;
    int currentLine;
    int endAtLine;
    bool ended;

public:
    //Constructor
    Dialog(std::string *m);

    //Getters and setters
    std::string *getMessage();

    int getCurrentLine();
    void setCurrentLine(int i);

    int getEndAtLine();
    void setEndAtLine(int i);

    bool isEnded();

    //Other functions
    void update();
};


#endif //SOM_DIALOG_H
