// Trigonometric identities
#define PI 3.14159265358979323846

double sin_plus(double v, double w) {
    return sin(v) * cos(w) + cos(v) * sin(w);
}

double cos_plus(double v, double w) {
    return cos(v) * cos(w) - sin(v) * sin(w);
}

double tan_plus(double v, double w) {
    return (tan(v) + tan(w)) / (1 - tan(v) * tan(w));
}
