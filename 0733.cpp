// First time
/*
    Recursive
    DFS
    Make all pixels which value equal to image[sr][sc] become to "color"
    So we need to save the original value "image[sr][sc]"
    
    *Constraints:
    0 <= sr < image.length
    0 <= sc < image[i].length

*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int start) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == color || image[sr][sc] != start)
            return;
        image[sr][sc] = color;
        dfs(image, sr-1, sc, color, start);
        dfs(image, sr+1, sc, color, start);
        dfs(image, sr, sc-1, color, start);
        dfs(image, sr, sc+1, color, start);
    }
};

/*
    BFS
    try to use queue to implement?
    DFS
    try to use stack to implement??
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    }

};
