#ifndef STDVECTORPERFORMANCE_H
#define STDVECTORPERFORMANCE_H

#include <iostream>
#include <vector>
#include <QElapsedTimer>


const INT stdLOOP = AMOUNT;
QElapsedTimer stdTimer;
std::vector<INT> stdVec;

void clearStd() {
    stdVec.clear();
    stdVec.reserve(stdLOOP);
    stdTimer.restart();
}

void stdfillUp() {
    stdVec.clear();
    stdVec.reserve(stdLOOP);
    for (INT i = 0; i < stdLOOP; ++i)
        stdVec.emplace_back(i);
}

static void stdPrint(QString str) {
    std::cout << str.toStdString() << std::endl;
}


void StdVectorPerofmance() {

    // init to make sure that memory has been allocated physically
    clearStd();
    for (INT i = 0; i < stdLOOP; ++i)
    {
        stdVec.data()[i];
    }

    // Check adding values
    clearStd();
    for (INT i = 0; i < stdLOOP; ++i)
    {
        stdVec.push_back(i);
    }
    QString pushBackStr = "vec.push_back(i) == " + QString::number(stdTimer.elapsed());
    stdPrint(pushBackStr);

    clearStd();
    for (INT i = 0; i < stdLOOP; ++i) 
    {
        stdVec.emplace_back(i);
    }
    QString emplace_backStr = "vec.emplace_back(i) == " + QString::number(stdTimer.elapsed());
    stdPrint(emplace_backStr);

    clearStd();
    for (INT i = 0; i < stdLOOP; ++i)
    {
       stdVec.insert(stdVec.end(), i);
    }
    QString insertStr = "vec.insert(i) == " + QString::number(stdTimer.elapsed());
    stdPrint(insertStr);

    clearStd();
    for (INT i = 0; i < stdLOOP; ++i)
    {
        stdVec.data()[i] = i;
    }
    QString dataAccessStr = "vec.data()[i] == " + QString::number(stdTimer.elapsed());
    stdPrint(dataAccessStr);

    // Check access
    unsigned long long int sum = 0;
    stdfillUp();
    stdTimer.restart();
    for (INT i = 0; i < stdLOOP; ++i) {
        sum += stdVec.at(i);
    }
    QString atStr = "Access at() == " + QString::number(stdTimer.elapsed());
    stdPrint(atStr);
    stdPrint(QString::number(sum));


    sum = 0;
    stdTimer.restart();
    for(auto it = stdVec.begin(); it != stdVec.end(); ++it) {
        sum += (*it);
    }
    QString iterStr = "Access iterator == " + QString::number(stdTimer.elapsed());
    stdPrint(iterStr);
    stdPrint(QString::number(sum));


    sum = 0;
    stdTimer.restart();
    for (INT i = 0; i < stdLOOP; ++i) {
        sum += stdVec[i];
    }
    QString subscriptingStr = "Access subscription == " + QString::number(stdTimer.elapsed());
    stdPrint(subscriptingStr);
    stdPrint(QString::number(sum));
}

#endif // STDVECTORPERFORMANCE_H
