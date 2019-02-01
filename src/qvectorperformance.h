#ifndef QVECTORPERFORMANCE_H
#define QVECTORPERFORMANCE_H

#include <QtCore>
#include <iostream>
#include <QElapsedTimer>


const INT LOOP = AMOUNT;
QElapsedTimer timer;
QVector<INT> vec;


void clear() {
    vec.clear();
    vec.reserve(LOOP);
    timer.restart();
}

void fillUp() {
    vec.clear();
    vec.reserve(LOOP);
    for (INT i = 0; i < LOOP; ++i)
        vec.append(i);
}

static void print(QString str) {
    std::cout << str.toStdString() << std::endl;
}


void QVectorPerofmance() {
    
    // init to make sure that memory has been allocated physically
    clear();
    for (INT i = 0; i < LOOP; ++i)
    {
        vec.data()[i] = i;
    }

    // Check adding values
    clear();
    for (INT i = 0; i < LOOP; ++i)
    {
        vec.append(i);
    }
    QString appendStr = "vec.append(i) == " + QString::number(timer.elapsed());
    print(appendStr);

    clear();
    for (INT i = 0; i < LOOP; ++i)
    {
       vec.push_back(i);
    }
    QString pushBackStr = "vec.push_back(i) == " + QString::number(timer.elapsed());
    print(pushBackStr);

    clear();
    for (INT i = 0; i < LOOP; ++i)
    {
       vec.insert(vec.end(), i);
    }
    QString insertStr = "vec.insert(i) == " + QString::number(timer.elapsed());
    print(insertStr);

    clear();
    for (INT i = 0; i < LOOP; ++i)
    {
        vec.data()[i] = i;
    }
    QString dataAccessdStr = "vec.data()[i] == " + QString::number(timer.elapsed());
    print(dataAccessdStr);

    // Check access
    unsigned long long int sum = 0;
    fillUp();
    timer.restart();
    for (INT i = 0; i < LOOP; ++i) {
        sum += vec.at(i);
    }
    QString atStr = "Access at() == " + QString::number(timer.elapsed());
    print(atStr);
    print(QString::number(sum));


    sum = 0;
    timer.restart();
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        sum += (*it);
    }
    QString iterStr = "Access iterator == " + QString::number(timer.elapsed());
    print(iterStr);
    print(QString::number(sum));


    sum = 0;
    timer.restart();
    for (INT i = 0; i < LOOP; ++i) {
        sum += vec[i];
    }
    QString subscriptingStr = "Access subscription == " + QString::number(timer.elapsed());
    print(subscriptingStr);
    print(QString::number(sum));
}



#endif // QVECTORPERFORMANCE_H
