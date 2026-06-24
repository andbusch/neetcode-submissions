class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // three vectors of sets
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> boxes(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c != '.'){
                    if (!rows[i].insert(c).second){
                        printf("duplicate row %d", i);
                        return false;
                    }
                    if(!cols[j].insert(c).second){
                        printf("duplicate col %d", j);
                        return false;
                    }
                    if(!boxes[j/3 + (3 * (i/3))].insert(c).second){
                        printf("duplicate num %c", c);
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
