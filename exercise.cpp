#include "exercise.h"

Exercise::Exercise(const QString& name, const QString& description, int duration, int calories)
    : name(name), description(description), duration(duration), calories(calories) {}

QString Exercise::getName() const {
    return name;
}

QString Exercise::getDescription() const {
    return description;
}

int Exercise::getDuration() const {
    return duration;
}

int Exercise::getCalories() const {
    return calories;
}
