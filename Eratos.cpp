void Eratos(int n) {
    if (n <= 1) return;
    bool* PrimeArray = new bool[n + 1];
    for (int i = 2; i <= n; i++) PrimeArray[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i) PrimeArray[j] = false;
    }
}