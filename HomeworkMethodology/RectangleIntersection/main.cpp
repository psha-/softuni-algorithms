#include <iostream>
#include <vector>
#include <limits>

using namespace std;

namespace Rectangles {
    vector<vector<short> > IntersectMap;
    int MapOffsetX;
    int MapOffsetY;
    int IntersectArea = 0;

    vector<vector<int> > coords;

    void ReadCoords()
    {
        int n;
        cin >> n;
        coords = vector<vector<int> >();
        coords.reserve(n);

        MapOffsetX = numeric_limits<int>::max();
        MapOffsetY = numeric_limits<int>::max();

        for( int r=0; r<n; r++ ) {
            coords.push_back(vector<int>());
            coords[r].reserve(4);
            int minX, maxX, minY, maxY;

            cin >> minX >> maxX >> minY >> maxY;
            if(minX < MapOffsetX) {
                MapOffsetX = min(0, minX);
            }
            if(minY < MapOffsetY) {
                MapOffsetY = min(0, minY);
            }

            coords[r].push_back(minX);
            coords[r].push_back(maxX);
            coords[r].push_back(minY);
            coords[r].push_back(maxY);
        }
    }

    void CalculateIntersection()
    {
        if( coords.size() == 0 ) {
            return;
        }
        IntersectMap = vector<vector<short> >(2001, std::vector<short>(2001, 0));
        for(int r=0; r<coords.size(); r++) {
            int minX = coords[r][0] - MapOffsetX;
            int maxX = coords[r][1] - MapOffsetX;
            int minY = coords[r][2] - MapOffsetY;
            int maxY = coords[r][3] - MapOffsetY;
            for( int x = minX; x < maxX; x++ ) {
                for( int y = minY; y < maxY; y++ ) {
                    if( IntersectMap[x][y] == 1) {
                        IntersectArea += 1;
                    }
                    IntersectMap[x][y]++;
                }
            }
        }
    }
}

int main()
{
    Rectangles::ReadCoords();
    Rectangles::CalculateIntersection();
    cout << Rectangles::IntersectArea << endl;

    return 0;
}

