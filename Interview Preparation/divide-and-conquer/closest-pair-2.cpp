// time complexity: O(n * log2(n))

#include <bits/stdc++.h>
using namespace std;

struct Point
{
  int x, y;
};
void printArray(vector<Point> &arr)
{
  cout << "[";
  for(int i = 0; i < arr.size(); i++)
    cout << "(" << arr[i].x << "," << arr[i].y << ")" << " ";
  cout << "]" << endl;
}
double eclideanDistance(Point &p1, Point &p2)
{
  return sqrt(
    (p1.x - p2.x) * (p1.x - p2.x) * double(1.0) + 
    (p1.y - p2.y) * (p1.y - p2.y) * double(1.0)
  );
}

bool compareX(Point &p1, Point &p2)
{
  if(p1.x == p1.x)
    return p1.y < p2.y;
  return p1.x < p2.x;
}

bool compareY(Point &p1, Point &p2)
{
  if(p1.y == p1.y)
    return p1.x < p2.x;
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
  for(int i = 0; i < strip.size(); i++)
  {
    // only run this loop when distance between y coordinates is less than d
    for(int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++)
      d = min(d, eclideanDistance(strip[i], strip[j]));
  }
  return d;
}

double closestUtil(vector<Point> &pointsX, vector<Point> &pointsY)
{
  printArray(pointsX);
  printArray(pointsY);
  // base case
  if(pointsX.size() <= 3)
  {
    return bruteForce(pointsX);
  }
  // step 2: find the mid point in sorted array
  int mid = pointsX.size() / 2;
  Point midPoint = pointsX[mid];

  vector<Point> pointsXl, pointsXr;
  for(int i = 0; i < pointsX.size(); i++)
  {
    if(i < mid)
      pointsXl.push_back(pointsX[i]);
    else
      pointsXr.push_back(pointsX[i]);
  }

  vector<Point> pointsYl, pointsYr;
  for(int i = 0; i < pointsY.size(); i++)
  {
    if((pointsY[i].x < midPoint.x || (pointsY[i].x == midPoint.x && pointsY[i].y < midPoint.y)) && pointsYl.size() < mid)
      pointsYl.push_back(pointsY[i]);
    else
      pointsYr.push_back(pointsY[i]);
  }
  // step 3: divide the array into two halves
  // answer from left region
  double dl = closestUtil(pointsXl, pointsYl);

  // answer from right region
  double dr = closestUtil(pointsXr, pointsYr);

  double d = min(dl, dr);

  // step 4: find the points closest to mid point
  vector<Point> strip;
  for(int i = 0; i < pointsY.size(); i++)
  {
    if(abs(pointsY[i].x - midPoint.x) < d)
    {
      strip.push_back(pointsY[i]);
    }
  }
  // find minimum when one point is from left and one is from right
  return min(d, stripClosest(strip, d));
}

double closest(vector<Point>& points)
{
  // step 1: sort the points by x co-ordinate
  vector<Point> pointsX = points;
  sort(begin(pointsX), end(pointsX), compareX);
  vector<Point> pointsY = points;
  sort(begin(pointsY), end(pointsY), compareY);
  return closestUtil(pointsX, pointsY);
}

int main()
{
  vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
  cout << "Brute Force: " << bruteForce(points) << endl;
  double ans = closest(points);
  cout << "Closest Distance: " << ans << endl;
  return 0;
}