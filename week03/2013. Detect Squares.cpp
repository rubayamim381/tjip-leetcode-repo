//tc = O(n), mc = O(n)
//n = total number of points

class DetectSquares {
public:

    map<vector<int>, int> points;

    DetectSquares() {
        points.clear();
    }

    void add(vector<int> point) {
        points[point]++;
    }

    int count(vector<int> qpoint) {

     int total_sqr = 0;
     int x2 = qpoint[0];
     int y2 = qpoint[1];

     for(auto &p : points){
         /*
         x4y2------q(x2y2)
         |
         |
         |
         x4y4------x2y4
         */

         int x4 = p.first[0];
         int y4 = p.first[1];

         if( (x2 == x4) && (abs(x2-x4) != abs(y2-y4)) )
            continue;

         if(points.count({x4,y2}) && points.count({x2,y4})){
             total_sqr += points[{x4,y2}] * points[{x2,y4}] * points[{x4,y4}] ;
         }

     }

     return total_sqr;

    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
