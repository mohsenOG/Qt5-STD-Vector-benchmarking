#include <QCoreApplication>


#define INT unsigned long long int
#define TEN_MILLION 10'000'000
#define HUNDRED_MILLION 100'000'000
#define BILLION 1'000'000'000
#define AMOUNT HUNDRED_MILLION

#include "qvectorperformance.h"
#include "stdvectorperformance.h"






int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    print("QVector performance....");
    QVectorPerofmance();
    print("");
    print("StdVector performance....");
    StdVectorPerofmance();
    return a.exec();
}
