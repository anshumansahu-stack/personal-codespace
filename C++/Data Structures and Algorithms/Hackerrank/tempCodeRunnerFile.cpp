while (sum < n)
        {
            long long c = 4 * a + b;
            sum += c;
            a = b;
            b = c;
        }