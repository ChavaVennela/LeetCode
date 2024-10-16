class Solution {
    private static final int MOD = 1000000007;

    // Adds two integers with modulo operation
    private int modAdd(int a, int b) {
        if ((a += b) >= MOD) {
            a -= MOD;
        }
        return a;
    }

    // Multiplies two long values with modulo operation
    private int modMul(long a, long b) {
        return (int) (a * b % MOD);
    }

    // Calculates Z-array for a given string
    private int[] calculateZArray(String str) {
        int len = str.length();
        int[] zArray = new int[len];
        for (int i = 1, left = 0, right = 0; i < len; ++i) {
            if (i <= right && zArray[i - left] <= right - i) {
                zArray[i] = zArray[i - left];
            } else {
                int zLen = Math.max(0, right - i + 1);
                while (i + zLen < len && str.charAt(i + zLen) == str.charAt(zLen)) {
                    zLen++;
                }
                zArray[i] = zLen;
            }
            if (i + zArray[i] - 1 > right) {
                left = i;
                right = i + zArray[i] - 1;
            }
        }
        return zArray;
    }

    // Multiplies two matrices with modulo operation
    private int[][] modMatrixMultiply(int[][] matA, int[][] matB) {
        int rowsA = matA.length, colsA = matA[0].length, colsB = matB[0].length;
        int[][] result = new int[rowsA][colsB];
        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsB; ++j) {
                for (int k = 0; k < colsA; ++k) {
                    result[i][j] = modAdd(result[i][j], modMul(matA[i][k], matB[k][j]));
                }
            }
        }
        return result;
    }

    // Computes matrix exponentiation with modulo
    private int[][] modMatrixPower(int[][] mat, long exponent) {
        int n = mat.length;
        int[][] identity = new int[n][n];
        for (int i = 0; i < n; ++i) {
            identity[i][i] = 1;
        }
        int[][] baseMatrix = new int[n][n];
        for (int i = 0; i < n; ++i) {
            System.arraycopy(mat[i], 0, baseMatrix[i], 0, n);
        }
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                identity = modMatrixMultiply(identity, baseMatrix);
            }
            baseMatrix = modMatrixMultiply(baseMatrix, baseMatrix);
            exponent >>= 1;
        }
        return identity;
    }

    // Finds the number of ways to transform string `s` into `t` using `k` operations
    public int numberOfWays(String s, String t, long k) {
        int n = s.length();
        int[] dp = modMatrixPower(new int[][]{{0, 1}, {n - 1, n - 2}}, k)[0];
        s += t + t;  // Concatenate `t` twice to `s` for cyclic rotation
        int[] zArray = calculateZArray(s);
        int maxLen = n + n;
        int totalWays = 0;

        for (int i = n; i < maxLen; ++i) {
            if (zArray[i] >= n) {
                totalWays = modAdd(totalWays, dp[i - n == 0 ? 0 : 1]);
            }
        }
        return totalWays;
    }
}
