template<typename T>
struct BIT2D
{
    int n, m;
    vector<vector<T>> bit;

    BIT2D(int n, int m) : n(n), m(m)
    {
        bit.resize(n + 1, vector<T>(m + 1, 0));
    }

    void update(int x, int y, T v)
    {
        int originalX = x, originalY = y;
        while (x <= n)
        {
            y = originalY;
            while (y <= m)
            {
                bit[x][y] += v;
                y += (y & -y);
            }
            x += (x & -x);
        }
    }

    T query(int x, int y)
    {
        int originalX = x, originalY = y;
        T ans = 0;
        while (x > 0)
        {
            y = originalY;
            while (y > 0)
            {
                ans += bit[x][y];
                y -= (y & -y);
            }
            x -= (x & -x);
        }
        return ans;
    }

    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                update(i, j, arr[i][j]);
            }
        }
    }

    T queryRange(int x1, int y1, int x2, int y2)
    {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};


/**
  BIT2D<int> bit2d(n, m);
  BIT2D<long long> bit2d(n, m);
**/
