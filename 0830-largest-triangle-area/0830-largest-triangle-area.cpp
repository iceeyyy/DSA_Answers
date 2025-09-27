class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result=0;
        int n=points.size();

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){

                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];

                    double area = fabs(x1*(y2 - y3) + x2*(y3 - y1) +  x3*(y1 - y2)) / 2.0;

                    result=max(result,area);
                }
            }
        }
        return result;
    }
};