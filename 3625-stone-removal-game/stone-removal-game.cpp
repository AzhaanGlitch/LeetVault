class Solution {
public:
    bool canAliceWin(int n) {
        if(n <= 9){
            return false;
        }
        else if(n <= 18){
            return true;
        }
        else if(n <= 26){
            return false;
        }
        else if(n <= 33){
            return true;
        }
        else if(n <= 39){
            return false;
        }
        else if(n <= 44){
            return true;
        }
        else if(n <= 46){
            return false;
        }
        else if(n <= 48){
            return false;
        }
        else{
            return true;
        }
    }
};