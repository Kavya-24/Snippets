/*
Problem Statement: Non-Degenerate Right Triangles

Satyam is given n distinct points on a 2D coordinate plane. It is guaranteed that 0 ≤ yi ≤ 1 for all the given points (xi, yi).
Your task is to determine how many different non-degenerate right triangles can be formed by choosing three different points as its vertices.

Definitions:
- A non-degenerate right triangle has positive area and an interior 90° angle.
- Two triangles are considered different if there is at least one point that is a vertex of one triangle but not the other.

Input:
- The first line contains an integer t (1 ≤ t ≤ 10^4) — the number of test cases.
- The first line of each test case contains an integer n (3 ≤ n ≤ 2⋅10^5) — the number of points.
- The following n lines contain two integers xi and yi (0 ≤ xi ≤ n, 0 ≤ yi ≤ 1) — the coordinates of the i-th point. All points (xi, yi) are distinct.

Output:
For each test case, output the number of distinct non-degenerate right triangles that can be formed from choosing three points.

Constraints:
- The sum of all n over all test cases does not exceed 2⋅10^5.
*/

// THE SOLUTION:

#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
#define int long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        map<pair<int, int>, int> m;
        vector<int> count(2); // To store count of points where y=0 and y=1

        fo(i, n)
        {
            int x, y;
            cin >> x >> y;
            m[{x, y}] = 1;
            count[y]++;
        }

        int ans = 0;
        for (auto &[i, j] : m)
        {
            int x = i.first;
            int y = i.second;

            if (m.count({x, 1 - y}))
            {
                ans += count[y] - 1; // Right angle triangle sharing a vertical line
            }

            if (m.count({x - 1, 1 - y}) && m.count({x + 1, 1 - y}))
            { // trinagle with  90 degree at the y=0 and y=1 point.
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
