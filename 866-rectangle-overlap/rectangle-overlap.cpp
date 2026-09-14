class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a=rec1[0];
        int b=rec1[1];
        int c=rec1[2];
        int d=rec1[3];
        int a1=rec2[0];
        int b1=rec2[1];
        int c1=rec2[2];
        int d1=rec2[3];
        if(a<c1 && a1<c && b<d1 && b1<d )return true;
        return false;

    }
};