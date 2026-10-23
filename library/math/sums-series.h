// Sums and Series
double ln_series(double x) {
    return x - (x * x / 2) + (x * x * x / 3);
}

double sin_series(double x) {
    return x - pow(x, 3) / 6 + pow(x, 5) / 120;
}

double cos_series(double x) {
    return 1 - pow(x, 2) / 2 + pow(x, 4) / 24;
}
