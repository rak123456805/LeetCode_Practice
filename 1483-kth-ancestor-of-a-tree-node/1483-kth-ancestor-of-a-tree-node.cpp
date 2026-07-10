class TreeAncestor {
public:
    int col, row;
    vector<vector<int>> ansistor;
    TreeAncestor(int n, vector<int>& parent) {
        row = n;
        col = log2(n) + 1;
        ansistor.resize(n, vector<int>(col, -1));
        for (int i = 0; i < n; i++) {
            ansistor[i][0] = parent[i];
        }
        for (int i = 1; i < col; i++) {
            for (int j = 0; j < n; j++) {
                if (ansistor[j][i - 1] != -1) {
                    ansistor[j][i] = ansistor[ansistor[j][i - 1]][i - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        long long p = 1;

        for (int i = 0; i < col; i++) {
            if ((k / p) % 2) {
                node = ansistor[node][i];
                if (node == -1)
                    return -1;
            }
            p *= 2;
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */