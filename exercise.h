#ifndef EXERCISE_H
#define EXERCISE_H

#include <QString>

class Exercise {
public:
    Exercise(const QString& name, const QString& description, int duration, int calories);
    QString getName() const;
    QString getDescription() const;
    int getDuration() const;
    int getCalories() const;

private:
    QString name;
    QString description;
    int duration;
    int calories;
};

#endif // EXERCISE_H
