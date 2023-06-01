// First time
/*
    Union find algorithm: It is used to handle Disjoint-set data structure "union" and "find", usually be used on the graph with connected component.
    Reduce time complexity:
    1. Path compression
        O
      / | \
     o  o  o
    2. Union by rank
        O                    O              O
      / | \   +   O   =   / | \ \   not    /
     o  o  o             o  o  o o        O
                                        / | \
                                       o  o  o

    T: O(n)/S: O(n)
*/
class Solution {
public:
    // Use Path compression to reduce time complexity
    int find_set(int node, vector<int> &parent) {
        if (parent[node] == node) return node;
        return parent[node] = find_set(parent[node], parent);
    }
    // Use rank to determine how to union
    void union_set(int x, int y, vector<int> &parent, vector<int> &rank) {
        x = find_set(x, parent);
        y = find_set(y, parent);
        if (rank[x] > rank[y]) parent[y] = x;
        else if (rank[x] < rank[y]) parent[x] = y;
        else parent[y] = x; rank[y]++;
        // if (x != y) parent[x] = y;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent, rank;
        unordered_map<string, int> email2idx;
        // Separate different emails to accounts index, also record their parent's index
        for (int i=0; i < accounts.size(); ++i) {
            parent.push_back(i);
            rank.push_back(0);
            for (int j=1; j < accounts[i].size(); ++j) {
                if (email2idx.count(accounts[i][j]))
                    union_set(email2idx[accounts[i][j]], i, parent, rank);
                else
                    email2idx[accounts[i][j]] = i;
            }
        }
        // Transfer accounts index to parent's index and unify the email which has the same parent
        unordered_map<int, vector<string>> parentidx2email;
        for(auto it : email2idx){
            parentidx2email[find_set(it.second, parent)].push_back(it.first);
        }
        // Transfer parent's index to name and sort the emails
        vector<vector<string>> ans;
        for (auto it : parentidx2email) {
            vector<string> account = it.second;
            account.insert(account.begin(), accounts[it.first][0]);
            sort(account.begin()+1, account.end());
            ans.push_back(account);
        }
        return ans;
    }
};