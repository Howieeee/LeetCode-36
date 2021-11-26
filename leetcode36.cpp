class Solution {
public:
    
    bool check_each_array_vaild(vector<char>& arr){
        set<char> s;
        for(int i=0;i<arr.size();i++){
            if(arr[i] == '.')
                continue;
            if(!s.count(arr[i]))
                s.insert(arr[i]);
            else
                return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 0 , col = 0;
        vector<vector<char>>box(9,(vector<char>(0,' ')));
        
        for(int i=0;i<9;i++){
            if(!check_each_array_vaild(board[i]))
                return false; 
            
            vector<char> arr;
            for(int j=0;j<9;j++){
                row = 3*(i/3);
                col = (j/3);
                //cout << row << " " << col << " ";
                arr.push_back(board[j][i]);
                box[row+col].push_back(board[i][j]);
            }
            //cout << endl;
            if(!check_each_array_vaild(arr))
                return false;
            
            
            
        }
        
        for(int i=0;i<9;i++){
            if(!check_each_array_vaild(box[i]))
                return false;
        }
        
        
        
        
        return true;
    }
};
