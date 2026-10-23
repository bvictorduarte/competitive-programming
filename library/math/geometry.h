// Geometry functions
double area_triangle(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double circumradius(double a, double b, double c) {
    double A = area_triangle(a, b, c);
    return (a * b * c) / (4 * A);
}

double inradius(double a, double b, double c) {
    double A = area_triangle(a, b, c);
    return A / ((a + b + c) / 2);
}
