#include <vector>
using namespace std;

class Solution
{
public:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int INF = (int)1e9;
        int Row = (int)mat.size();
        int Col = (int)mat[0].size();

        vector<vector<int>> dist(Row, vector<int>(Col, INF));

        for (int r = 0; r < Row; r++)
            for (int c = 0; c < Col; c++)
                if (mat[r][c] == 0)
                    dist[r][c] = 0;

        //----只能左上
        for (int r = Row - 1; r > -1; r--)
        {
            for (int c = Col - 1; c > -1; c--)
            {
                dist[r][c] = min(dist[r][c], r + 1 < Row ? dist[r + 1][c] + 1 : INF);
                dist[r][c] = min(dist[r][c], c + 1 < Col ? dist[r][c + 1] + 1 : INF);
            }
        }

        //----只能右下
        for (int r = 0; r < Row; r++)
        {
            for (int c = 0; c < Col; c++)
            {
                dist[r][c] = min(dist[r][c], 0 <= r - 1 ? dist[r - 1][c] + 1 : INF);
                dist[r][c] = min(dist[r][c], 0 <= c - 1 ? dist[r][c - 1] + 1 : INF);
            }
        }

        return dist;
    }
};
