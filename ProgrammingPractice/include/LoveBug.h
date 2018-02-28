#ifndef LOVE_BUG
#define LOVE_BUG

/*
 * A LoveBug (google it if you dare) can occupy any floating-point coordinates (x, y).
 * Its initial position is given in the constructor. Its move member function has another LoveBug as a parameter.
 * If it is closer than 0.1 to that love bug, this love bug's happiness goes up by 1. Otherwise, it Moves itself halfway towards the position of the other love bug
 * Asks the other love bug to move it closer to this one. (Hint: *this). Yes, this will cause this bug recursively to move closer again.
 * Love is like that. “Mathematicians are like lovers… Grant a mathematician the least principle, and he will draw from it a
 * consequence which you must grant him also, and from this consequence another.”—Bernard Le Bovier de Fontenelle
 * However, no love bug loves itself. If the move method is called with the same bug as parameter, it does nothing.
 */

class LoveBug
{
 private:
	int happiness;
	double x, y;
 public:
    LoveBug(double x, double y);
    void move(LoveBug& other);
    double distance(const LoveBug& other) const;
    double get_x() const;
    double get_y() const;
    int get_happiness() const;
 };

#endif
