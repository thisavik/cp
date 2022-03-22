// time complexity: O(n * log2(n)^2)

#include <bits/stdc++.h>
using namespace std;

struct Point
{
  int x, y;
};

double eclideanDistance(Point &p1, Point &p2)
{
  return sqrt(
    (p1.x - p2.x) * (p1.x - p2.x) * double(1.0) + 
    (p1.y - p2.y) * (p1.y - p2.y) * double(1.0)
  );
}

bool compareX(Point &p1, Point &p2)
{
  return p1.x < p2.x;
}

bool compareY(Point &p1, Point &p2)
{
  return p1.y < p2.y;
}

double bruteForce(vector<Point> &points)
{
  vector<Point> ans;
  double min = 1e9;
  for(int i = 0; i < points.size(); i++)
  {
    for(int j = i+1; j < points.size(); j++)
    {
      double dist = eclideanDistance(points[i], points[j]);
      if(dist < min)
      {
        min = dist;
        ans.clear();
        ans.push_back(points[i]);
        ans.push_back(points[j]);
      }
    }
  }
  return min;
}

double stripClosest(vector<Point> &strip, double &d)
{
  // step 5: sort the strip w.r.t. y coordinates
  sort(begin(strip), end(strip), compareY);
  for(int i = 0; i < strip.size(); i++)
  {
    // only run this loop when distance between y coordinates is less than d
    for(int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++)
      d = min(d, eclideanDistance(strip[i], strip[j]));
  }
  return d;
}

double closestUtil(vector<Point> &points, int l, int r)
{
  // base case
  if(r-l+1 <= 3)
  {
    return bruteForce(points);
  }
  // step 2: find the mid point in sorted array
  int mid = points.size() / 2;
  Point midPoint = points[mid];

  // step 3: divide the array into two halves
  // answer from left region
  double dl = closestUtil(points, l, mid-1);

  // answer from right region
  double dr = closestUtil(points, mid+1, r);

  double d = min(dl, dr);

  // step 4: find the points closest to mid point
  vector<Point> strip;
  for(int i = l; i <= r; i++)
  {
    if(abs(points[i].x - midPoint.x) < d)
    {
      strip.push_back(points[i]);
    }
  }
  // find minimum when one point is from left and one is from right
  return min(d, stripClosest(strip, d));
}

double closest(vector<Point>& points)
{
  // step 1: sort the points by x co-ordinate
  sort(begin(points), end(points), compareX);
  return closestUtil(points, 0, points.size() - 1);
}

int main()
{
  vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
  cout << "Brute Force: " << bruteForce(points) << endl;
  cout << "Closest Distance: " << closest(points) << endl;
  return 0;
}