#include <iostream>
#include <vector>

using namespace std;

void color(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor, vector<vector<bool>>& seen)
{
    cout << "In color: (" << sr << ", " << sc << ")\n";
    if (!(0 <= sr && sr < image.size() && 0 <= sc && sc < image[0].size()) || seen[sr][sc] || image[sr][sc] != oldColor)
        return;

    image[sr][sc] = newColor;
    seen[sr][sc] = true;
    color(image, sr - 1, sc, oldColor, newColor, seen);
    color(image, sr, sc - 1, oldColor, newColor, seen);
    color(image, sr + 1, sc, oldColor, newColor, seen);
    color(image, sr, sc + 1, oldColor, newColor, seen);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    vector<vector<bool>> seen(image.size(), vector<bool>(image[0].size(), false));
    color(image, sr, sc, image[sr][sc], newColor, seen);
    return image;
}

int main()
{
    vector<vector<int>> input {
        {1, 1, 1},
        {1, 1, 2},
        {1, 0, 1}
    };

    auto result = floodFill(input, 1, 1, 2);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}