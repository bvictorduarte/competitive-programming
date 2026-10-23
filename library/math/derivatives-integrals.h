// Derivatives and Integrals
double d_arcsin_dx(double x) {
    return 1 / sqrt(1 - x * x);
}

double d_arccos_dx(double x) {
    return -1 / sqrt(1 - x * x);
}

double integral_tan(double a) {
    return -log(fabs(cos(a))) / a;
}

double integral_exp(double x) {
    return sqrt(M_PI) / 2 * erf(x);
}
