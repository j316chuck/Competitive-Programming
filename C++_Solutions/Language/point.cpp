struct point {
       double x, y;

       // ...

       // Declare operator < taking precision into account
       bool operator < (const point& p) const {
            if(x < p.x - epsilon) return true;
            if(x > p.x + epsilon) return false;
            if(y < p.y - epsilon) return true;
            if(y > p.y + epsilon) return false;
            return false;
       }
 };
