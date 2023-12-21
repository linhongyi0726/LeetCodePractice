// First time
/*
    Because the number in img only in [0, 255], it only use bit 0 to bit 7
    we can store the result after bit 8

    T: O(nm)/S: O(1)
*/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0, cnt = 0;
                for (int x = max(j - 1, 0); x <= min(j + 1, m - 1); ++x) {
                    for (int y = max(i - 1, 0); y <= min(i + 1, n - 1); ++y) {
                        sum += img[y][x] & 0xff;
                        cnt++;
                    }
                }
                img[i][j] |= (sum / cnt) << 8;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                img[i][j] >>= 8;
            }
        }
        return img;
    }
};

/*
    T: O(nm)/S: O(nm)
*/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0, cnt = 0;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        int nx = j + x, ny = i + y;
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            sum += img[ny][nx];
                            cnt++;
                        }
                    }
                }
                ret[i][j] = sum / cnt;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0, cnt = 0;
                for (int x = max(j - 1, 0); x <= min(j + 1, m - 1); ++x) {
                    for (int y = max(i - 1, 0); y <= min(i + 1, n - 1); ++y) {
                        sum += img[y][x];
                        cnt++;
                    }
                }
                ret[i][j] = sum / cnt;
            }
        }
        return ret;
    }
};

/*
    T: O(nm)/S: O(nm)
*/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = img[i][j], cnt = 1;
                if (i > 0) {
                    sum += img[i - 1][j];
                    cnt++;
                }
                if (i > 0 && j > 0) {
                    sum += img[i - 1][j - 1];
                    cnt++;
                }
                if (i > 0 && j < m - 1) {
                    sum += img[i - 1][j + 1];
                    cnt++;
                }
                if (j > 0) {
                    sum += img[i][j - 1];
                    cnt++;
                }
                if (j < m - 1) {
                    sum += img[i][j + 1];
                    cnt++;
                }
                if (i < n - 1) {
                    sum += img[i + 1][j];
                    cnt++;
                }
                if (i < n - 1 && j > 0) {
                    sum += img[i + 1][j - 1];
                    cnt++;
                }
                if (i < n - 1 && j < m - 1) {
                    sum += img[i + 1][j + 1];
                    cnt++;
                }
                ret[i][j] = sum / cnt;
            }
        }
        return ret;
    }
};